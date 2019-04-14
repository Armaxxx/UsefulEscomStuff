
#include<stdio.h>
#include<pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
void* hilo_resp(void* params){
	char * numbern = (char *)params;
  	int i=0,a=0,tamrecv,n1=0,n2=0;
  	char * numero;
 	numero = (char *)malloc(10);
  	socklen_t longitud_addr;
  	struct sockaddr_in remota; //local recibe, remota envía
  	//argv[1] cantidad de numeros
  	int ds=-1, errorlocal, lbind;
  	char * buff;
   	buff = (char *)malloc(100); 
  	if((ds = socket(PF_INET, SOCK_DGRAM, 0))==-1){
    	errorlocal=errno;
    	perror("Algo salió mal al abrir el socket");
    	exit(errorlocal);
  	}
  	else
    	//printf("El socket fue abierto correctamente\n");
  	longitud_addr = sizeof(remota);
  	memset(&remota, 0, sizeof(remota));
  	remota.sin_family=PF_INET;
  	remota.sin_port=htons(1200);
  	inet_aton("127.0.0.1", &remota.sin_addr);
  	numero = strtok(numbern,"/");
  	n1 = atoi(numero);
	numero = strtok(NULL,"/");
	n2 = atoi(numero);
	printf("Se enviara desde el paquete: %d, al: %d\n",n1,n2);
  	for(i=n1;i<=n2;i++){
  		sprintf(buff,"%d",i);
    	if((sendto(ds, buff, sizeof(buff), 0, (struct sockaddr*)&remota, sizeof(remota)))==-1){
          	perror("Ups, algo salió mal al enviar");
          	errorlocal=errno;
          	close(ds);
          	exit(errorlocal);
      	}
      	else{
          	//printf("Envio exitoso del paquete perdido:  %s\n", buff);
      	}
   }
  	close(ds);
  	return NULL;
}
int main(void){
	int n_h=0,i;
	char *n1;
	n1 = (char *)malloc(10);
	pthread_t *hilo;
	malloc(10);
	hilo= (pthread_t *)malloc(sizeof(pthread_t)*2);
	char * p, total[10];
	struct sockaddr_in servidor, cliente; 
	int ds=-1, errorlocal, lbind, puerto_escucha = 1100, tamrecv, lostpack=0, aux=0, generallost=0;
	float porcent;
	socklen_t longitud_addr;
	char buff[100];
	if((ds = socket(PF_INET, SOCK_DGRAM, 0))==-1){
		errorlocal=errno;
		perror("Algo salió mal al abrir el socket");
		exit(errorlocal);
	}
	else
		printf("El socket fue abierto correctamente\n");
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
		printf("Bind correcto\n");
	memset(&cliente, 0, sizeof(cliente));
	longitud_addr = sizeof(cliente);
	while(1){
		if((tamrecv = recvfrom(ds, buff, sizeof(buff), 0, (struct sockaddr*)&cliente, &longitud_addr))==-1){
			perror("Error al recibir");
		}
		else{
			if(buff[0]=='0'){
				break;
			}
			if(atoi(buff)!=aux+1){
				lostpack= lostpack + (atoi(buff)-(aux))-1;
				generallost = generallost+lostpack;
				sprintf(n1,"%d/%d",aux+1,aux+lostpack);
				printf("/////////Error.- paquetes perdidos:%s\n",n1);
				pthread_create((hilo + n_h), NULL, hilo_resp, (void *)n1);
				n_h++;
				hilo = (pthread_t *)realloc(hilo, sizeof(pthread_t)*(n_h+2));
				
				//printf("\nSe perdió el paquete: %d\n\n",aux+1);
				lostpack = 0;
			}
			printf("Se recibio: %s\n",buff);
			aux= atoi(buff);
			//printf("Bytes recibidos %d\nNumero: %s\n", tamrecv, buff);
	    }
	}
	p = strtok(buff,"/");
	p = strtok(NULL,"/");
	strcpy(total,p);
	aux = atoi(total);
	porcent = (float)(generallost * 100)/aux;
	memset(&buff, 0, sizeof(buff));
	gcvt(porcent, 99, buff);
	printf("Paquetes perdidos = %0.2f%c\n",porcent,37);
	for(i =0;i<n_h;i++);
		pthread_join(*(hilo+i), NULL);
	if((sendto(ds, buff, sizeof(buff), 0, (struct sockaddr*)&cliente, sizeof(cliente)))==-1){
      	perror("Ups, algo salió mal al enviar");
       	errorlocal=errno;
       	close(ds);
       	exit(errorlocal);
	}
	else{
	 	printf("Envio de porcentaje correcto\n");
	}
	close(ds);
	return 0;
}