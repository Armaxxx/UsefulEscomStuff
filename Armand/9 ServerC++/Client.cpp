#include <iostream>
#include "SocketDatagrama.hpp"
#include "PaqueteDatagrama.hpp"

int puerto = 7200;

int main(void)
{
   SocketDatagrama clientAddr;
   PaqueteDatagrama msgtoserver;
   
   msgtoserver = new PaqueteDatagrama("Un mensaje",10,"192.168.100.12",puerto)
   clientAddr = new SocketDatagrama(puerto)
  
   clientAddr.envia(msgtoserver);

   clientAddr.recibe(msgtoserver);

   cout << "Mensaje recibido: " << msgtoserver.obtieneDatos() << endl;
   delete(clientAddr);
   delete(msgtoserver);
}

