#ifndef SOLICITUD_HPP_
#define SOLICITUD_HPP_
#include "SocketDatagrama.hpp"
#include "mensaje.h"
#include <string.h>
#include <iostream>
#include <fcntl.h>
#include <unistd.h>

class Solicitud
{
private:
    SocketDatagrama *socketlocal;
    int id = 0;
public:
    Solicitud();
    char *doOperation(char *IP, int puerto, int operationId, char *arguments);
};
#endif