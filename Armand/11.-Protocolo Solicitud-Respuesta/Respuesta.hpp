#ifndef RESPUESTA_HPP_
#define RESPUESTA_HPP_
#include "mensaje.h"
#include "SocketDatagrama.hpp"
#include <iostream>
#include <string.h>

class Respuesta
{
private:
    SocketDatagrama *socketlocal;
public:
    Respuesta(int pl);
    struct mensaje *getRequest(void);
    void sendReply(char *respuesta, char *ipCliente, int puertoCliente);
};

#endif