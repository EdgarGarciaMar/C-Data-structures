//
//  main.c
//  arbolB
//
//  Created by Caleb on 18/06/20.
//  Copyright © 2020 Caleb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#define N 3 // grado del arbol
//los nodos deben de tener al menos N/2 hijos (N/2 -1 claves), la raiz es excepcion

typedef struct Nodo{
    int claves[N];//lo tratamos como N-1
    int numeroClaves;
    struct Nodo *hijos[N];
    int numeroHijos;
}nodo;

int esHoja(nodo *nodo);
int busqueda(nodo *nodo, int valor);
void insercionOrdenada(nodo *nodox, nodo *hijoDerecho, int valor);
nodo *division(nodo *nodox);
int buscarHijo(nodo *nodox, int valor);
nodo *crearNodo(void);
nodo *insercion(nodo *nodox, int valor);
nodo *divisionEnRaiz(nodo *nodox);
void menu(void);
int redondear(int a, int b);
void mostrarArbol(nodo *nodox, int espacios);
int obtenerMinimo(nodo *nodox);
int obtenerMaximo(nodo *nodox);

nodo *nodoRaiz;

nodo *auxiliar;

int main(int argc, const char * argv[]) {
    // insert code here...
    nodoRaiz = crearNodo();
    menu();
    return 0;
}

void menu(){
    int opc = 0;
    int clave = 0;
    printf("\nArbol B\n");
    printf("1. Insertar\n");
    printf("2. Obtener Minimo y Maximo\n");
    printf("3. Buscar Clave\n");
    printf("4. Mostrar Arbol\n");
    printf("5. Salir\n");
    printf("Digite una opcion\n");
    scanf("%d", &opc);
    switch (opc) {
        case 1:
            printf("Escribe un valor entero\n");
            scanf("%d", &clave);
            insercion(nodoRaiz, clave);
            break;
        case 2:
            printf("Valor minimo: %d\n", obtenerMinimo(nodoRaiz));
            printf("Valor maximo: %d\n", obtenerMaximo(nodoRaiz));
            break;
        case 3:
            printf("Escribe un valor entero a buscar\n");
            scanf("%d", &clave);
            busqueda(nodoRaiz, clave);
            break;
        case 4:
            mostrarArbol(nodoRaiz, 0);
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Selecciona una opcion\n");
            menu();
            break;
    }
    menu();
}



//operaciones
/*
 Busqueda(Valor, nodo)
 Busqueda, Insercion, Borrado, Recorrido, Division, Reestructurar
 (Suprimir, buscar, insertar)
 */

int busqueda(nodo *nodo, int valor){
    int i = 0;
    while((i < nodo->numeroClaves)&&(nodo->claves[i] <= valor)){
        if((i < nodo->numeroClaves)&&(nodo->claves[i] == valor)){
            printf("Valor %d encontrado", valor);
            return i;
        }
        i++;
    }
    if(esHoja(nodo)){
        printf("No se encontro el valor en el arbol");
        return -1;
    }
    else{
        return busqueda(nodo->hijos[i], valor);
    }
}

int esHoja(nodo *nodo){
    return nodo->numeroHijos == 0;
}//i = i+1

//funcion primitiva que guarda los elementos ordenadamente
void insercionOrdenada(nodo *nodox, nodo *hijoDerecho, int valor){
    int pivote = 0;//posicion del pivote
    if(nodox->numeroClaves >0){
        while(nodox->claves[pivote] < valor && nodox->claves[pivote] != 0){
            pivote++;
        }
        //recorremos los valores
        for (int i = nodox->numeroClaves-1; i>=pivote; i--) {
            nodox->claves[i+1] = nodox->claves[i];
        }
        //recorremos los hijos
        for (int i = nodox->numeroHijos-1; i>=pivote; i--) {
            if(i+1 < N){
                nodox->hijos[i+1] = nodox->hijos[i];
            }
            else{
                auxiliar = hijoDerecho;//guarda el hijo derecho perdido
            }
        }
        //insertamos el valor en la posicion pivote
    }
    nodox->claves[pivote] = valor;
    if(pivote+1 < N){
        nodox->hijos[pivote+1] = hijoDerecho;//guardar ultimo hijo derecho para que no se pierda
    }
    nodox->numeroClaves++;
    if(!esHoja(nodox)){
        nodox->numeroHijos++;
    }
}

nodo *insercion(nodo *nodox, int valor){
    if(esHoja(nodox)){
        if(buscarHijo(nodox, valor) != -1){
            insercionOrdenada(nodox, NULL, valor);
        }
        else{
            return NULL;
        }
    }
    else{
        int i = buscarHijo(nodox, valor);
        if(i == -1){
            printf("Abortando insercion");
            return NULL;
        }
        nodo *nuevo = insercion(nodox->hijos[i], valor);
        if(nuevo != NULL){
            int pivote = nuevo->claves[0];
            insercionOrdenada(nodox, nuevo, pivote);
            //quitar la clave 0 de nuevo
            //int i=1; i<N; i++
            for (i=1; i<N; i++) {
                nuevo->claves[i-1] = nuevo->claves[i];
            }
            nuevo->claves[N-1] = 0;
            nuevo->numeroClaves--;
        }
    }
    
    if(nodox->numeroClaves > N-1){
        return division(nodox);
    }
    else{
        return NULL;
    }
}

nodo *division(nodo *nodox){
    //fabricar un nuevo nodo
    //pivote es punto medio
    if(nodox == nodoRaiz){
        return divisionEnRaiz(nodox);
    }
    else{
        nodo *nuevoNodo = crearNodo();
        for (int i=redondear(N,2)-1, j=0; i<N; i++, j++) {
            nuevoNodo->claves[j] = nodox->claves[i];
            nuevoNodo->numeroClaves++;
            nodox->claves[i] = 0;//borramos los valores de las claves
            nodox->numeroClaves--;
            if(!esHoja(nodox)){//transfermos los punteros derechos si no es hoja
                nuevoNodo->hijos[j+1] = nodox->hijos[i+1];
                nodox->hijos[i+1] = NULL;//borramos apuntadores
            }
        }
        if(!esHoja(nodox)){
            nuevoNodo->numeroHijos = 0;// el nuevo nodo es hojo
        }
        return nuevoNodo;
    }
}

nodo *divisionEnRaiz(nodo *nodox){
    nodo *nuevoNodo = crearNodo();
    //el valor del pivote sera la nueva raiz,
    //las claves a la izquierda del pivote seran los hijos menores(nodox)
    //las claves a la derecha del pivote seran los hijos mayores(nuevoNodo)
    nodo *nuevoNodoRaiz = crearNodo();
        for (int i=redondear(N, 2)-1, j=0; i<N; i++, j++) {
            nuevoNodo->claves[j] = nodox->claves[i];
            nuevoNodo->numeroClaves++;
            nodox->numeroClaves--;
            nodox->claves[i] = 0;//borramos los valores de las claves
            if(!esHoja(nodox)){//transfermos los punteros derechos si no es hoja
                nuevoNodo->hijos[j] = nodox->hijos[i+1];//AQUI HAY ERROR(arreglado)
                nuevoNodo->numeroHijos++;
                nodox->numeroHijos--;
                if(i+1 < N){
                    nodox->hijos[i+1] = NULL;
                }
                //printf("numero de hijos: %d", nodox->numeroHijos);
            }
        }
        if(auxiliar != NULL){
            nuevoNodo->hijos[1] = auxiliar;
            auxiliar = NULL;
        }
        nuevoNodoRaiz->claves[0] = nuevoNodo->claves[0];//ponemos el pivote en la raiz y recorremos
        nuevoNodoRaiz->numeroClaves++;
        nuevoNodo->numeroClaves--;
        for (int i=1; i<N; i++) {
            nuevoNodo->claves[i-1] = nuevoNodo->claves[i];
        }
        nuevoNodo->claves[N-1] = 0;
        //ponemos los nodos hijos
        nuevoNodoRaiz->hijos[0] = nodox;
        nuevoNodoRaiz->numeroHijos++;
        nuevoNodoRaiz->hijos[1] = nuevoNodo;
        nuevoNodoRaiz->numeroHijos++;
        nodoRaiz = nuevoNodoRaiz;
        return nuevoNodoRaiz;
    
}

nodo *crearNodo(){
    nodo *nuevoNodo;
    if((nuevoNodo = (nodo *)malloc(sizeof(nodo))) == NULL){
        printf("No se pudo asignar nodo a la memoria");
    }
    nuevoNodo->numeroClaves = 0;
    nuevoNodo->numeroHijos = 0;
    return nuevoNodo;
}

int buscarHijo(nodo *nodox, int valor){
    int i = 0;
    while((i < nodox->numeroClaves)&&(nodox->claves[i] <= valor)){
        if((i < nodox->numeroClaves)&&(nodox->claves[i] == valor)){
            printf("Valor duplicado");
            return -1;
        }
        i++;
    }
    return i;
}

int redondear(int a, int b){
    return (a / b) + ((a % b) != 0);
}

void mostrarArbol(nodo *nodox, int tabuladores){
    if (!esHoja(nodox)) {
        for (int i = 1; i <= tabuladores; i++){
            printf(" 1");
        }
        printf("|");
        for (int i = 0; i < nodox->numeroClaves; i++){
            printf("%d ", nodox->claves[i]);
        }
        printf("|\n");
        for (int i = 0; i < nodox->numeroHijos; i++){
            mostrarArbol(nodox->hijos[i], tabuladores + 2);
        }
        
                    
    }
    else{
        printf("|");
        for (int i = 0; i < nodox->numeroClaves; i++){
            printf("%d ", nodox->claves[i]);
        }
        printf("|\t");
    }
}

int obtenerMinimo(nodo *nodox){
    int minimo;
    if(nodox != NULL){
        if(esHoja(nodox)){
            minimo = nodox->claves[0];
        }
        else{
            minimo = obtenerMinimo(nodox->hijos[0]);
        }
        return minimo;
    }
    return 0;
}

int obtenerMaximo(nodo *nodox){
    int maximo;
    if(nodox != NULL){
        if(esHoja(nodox)){
            maximo = nodox->claves[nodox->numeroClaves-1];
        }
        else{
            maximo = obtenerMaximo(nodox->hijos[nodox->numeroHijos-1]);
        }
        return maximo;
    }
    return 0;
}
