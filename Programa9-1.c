#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>

int puerto = 7200;

int main(void){
    int num[2];
    int s, res, clilen;
    struct sockaddr_in server_addr, msg_to_client_addr;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    /*Se asigna una dirección al socket del servido*/
    bzero((char *) )
}