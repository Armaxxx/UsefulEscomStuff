#include <iostream>
using namespace std;

int main( )
{
    //Parte uno
    int numeroUno =10, numeroDos=12;
    int resultadoEntero;
    float resultadoEntero2;

    cout << "Division de entre dos numeros enteros\n";
    cout << "10/12 = ";

    resultadoEntero = numeroUno/numeroDos;
    resultadoEntero2 = numeroUno/numeroDos;
    
    cout << "\nEl resultado en una variable int es: "<<resultadoEntero;
    cout << "\nEl resultado en una variable float es: "<<resultadoEntero2<<"\n";


    //Parte dos
    float numeroUnoFloat =55.5, numeroDosFloat=12.5;
    int resultadoEnteroFloat;
    float resultadoEntero2Float;

    cout << "Division de entre dos numeros float\n";
    cout << "55.5/12.5 = ";

    resultadoEnteroFloat = numeroUnoFloat/numeroDosFloat;
    resultadoEntero2Float = numeroUnoFloat/numeroDosFloat;
    
    cout << "\nEl resultado en una variable int es: "<<resultadoEnteroFloat;
    cout << "\nEl resultado en una variable float es: "<<resultadoEntero2Float<<"\n";
    return 0;
}

/*
    Parte uno
        Division con dos numeros enteros
        Si el resultado de la division entre enteros se guarda en una varible del mismo tipo no se muestran datos decimales, solo numeros enteros.
        Si el resultado de la division entre enteros se guarda en una varible del tipo float no se muestran datos decimales, solo numeros enteros.
        "No existe ningun warning al realizar la division"

    Parte dos
        Division con dos numeros float
        Si el resultado de la division entre float se guarda en una varible del tipo int no se muestran datos decimales, solo numeros enteros.
        Si el resultado de la division entre float se guarda en una varible del tipo float se muestran datos decimales y numeros enteros.
*/
