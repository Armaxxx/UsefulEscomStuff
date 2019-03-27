#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_

#include "Coordenada.h"
#include <vector>
#include <math.h>

using namespace std;

class PoligonoIrreg
{
	private:
		vector<Coordenada> v;
		std::vector<Coordenada>::iterator i;

	public:
		PoligonoIrreg();
		void anadeVertice(Coordenada coordenada);
		void imprimeVertices();
		void ordenaA();

};
 

#endif