#ifndef FECHA_H_
#define FECHA_H_

class Fecha
{
  private:
    int numero_1;

  public:
    /*
    Fecha(int = 3, int = 4, int = 2014);
    void inicializaFecha(int, int, int);
    void muestraFecha();

    //Metodo para saber si el año es bisiesto
    bool leapyr(int);

    */
    Fecha (int numero);
    int referencia(Fecha*, Fecha*);
    int parametros(Fecha, Fecha);
    int referenciaCPP(Fecha&, Fecha&);
};

#endif
