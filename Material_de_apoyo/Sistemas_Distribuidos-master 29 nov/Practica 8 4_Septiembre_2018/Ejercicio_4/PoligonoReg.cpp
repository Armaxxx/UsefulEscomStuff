#include "PoligonoReg.h"
#include "Coordenada.h"
#include <iostream>
#include <iomanip>      // std::setprecision
#include <cmath>

using namespace std;

PoligonoReg::PoligonoReg(int a)
{

	numVertices = a;

	//v.anadeVertice(Coordenada(1,1));
	//angulo = b;

}

void PoligonoReg::obtieneArea(){


	int angulosCentrales = 360/numVertices;
	int cx = 0;
	int cy = 0;
	int r = 1;
	double  apotema =0.0;




	cout << "Coordenadas del poligono : " << endl;

	double x = 0.0;
	double y = 0.0;
	Coordenada cor ;
	Coordenada aux1;
	Coordenada aux2;

	double distancia ;


	for (int i = 1; i <= numVertices; i++){

		double aRad =  (M_PI/180) * (angulosCentrales * i);

		x = cx + r * cos(aRad);

		y = cy + r * sin(aRad);


		cor = Coordenada(x,y);


		cout << "Coordenada " << i << ": " << endl;
		cout << "x : " << std::setprecision(50) << cor.obtenerX() << endl;
		cout << "y : " << std::setprecision(50) << cor.obtenerY() << endl<< endl;

		if(i ==2 ){

			aux1 = cor;


		}else if(i == 3){

			aux2 = cor;

		}


		
	}

 
			double a = pow((aux2.obtenerX() - aux1.obtenerX()),2);
			double b = pow((aux2.obtenerY() - aux1.obtenerY()),2);

			distancia = sqrt(a + b);         
			
			apotema = (distancia/2)/(tan(angulosCentrales/2));

			cout << "Distancia : " << distancia << endl;


			cout <<"Area del poligono : " << numVertices *sin(M_PI/numVertices)*cos(M_PI/numVertices) << endl;
}
/*
void PoligonoIrreg::imprimeVertices(){
	for (int i = 0; i < v.size(); i++)
	{
		cout<<"Coordenada x: "<<v[i].obtenerX() <<" y: "<<v[i].obtenerY()<< endl;
	}
}
*/




