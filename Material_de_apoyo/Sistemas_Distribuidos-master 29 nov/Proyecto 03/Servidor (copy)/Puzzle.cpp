#include "Puzzle.h"

using namespace std;

Puzzle::Puzzle()
{

}

Puzzle::Puzzle(int nodoInicial[], int nodoFinal[])
{
    nodo_inicial.inicializarNodo(nodoInicial, 1, "1");
    nodo_final.inicializarNodo(nodoFinal, 0, "0");
    
    nodos_ultimashojas.push_back(nodo_inicial);
}

int Puzzle::movimientos()
{
    int contador, contadordos, respuesta = 0;
    string nombre_auxiliar =" ";
    Nodo nodotemp, nodoAuxiliar;
    vector<Nodo> nuevos_nodos;
    for(contador = 0; contador < nodos_ultimashojas.size(); contador++)
    {
        nodotemp =nodos_ultimashojas[contador];
        int aux1[NUEVE] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
        int i = 0, j;
        //Busco donde esta el espacio en blanco
        while (nodotemp.nododearbol[i] != 0)
        {
            i++;
        }

        switch (i)
        {
        case 0:
            //Hacemos el primer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 0)
                    aux1[0] = nodotemp.nododearbol[1];
                else if (j == 1)
                    aux1[1] = nodotemp.nododearbol[0];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".1");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el segundo desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 0)
                    aux1[0] = nodotemp.nododearbol[3];
                else if (j == 3)
                    aux1[3] = nodotemp.nododearbol[0];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".2");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            break;
        case 1:
            //Hacemos el primer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 1)
                    aux1[1] = nodotemp.nododearbol[0];
                else if (j == 0)
                    aux1[0] = nodotemp.nododearbol[1];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".1");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el segundo desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 1)
                    aux1[1] = nodotemp.nododearbol[4];
                else if (j == 4)
                    aux1[4] = nodotemp.nododearbol[1];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".2");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el tercer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 1)
                    aux1[1] = nodotemp.nododearbol[2];
                else if (j == 2)
                    aux1[2] = nodotemp.nododearbol[1];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".3");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            break;
        case 2:
            //Hacemos el primer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 2)
                    aux1[2] = nodotemp.nododearbol[1];
                else if (j == 1)
                    aux1[1] = nodotemp.nododearbol[2];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".1");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el segundo desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 2)
                    aux1[2] = nodotemp.nododearbol[5];
                else if (j == 5)
                    aux1[5] = nodotemp.nododearbol[2];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".2");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            break;
        case 3:
            //Hacemos el primer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 3)
                    aux1[3] = nodotemp.nododearbol[0];
                else if (j == 0)
                    aux1[0] = nodotemp.nododearbol[3];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".1");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el segundo desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 3)
                    aux1[3] = nodotemp.nododearbol[4];
                else if (j == 4)
                    aux1[4] = nodotemp.nododearbol[3];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".2");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el tercero desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 3)
                    aux1[3] = nodotemp.nododearbol[6];
                else if (j == 6)
                    aux1[6] = nodotemp.nododearbol[3];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".3");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            break;
        case 4:
            //Hacemos el primer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 4)
                    aux1[4] = nodotemp.nododearbol[1];
                else if (j == 1)
                    aux1[1] = nodotemp.nododearbol[4];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".1");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el segundo desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 4)
                    aux1[4] = nodotemp.nododearbol[3];
                else if (j == 3)
                    aux1[3] = nodotemp.nododearbol[4];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".2");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el tercer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 4)
                    aux1[4] = nodotemp.nododearbol[5];
                else if (j == 5)
                    aux1[5] = nodotemp.nododearbol[4];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".3");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el cuarto desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 4)
                    aux1[4] = nodotemp.nododearbol[7];
                else if (j == 7)
                    aux1[7] = nodotemp.nododearbol[4];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".4");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            break;
        case 5:
            //Hacemos el primer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 5)
                    aux1[5] = nodotemp.nododearbol[2];
                else if (j == 2)
                    aux1[2] = nodotemp.nododearbol[5];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".1");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el segundo desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 5)
                    aux1[5] = nodotemp.nododearbol[4];
                else if (j == 4)
                    aux1[4] = nodotemp.nododearbol[5];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".2");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el tercer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 5)
                    aux1[5] = nodotemp.nododearbol[8];
                else if (j == 8)
                    aux1[8] = nodotemp.nododearbol[5];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".3");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            break;
        case 6:
            //Hacemos el primer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 6)
                    aux1[6] = nodotemp.nododearbol[3];
                else if (j == 3)
                    aux1[3] = nodotemp.nododearbol[6];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".1");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el segundo desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 6)
                    aux1[6] = nodotemp.nododearbol[7];
                else if (j == 7)
                    aux1[7] = nodotemp.nododearbol[6];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".2");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            break;
        case 7:
            //Hacemos el primer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 7)
                    aux1[7] = nodotemp.nododearbol[6];
                else if (j == 6)
                    aux1[6] = nodotemp.nododearbol[7];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".1");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el segundo desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 7)
                    aux1[7] = nodotemp.nododearbol[4];
                else if (j == 4)
                    aux1[4] = nodotemp.nododearbol[7];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".2");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el tercer desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 7)
                    aux1[7] = nodotemp.nododearbol[8];
                else if (j == 8)
                    aux1[8] = nodotemp.nododearbol[7];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".3");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            break;

        case 8:
            //Hacemos el segundo desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 8)
                    aux1[8] = nodotemp.nododearbol[5];
                else if (j == 5)
                    aux1[5] = nodotemp.nododearbol[8];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".1");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            //Hacemos el segundo desplazamiento
            for (j = 0; j < NUEVE; j++)
            {
                if (j == 8)
                    aux1[8] = nodotemp.nododearbol[7];
                else if (j == 7)
                    aux1[7] = nodotemp.nododearbol[8];
                else
                    aux1[j] = nodotemp.nododearbol[j];
            }
            //Guardamos los nodos en nuestro Vector
            nodoAuxiliar.inicializarNodo(aux1, nodotemp.identificador, nodotemp.nombre+".2");
            if(0 == buscarExistenciaDeNodo(nodoAuxiliar))
            {
                nuevos_nodos.push_back(nodoAuxiliar);
            }
            break;

        }
    }

    //Actualizamos las ultimas hojas
        //Primero guardamos y borramos las actuales
    for(contador = 0; contador < nodos_ultimashojas.size(); contador++)
    {
        almacen_nodos.push_back(nodos_ultimashojas[contador]);
    }
    nodos_ultimashojas.clear();
        //Luego actualizamos estos ultimos
    for(contador = 0; contador < nuevos_nodos.size(); contador++)
    {
        respuesta =revisarEstadoNodo(nuevos_nodos[contador]);
        nodos_ultimashojas.push_back(nuevos_nodos[contador]);
        if(respuesta == 1)
        {
            almacen_nodos.push_back(nuevos_nodos[contador]);
            break;
        }
            
    }
    return respuesta;
}

int Puzzle::revisarEstadoNodo(Nodo nodo)
{
    int iguales = 1, contador;
    for (contador = 0; contador < NUEVE; contador++)
    {
        if (nodo.nododearbol[contador] != nodo_final.nododearbol[contador])
        {
            iguales = 0;
            break;
        }
            
    }
    return iguales;
}

int Puzzle::buscarExistenciaDeNodo(Nodo nodo)
{
    int contador, i, j, respuesta = 0;
    Nodo temp;
    for(contador = 0; contador < almacen_nodos.size(); contador++)
    {
        temp =almacen_nodos[contador];
        j = 0;
        for (i = 0; i < NUEVE; i++)
        {
            if (nodo.nododearbol[i] == temp.nododearbol[i])
            {
                j++;
            }
        }
        if(j==9){
            respuesta =1;
            break;
        }
    }
    return respuesta;
}


void Puzzle::imprimirUltimasHojas()
{
    int i, j;
    Nodo nodo_auxiliar;
    for (i = 0; i < nodos_ultimashojas.size(); i++)
    {
        nodo_auxiliar = nodos_ultimashojas[i];
        cout<<"Identificador: "<<nodo_auxiliar.identificador<<" Posicion: "<<nodo_auxiliar.nombre<<endl;
        for (j = 0; j < NUEVE; j++)
        {
            printf("%d ", nodo_auxiliar.nododearbol[j]);
        }
        printf("\n");
    }
    cout<<"Contamos con: "<<nodos_ultimashojas.size()<<" hojas"<<endl;
}

void Puzzle::imprimirAlmacen()
{
    int i, j;
    Nodo nodo_auxiliar;
    for (i = 0; i < almacen_nodos.size(); i++)
    {
        nodo_auxiliar = almacen_nodos[i];
        cout<<"Posicion: "<<nodo_auxiliar.nombre<<endl;
        for (j = 0; j < NUEVE; j++)
        {
            printf("%d ", nodo_auxiliar.nododearbol[j]);
        }
        printf("\n");
    }
    cout<<"Nuestro Almacen tiene: "<<almacen_nodos.size()<<" elementos"<<endl;
}