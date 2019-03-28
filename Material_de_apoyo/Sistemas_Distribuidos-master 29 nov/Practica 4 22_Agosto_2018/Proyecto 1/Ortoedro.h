#ifndef OCTOEDRO_H_
#define OCTOEDRO_H_
#include "Coordenada.h"
#include "Rectangulo.h"

class Octoedro{
	private:
		Rectangulo rectangulo1;
		Rectangulo rectangulo2;
		Rectangulo rectangulo3;
		Rectangulo rectangulo4;
		Rectangulo rectangulo5;
		Rectangulo rectangulo6;

	public:
		//Ortoedro();
		Ortoedro(Rectangulo rect1, Rectangulo rect2, Rectangulo rect3, Rectangulo rect4, Rectangulo rect5, Rectangulo rect6);
		void obtieneVertices();
		void obtieneArea();
		void obtieneVolumen();

};


#endif