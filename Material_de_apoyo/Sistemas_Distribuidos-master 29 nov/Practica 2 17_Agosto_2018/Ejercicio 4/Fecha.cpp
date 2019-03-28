#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa)
{
  mes = mm;
  dia = dd;
  anio = aaaa;
}

void Fecha::inicializaFecha(int dd, int mm, int aaaa)
{
  anio = aaaa;
  mes = mm;
  dia = dd;
    return;
}

void Fecha::muestraFecha()
{
  cout << "La fecha es(dia-mes-año): " << dia << "-" << mes << "-" << anio << endl;
    return;
}

bool Fecha::leapyr(int aaaa){
  bool resultado =false;
    if((aaaa%4)==0 && (aaaa%100) != 0 )
      resultado =true;
    if((aaaa%400) ==0)
      resultado =true;
      
      return resultado;
}
