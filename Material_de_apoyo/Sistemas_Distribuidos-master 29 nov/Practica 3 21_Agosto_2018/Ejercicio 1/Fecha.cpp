#include "Fecha.h"
#include <iostream>
using namespace std;

Fecha::Fecha(int dd, int mm, int aaaa): dia(dd), mes(mm), anio(aaaa){
	if((dia>=1) && (dia<=31)){
		cout<<"Dia dentro del rango\n";
	}else{
		cout<<"Dia fuera del rango\n";
		exit (1);
	}

	if((mes>=1) && (mes<=12)){
		cout<<"Mes dentro del rango\n";
	}else{
		cout<<"Mes fuera del rango\n";
		exit (1);
	}

}

/*Fecha::Fecha(int dd, int mm, int aaaa)
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

bool leapyr(int aaaa){

}
*/