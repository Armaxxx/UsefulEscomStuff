#include "SocketDatagrama.hpp"
using namespace std;
//Tiempo = 28.115
int puerto = 7200;

int main(void){
   unsigned int num[3],incremento,respuesta = 0;
   char ip[] = "127.0.0.1";
   SocketDatagrama clientSocket(0);
   PaqueteDatagrama *mensaje;

   cout << "Ingresa el numero a comprobar\n";
   cin >> num[0];
/////////////////////////////////////////////////////////////////////////
   cout << "Se busca comprobar el numero " << num[0] << endl;
   num[1] = 2;
   num[2] = num[0] - 1;
   mensaje = new PaqueteDatagrama((char*)num, 3*sizeof(int), ip, puerto);
   clientSocket.envia(*mensaje);

   mensaje = new PaqueteDatagrama(sizeof(int));
   clientSocket.recibe(*mensaje);
   respuesta += *(int*)mensaje->obtieneDatos();

   if(respuesta == 1){
      cout << "El numero " << num[0] << " es primo\n";
   }else{
      cout << "El numero " << num[0] << " no es primo\n";
      num[0]--;
      respuesta = 0;
   }
}
