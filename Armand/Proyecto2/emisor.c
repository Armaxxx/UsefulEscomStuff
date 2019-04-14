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
#include <pthread.h>
#include <sys/sem.h>
#include <semaphore.h>

void HiloReceptor();
int puerto = 7201;
struct sockaddr_in msg_to_server_addr, client_addr;
int s, errors = 0;
sem_t mutex1;
sem_t mutex2;

int main(int argc, char const *argv[]){
    pthread_t th1;
    int max, x;
    float res;
    max = atoi(argv[1]);
    sem_init(&mutex1, 0, 0);
    sem_init(&mutex2, 0, 0);

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
    pthread_create(&th1,NULL,(void *) HiloReceptor, NULL);
    for(x = 1; x < max; x++){
        sendto(s, (char *)&x, sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
    }
    x = 0;
    sendto(s, (char *)&x, sizeof(int), 0, (struct sockaddr *) &msg_to_server_addr, sizeof(msg_to_server_addr));
    /* se bloquea esperando respuesta */
    sem_wait(&mutex2);
    recvfrom(s, (char *)&res, sizeof(float), 0, NULL, NULL);
    sem_post(&mutex1);
    pthread_join(th1, NULL);
    printf("Existe una perdida de paquetes del %.2f porciento,\nLISTA DE ERRORES:\n", res*100);
    close(s);
}


void HiloReceptor(){
    FILE *fptr;
    fptr = fopen("errors.txt","w");
    fprintf(fptr,"LISTA DE ERRORES: \n");
    fclose(fptr);
    fptr = fopen("errors.txt","a");
    int code;
    while(1){
        recvfrom(s, (char *)&code, sizeof(int), 0, NULL, NULL);
        if(code == 0)
            break;
        errors++;
        fprintf(fptr,"%d ", code);
        if(errors % 15 == 0)
            fprintf(fptr,"\n");
    }
    sem_post(&mutex2);
    sem_wait(&mutex1);
    fclose(fptr);
    pthread_exit(NULL);
}