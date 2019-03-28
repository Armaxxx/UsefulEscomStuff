#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

 
int main( )
{
  	srand (time(NULL));

	int numvertices =(rand() % 50)+1;
	PoligonoIrreg poligonoIrreg;
	cout<<"Num de vertices: "<<numvertices<<endl;

	for(int i=0; i<numvertices; i++){
		double dato1, dato2;
			do{
				dato1 =static_cast<double>(rand() % 200 - 100) +1;
				dato2 =static_cast<double>(rand() % 200 - 100) +1;
			}while(dato1 == 0 || dato2 == 0);

		double decimales = (static_cast<double>(rand() %888 + 111) * 0.001);
			dato1 = dato1 + decimales;
		decimales = (static_cast<double>(rand() %888 + 111) * 0.001);
			dato2 = dato2 + decimales;
			
		poligonoIrreg.anadeVertice(Coordenada(dato1,dato2));		
		
	}

	poligonoIrreg.ordenaA();



//cout<<drand48() * (200.99-100.99) + 1.11<<endl;
/*
	Rectangulo rectangulo1(2,3,5,1);
	double ancho, alto;
	
	cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";

	rectangulo1.imprimeEsq();
		alto = rectangulo1.obtieneSupIzq().obtenerY() -
		rectangulo1.obtieneInfDer().obtenerY();

		ancho = rectangulo1.obtieneInfDer().obtenerX() -
		rectangulo1.obtieneSupIzq().obtenerX();

	cout << "El área del rectángulo es = " << ancho*alto << endl;

*/
	return 0;
}