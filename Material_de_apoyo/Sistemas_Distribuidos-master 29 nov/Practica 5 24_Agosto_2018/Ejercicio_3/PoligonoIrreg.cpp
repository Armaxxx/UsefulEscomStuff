#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <algorithm> 

using namespace std;

bool myfunction (Coordenada i,Coordenada j) {
 return (i.obtenerX() > j.obtenerX()); 
}

PoligonoIrreg::PoligonoIrreg()
{}

void PoligonoIrreg::anadeVertice(Coordenada coordenada){
	v.push_back(coordenada);
	contadorvertices++;
}

void PoligonoIrreg::anadeVerticeRecerve(Coordenada coordenada){
	v.reserve(v.size()+1);
	v[v.size()] =coordenada;
	//v.push_back(coordenada);
	contadorvertices++;
}

void PoligonoIrreg::ordenaA(){
	std::sort (v.begin(), v.end(), myfunction);


	for (std::vector<Coordenada>::iterator it=v.begin(); it!=v.end(); it++){
    	std::cout << ' ' << "X: " <<it -> obtenerX()<<" Y: "<< it -> obtenerY() ;
  		std::cout << '\n';
  	}
}


void PoligonoIrreg::imprimeVertices(){
	

	for (int i = 0; i < v.size(); i++)
	{
		cout<<"Coordenada x: "<<v[i].obtenerX() <<" y: "<<v[i].obtenerY()<< endl;		
	}
}


int PoligonoIrreg::contadorvertices=0;

int PoligonoIrreg::getContadorVertices(){
	//cout<< "Valor de la static: "<<contadorvertices<<endl;
	return contadorvertices;
}


