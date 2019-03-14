#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

int puerto = 7200;

int main(void){
    int num[3];
    int s, res, clilen, x;
    struct sockaddr_in server_addr, msg_to_client_addr;
    unsigned char aux[4], aux1[2];

    s = socket(AF_INET, SOCK_DGRAM, 0);

    /* se asigna una direccion al socket del servidor*/
    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(puerto);
    bind(s, (struct sockaddr *)&server_addr, sizeof(server_addr));
    clilen = sizeof(msg_to_client_addr);
    while(1) {
        recvfrom(s, (char *)num, 3*sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, &clilen);
        printf("Recibido %d del intervalo %d al %d\n",num[0],num[2],num[2]-num[1]);
        for(;num[2] > )
        memcpy(aux, &msg_to_client_addr.sin_addr.s_addr, 4);  
        printf("Ip del cliente: %d %d %d %d\n",aux[0],aux[1],aux[2],aux[3]);      
        
        printf("Puerto cliente: %d\n", ntohs(msg_to_client_addr.sin_port));

        /* envía la petición al cliente. La estructura msg_to_client_addr contiene la dirección socket del cliente */
        sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
    }
}

