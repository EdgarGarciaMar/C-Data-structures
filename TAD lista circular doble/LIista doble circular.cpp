#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    int dato;
    struct nodo *anterior;
    struct nodo *siguiente;
}Nodo;

typedef struct lista{
    Nodo *raiz;
}Lista;

void imprimirLista(Lista *lista);
Nodo *crearNodo(int dato);
Lista *crearLista(void);
void insertarAlFinal(Lista *lista, int dato);
int listaVacia(Lista * lista);
void menu(void);
int obtenerTamanoLista(Lista *lista);
void borrar(Lista *lista, int posicion);
void insertarAntes(Lista *lista, int dato, int posicion);
void insertarDespues(Lista *lista, int dato, int posicion);
int buscar(Lista *lista, int dato);
int buscarKesimo(Lista *lista, int posicion);

Lista *listax;
int main(int argc, const char * argv[]) {
    listax = crearLista();
    menu();
    return 0;
}

void menu(){
    int opc = 0;
    printf("Valores de la lista:\n");
    imprimirLista(listax);
    printf("\nOpciones\n");
    printf("1. Insertar\n");
    printf("2. Insertar antes\n");
    printf("3. Insertar despues\n");
    printf("4. Buscar\n");
    printf("5. Buscar k esimo\n");
    printf("6. Borrar\n");
    printf("7. Salir\n");
    printf("Digite una opcion\n");
    scanf("%d", &opc);
    int valor=0;
    int posicion=0;
    switch (opc) {
        case 1:
            printf("Escribe el valor del dato\n");
            scanf("%d", &valor);
            insertarAlFinal(listax, valor);
            break;
        case 2:
            printf("Escribe el valor del dato\n");
            scanf("%d", &valor);
            printf("Escribe la posicion\n");
            scanf("%d", &posicion);
            insertarAntes(listax, valor, posicion);
            break;
        case 3:
            printf("Escribe el valor del dato\n");
            scanf("%d", &valor);
            printf("Escribe la posicion\n");
            scanf("%d", &posicion);
            insertarDespues(listax, valor, posicion);
            break;
        case 4:
            printf("Escribe el valor del dato a buscar\n");
            scanf("%d", &valor);
            posicion = buscar(listax, valor);
            if(posicion != -1){
                printf("El dato %i se encuentra en la posicion %i\n", valor, posicion);
            }
            else{
                printf("El dato no esta en la lista\n");
            }
            break;
        case 5:
            printf("Escribe la posicion del dato a buscar\n");
            scanf("%d", &posicion);
            valor = buscarKesimo(listax, posicion);
            if(valor != -1){
                printf("En la posicion %i se encuentra el valor %i\n", posicion, valor);
            }
            else{
                printf("La posicion no esta en la lista\n");
            }
            break;
        case 6:
            printf("Escribe la posicion del nodo que deseas borrar\n");
            scanf("%d", &valor);
            borrar(listax, valor);
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Selecciona una opcion\n");
            menu();
            break;
    }
    menu();
}

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
Nodo *crearNodo(int dato){
    Nodo *nodo;
    if((nodo = (Nodo *)malloc(sizeof(Nodo))) == NULL){
        printf("No se pudo asignar nodo a la memoria");
    }
    nodo->dato = dato;
    nodo->anterior = NULL;
    nodo->siguiente = NULL;
    return nodo;
}

void insertarAlFinal(Lista *lista, int dato){//por default inserta al ultimo
    Nodo *nuevoNodo = crearNodo(dato);
    if(lista->raiz==NULL){//primera insercion
        nuevoNodo->anterior = nuevoNodo;
        nuevoNodo->siguiente = nuevoNodo;
        lista->raiz = nuevoNodo;
    }
    else{
        Nodo *ultimoNodo = lista->raiz->anterior;
        nuevoNodo->siguiente = lista->raiz;
        nuevoNodo->anterior = ultimoNodo;
        lista->raiz->anterior = nuevoNodo;
        ultimoNodo->siguiente = nuevoNodo;
    }
}

void insertarAntes(Lista *lista, int dato, int posicion){
    int tamano = obtenerTamanoLista(lista);
    if(posicion > 0 && posicion <= tamano){
        Nodo *nuevoNodo = crearNodo(dato);
        if(posicion == 1){//operando con la raiz
            Nodo *ultimo = lista->raiz->anterior;
            Nodo *exraiz =lista->raiz;
            nuevoNodo->anterior = ultimo;
            nuevoNodo->siguiente = exraiz;
            lista->raiz = nuevoNodo;
            ultimo->siguiente = lista->raiz;
            exraiz->anterior= lista->raiz;
        }
        else{
            Nodo *auxiliar = lista->raiz;
            for (int i = 1; i<posicion-1; i++) {
                auxiliar = auxiliar->siguiente;
            }
            Nodo *nodoAnterior = auxiliar;
            auxiliar = auxiliar->siguiente;
            Nodo *nodoSiguiente = auxiliar;
            nuevoNodo->anterior = nodoAnterior;
            nuevoNodo->siguiente = nodoSiguiente;
            nodoAnterior->siguiente = nuevoNodo;
            nodoSiguiente->anterior = nuevoNodo;
        }
    }
    else{
        printf("Elige una posicion correcta\n");
    }
}

void insertarDespues(Lista *lista, int dato, int posicion){
    int tamano = obtenerTamanoLista(lista);
    if(posicion > 0 && posicion <= tamano){
        if(posicion == obtenerTamanoLista(lista)){//operando con ultimo nodo
            insertarAlFinal(lista, posicion);
        }
        else{
            Nodo *nuevoNodo = crearNodo(dato);
            Nodo *auxiliar = lista->raiz;
            for (int i = 1; i<posicion; i++) {
                auxiliar = auxiliar->siguiente;
            }
            Nodo *nodoAnterior = auxiliar;
            auxiliar = auxiliar->siguiente;
            Nodo *nodoSiguiente = auxiliar;
            nuevoNodo->anterior = nodoAnterior;
            nuevoNodo->siguiente = nodoSiguiente;
            nodoAnterior->siguiente = nuevoNodo;
            nodoSiguiente->anterior = nuevoNodo;
        }
    }
    else{
        printf("Elige una posicion correcta\n");
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
            Nodo *ultimo = lista->raiz->anterior;
            lista->raiz = lista->raiz->siguiente;
            ultimo->siguiente = lista->raiz;
            lista->raiz->anterior = ultimo;
            free(nodoBorrar);
        }
        else{
            Nodo *auxiliar = lista->raiz;
            for (int i = 1; i<posicion-1; i++) {
                auxiliar = auxiliar->siguiente;
            }
            Nodo *nodoBorrar = auxiliar;
            Nodo *anterior = auxiliar->anterior;
            auxiliar = auxiliar->siguiente;
            anterior->siguiente = auxiliar;
            auxiliar->anterior = anterior;
            free(nodoBorrar);
        }
    }
    
}

int buscar(Lista *lista, int dato){
    Nodo *auxiliar = lista->raiz;
    int i = 1;
    if(!listaVacia(lista)){
        do{
            if(dato == auxiliar->dato){
                return i;
            }
            auxiliar = auxiliar->siguiente;
            i++;
        }while(auxiliar != lista->raiz);
    }
    return -1;
}

int buscarKesimo(Lista *lista, int posicion){
    Nodo *auxiliar = lista->raiz;
    int i = 1;
    if(!listaVacia(lista)){
        do{
            if(posicion == i){
                return auxiliar->dato;
            }
            auxiliar = auxiliar->siguiente;
            i++;
        }while(auxiliar != lista->raiz);
    }
    return -1;
}

void imprimirLista(Lista *lista){
    Nodo *auxiliar = lista->raiz;
    int i = 1;
    if(!listaVacia(lista)){
        printf("Posicion\tValor \n");
        do{
            printf("\t%i\t \t%i \n", i, auxiliar->dato);
            auxiliar = auxiliar->siguiente;
            i++;
        }while(auxiliar != lista->raiz);
        printf("\n");
    }
}

int obtenerTamanoLista(Lista *lista){
    Nodo *auxiliar = lista->raiz;
    int i = 0;
    if(!listaVacia(lista)){
        do{
            auxiliar = auxiliar->siguiente;
            i++;
        }while(auxiliar != lista->raiz);
    }
    return i;
}

int listaVacia(Lista * lista){
    return lista->raiz == NULL;
}
