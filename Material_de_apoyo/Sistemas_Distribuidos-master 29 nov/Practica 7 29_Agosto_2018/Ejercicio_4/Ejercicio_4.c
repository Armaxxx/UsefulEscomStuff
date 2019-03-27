#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){


	double i = 0;
	int max = 100000000;

	double seno;
	double coseno;
	double tangente;
	double logaritmo;
	double raizCuadrada;


	while(i < max){

		coseno = coseno + cos(i);
		seno = seno + sin(i);
		tangente = tan(i);
		logaritmo = logaritmo + log(i);
		raizCuadrada = raizCuadrada + sqrt(i);

		i++;

	}


	printf("Valor del seno %f\n: " , seno );
	printf("Valor del coseno %f\n: " , coseno );
	printf("Valor del tangente %f\n: " , tangente );
	printf("Valor del logaritmo %f\n: " , logaritmo );
	printf("Valor del raizCuadrada %f\n: " ,raizCuadrada );





	return 1;
}