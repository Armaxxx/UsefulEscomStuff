#include "Archivo.h"
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;




int main(int argc, char*argv[])
{

	cout << "Programa de manejos de archivos" << endl << endl;

	string archivoOrig;
	string archivoDest;

	archivoOrig = argv[1];
	archivoDest = argv[2];

	cout << "Este son las propiedades del archivo :" << endl<< endl ;

	//Archivo archivo("archivo.txt");
	Archivo archivo(archivoOrig, O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
	archivo.lee();

	Archivo archivo2(archivoDest, O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
	archivo2.escribe(archivo.get_contenido(), archivo.get_longitud());
	//archivo.obtieneNum_bytes();


	//cout << "Valor de la variable contenido :" <<archivo.get_contenido() << endl;
	archivo.~Archivo();
	cout << endl;


	/*archivoOrig = argv[1];
	archivoDest = argv[2];


	cout << archivoDest << endl;
	cout << archivoOrig << endl;




	

	/*Archivo archivoOrigen(archivoOrig, O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
	Archivo archivoDestino(archivoDest, O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    archivoOrigen.copyArchivos(archivoDestino);*/
	return 0;
}	


