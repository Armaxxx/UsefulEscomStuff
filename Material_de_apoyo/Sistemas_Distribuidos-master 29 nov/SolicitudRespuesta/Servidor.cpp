#include <cstdlib>
#include <string>
#include "Respuesta.h"

using namespace std;

char * reverse (char * data)
{
  string return_data (" "), word;
  size_t size_data = strlen(data);
  for (size_t i = 0;i < size_data+1;i++)
  {
    unsigned char c = data[i];
    switch (c)
    {
      default:
        word += c;
        break;
      case '\0':
      case '\n':
      case ' ':
        if(!word.empty ())
        {
          word += ' ';
          return_data.insert (0, word);
          word.clear();
        }
        break;
    }
  }
  char * resp = (char*)malloc (size_data);
  memcpy (resp,return_data.c_str(),size_data);
  return resp;
}

int main() {

	Respuesta respuesta(7200);
	
	while(1) {
		struct mensaje msj;
    struct mensaje m1;
    char * cadenaInversa;
		cout << "Servidor iniciado correctamente : " << endl;
		//msj = respuesta.getRequest();
		memcpy(&msj, respuesta.getRequest(), sizeof(struct mensaje));

    cout << "Estos son loa argumentos antes de laoperacion: " << msj.arguments << endl;
		cout << "id: " << msj.operationId << endl;
		switch(msj.operationId) {
			case 1:
				cout << "Id encontrado :  1" << endl;
				cout << "Los argumentos son : " << msj.arguments << endl;
				
        memcpy(m1.arguments, reverse(msj.arguments), strlen(msj.arguments));
       
        m1.messageType = 1;
        memcpy(m1.IP, msj.IP, 16);//------------------
        
        m1.puerto = msj.puerto;
        m1.requestId = msj.requestId;
        

				respuesta.sendReply((char*) m1.arguments,&msj.IP[0], msj.puerto);
				cout << "Fin del servicio" << endl;
        break;
			default:
				cout << "Error en el numero de operación" << endl;
				cout << "numero: " << msj.operationId << endl;
				exit(-1);
		}
	}
	

	return 0;
}
