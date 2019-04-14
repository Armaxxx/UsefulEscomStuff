#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <strings.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/sem.h>
#include <semaphore.h>

void HiloEmisor();
int puerto = 7201;
int s, clilen;
struct sockaddr_in server_addr, msg_to_client_addr;
sem_t mutex1;
sem_t mutex2;

int main(void){
    int missing[2];
    pthread_t th1;
    char aux[4];
    int res = 1, num, error = 0;
    float prom;

    sem_init(&mutex1, 0, 1);
    sem_init(&mutex2, 0, 0);

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
            missing[0] = res;
            missing[1] = num;
            error += num - res;
            res = num;
            pthread_create(&th1,NULL,(void *) HiloEmisor, (void *)missing);
        }
        if (num == 0){
            break;
        }
        res++;
    }
    sem_wait(&mutex1);
    missing[0] = 0;
    missing[1] = 1;
    pthread_create(&th1,NULL,(void *) HiloEmisor, missing);
    printf("Se finalizo con %d errores y %d paquetes enviados\n",error,res);
    prom = (float)error/(float)res;
    sem_post(&mutex1);
    sem_wait(&mutex2);
    sendto(s, (char *)&prom, sizeof(float), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
}

void HiloEmisor(int *missing){
    sem_wait(&mutex1);
    int x;
    for(x = missing[0]; x < missing[1]; x++)
        sendto(s, (char *)&x, sizeof(int), 0, (struct sockaddr *)&msg_to_client_addr, clilen);
    if (missing[0] == 0)
        sem_post(&mutex2);
    sem_post(&mutex1);
    pthread_exit(NULL);
    
}