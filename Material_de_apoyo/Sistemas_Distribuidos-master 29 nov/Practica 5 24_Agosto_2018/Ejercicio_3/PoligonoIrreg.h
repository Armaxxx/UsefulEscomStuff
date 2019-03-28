#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_

#include "Coordenada.h"
#include <vector>

using namespace std;



class PoligonoIrreg
{
	private:
		vector<Coordenada> v;
	
	public:
	 	static int contadorvertices; 

	public:
		PoligonoIrreg();
		void anadeVertice(Coordenada coordenada);
		void anadeVerticeRecerve(Coordenada coordenada);
		void imprimeVertices();
		void ordenaA();
		static int getContadorVertices();
};


#endif