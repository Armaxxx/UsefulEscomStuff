#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

int main(){

    srand(time(NULL));
    int n = pow(26,3);
    char aux[4];

    char *cadenota =NULL;
    int j=0;
    for (int i = 0,j = 0; i < n; i++, j+=4) {
        cadenota = (char*)realloc(cadenota, j+4);

            aux[0] = rand() % 26 + 65;
            aux[1] = rand() % 26 + 65;
            aux[2] = rand() % 26 + 65;
            aux[3] = 32;

        memcpy(&cadenota[j], aux, 4);

        //strcat(cadenota,aux);
    //printf("%d ", j); 
    //printf("%s\n", aux);   
    }

    int buscar =0;
    //printf("CADENOTA: %s\n", cadenota);   

    for(int i=0; i<n; i++){
    //    cout<<cadenota[i];
        if(cadenota[i]=='I'){
            if (cadenota[i+1] == 'P'){
                if(cadenota[i+2] == 'N'){
                    buscar++;
                }
            }
        }
        i+=4;
    }

    printf("Buscar: %d\n", buscar);

	return 0;
}

int lenght2(char * cadena){
    int count =0;

    while(*(cadena++)!='\0'){
        count++;
    }

    return count;
}