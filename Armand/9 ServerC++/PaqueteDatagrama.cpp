#include <iostream>
#include <string.h>
#include "PaqueteDatagrama.hpp"
using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char *dat, unsigned int len, char *addr , int port):longitud(len),puerto(port){
    memcpy(datos,dat,sizeof(dat));
    memcpy(ip,addr,sizeof(addr));
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
    memcpy(datos,data,sizeof(data));
}

void PaqueteDatagrama::inicializaIp(char *addr){
    memcpy(ip,addr,sizeof(addr));
}

void PaqueteDatagrama::inicializaPuerto(int port){
    puerto = port;
}