#include <unistd.h>
#include <iostream>

using namespace std;


class NumerosRand{

private:
	int * arreglo;
	unsigned int numeroElementos;

public:
	NumerosRand(unsigned int num);
	void inicializaNumerosRand(void);
	~NumerosRand(); // Destructor



};


NumerosRand::NumerosRand(unsigned int num){

	numeroElementos = num;
	arreglo = new int(numeroElementos);
}

NumerosRand::~NumerosRand(){
	delete[] arreglo;
}


void NumerosRand::inicializaNumerosRand(){

	unsigned int i;
	for (int i = 0; i < numeroElementos; i++){
		arreglo[i] =  rand();
	}
}

void pruebaClase(){

	unsigned int capacidad;

	cout << "Numero de enteros aleatorios en el arreglo : ";

	cin >> capacidad;

	NumerosRand tmp(capacidad);
	tmp.inicializaNumerosRand();
	tmp.~NumerosRand();
	sleep(7);

}

int main(){

	char res;

	do{

		pruebaClase();
		cout << "Probar de nuevo? (s/n)";
		cin >> res;
		

	}while((res == 's') || (res == 'S'));
	
	return 0;
}

//¿Qué sucede con la cantidad de memoria ocupada en el monitor de sistema?

/* Respuesta :
La me moria empieza a incrementar poco a poco cada vez que se llama al 
metodo dentro del ciclo while
*/

//¿Qué pasa si no se llama al método que inicializa el arreglo de enteros? ¿Por qué?

/* Respuesta :
Auque llamemos muchas veces el metodo , la memoria del sistema no se ve afectada
*/


//¿Qué sucede con la memoria si se llama dos o más veces a ejecutar la función pruebaClase()?
/*
Empieza a incrementar
*/


/*¿Qué sucede con la memoria si en el programa primero requiero un arreglo de cien millones de
elementos y después solo necesito un arreglo con cien elementos?*/



