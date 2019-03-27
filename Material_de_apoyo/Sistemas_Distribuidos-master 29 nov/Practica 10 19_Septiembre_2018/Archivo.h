#ifndef ARCHIVO_H_
#define ARCHIVO_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>

using namespace std;

class Archivo
{

	private:
		 string nombreArchivo;
		 int fd;
		 char *contenido = NULL;
		 size_t num_bytes;
		 size_t longitud;
	public:
		 Archivo(string filename);
		 Archivo(string filename, int banderas, mode_t modo);
		 //size_t lee(size_t nbytes);
		 size_t lee();
		 size_t escribe(const char * data, size_t longi);
		 size_t obtieneNum_bytes();
		 const char *get_contenido();
		 size_t get_longitud();
		 void copyArchivos(Archivo destino);
		 int getfd();

		 ~Archivo(); 
};
 

#endif