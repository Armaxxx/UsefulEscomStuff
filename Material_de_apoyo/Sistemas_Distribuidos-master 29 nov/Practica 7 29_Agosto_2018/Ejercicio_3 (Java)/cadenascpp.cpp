
#include <string>
#include <iostream>
#include <time.h>
#include <math.h>

using namespace std; 

int main(){

    srand(time(NULL));
    //int n = 100000;
    int n = pow(26,3);
    string cadenota;
    string cRand;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 3; j ++) {
            cRand = rand() % 26 + 65;
            cadenota = cadenota + cRand;
        }
        cadenota = cadenota + " ";
    }
    

    int buscar = 0; /* Contador de las veces que aparece la palabra IPN */
    int pos; /* Variable que guarda la posición en la que se encontro la palabra IPN */
    for (int a = 0; a < n; a ++) {
        pos = cadenota.find("IPN", a);
        if(pos != -1) {
            buscar ++;
            a = pos+=3;
        }
    }
    
    //cout << cadenota << endl;
    cout << "Buscar: " << buscar << endl;

	return 0;
}