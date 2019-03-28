
#include <string>
#include <sstream>
#include <iostream>
#include <time.h>

using namespace std; 

int main(){

    srand(time(NULL));
    int n = 400000;
    char* cadenota =(char*)malloc (n*sizeof(char) );
    char cRand;

    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < 3; j ++) {
            cRand = rand() % 26 + 65;
            cadenota[i] =cRand;
            i++;
        }
        cadenota[i]=' ';
        i++;
    }

    int buscar =0;
    for(int i=0; i<n; i++){
    //    cout<<cadenota[i];
        if((cadenota[i]=='I') && (cadenota[i+1]=='P') && (cadenota[i+2]=='N')){
            //cout<<cadenota[i]<<cadenota[i+1]<<cadenota[i+2]<<endl;
            buscar++;
        }
    }

    
    cout << "\nBuscar: " << buscar << endl;

/*
    int n = 100000;
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
  /*
    int pos; /* Variable que guarda la posición en la que se encontro la palabra IPN */
 /*
    for (int a = 0; a < n; a ++) {
        pos = cadenota.find("IPN", a);
        if(pos != -1) {
            buscar ++;
            a = pos;
        }
    }
    
    cout << cadenota << endl;
    cout << "Buscar: " << buscar << endl;

    */

	return 0;
}