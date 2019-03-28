#include "Fecha.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;


int main()
{
	srand(time(NULL));
	int i=0;

	cout<<"Datos enviados por parametros\n";
	//Por parametros 
	clock_t c1 = clock();
	for(i = 0; i<3000000; i++){
		int dd_1 =rand()%30+1, mm_1=rand()%11+1, aaaa_1=rand()%2017+1;
		int dd_2 =rand()%30+1, mm_2=rand()%11+1, aaaa_2=rand()%2017+1;
		Fecha a(dd_1,mm_1,aaaa_1);
		Fecha b(dd_2,mm_2,aaaa_2);
		Fecha c(1,1,1);

		int resultado =c.parametros(a, b);
		//cout<<"Valor 1: "<<numero_1<<" Valor 2: "<<numero_2<< " Resultado: "<<resultado<<"\n";
	}
	cout<<"Tiempo x parametros "<< (clock()-c1)*1000/1000000<< " ms\n";


	cout<<"\nDatos enviados por referencia\n";
	//Por referencia
	clock_t c2 = clock();
	for(i =0; i<3000000; i++){
		int dd_1 =rand()%30+1, mm_1=rand()%11+1, aaaa_1=rand()%2017+1;
		int dd_2 =rand()%30+1, mm_2=rand()%11+1, aaaa_2=rand()%2017+1;
		Fecha a(dd_1,mm_1,aaaa_1);
		Fecha b(dd_2,mm_2,aaaa_2);
		Fecha c(1,1,1);

		int resultado =c.referencia(a, b);
		//cout<<"Valor 1: "<<numero_1<<" Valor 2: "<<numero_2<< " Resultado: "<<resultado<<"\n";
	}
	cout<<"Tiempo x referencia "<< (clock()-c2)*1000/1000000<< " ms\n";


return 1;
}
