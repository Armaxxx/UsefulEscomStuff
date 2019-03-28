#include "Archivo.h"
#include <iostream>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int lenght(char * cadena){

	int count = 0;

	 while(*(cadena++) !='\0'){  
           count++; 
     }

     return count;
}

Archivo::Archivo(string name){
	nombreArchivo = name;
	fd = open(nombreArchivo.c_str(),O_RDONLY);
	contenido = (char*)malloc(1);
}

Archivo::Archivo(string name, int banderas, mode_t modo){

	nombreArchivo = name;
	fd = open(nombreArchivo.c_str(),banderas,modo);
	contenido = (char*)malloc(1);

}

Archivo::~Archivo() {
   close(fd);
}


size_t Archivo::lee(){

	char buffer[BUFSIZ];
	int count = 1;
	int count1 =0;
	int byteLeidos = 0;
	int totalbyteLeidos = 0;

	if(fd!=-1){

		

		while( (byteLeidos = read(fd,buffer,sizeof buffer)) > 0 ){
			
			//cout << "bytes leidos :  : " << byteLeidos << endl;
			//cout << "longitud ante de realloc : " << totalbyteLeidos << endl;

			contenido = (char *) realloc(contenido, byteLeidos+ totalbyteLeidos);
			totalbyteLeidos = byteLeidos+ totalbyteLeidos;
			//cout << "Longitud del apuntador actualmente: " << strlen(contenido) << endl;
			
			for (int i = 0; i < byteLeidos; i++){
				
				*(contenido+count1) = buffer[i];
				count1 = count1+ 1;
			
				//cout << *(contenido+count1) ;

				
			}

			//cout << "Valor final del contador : " << count1 << endl; 

			longitud = totalbyteLeidos;

//			free(contenido);

			count++;

			 
			
		

			

		}
		cout << endl;

		cout << "contenido del archivo: "<<longitud<< endl;


		return 0;
	}else{
	 
	 	printf("\nEl archivo no existe");
	 	return 1;
	}

}

size_t Archivo::escribe( const char * data, size_t longi){	

	write(fd,data,longi);
	return 0;

}

size_t Archivo::obtieneNum_bytes(){

	char buffer;
	int count = 0;

	if(fd!=-1){

		while( read(fd,&buffer,sizeof buffer) > 0){
			count++;
		}

	}else{
	 
	 	printf("\nEl archivo no existe");
	 
	}

	cout << "Este archivo contiene : " << count << " bytes" << endl;

	return count;

}

const char * Archivo::get_contenido(){

	return contenido;

}

size_t Archivo::get_longitud(){

	return longitud;

}

int Archivo::getfd(){

	return fd;
}

 void Archivo::copyArchivos(Archivo destino){

 	int origenfd = fd;
 	int destinofd = destino.getfd();
 	int nbytes = 1;
 	int count = 0;

 

 	char buffer[BUFSIZ];
 	while(read(origenfd, buffer, sizeof buffer) > 0  ){

 			contenido = (char *)realloc(contenido,strlen(contenido) + BUFSIZ); 

 			cout << "Este es el tamaño del buffer: " << BUFSIZ << endl;


 		if( count == 0){
			

			for (int i = 0; i < strlen(buffer); i++)
			{
				*(contenido++) = buffer[i];
			}

 		}else{
			

			for (int i = 0; i < strlen(buffer); i++)
			{
				*(contenido++) = buffer[i];
			}
			
 		}

 		
 		count++;

 		
 	}

 	write(destinofd,contenido,nbytes);

 }


