#include <sys/types.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>

int puerto = 7200;

int main(int argc, char const *argv[]){
    struct sockaddr_in msg_to_server_addr, client_addr;
    int s, max, x;
    float res;

    max = atoi(argv[1]);

    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
    msg_to_server_addr.sin_family = AF_INET;
    msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    msg_to_server_addr.sin_port = htons(puerto);

    bzero((char *)&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = INADDR_ANY;
    client_addr.sin_port = htons(0);
    bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));

    for(x = 1; x < max; x++){
        sendto(s, (char *)&x, sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
    }
    x = 0;
    sendto(s, (char *)&x, sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
    /* se bloquea esperando respuesta */
    recvfrom(s, (char *)&res, sizeof(float), 0, NULL, NULL);
    printf("Existe una perdida de paquetes del %.2f porciento,\n", res*100);
    close(s);
}