#include "Fecha.h"
#include <iostream>
using namespace std;


Fecha::Fecha (int dd, int mm, int anio){
    dia =dd;
    mes =mm;
    anio =anio;
}

int Fecha::parametros(Fecha fecha1, Fecha fecha2){

	int dato1 =fecha1.convierte(fecha1);
	int dato2 =fecha2.convierte(fecha2);

	if(dato1 > dato2)
		return 0;
	else if(dato1 == dato2)
		return 1;
	else
		return -1;

}

int Fecha::referencia(Fecha &fecha1, Fecha &fecha2){

	int dato1 =fecha1.convierte(fecha1);
	int dato2 =fecha2.convierte(fecha2);

	if(dato1 > dato2)
		return 0;
	else if(dato1 == dato2)
		return 1;
	else
		return -1;
}

 int Fecha::convierte(Fecha fecha){
 	return fecha.anio*10000+fecha.mes*100+fecha.dia;
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