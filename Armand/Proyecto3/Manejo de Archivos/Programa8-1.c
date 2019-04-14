#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

char buffer[BUFSIZ]; /*Region de memoria para el almacenamiento temporal de datos*/

int main(int argc, char const *argv[])
{
    int nbytes, origen, destino;

    if(argc != 3){
        printf("Forma de uso: %s archivo_origen archivo_destino\n",argv[0]);
        exit(-1);
    }
    if((origen = open(argv[1], O_RDONLY)) == -1) {
        perror(argv[1]);
        exit(-1);
    }
    printf("Origen = %d\n",origen);
    if((destino = open(argv[2], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1)
    {
        perror(argv[2]);
        exit(-1);
    }
    printf("Destino = %d\n\n",destino);
    while((nbytes = read(origen, buffer, sizeof(buffer))) > 0){
        printf("nbytes = %d\nbuffer = %s\n",nbytes, buffer);
        write(destino, buffer, nbytes);
        printf("\tdestino = %d\n\tbuffer = %s\n",destino, buffer);
    }
    close(destino);
    close(origen);
    return 0;
}
