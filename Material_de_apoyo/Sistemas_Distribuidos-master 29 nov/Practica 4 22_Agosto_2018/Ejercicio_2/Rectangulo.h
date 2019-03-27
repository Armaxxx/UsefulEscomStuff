#ifndef RECTANGULO_H_
#define RECTANGULO_H_
#include "Coordenada.h"

class Rectangulo
{
	private:
		Coordenada superiorIzq;
		Coordenada inferiorDer;

	public:
		Rectangulo();
		//Rectangulo(double xSupIzq, double ySupIzq, double xInfDer, double yInfDer);
		Rectangulo(Coordenada coordenada1, Coordenada coordenada2);
		void imprimeEsq();
		Coordenada obtieneSupIzq();
		Coordenada obtieneInfDer();
};


#endif