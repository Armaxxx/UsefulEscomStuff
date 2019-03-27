#include <iostream>
#include <string.h>
#ifndef PAQUETEDATAGRAMA_HPP_
#define PAQUETEDATAGRAMA_HPP_

class PaqueteDatagrama{
    private:
        char *datos;            //Almacena los datos
        char ip[16];            //Almacena la IP
        unsigned int longitud;  //Almacena la longitud
        int puerto;             //Almacena el puerto 
    public:
        PaqueteDatagrama(char *, unsigned int, char *, int );
        PaqueteDatagrama(unsigned int );
        char *obtieneDireccion();
        unsigned int obtieneLongitud();
        int obtienePuerto();
        char *obtieneDatos();
        void inicializaPuerto(int);
        void inicializaIp(char *);
        void inicializaDatos(char *);
};
#endif