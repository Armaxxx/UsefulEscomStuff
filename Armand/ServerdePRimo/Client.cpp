#include <iostream>
#include <string.h>
#include <unistd.h>
#include <vector>
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
   vector<PaqueteDatagrama> msgstoserver;
   PaqueteDatagrama *msgtoserver;
   msgtoserver = new PaqueteDatagrama((char*)num,3,ip,puerto);
   msgstoserver.push_back(*msgtoserver);

   num[1] = num[2];
   num[2] += incremento;

   msgtoserver = new PaqueteDatagrama((char*)num,3,ip,puerto);
   msgstoserver.push_back(*msgtoserver);

   num[1] = num[2];
   num[2] += incremento;

   msgtoserver = new PaqueteDatagrama((char*)num,3,ip,puerto);
   msgstoserver.push_back(*msgtoserver);
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

