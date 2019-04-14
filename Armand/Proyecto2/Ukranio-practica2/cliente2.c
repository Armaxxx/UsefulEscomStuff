#include<stdio.h>
#include<pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int * stackn;
int x=0;
typedef struct{
  int ds;
  char n[10];
  struct sockaddr_in *lol;
}sock;
void* hilo_receptor(void* params){
	char *n1,*n2;
	n1 = (char *)malloc(10);
	n2 = (char *)malloc(10);
	pthread_t hilo[2];
	char * p, total[10];
	struct sockaddr_in servidor, cliente; 
	int ds=-1, errorlocal, lbind, puerto_escucha = 1200, tamrecv, lostpack=0, aux=0;
	float porcent;
	socklen_t longitud_addr;
	char buff[100];
	if((ds = socket(PF_INET, SOCK_DGRAM, 0))==-1){
		errorlocal=errno;
		perror("Algo salió mal al abrir el socket");
		exit(errorlocal);
	}
	else
		//printf("El socket fue abierto correctamente\n");
	memset(&servidor, 0, sizeof(servidor));
	servidor.sin_family=PF_INET;
	servidor.sin_port=htons(puerto_escucha);
	servidor.sin_addr.s_addr=INADDR_ANY;
	if((bind(ds, (struct sockaddr *)&servidor, sizeof(servidor)))==-1){
		errorlocal = errno;
		perror("Error en bind");
		close(ds);
		exit(errorlocal);
	}
	else
		//printf("Bind correcto\n");
	memset(&cliente, 0, sizeof(cliente));
	longitud_addr = sizeof(cliente);
	while(1){
		if((tamrecv = recvfrom(ds, buff, sizeof(buff), 0, (struct sockaddr*)&cliente, &longitud_addr))==-1){
			perror("Error al recibir");
		}
		else{
			*(stackn+x)=atoi(buff);
			printf("Se recibió el error: %d\n",*(stackn+x));
			x++;
	    }
	}
	close(ds);
	return 0;
}
void* hilo_envio(void* params){
  char * numbern = (char *)params;
  int i,a=0,tamrecv;
  char * numero;
  numero = (char *)malloc(10);
  socklen_t longitud_addr;
  struct sockaddr_in local, remota; //local recibe, remota envía
  //argv[1] cantidad de numeros
  int ds=-1, errorlocal, lbind;
  char buff[100];
  if((ds = socket(PF_INET, SOCK_DGRAM, 0))==-1){
    errorlocal=errno;
    perror("Algo salió mal al abrir el socket");
    exit(errorlocal);
  }
  else
    printf("El socket fue abierto correctamente\n");
  memset(&local, 0, sizeof(local));
  local.sin_family=PF_INET;
  local.sin_port=htons(0);
  local.sin_addr.s_addr=INADDR_ANY;
  if((bind(ds, (struct sockaddr *)&local, sizeof(local)))==-1){
    errorlocal = errno;
    perror("Error en bind");
    close(ds);
    exit(errorlocal);
  }
  else
    printf("Bind correcto\n");
  longitud_addr = sizeof(local);
  memset(&remota, 0, sizeof(remota));
  remota.sin_family=PF_INET;
  remota.sin_port=htons(1100);
  inet_aton("127.0.0.1", &remota.sin_addr);
  
  for(i=0;i<atoi(numbern);i++){
    sprintf(buff,"%d",i+1);
    if((sendto(ds, buff, sizeof(buff), 0, (struct sockaddr*)&remota, sizeof(remota)))==-1){
          perror("Ups, algo salió mal al enviar");
          errorlocal=errno;
          close(ds);
          exit(errorlocal);
      }
      else{
          printf("Envio exitoso de %s\n", buff);
      }
  }
  memset(&buff, 0, sizeof(buff));
  buff[0] = '0';
  buff[1] = '/';
  buff[2] = '\0';
  a=strlen(buff)+strlen(numbern);
  strcat(buff,numbern);
  buff[a]='\0';
  for(i=0;i<atoi(numbern);i++){
    if((sendto(ds, buff, sizeof(buff), 0, (struct sockaddr*)&remota, sizeof(remota)))==-1){
          perror("Ups, algo salió mal al enviar");
          errorlocal=errno;
          close(ds);
          exit(errorlocal);
    }
  }
  memset(&buff, 0, sizeof(buff));
  if((tamrecv = recvfrom(ds, buff, sizeof(buff), 0, (struct sockaddr*)&local, &longitud_addr))==-1){
      perror("Error al recibir");
  }
  else{
    //printf("Bytes recibidos %d\nNumero: %s\nPuerto Origen: %d\n", tamrecv, buff, ntohs(cliente.sin_port));
    printf("Porcentaje de paquetes perdidos recibido: %s%c\n",buff,37);
  }
  close(ds);
  return 0;
}
int main(int argc, char **argv){
  char * numbern;
  numbern = (char *)malloc(10);
  stackn = (int *)malloc(sizeof(int)*(atoi(argv[1])));
  pthread_t hilo[2];
  strcpy(numbern,argv[1]);
  pthread_create(&hilo[0], NULL, hilo_envio, (void *)numbern);
  pthread_create(&hilo[1], NULL, hilo_receptor, (void *)NULL);
  pthread_join(hilo[0], NULL);
  printf("Se perdieron los siguientes paquetes:\n");
  for(int i=0;i<x;i++){
  	printf("%d\n",*(stackn+i));
  }
  pthread_cancel(hilo[1]);
  return 0;
}