#include <iostream>
#include <string.h>
#include <unistd.h>
#include "SocketDatagrama.hpp"
#include "PaqueteDatagrama.hpp"
using namespace std;

int puerto = 7200;

int main(void)
{
   int num[3],incremento;
   char ip[] = "127.0.0.1";
   SocketDatagrama clientAddr(0);
   
   cout << "Ingresa el numero a comprobar\n";
   cin >> num[0];
   incremento = num[0]/3;
   num[1] = 2;
   num[2] = incremento;

   PaqueteDatagrama msgtoserver((char*)num,3,ip,puerto);
   while(true){
      clientAddr.envia(msgtoserver);
      num[1] = num[2]+1;
      num[2] += incremento;
      //Codigo para asignar ip
      clientAddr.envia(msgtoserver);
   }
   
   cout << "Esperando RESPUESTA DEL SERVER" << endl;
   clientAddr.recibe(msgtoserver);
   cout << "Mensaje recibido: " << msgtoserver.obtieneDatos() << endl;

}

