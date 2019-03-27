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
	cout << "x = " << superiorIzq.obtenerX() << " y = " << superiorIzq.obtenerY() << " z = " << superiorIzq.obtenerZ()  << endl;
	cout << "Para la esquina inferior derecha.\n";
	cout << "x = " << inferiorDer.obtenerX() << " y = " << inferiorDer.obtenerY() << " z = " << inferiorDer.obtenerZ() << endl;
}

double Rectangulo::obtieneArea()
{
		double ancho, alto, largo, resultado;

		alto = superiorIzq.obtenerY() - inferiorDer.obtenerY();
		largo = inferiorDer.obtenerX() - superiorIzq.obtenerX();
		ancho = inferiorDer.obtenerZ() - superiorIzq.obtenerZ();

		if(alto == 0){
			resultado = largo * ancho;
		}else if(largo == 0){
			resultado = alto * ancho;
		}else{  //anncho =0
			resultado = alto * largo;
		}

		cout << "El área del rectángulo es = " << resultado<< endl; 
		return resultado;
}

Coordenada Rectangulo::obtieneSupIzq()
{
	return superiorIzq;
}
Coordenada Rectangulo::obtieneInfDer()
{
	return inferiorDer;
}