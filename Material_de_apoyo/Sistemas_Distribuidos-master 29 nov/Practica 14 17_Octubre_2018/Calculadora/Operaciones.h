#include <stdio.h>
#include <stdlib.h>

struct Operandos{
	float i;
	float j;
};

float suma(struct Operandos datos){
	return datos.i + datos.j;
}

float producto(struct Operandos datos){
	return datos.i * datos.j;
}

float cociente(struct Operandos datos){
	return datos.i / datos.j;
}