#ifndef POLIGONOREG_H_
#define POLIGONOREG_H_

#include "Coordenada.h"
#include "PoligonoIrreg.h"
#include <vector>

using namespace std;

class PoligonoReg :public PoligonoIrreg
{
	private:
		int numVertices;
		int angulo;

	public:
		PoligonoReg(int =1);
		void obtieneArea();

};
 

#endif