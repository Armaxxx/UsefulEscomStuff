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
    char *aux;
    int num[2];
    int s, res, clilen;
    struct sockaddr_in server_addr, msg_to_client_addr;
    /*Estructura que almacena la direccion generica de un socket
    y se encuentra definida como sigue:
    struct sockaddr_un{
        short sun_family;  AF_UNIX
        char sun_path[108];  RUTA
    }
    Para el caso de socket internet se usa la estructura>
    struct sockaddr_in{
        short sin_family;       AF_INET
        u_short sin_port;       16 bits con el numero de ....
        struct in_addr sin_addr;    32 bits con la identificacion de la red y del nodo
        char sin_zero[8];       8 bytes no usados
    }
    Donde
    struct in_addr{
        u_long s_addr;      32 bits que contienen la identificacion de la red y del nodo
    }*/


    s = socket(AF_INET, SOCK_DGRAM, 0);
    /*Se asigna una direccion al socket servidor
    Un socket se crea mediante la funcion:
    int socket(int dominio, int tipo, int protocolo)
    Si protocolo es 0, ser[a en manos del sistema.
    El socket creado aun no tiene direccion asociada*/

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(puerto);

    bind(s, (struct sockaddr *) &server_addr, sizeof(server_addr));
    /*Para asignar una direccion IP y un puerto a un socket para que se pueda ubicar 
    el punto de conexion, se utiliza la funcion bind:
    int bind(int socket, struct sockaddr *dir, int long);
    El primer argumento es el identificador devuelto por socket().
    El segundo especifica la direccion que se va a asignar al socket,
    la cual se debe de encontrar en la estructura definida en la linea 1.
    El tercer argumento especifica la direccion en bytes que ocupa la direccion en la estructura*/
    clilen = sizeof(msg_to_client_addr);

    while(1){
        recvfrom(s, (char *) num, 2*sizeof(int), 0, (struct sockaddr *) &msg_to_client_addr, &clilen);
        /*Para recibir datos en una conexion de tipo datagrama se utiliza:
        int recvfrom(int socket, char *mensaje, int len, int flags, struct sockaddr *dir, int *long);
        len representa el maximo numero de bytes que se pueden escribir
        en la memoria referenciada por mensaje. El miembro flags se inicializa con 0, dir
        almacena la direccion del socket del que se han recibido los datos y long la
        longitud que ocupa dicha direccion en bytes.
        La estructura sockaddr es utilizada por muchas llamadas al sistema y tiene la forma:
        struct sockaddr{
            u_short sa_family;
            char sa_data[14];
        }
        La funcion retorna el numero de bytes leidos.*/

        memcpy(aux, &msg_to_client_addr.sin_addr.s_addr, 4);  
        printf("Ip del cliente: %d %d %d %d\n",aux[0],aux[1],aux[2],aux[3]);      
        
        printf("Puerto cliente: %d\n", ntohs(msg_to_client_addr.sin_port));

        res = num[0] + num[1];
        

        /*Envia la peticion al cliente. La estructura msg_to_client_addr contiene la direccion del socket cliente*/

        sendto(s, (char *)&res, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
        /*Para enviar datos en una conexion de tipo datagrama se utiliza:
        int sendto(int socket, char*mensaje, int long, int flags, struct sockaddr *dir, int long);
        El argumento dir representa la direccion del socket remoto al que se quieren enviar
        los datos, y long la longitud en bytes que ocupa dicha direccion*/
    }
}