#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

int puerto = 7200;

int main(void){
    char aux[4];
    int s, res = 1, num, clilen,error = 0;
    float prom;
    struct sockaddr_in server_addr, msg_to_client_addr;

    s = socket(AF_INET, SOCK_DGRAM, 0);

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(puerto);
    bind(s, (struct sockaddr *) &server_addr, sizeof(server_addr));
    clilen = sizeof(msg_to_client_addr);

    while(1){
        recvfrom(s, (char *)&num, sizeof(int), 0, (struct sockaddr *) &msg_to_client_addr, &clilen);
        if ( num > res){
            error += num - res;
            res = num;
        }
        if (num == 0){
            break;
        }
        res++;
    }
    printf("Se finalizo con %d errores y %d paquetes enviados",error,res);
    prom = (float)error/(float)res;

    sendto(s, (char *)&prom, sizeof(float), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
}