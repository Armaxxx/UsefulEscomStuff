#include "Fecha.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;


int main()
{
	int i, numero_1=rand()%51, numero_2=rand()%51;;
	Fecha a(numero_1),b(numero_2),c(1);

	srand(time(NULL));

	cout<<"Datos enviados por referencia\n";
	//Por referencia
	clock_t c2 = clock();
	for(i =0; i<300000000; i++){

		int resultado =c.referencia(&a, &b);
		//cout<<"Valor 1: "<<numero_1<<" Valor 2: "<<numero_2<< " Resultado: "<<resultado<<"\n";
	}
	cout<<"Tiempo x referencia a estilo C: "<< (clock()-c2)*1000/1000000<< " ms\n";

	cout<<"\nDatos enviados por parametros\n";
	//Por parametros 
	clock_t c1 = clock();
	for(i = 0; i<300000000; i++){
		int resultado =c.parametros(a, b);
		//cout<<"Valor 1: "<<numero_1<<" Valor 2: "<<numero_2<< " Resultado: "<<resultado<<"\n";
	}
	cout<<"Tiempo x parametros "<< (clock()-c1)*1000/1000000<< " ms";


	cout<<"\n\nDatos enviados por referencia\n";
	//Por referencia
	clock_t c3 = clock();
	for(i =0; i<300000000; i++){

		int resultado =c.referenciaCPP(a, b);
		//cout<<"Valor 1: "<<numero_1<<" Valor 2: "<<numero_2<< " Resultado: "<<resultado<<"\n";
	}
	cout<<"Tiempo x referencia "<< (clock()-c3)*1000/1000000<< " ms";

return 1;
}
