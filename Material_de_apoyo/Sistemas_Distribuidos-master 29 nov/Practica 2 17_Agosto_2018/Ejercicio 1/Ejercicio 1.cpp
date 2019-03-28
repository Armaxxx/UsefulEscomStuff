#include <iostream>
using namespace std;

class Fecha{
private:
    int dia;
    int mes;
    int anio;

public:
  Fecha(int =3 , int = 4, int = 2014);
  void inicializarFecha(int, int,int);
  void muestraFecha();
};

Fecha::Fecha(int dd, int mm, int aaaa)
{
  mes = mm;
  dia = dd;
  anio = aaaa;
}

void Fecha::inicializarFecha(int dd, int mm, int aaaa)
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

int main()
{
  Fecha a, b, c(21, 9, 1973);

  b.inicializarFecha(17, 6 , 2000);
  a.muestraFecha();
  b.muestraFecha();
  c.muestraFecha();

    std::cout << "Valor de dia:" <<b.dia << '\n';
}

/*Al intentar acceder a la variable, solo para imprimir su valor, el
compilador indica que el contexto de esta es de tipo private y no
permita imprmimr*/
