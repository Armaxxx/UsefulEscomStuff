#include "Solicitud.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char*argv[]) {

	char arreglo[100] = "Cadena que se va a invertir y se mostrara en el servidor \0";
	char *ip;
	int puerto;
	int operacion = 1;


	ip =argv[1];
	puerto = atoi(argv[2]);
/*
	cout << "Ingresa la IP : " << endl;
	cin >> ip;
	cout << "Ingresa el puerto del servidor:" << endl;
	cin >> puerto;
*/
	Solicitud cliente;
	//cliente.doOperation(ip, puerto, operacion, arreglo);

	printf("La respuesta del servidor es :\n\n%s\n", cliente.doOperation(ip, puerto, operacion, arreglo));

	return 0;
}