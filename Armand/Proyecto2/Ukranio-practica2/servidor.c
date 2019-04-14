#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
int main(void){
	char * p, total[10];
	struct sockaddr_in servidor, cliente; 
	int ds=-1, errorlocal, lbind, puerto_escucha = 1100, tamrecv, lostpack=0, aux=0;
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
				lostpack= lostpack + (atoi(buff)-(aux));
				printf("\nSe perdió el paquete: %d\n\n",aux+1);
			}
			aux= atoi(buff);
			//printf("Bytes recibidos %d\nNumero: %s\nPuerto Origen: %d\n", tamrecv, buff, ntohs(cliente.sin_port));
			printf("Bytes recibidos %d\nNumero: %s\n", tamrecv, buff);
	    }
	}
	p = strtok(buff,"/");
	p = strtok(NULL,"/");
	strcpy(total,p);
	aux = atoi(total);
	porcent = (float)(lostpack * 100)/aux;
	memset(&buff, 0, sizeof(buff));
	gcvt(porcent, 9, buff);
	printf("Paquetes perdidos = %0.2f%c\n",porcent,37);
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