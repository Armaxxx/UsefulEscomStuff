#include <iostream>
using namespace std;

int main( )
{
    const double PI =3.1415926;    
    double radio, area;
    
    cout << "!!!Calculo de area de un circulo!!! \n";
    cout << "Ingrese el radio r = ";

    cin >> radio;

    area =PI*(radio*radio);

    cout << "\nEl radio es: "<<area<<"\n";

    return 0;
}
