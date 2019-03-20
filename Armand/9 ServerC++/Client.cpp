#include <iostream>
#include "SocketDatagrama.hpp"
#include "PaqueteDatagrama.hpp"
using namespace std;

int puerto = 7200;

int main(void)
{
   cout << "Inicializa el CLIENTE" << endl;
   char msg[11] = "Un mensaje";
   char ip[16] = "127.0.0.1";
   cout << "Creando Socket CLIENTE" << endl;
   SocketDatagrama clientAddr(0);
   cout << "Socket Cliente Creado" << endl;
   cout << "Creando Mensaje" << endl;
   PaqueteDatagrama msgtoserver(msg,11,ip,puerto);
   cout << "Mensaje Creado" << endl;
  
   cout << "Enviando Mensaje" << endl;
   clientAddr.envia(msgtoserver);
   cout << "Mensaje Enviado" << endl;
   
   cout << "Esperando RESPUESTA DEL SERVER" << endl;
   clientAddr.recibe(msgtoserver);

   cout << "Mensaje recibido: " << msgtoserver.obtieneDatos() << endl;
}

