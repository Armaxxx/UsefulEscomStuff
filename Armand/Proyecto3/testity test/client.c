#include <string.h>
#include <stdio.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <unistd.h>

#define SERV_PORT 49312
#define MAXLINE   1024

char *BanderadeFin = "================END";

int main(int argc, char **argv)
{
    int s, n, archivo;
    struct sockaddr_in servaddr;
    char buf[MAXLINE];
    char *destino, *origen;

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

    s = socket(AF_INET, SOCK_DGRAM, 0);

    origen = argv[2];
    destino = argv[3];
    sendto(s, destino, strlen(destino), 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
    n = recvfrom(s, buf, MAXLINE, 0, NULL, NULL);
    if (!strncmp(buf, "ok", 2)) {
        printf("Filename sent.\n");
    }
    
    archivo = open(origen, O_RDONLY);
    while ((n = read(archivo, buf, MAXLINE)) > 0) {
        sendto(s, buf, n, 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
    }
    sendto(s, BanderadeFin, strlen(BanderadeFin), 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
    
    return 0;
}