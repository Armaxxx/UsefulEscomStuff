#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
char* itoa(int val, int base){
  static char buf[32] = {0};
  int i = 30;
  for(; val && i ; --i, val /= base)
    buf[i] = "0123456789abcdef"[val % base];
  return &buf[i+1];
}
int main(int argc, char **argv){
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
	
	for(i=0;i<atoi(argv[1]);i++){
		numero = itoa(i+1,10);
		memset(&buff, 0, sizeof(buff));
		strcpy(buff, numero);
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
	a=strlen(buff)+strlen(argv[1]);
	strcat(buff,argv[1]);
	buff[a]='\0';
	printf("%s\n",buff);
	for(i=0;i<atoi(argv[1]);i++){
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
		printf("Paquetes perdidos = %s%c\n",buff,37);
	}
	close(ds);
	return 0;
}