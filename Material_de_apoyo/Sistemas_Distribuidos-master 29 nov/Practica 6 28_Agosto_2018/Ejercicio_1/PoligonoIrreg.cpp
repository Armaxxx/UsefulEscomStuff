#include "PoligonoIrreg.h"
#include <iostream>
#include <algorithm> 

using namespace std;


bool myfunction (Coordenada i,Coordenada j) {
 return (i.obtenerMagnitud() > j.obtenerMagnitud()); 
}


PoligonoIrreg::PoligonoIrreg()
{}

void PoligonoIrreg::anadeVertice(Coordenada coordenada){
		double magnitud; 
		magnitud = pow(coordenada.obtenerX(),2) + pow(coordenada.obtenerY(),2);
		magnitud =sqrt(magnitud);
		coordenada.setMagnitud(magnitud);

	v.push_back(coordenada);
}

void PoligonoIrreg::imprimeVertices(){

	double magnitud; 
	for (i = v.begin(); i != v.end(); i++){
		magnitud = pow(i->obtenerX(),2) + pow(i->obtenerY(),2);
		magnitud =sqrt(magnitud);
		printf("Coordenada x: %4.3f\t y: %4.3f\t Con una magnitud = %4.3f\n" ,i->obtenerX(),i->obtenerY(),magnitud);
	}



	

//	for (int i = 0; i < v.size(); i++)
//	{
//		printf("Coordenada x: %.3f y: %.3f \n",v[i].obtenerX(),v[i].obtenerY());
		//cout<<"Coordenada x: "<<v[i].obtenerX() <<" y: "<<v[i].obtenerY()<< endl;
//	}
}


void PoligonoIrreg::ordenaA(){
	std::sort (v.begin(), v.end(), myfunction);


	imprimeVertices();
}



