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
    s = socket(AF_INET, SOCK_DGRAM, 0);

    bzero((char *) &direccionLocal, sizeof(direccionLocal));
    direccionLocal.sin_family = AF_INET;
    direccionLocal.sin_addr.s_addr = INADDR_ANY;
    direccionLocal.sin_port = htons(puerto);

    bind(s, (struct sockaddr *) &direccionLocal, sizeof(direccionLocal));
}

int SocketDatagrama::recibe(PaqueteDatagrama &p){
    char *num;
    int i = 0;
    while(i == 0) {
        unsigned int tam = sizeof(direccionForanea);
        i = recvfrom(s, (char *) num, p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *)&direccionForanea, &tam);
        cout << "Enviado Por: " << inet_ntoa(direccionForanea.sin_addr) << ": "<< ntohs(direccionForanea.sin_port) << endl;
    }
    return i;
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    unsigned int tam = sizeof(direccionForanea);
    return sendto(s, p.obtieneDatos(), p.obtieneLongitud()*sizeof(char), 0, (struct sockaddr *)&direccionForanea, tam);
}