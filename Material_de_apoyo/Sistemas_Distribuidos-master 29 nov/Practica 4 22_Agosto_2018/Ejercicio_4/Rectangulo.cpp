#include "Rectangulo.h"
#include <iostream>

using namespace std; 

Rectangulo::Rectangulo() : superiorIzq(0,0), inferiorDer(0,0)
{ }
//Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer):superiorIzq(xSupIzq, ySupIzq), inferiorDer(xInfDer, yInfDer)
//{ }

Rectangulo::Rectangulo(Coordenada coordenada1, Coordenada coordenada2){
	superiorIzq =coordenada1;
	inferiorDer =coordenada2;
}

void Rectangulo::imprimeEsq()
{
	cout << "Para la esquina superior izquierda.\n";
	cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << endl;
	cout << "Para la esquina inferior derecha.\n";
	cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << endl;
}

void Rectangulo::obtieneArea()
{
		double ancho, alto;

		alto = superiorIzq.obtenerY() - inferiorDer.obtenerY();
		ancho = inferiorDer.obtenerX() - superiorIzq.obtenerX();

	cout << "El área del rectángulo es = " << ancho*alto << endl; 
}

Coordenada Rectangulo::obtieneSupIzq()
{
	return superiorIzq;
}
Coordenada Rectangulo::obtieneInfDer()
{
	return inferiorDer;
}