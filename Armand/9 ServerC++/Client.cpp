#include <iostream>
#include <string.h>
#include <unistd.h>
#include "SocketDatagrama.hpp"
#include "PaqueteDatagrama.hpp"
using namespace std;

int puerto = 7200;

int main(void)
{
   cout << "Inicializa el Cliente" << endl;
   char msg[] = "Un mensaje simple";
   char ip[] = "127.0.0.1";
   cout << "Creando Socket Cliente" << endl;
   SocketDatagrama clientAddr(0);
   cout << "Socket Cliente Creado" << endl;

   cout << "Creando Mensaje para servidor" << endl;
   PaqueteDatagrama msgtoserver(msg,sizeof(msg),ip,puerto);
   cout << "Mensaje Creado" << endl;
  
   cout << "Enviando Mensaje" << endl;
   clientAddr.envia(msgtoserver);
   cout << "Mensaje Enviado" << endl;
   sleep(2);
   cout << "Esperando RESPUESTA DEL SERVER" << endl;
   clientAddr.recibe(msgtoserver);
   cout << "Mensaje recibido: " << msgtoserver.obtieneDatos() << endl;

}

