#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;




int main(){


	double i = 0;
	int max = 100000000;

	double seno;
	double coseno;
	double tangente;
	double logaritmo;
	double raizCuadrada;


	while(i < max){

		coseno = coseno + cos(i);
		seno = seno + sin(i);
		tangente = tan(i);
		logaritmo = logaritmo + log(i);
		raizCuadrada = raizCuadrada + sqrt(i);

		i++;

	}


	cout << "Valor del seno : " << seno << endl;
	cout << "Valor del coseno : " << coseno << endl;
	cout << "Valor del tangente : " << tangente << endl;
	cout << "Valor del logaritmo : " << logaritmo << endl;
	cout << "Valor del raizCuadrada : " << raizCuadrada << endl;



	return 1;
}