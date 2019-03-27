#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

int main(int argc, char *argv[]){
	int operacion;
	float resultado = 0;
	if(argc != 4) {
		printf("Uso: %s dato1 dato2 operacion\n", argv[0]);
    	exit(1);
   	}

	struct Operandos datos = {atoi(argv[1]), atoi(argv[2])};

	operacion = atoi(argv[3]);
	
	switch(operacion){
		case 1: resultado = suma(datos);
				break;
		case 2: resultado = producto(datos);
				break;
		case 3: resultado = cociente(datos);
				break;
		default: printf("1: Suma 2: Producto 3: Cociente\n");
				 exit(1);
	}	
	printf("El resultado es: %f\n", resultado);
	exit(0);
}