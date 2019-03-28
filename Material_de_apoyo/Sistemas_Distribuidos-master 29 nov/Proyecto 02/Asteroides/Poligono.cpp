#include "Poligono.h"
#include <iostream>
using namespace std;

//Constructor
Poligono::Poligono(int id)
{
	
	tipofigura = rand() % 1 + 1;
	base = rand() % 40 + 11;
	direccion =rand() % 8;
	identificador = id;

	//Asiganamos la velocidad
	velocidad = 6 - (base/10);

	//Figura del tipo Hexagono
	vertice_coordenadasX = new int[8];
	vertice_coordenadasY = new int[8];

	//Iniciamos la variable choco a false
	exploto =false;
}
Poligono::Poligono(){};

		/*Creamos poligono con un tipo de figura entre 0 y 1, una base entre 20 y 21,
		una velocidad entre 1 y 2, un id*/
/*
	tipofigura = rand() % 1 + 1;
	base = rand() % 50 + 30;
	velocidad = rand() % 5 + 1;
	direccion =rand() % 8;
	identificador = id;

	//Figura del tipo Hexagono
	vertice_coordenadasX = new int[8];
	vertice_coordenadasY = new int[8];


*/