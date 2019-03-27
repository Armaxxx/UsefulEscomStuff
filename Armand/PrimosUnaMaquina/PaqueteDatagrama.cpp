#include "PaqueteDatagrama.hpp"
using namespace std;

PaqueteDatagrama::PaqueteDatagrama(char *dat, unsigned int len, char *addr , int port):longitud(len),puerto(port){
    datos = new char[len];
    memcpy(datos,dat,len);
    strcpy(ip,addr);
    cout << "\tMensaje creado para:\n\t\tip: " << ip << "\n\t\tPuerto: " << puerto << "\n\t\tDatos: " << datos << endl;
}
PaqueteDatagrama::PaqueteDatagrama(unsigned int len):longitud(len){
    datos = new char[len];
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