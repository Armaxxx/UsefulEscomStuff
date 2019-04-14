#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
  
#define SERV_PORT 49312
#define MAXLINE   1024
  
char *BanderaFin = "================END";

void run(int s, struct sockaddr *direccionCliente, socklen_t clilen)
{
    int n, Archivo;
    socklen_t len;
    char buf[MAXLINE];

    len = clilen;
    n = recvfrom(s, buf, MAXLINE, 0, direccionCliente, &len);
    buf[n] = 0;
    printf("Received from client: [%s]\n", buf);
    sendto(s, "ok", strlen("ok"), 0, direccionCliente, len);
    Archivo = open(buf, O_RDWR | O_CREAT, 0666);

    while ((n = recvfrom(s, buf, MAXLINE, 0, direccionCliente, &len))) {
        buf[n] = 0;
        printf("%s", buf);
        if (!(strcmp(buf, BanderaFin))) {
            break;
        }
        write(Archivo, buf, n);
    }
    close(Archivo);
}
         
int main(int argc, char **argv)
{
    int s;
    struct sockaddr_in servaddr, direccionCliente;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(SERV_PORT);

    bind(s, (struct sockaddr *) &servaddr, sizeof(servaddr));

    run(s, (struct sockaddr *) &direccionCliente, sizeof(direccionCliente));

    return 0;
}