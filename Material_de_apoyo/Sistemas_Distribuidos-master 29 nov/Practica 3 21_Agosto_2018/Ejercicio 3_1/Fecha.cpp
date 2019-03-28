#include "Fecha.h"
#include <iostream>
using namespace std;


Fecha::Fecha(int numero)
{
	numero_1 =numero;
}

int Fecha::referencia(Fecha *fecha1, Fecha *fecha2){
	if(fecha1->numero_1 > fecha2->numero_1)
		return 0;
	else if(fecha1->numero_1 == fecha2->numero_1)
		return 1;
	else
		return -1;
}

int Fecha::parametros(Fecha fecha1, Fecha fecha2){
	if(fecha1.numero_1 > fecha2.numero_1)
		return 0;
	else if(fecha1.numero_1 == fecha2.numero_1)
		return 1;
	else
		return -1;
}

int Fecha::referenciaCPP(Fecha &fecha1, Fecha &fecha2){
	if(fecha1.numero_1 > fecha2.numero_1)
		return 0;
	else if(fecha1.numero_1 == fecha2.numero_1)
		return 1;
	else
		return -1;
}


/*
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