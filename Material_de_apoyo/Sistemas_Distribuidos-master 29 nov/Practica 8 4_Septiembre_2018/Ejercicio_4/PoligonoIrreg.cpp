#include "PoligonoIrreg.h"
#include <iostream>

using namespace std;

PoligonoIrreg::PoligonoIrreg()
{}

void PoligonoIrreg::anadeVertice(Coordenada coordenada){
	v.push_back(coordenada);
}

void PoligonoIrreg::imprimeVertices(){
	for (int i = 0; i < v.size(); i++)
	{
		cout<<"Coordenada x: "<<v[i].obtenerX() <<" y: "<<v[i].obtenerY()<< endl;
	}
}




