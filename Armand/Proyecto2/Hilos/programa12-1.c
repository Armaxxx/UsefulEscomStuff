#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void funcion(void){
    printf("Hilo %lu \n", pthread_self());
    /*con pthread_self un hilo puede conocer su identificador*/
    sleep(2);
    pthread_exit(0);
    /*La funcion:
    int pthread_exit(void *value);
    
    Finaliza un hilo e incluye un apuntador a una estructura de dato para el hilo
    que llame la funcion join. */
}

int main(void){
    pthread_t th1, th2;
    /* Se crean dos hilos con atributos predeterminados */
    pthread_create(&th1,NULL,(void *) funcion, NULL);
    /*La funcion:
    int pthread_create(pthread_t *thread, pthread_attr_r *attr, void*(*start_routine)(void *), void *arg);
    
    Permite crear un hilo
    *thread = identificador del hilo. 
    *attr = atributos asociados al nuevo hilo. (si es NULL se utilizan los atributos predeterminados) 
        lo cual implica ser un hilo dependiente. 
    *start_routine = nombre de la funcion a ejecutar por el hilo.
    *arg = un unico parametro que puede pasarsele a la funcion.*/
    pthread_create(&th2,NULL,(void *) funcion, NULL);
    printf("El hilo principal espera a sus hijos...\n");

    /* Se espera la terminacion */
    pthread_join(th1, NULL);
    /*LA funcion:
    pthead_join(pthread th1, void **value);
    
    EL hilo que la llama espera a que termine el hilo especificado en el primer
    argumento y que no tiene que ser necesariamente un hilo hijo. Esta funcion se
    puede solicitar unicamente sobre hilos dependientes. La funcion devuelve en el
    segundo argumento el valor que devuelve el hilo que finaliza su ejecucion.*/
    pthread_join(th2, NULL);
    printf("El hilo principal termina\n");

    return 0;
}