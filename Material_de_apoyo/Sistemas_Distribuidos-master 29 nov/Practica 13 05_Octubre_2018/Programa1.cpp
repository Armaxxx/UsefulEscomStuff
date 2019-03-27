#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char const *argv[]){
	unsigned int num = atoi(argv[1]);
	int aux = 0;

	for (int i = 1; i < num + 1; i++){
		if(num % i == 0){
			aux++;
		}
	}

	if(aux != 2){
		cout << "No es primo" << endl;
	}
	else{
		cout << "Es primo" << endl;
	}

	return 0;
}