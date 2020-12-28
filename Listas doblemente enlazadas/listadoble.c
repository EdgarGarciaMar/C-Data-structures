/*
    Listas doblemente enlazadas
    Asael García
    20/09/2015
*/
#include <stdio.h>
#include <stdlib.h>

//Estructura del nodo
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
    struct nodo *anterior;
} NODO;


NODO *CrearNodo(int dato);
int InsertarInicio(NODO **cabeza, int dato);
int InsertarFinal(NODO **cabeza, int dato);
void ImprimirLista(NODO *cabeza);
int EliminarNodo(NODO **cabeza, int dato);


int main()
{
    NODO *cabeza = NULL;

    InsertarInicio(&cabeza, 1);
    InsertarInicio(&cabeza, 2);
    InsertarFinal(&cabeza, 3);
    InsertarFinal(&cabeza, 4);
    ImprimirLista(cabeza);
    system("PAUSE");
    EliminarNodo(&cabeza, 4);
    ImprimirLista(cabeza);
    system("pause>nul");

    return 0;
}

//Función para eliminar un nodo de la lista
int EliminarNodo(NODO **cabeza, int dato)
{
    NODO *actual = *cabeza, *ant = NULL, *sig = NULL;

    while(actual != NULL)
    {
        if(actual->dato == dato)
        {
            if( actual == *cabeza)
            {
                *cabeza = actual->siguiente;
                if( actual->siguiente != NULL)
                    actual->siguiente->anterior = NULL;
            }
            else if( actual->siguiente == NULL)
            {
                ant = actual->anterior;
                actual->anterior = NULL;
                ant->siguiente = NULL;
            }
            else
            {
                ant = actual->anterior;
                actual->anterior = NULL;
                sig = actual->siguiente;
                actual->siguiente = NULL;
                ant->siguiente = sig;
                sig->anterior = ant;
            }
            free(actual);
            return 1;
        }
        actual = actual->siguiente;
    }
    return 0;
}

//Función para insertar al final de la lista
int InsertarFinal(NODO **cabeza, int dato)
{
    NODO *nuevo = NULL, *nAux = *cabeza;

    nuevo = CrearNodo(dato);
    if (nuevo != NULL)
    {
        while(nAux->siguiente != NULL){ nAux = nAux->siguiente;}
        nuevo->anterior = nAux;
        nAux->siguiente = nuevo;
        return 1;
    }
    return 0;
}

//Función para imprimir la lista
void ImprimirLista(NODO *cabeza)
{
    NODO *nAux = cabeza;

    while(nAux != NULL)
    {
        printf("%d ", nAux->dato);
        nAux = nAux->siguiente;
    }
}

//Función para insertar al inicio de la lista
int InsertarInicio(NODO **cabeza, int dato)
{
    NODO *nuevo = NULL;

    nuevo = CrearNodo(dato);
    if (nuevo != NULL)
    {
        nuevo->siguiente = *cabeza;
        nuevo->anterior = NULL;
        if( *cabeza != NULL)
            (*cabeza)->anterior = nuevo;
        *cabeza = nuevo;
        return 1;
    }
    return 0;
}

//Función para crear un nuevo nodo
NODO *CrearNodo(int dato)
{
    NODO* nuevo = NULL;

    nuevo = (NODO*)malloc(sizeof(NODO));
    if( nuevo != NULL)
    {
        nuevo->dato = dato;
        nuevo->siguiente = NULL;
        nuevo->anterior = NULL;
    }
    return nuevo;
}
