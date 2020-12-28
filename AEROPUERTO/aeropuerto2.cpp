#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <conio.h>

typedef struct nodo{
    struct nodo *anterior;
    char destino[50];
    char compania[50];
    int pasajeros;
    int horas;
    int minutos;
    struct nodo *siguiente;
}Nodo;

typedef struct lista{
    Nodo *raiz;
}Lista;

void imprimirLista(Lista *lista);
Nodo *crearNodo(char destino[], char compania[], int pasajeros, int horas, int minutos);
Lista *crearLista(void);
void insertarAlFinal(Lista *lista, Nodo *nuevoNodo);
int listaVacia(Lista * lista);
void menu(void);
int obtenerTamanoLista(Lista *lista);
void borrar(Lista *lista, int posicion);
Nodo escanearVuelo(void);
int checarSalidas(Lista *lista, int horas, int minutos);
void contadorTiempo(void);

Lista *listax;
int segundos, minutos, horas;

int main(int argc, const char * argv[]) {
    listax = crearLista();
    time_t tiempo;
	struct tm * tiempoinfo;
	time (&tiempo);
	tiempoinfo = localtime (&tiempo);
    horas = tiempoinfo->tm_hour;
    minutos = tiempoinfo->tm_min;
    segundos = 0;
    printf("%d : %d: %d\n", horas, minutos, segundos);
    contadorTiempo();
    return 0;
}

void menu(){
    int opc = 0;
    printf("\nOpciones\n");
    printf("1. Agregar un vuelo\n");
    printf("2. Salir\n");
    printf("Digite una opcion\n");
    scanf("%d", &opc);
    Nodo vuelox;
    switch (opc) {
        case 1:
            vuelox = escanearVuelo();
            insertarAlFinal(listax, crearNodo(vuelox.destino, vuelox.compania, vuelox.pasajeros, vuelox.horas, vuelox.minutos));
            break;
        case 2:
            exit(0);
            break;
        default:
            printf("Selecciona una opcion\n");
            menu();
            break;
    }
    //menu();
}

Nodo escanearVuelo(){
    Nodo vuelox;
    printf("Ingrese el destino del vuelo: ");
    scanf(" %s", vuelox.destino);
    printf("Ingrese la compania: ");
    scanf(" %s", vuelox.compania);
    printf("\nEscribe la cantidad de pasajeros del vuelo ");
    scanf(" %i", &vuelox.pasajeros);
    printf("\nEscribe la hora de partida ");
    scanf(" %i", &vuelox.horas);
    printf("\nEscribe los minutos de la partida ");
    scanf(" %i", &vuelox.minutos);
    return vuelox;
}

void contadorTiempo(){
    menu();
    while(!_kbhit()){
        if(segundos == 60) {
            minutos++;
            segundos = 0;
            if(minutos == 60){
                minutos = 0;
                horas++;
            }
        }
        int posicion = checarSalidas(listax, horas, minutos);
        if(posicion>0){
            borrar(listax, posicion);
            printf("se borro %d \n", posicion);
        }
        system("cls");
        printf("Vuelos disponibles:\n");
        imprimirLista(listax);
		printf("%d : %d: %d\n", horas, minutos, segundos);
		printf("Presiona una tecla para desplegar el menu\n");
        segundos++;
        sleep(1);
    }
    contadorTiempo();
}

int checarSalidas(Lista *lista, int horas, int minutos){
    Nodo *auxiliar = lista->raiz;
    int i=0;
    while (auxiliar != NULL) {
        i++;
        if(auxiliar->horas == horas && auxiliar->minutos == minutos){
            return i;
        }
        auxiliar = auxiliar->siguiente;
    }
    return -1;
}

//funciones de la listas -----------------------------------------------------

Lista *crearLista(){//dinamico
    Lista *lista;
    if((lista = (Lista *)malloc(sizeof(Lista))) == NULL){
        printf("No se pudo asignar lista a la memoria");
    }
    lista->raiz = NULL;
    return lista;
}


//crea los nodos que van dentro de la lista, la asigna el valor
//de su dato y por defecto pone los apuntadores anterior y siguiente a NULL
Nodo *crearNodo(char destino[], char compania[], int pasajeros, int horas, int minutos){
    Nodo *nodo;
    if((nodo = (Nodo *)malloc(sizeof(Nodo))) == NULL){
        printf("No se pudo asignar nodo a la memoria");
    }
    nodo->anterior = NULL;
    strncpy(nodo->destino, destino, 50);
    strncpy(nodo->compania, compania, 50);
    nodo->pasajeros = pasajeros;
    nodo->horas = horas;
    nodo->minutos= minutos;
    nodo->siguiente = NULL;
    return nodo;
}

void insertarAlFinal(Lista *lista, Nodo *nuevoNodo){//por default inserta al ultimo
    if(lista->raiz==NULL){//primera insercion
        nuevoNodo->anterior = NULL;
        nuevoNodo->siguiente = NULL;
        lista->raiz = nuevoNodo;
    }
    else{
        Nodo *ultimoNodo = lista->raiz;//llegara al ultimo nodo de la lista
        while(ultimoNodo->siguiente != NULL){
            ultimoNodo = ultimoNodo->siguiente;
        }
        nuevoNodo->anterior = ultimoNodo;
        nuevoNodo->siguiente = NULL;
        ultimoNodo->siguiente = nuevoNodo;
    }
}

void borrar(Lista *lista, int posicion){
    int tamano = obtenerTamanoLista(lista);
    if(posicion > 0 && posicion <= tamano){
        if(posicion == 1){//operando con la raiz
            if(posicion == tamano){//unico elemento en la lista
                free(lista->raiz);
                lista->raiz = NULL;
                return;
            }
            Nodo *nodoBorrar = lista->raiz;
            lista->raiz = lista->raiz->siguiente;
            lista->raiz->anterior = NULL;
            free(nodoBorrar);
        }
        else{
            Nodo *auxiliar = lista->raiz;
            int i;
            for (i = 1; i<posicion; i++) {
                auxiliar = auxiliar->siguiente;
            }
            Nodo *nodoBorrar = auxiliar;
            Nodo *anterior = auxiliar->anterior;//izquierda
            auxiliar = auxiliar->siguiente;//derecha
            anterior->siguiente = auxiliar;
            auxiliar->anterior = anterior;
            free(nodoBorrar);
        }
    }
    
}

void imprimirLista(Lista *lista){
    Nodo *auxiliar = lista->raiz;
    int i = 1;
    if(!listaVacia(lista)){
        printf(" \tDestino\tCompania\tPasajeros\tSalida\n");
        while (auxiliar != NULL) {
            printf("%i\t%s\t%s\t%d\t%d:%d \n", i, auxiliar->destino, auxiliar->compania, auxiliar->pasajeros, auxiliar->horas, auxiliar->minutos);
            i++;
            auxiliar = auxiliar->siguiente;
        }
        printf("\n");
    }
}

int obtenerTamanoLista(Lista *lista){
    Nodo *auxiliar = lista->raiz;
    int i = 0;
    if(!listaVacia(lista)){
        while (auxiliar != NULL) {
            i++;
            auxiliar = auxiliar->siguiente;
        }
    }
    return i;
}

int listaVacia(Lista * lista){
    return lista->raiz == NULL;
}
