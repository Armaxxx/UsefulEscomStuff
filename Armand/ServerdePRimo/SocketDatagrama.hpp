#include <strings.h>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "PaqueteDatagrama.hpp"
#ifndef SOCKETDATAGRAMA_HPP_
#define SOCKETDATAGRAMA_HPP_

class SocketDatagrama{
private:
    struct sockaddr_in direccionLocal;
    struct sockaddr_in direccionForanea;
    int s; //ID socket
public:
    SocketDatagrama(int);
    //Recibe un paquete tipo datagrama proveniente de este socket
    int recibe(PaqueteDatagrama &p);
    //Envia un paquete tipo datagrama desde este socket
    int envia (PaqueteDatagrama &p);
};
#endif