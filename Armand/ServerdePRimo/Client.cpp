#include "SocketDatagrama.hpp"
using namespace std;

int puerto = 7200;

int main(void){
   int num[3],incremento,respuesta = 0;
   char ip[] = "127.0.0.1";
   SocketDatagrama clientSocket(0);
   PaqueteDatagrama *mensaje;

   cout << "Ingresa el numero a comprobar\n";
   cin >> num[0];

   while(num[0] > 2){
/////////////////////////////////////////////////////////////////////////
      cout << "Se busca comprobar el numero " << num[0] << endl;
      incremento = num[0]/3;
      num[1] = 2;
      num[2] = incremento;
      mensaje = new PaqueteDatagrama((char*)num, 3*sizeof(int), ip, puerto);
      clientSocket.envia(*mensaje);

      mensaje = new PaqueteDatagrama(sizeof(int));
      cout << "Esperando RESPUESTA DEL SERVER" << endl;
      clientSocket.recibe(*mensaje);
      cout << "Mensaje recibido: " << *(int*)mensaje->obtieneDatos() << endl;
      respuesta += *(int*)mensaje->obtieneDatos();
////////////////////////////////////////////////////////////////////////
      num[1] = num[2]+1;
      num[2] += incremento;
      mensaje = new PaqueteDatagrama((char*)num, 3*sizeof(int), ip, puerto);
      clientSocket.envia(*mensaje);
      
      mensaje = new PaqueteDatagrama(sizeof(int));
      cout << "Esperando RESPUESTA DEL SERVER" << endl;
      clientSocket.recibe(*mensaje);
      cout << "Mensaje recibido: " << *(int*)mensaje->obtieneDatos() << endl;
      respuesta += *(int*)mensaje->obtieneDatos();
/////////////////////////////////////////////////////////////////////
      num[1] = num[2]+1;
      num[2] = num[0]-1;
      mensaje = new PaqueteDatagrama((char*)num, 3*sizeof(int), ip, puerto);
      clientSocket.envia(*mensaje);
      
      mensaje = new PaqueteDatagrama(sizeof(int));
      cout << "Esperando RESPUESTA DEL SERVER" << endl;
      clientSocket.recibe(*mensaje);
      cout << "Mensaje recibido: " << *(int*)mensaje->obtieneDatos() << endl;
      respuesta += *(int*)mensaje->obtieneDatos();

      if(respuesta == 3){
         cout << "El numero " << num[0] << " es primo\n";
         break; 
      }else{
         num[0]--;
         respuesta = 0;
      }
   }
}
