#include "SocketDatagrama.hpp"

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
    cout << "\tUnidos\n";
}

int SocketDatagrama::recibe(PaqueteDatagrama &p){
    char *num;
    int i = 0;
    while(i == 0) {
        unsigned int tam = sizeof(direccionForanea);
        cout << "\tEsperando mensaje de size: " << p.obtieneLongitud() << endl;
        i = recvfrom(s, (char*)p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, &tam);
        p.inicializaIp(inet_ntoa(direccionForanea.sin_addr));
        p.inicializaPuerto(ntohs(direccionForanea.sin_port));
        cout << "\trecvfrom: " << i << "\n\tEnviado Por: " << inet_ntoa(direccionForanea.sin_addr) << ":"<< ntohs(direccionForanea.sin_port) << endl;
    }
    return i;
}

int SocketDatagrama::envia(PaqueteDatagrama &p){
    int i;
    direccionForanea.sin_family = AF_INET;
    direccionForanea.sin_addr.s_addr = inet_addr(p.obtieneDireccion());
    direccionForanea.sin_port = htons(p.obtienePuerto());
    cout << "\tEnviando mensaje a:\n\t\tip: " << inet_ntoa(direccionForanea.sin_addr) << "\n\t\tpuerto: " << ntohs(direccionForanea.sin_port) << endl;
    unsigned int tam = sizeof(direccionForanea);
    cout << "\tEnviando\n";
    i = sendto(s, p.obtieneDatos(), p.obtieneLongitud(), 0, (struct sockaddr *)&direccionForanea, tam);
    cout << "\tEnviado\n\tsendto: " << i << endl;
    return i;
}