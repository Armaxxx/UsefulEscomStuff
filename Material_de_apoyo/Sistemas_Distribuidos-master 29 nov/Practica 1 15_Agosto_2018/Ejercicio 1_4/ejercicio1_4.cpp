#include <iostream>
using namespace std;

int main( )
{
    double c =23;
    double f;
    cout << "Conversion de grados centigrados\n";
        f=(static_cast<double>(9)/static_cast<double>(5)) * c + 32.0;
    
    cout << "Cambio de 23°C a "<<f<< "°F\n";

 
    return 0;
}

/*Se probo con el dato de c= 20°C como en el ejercicio y no mostro error, el valor de la variable c por un
 23 de igual manera todo funciono de manera correcta.*/
