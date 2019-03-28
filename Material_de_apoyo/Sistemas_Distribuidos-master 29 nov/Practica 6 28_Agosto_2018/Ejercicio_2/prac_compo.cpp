#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;




int main( )
{

	vector<PoligonoIrreg> poligonos(10);

	PoligonoIrreg poligono;

	poligono.anadeVertice(Coordenada(2,1));
	poligono.anadeVertice(Coordenada(3,1));
	poligono.anadeVertice(Coordenada(5,1));
	poligono.anadeVertice(Coordenada(1,1));
	poligono.anadeVertice(Coordenada(4,1));

	/*for (int i = 0; i < poligonos.size(); i++)
	{

		for (int j = 0; j < rand(); j++)
		{
			poligonos[i].anadeVerticeRecerve(Coordenada(1,1));
		}
		
	}*/

	//PoligonoIrreg poligonoIrreg;

	//poligonoIrreg.anadeVerticeRecerve (Coordenada(1,1));

	printf("Numero de vertices : %d\n", poligono.getContadorVertices());
	poligono.ordenaA();

/*	PoligonoIrreg poligonoIrreg;


	poligonoIrreg.anadeVertice(Coordenada(1,1));
	poligonoIrreg.imprimeVertices();
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