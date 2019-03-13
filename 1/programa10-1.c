#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netdb.h>
#include <strings.h>

int puerto = 7200;

int main(int argc, char *argv[])
{
   struct sockaddr_in msg_to_server_addr, client_addr, msg_to_server_addr_prueba;
   int s, num[2], res;
   unsigned char aux[4];

   s = socket(AF_INET, SOCK_DGRAM, 0);
   /* rellena la dirección del servidor */
   bzero((char *)&msg_to_server_addr, sizeof(msg_to_server_addr));
   bzero((char *)&msg_to_server_addr_prueba, sizeof(msg_to_server_addr_prueba));
   msg_to_server_addr.sin_family = AF_INET;
   msg_to_server_addr.sin_addr.s_addr = inet_addr(argv[1]);
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
   client_addr.sin_port = htons(6666);
   printf("Mi puerto: %d\n", ntohs(client_addr.sin_port));
   bind(s, (struct sockaddr *)&client_addr,sizeof(client_addr));
   num[0] = 2;
   num[1] = 5; /*rellena el mensaje */
   sendto(s, (char *)num, 2 * sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
   
   /* se bloquea esperando respuesta */
   recvfrom(s, (char *)&res, sizeof(int), 0, NULL, NULL);
   printf("2 + 5 = %d\n", res);
   close(s);
}

