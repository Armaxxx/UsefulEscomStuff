#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <strings.h>
#include <arpa/inet.h>
#include <unistd.h>

int puerto = 7200;

int main(void){
    struct sockaddr_in msg_to_server_addr, client_addr;
    int s, num[3], res, divi;

    s = socket(AF_INET, SOCK_DGRAM, 0);
    /* rellena la dirección del servidor */
    bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
    msg_to_server_addr.sin_family = AF_INET;
    msg_to_server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    msg_to_server_addr.sin_port = htons(puerto);

    /*memcpy(aux, &msg_to_server_addr.sin_addr.s_addr, 4);
    printf("En Hexadecimal: %x %x %x %x\n",aux[0],aux[1],aux[2],aux[3]);
    printf("En Decimal: %d %d %d %d\n",aux[0],aux[1],aux[2],aux[3]);*/
    //printf("Mi puerto: %d\n", msg_to_server_addr.sin_port);


    /* rellena la direcciòn del cliente*/
    bzero((char *)&client_addr, sizeof(client_addr));
    client_addr.sin_family = AF_INET; 
    client_addr.sin_addr.s_addr = INADDR_ANY;
    /*cuando se utiliza por numero de puerto el 0, el sistema se encarga de asignarle uno */
    client_addr.sin_port = htons(0);   

    bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
    printf("Ingresa el numero para ser encontrar el primo mas grande: ");
    scanf("%d",&num[0]);
    while(1){
        num[1] = num[0] / 3;
        printf("\n EL intervalo es %d\n",num[1]);
        num[2] = num[1];
        sendto(s, (char *)num, 3*sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
        num[2] += num[1];
        sendto(s, (char *)num, 3*sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
        num[2] += num[1];
        sendto(s, (char *)num, 3*sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
        /* se bloquea esperando respuesta */
        recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
        if(res == 1){
            break;
        }
        printf("%d no es primo\n", num[0]);
        num[0]--;
    }
    printf("EL numero %d es Primo\n",num[0]);
    close(s);
}