/* Este programa muestra la sincronizacion en la impresion de 
dos Hilos */
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

int i = 10; /* Variable compartida */
sem_t mutex1;
sem_t mutex2;
void Hilo1(void);
void Hilo2(void);

int main(void){

    pthread_t th1, th2;

    // Inicializa los semaforos
    sem_init(&mutex1, 0, 1);
    sem_init(&mutex2, 0, 0);

    // Crea hilos
    pthread_create(&th1, NULL, (void *)Hilo1, NULL);
    pthread_create(&th2, NULL, (void *)Hilo2, NULL);

    // Esperar Hilos
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    return 0;
}

void Hilo1(void){
    while (i > 0){
        sem_wait(&mutex1);
        printf("Soy el hilo 1 (%ld) y esta es la impresion %d \n", pthread_self(), i--);
        sem_post(&mutex2);
    }
    pthread_exit(0);
}

void Hilo2(void){
    while (i > 0){
        sem_wait(&mutex2);
        printf("Soy el hilo 2 (%ld) y esta es la impresion %d \n", pthread_self(), i--);
        sem_post(&mutex1);
    }
    pthread_exit(0);
}