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
		PoligonoIrreg();
		void anadeVertice(Coordenada coordenada);
		void imprimeVertices();

};
 

#endif