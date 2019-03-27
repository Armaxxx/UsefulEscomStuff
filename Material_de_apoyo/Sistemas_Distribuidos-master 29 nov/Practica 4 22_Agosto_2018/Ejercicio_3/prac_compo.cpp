#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


int main( )
{

	Rectangulo rectangulo1(Coordenada(2,3),Coordenada(5,1));
	//Rectangulo rectangulo1(2,3,5,1);
	
	cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";

	rectangulo1.imprimeEsq();
	rectangulo1.obtieneArea();

	return 0;
}