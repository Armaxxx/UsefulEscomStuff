#ifndef SOLICITUD_HPP_
#define SOLICITUD_HPP_
#include "SocketDatagrama.hpp"
#include "mensaje.h"
#include <string.h>
#include <iostream>

class Solicitud
{
private:
    SocketDatagrama *socketlocal;
    //int id;
public:
    Solicitud();
    char *doOperation(char *IP, int puerto, int operationId, char *arguments);
};
#endif