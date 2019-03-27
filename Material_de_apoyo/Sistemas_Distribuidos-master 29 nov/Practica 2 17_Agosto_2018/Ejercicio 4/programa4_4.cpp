#include "Fecha.h"
#include <iostream>
using namespace std;


int main()
{
  bool bisiesto;
  int  i, numBisiestos = 0;
  Fecha a, b, c(21, 9, 1973), d;

  b.inicializaFecha(17, 6 , 2000);
  a.muestraFecha();
  b.muestraFecha();
  c.muestraFecha();

  for(i=1; i<=2018; i++){
  bisiesto = d.leapyr(i);
  if(bisiesto == 1){
    numBisiestos ++;
  }
  cout <<"Respuesta año: "<<i <<" ES: "<<bisiesto << '\n';
  }

  std::cout << "Numero de años biciestos: "<<numBisiestos << '\n';

return 1;
}
