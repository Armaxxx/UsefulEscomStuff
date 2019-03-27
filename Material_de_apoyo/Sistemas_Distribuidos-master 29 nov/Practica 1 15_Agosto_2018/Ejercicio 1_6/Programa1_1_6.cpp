#include <iostream>
#include <string>



using namespace std;

int main(){

	double precio = 78.7;

	cout << "Valor final de precio antes de la configuracion :" << precio << endl;

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Valor final de precio despues de la configuracion :" << precio << endl;


	return 0;

		/*****************Resultados*********************/


	/*

	Se pudo comprobar que antes de la configuracion se imprimio la variable double solo con un digito
	decimal, una vez aplicada la configuracion al cout se pudo imprimir con dos digitos 
	anexando un cero al final.



	*/

}
