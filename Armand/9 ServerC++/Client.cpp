#include <iostream>
#include "SocketDatagrama.hpp"
#include "PaqueteDatagrama.hpp"
using namespace std;

int puerto = 7200;

int main(void)
{
   char msg[11] = "Un mensaje";
   char ip[16] = "192.168.100.12";
   SocketDatagrama clientAddr(puerto);
   PaqueteDatagrama msgtoserver(msg,11,ip,puerto);
  
   clientAddr.envia(msgtoserver);

   clientAddr.recibe(msgtoserver);

   cout << "Mensaje recibido: " << msgtoserver.obtieneDatos() << endl;
}

