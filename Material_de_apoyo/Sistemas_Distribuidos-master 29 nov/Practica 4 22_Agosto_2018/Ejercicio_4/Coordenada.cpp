#include "Coordenada.h"
#include <iostream>
#include <cmath>

using namespace std;

Coordenada::Coordenada(double xx, double yy)
{ 
	phi =xx;
	teta =yy;

	x =(phi)*cos(teta);
	y =(phi)*sin(teta);

}

double Coordenada::obtenerX()
{
	return x;
}
double Coordenada::obtenerY()
{
	return y;
} 