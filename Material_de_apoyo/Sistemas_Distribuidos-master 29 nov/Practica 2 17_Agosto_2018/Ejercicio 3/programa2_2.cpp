#include "Fecha.h" 
#include <iostream> 
 
using namespace std;


int main(){

	Fecha a(1,4,2014);

	a.muestraFecha();

	int conv = a.convierte();

	 cout << "Conversion: " << conv << endl;

	return 1;
}