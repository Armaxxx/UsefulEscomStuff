#include "PaqueteDatagrama.hpp"
#include "SocketDatagrama.hpp"
#include <strings.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
using namespace std;

SocketDatagrama::SocketDatagrama(int puerto){
    cout << "\tCreando Socket\n";
    s = socket(AF_INET, SOCK_DGRAM, 0);
    cout << "\tSocket Creado\n";

    cout << "\tInicializa Direccion Local\n";
    bzero((char *) &direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(puerto);
    cout << "\tDireccion Local creada con:\n\t\tip: " << inet_ntoa(direccionLocal.sin_addr) << "\n\t\tpuerto: " << ntohs(direccionLocal.sin_port) << endl;

    cout << "\tUniendo socket a direccion local\n";
    bind(s, (struct sockaddr *) &direccionLocal, sizeof(direccionLocal));
    cout << "\t Unidos\n";
}

int SocketDatagrama::recibe(PaqueteDatagrama &p){
    char *num;
    int i = 0;
    while(i == 0) {
        unsigned int tam = sizeof(direccionForanea);
        cout << "\tEsperando mensaje\n";
        i = recvfrom(s, num, p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &tam);
        cout << "\tEnviado Por: " << inet_ntoa(direccionForanea.sin_addr) << ":"<< ntohs(direccionForanea.sin_port) << endl;
    }
    return i;
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    cout << "\tEnviando mensaje a:\n\t\tip: " << inet_ntoa(direccionForanea.sin_addr) << "\n\t\tpuerto: " << ntohs(direccionForanea.sin_port) << endl;
    unsigned int tam = sizeof(direccionForanea);
    cout << "\tEnviando\n";
    return sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, tam);
}