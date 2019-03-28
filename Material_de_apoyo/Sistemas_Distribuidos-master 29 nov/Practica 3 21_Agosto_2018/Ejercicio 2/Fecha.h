#ifndef FECHA_H_
#define FECHA_H_

class Fecha
{
  private:
    int dia;
    int mes;
    int anio;
    int var1[10000];

  public:
    /*
    Fecha(int = 3, int = 4, int = 2014);
    void inicializaFecha(int, int, int);
    void muestraFecha();

    //Metodo para saber si el año es bisiesto
    bool leapyr(int);

    */
    Fecha (int dd, int mm, int anio);
    int parametros(Fecha, Fecha);
    int referencia(Fecha&, Fecha&);
    int convierte(Fecha);
};

#endif
