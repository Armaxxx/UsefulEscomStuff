#include <iostream>
#include <string.h>
#include "PaqueteDatagrama.hpp"
using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char *dat, unsigned int len, char *addr , int port):longitud(len),puerto(port){
    datos = (char*)malloc(sizeof(dat[0])*len);
    memcpy(datos,dat,len);
    strcpy(ip,addr);
    cout << "\tMensaje creado para:\n\t\tip: " << ip << ":" << puerto << endl;
}
PaqueteDatagrama::PaqueteDatagrama(unsigned int len):longitud(len){
    datos = (char *)malloc(len*sizeof(char));
}

char *PaqueteDatagrama::obtieneDireccion(){
    return ip;
}

unsigned int PaqueteDatagrama::obtieneLongitud(){
    return longitud;
}

int PaqueteDatagrama::obtienePuerto(){
    return puerto;
}

char *PaqueteDatagrama::obtieneDatos(){
    return datos;
}

void PaqueteDatagrama::inicializaDatos(char *data){
    memcpy(datos,data,longitud);
}

void PaqueteDatagrama::inicializaIp(char *addr){
    strcpy(ip,addr);
}

void PaqueteDatagrama::inicializaPuerto(int port){
    puerto = port;
}