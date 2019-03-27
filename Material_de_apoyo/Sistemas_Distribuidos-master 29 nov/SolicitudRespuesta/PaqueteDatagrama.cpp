#include "PaqueteDatagrama.h"

PaqueteDatagrama::PaqueteDatagrama(char * cadena, unsigned int tam, char * dir, int port)
:longitud(tam),puerto(port)
{
    datos = new char[tam];
    memcpy(datos,cadena,tam);
    strcpy(ip,dir);
}

PaqueteDatagrama::PaqueteDatagrama(unsigned int tam):longitud(tam)
{
    datos = new char[tam];
}

PaqueteDatagrama::~PaqueteDatagrama()
{
    delete [] datos;
}

char * PaqueteDatagrama::obtieneDireccion()
{
    return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud()
{
    return longitud;
}

int PaqueteDatagrama::obtienePuerto()
{
    return puerto;
}

char * PaqueteDatagrama::obtieneDatos()
{
    return datos;
}

void PaqueteDatagrama::inicializaPuerto(int port)
{
    puerto = port;
}

void PaqueteDatagrama::inicializaIp(char * dir)
{
    strcpy(ip,dir);
}

void PaqueteDatagrama::inicializaDatos(char * cadena)
{
    memcpy(datos,cadena,longitud);
}