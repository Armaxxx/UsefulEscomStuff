#include "Coordenada.h"
#include "Rectangulo.h"
#include "Ortoedro.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


int main( )
{

	//Rectangulo rectangulo1(Coordenada(0,3,0),Coordenada(5,0,0));
	//Rectangulo rectangulo1(2,3,5,1);
	Ortoedro ortoedro1(rectangulo1(Coordenada(0,3,0),Coordenada(5,0,0),rectangulo2(Coordenada(0,3,0),Coordenada(5,0,0),rectangulo3(Coordenada(0,3,0),Coordenada(5,0,0),rectangulo4(Coordenada(0,3,0),Coordenada(5,0,0),rectangulo5(Coordenada(0,3,0),Coordenada(5,0,0),rectangulo6	(Coordenada(0,3,0),Coordenada(5,0,0));
	//Ortoedro ortoedro();
	cout << "Calculando el área de un rectángulo dadas sus coordenadas en un plano cartesiano:\n";

	//rectangulo1.imprimeEsq();
	//rectangulo1.obtieneArea();

	return 0;
}