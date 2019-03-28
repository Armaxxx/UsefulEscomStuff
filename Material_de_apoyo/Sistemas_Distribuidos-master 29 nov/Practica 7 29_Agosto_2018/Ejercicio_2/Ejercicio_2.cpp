#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cstring>

using namespace std;




int main(){


	/*string cadena("ESCOM");
	cout << cadena.at(4) << endl;*/


	char aCString[50];
	string stringVariable("hdskj");

	strcpy(aCString, stringVariable.c_str( )); 

	cout << "Esta es la variable :" << aCString << endl ;

	return 1;
}