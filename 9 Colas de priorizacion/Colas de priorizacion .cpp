#include <stdio.h>
#include <stdlib.h>

typedef int EntradaCola;

typedef struct nodo{
    EntradaCola dato;
    struct nodo *siguiente;
}Nodo;

typedef struct cola{
    Nodo *frente;
    Nodo *final;
}Cola;

void menu(void);
void encolar(EntradaCola entrada, Cola *cola);
EntradaCola desencolar(Cola *cola);
EntradaCola obtenerFrente(Cola *cola);
void imprimirCola(Cola *cola);
void insertar(void);
EntradaCola deleteMin(Cola * cola);
EntradaCola deleteMax(Cola *cola);
void ordenarAscendente(void);
void ordenarDescendente(void);
void liberarNodosDeCola(Cola *cola, Cola *colaAuxiliar);
void limpiarPantalla(void);

Cola colita;
Cola colaAuxiliar;


int main(int argc, const char * argv[]) {
    printf("Colas de Prioridad\n");
    menu();
    return 0;
}

void menu(){
    int opc = 0;
    printf("Valores de la cola:\n");
    imprimirCola(&colita);
    printf("\nOpciones\n");
    printf("1. Insertar\n");
    printf("2. Ordenar en prioridad ascendente\n");
    printf("3. Ordenar en prioridad descendente\n");
    printf("4. Salir\n");
    printf("Digite una opcion\n");
    scanf("%d", &opc);

    switch (opc) {
        case 1:
            insertar();
            limpiarPantalla();
            break;
        case 2:
            limpiarPantalla();
            ordenarAscendente();
            break;
        case 3:
            limpiarPantalla();
            ordenarDescendente();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Selecciona una opcion\n");
            menu();
            break;
    }
    menu();
}


void insertar(){
    EntradaCola entrada;
    printf("Ingresa el valor de entrada\n");
    scanf("%d", &entrada);
    encolar(entrada, &colita);
}

EntradaCola deleteMin(Cola * cola){//ascendente
    if(cola->frente == NULL){
        //printf("La cola esta vacia\n");
        return -1;
    }
    Nodo *auxiliar = cola->frente;
    Nodo *borrar = auxiliar;
    EntradaCola menor = auxiliar->dato;
    while (auxiliar != NULL) {
        auxiliar = auxiliar->siguiente;
        if(auxiliar != NULL){
            if(menor >= 0 && (auxiliar->dato) >= 0){
                if(!(menor <= auxiliar->dato) ){
                    menor = auxiliar->dato;
                    borrar = auxiliar;
                }
            }
            if(menor == -1){
                menor = auxiliar->dato;
                borrar = auxiliar;
            }
                
        }
    }
    borrar->dato = -1;
    return menor;
}

EntradaCola deleteMax(Cola *cola){//descendente
    if(cola->frente == NULL){
        //printf("La cola esta vacia\n");
        return -1;
    }
    Nodo *auxiliar = cola->frente;
    Nodo *borrar = auxiliar;
    EntradaCola mayor = auxiliar->dato;
    while (auxiliar != NULL) {
        auxiliar = auxiliar->siguiente;
        if(auxiliar != NULL){
            if(mayor >= 0 && (auxiliar->dato) >= 0){
                if(!(mayor >= auxiliar->dato) ){
                    mayor = auxiliar->dato;
                    borrar = auxiliar;
                }
            }
            if(mayor == -1){
                mayor = auxiliar->dato;
                borrar = auxiliar;
            }
                
        }
    }
    borrar->dato = -1;
    return mayor;
}

void ordenarAscendente(){
    EntradaCola entrada = deleteMin(&colita);
    while (entrada != -1) {
        encolar(entrada, &colaAuxiliar);
        entrada = deleteMin(&colita);
    }
    liberarNodosDeCola(&colita, &colaAuxiliar);
    printf("Orden ascendente\n");
}

void ordenarDescendente(){
    EntradaCola entrada = deleteMax(&colita);
    while (entrada != -1) {
        encolar(entrada, &colaAuxiliar);
        entrada = deleteMax(&colita);
    }
    liberarNodosDeCola(&colita, &colaAuxiliar);
    printf("Orden descendente\n");
}

void encolar(EntradaCola entrada, Cola *cola){
    Nodo *nuevoNodo;
    if((nuevoNodo = (Nodo *)malloc(sizeof(Nodo))) == NULL){
        printf("Error, no se pudo asignar memoria\n");
    }
    else{
        nuevoNodo->dato = entrada;
        nuevoNodo->siguiente = NULL;
        
        if(cola->frente == NULL && cola->final == NULL){
            cola->frente = nuevoNodo;
            cola->final = nuevoNodo;
            return;
        }
        else{
            cola->final->siguiente = nuevoNodo;
            cola->final = nuevoNodo;
        }
        
    }
}

EntradaCola desencolar(Cola *cola){
    Nodo *auxiliar = cola->frente;// nodo que esta en frente
    if(cola->frente == NULL){
        //printf("La cola esta vacia");
        return -2;
    }
    if(cola->frente == cola->final){
        cola->frente = NULL;
        cola->final = NULL;
    }
    else{
        cola->frente = cola->frente->siguiente;
    }
    EntradaCola valor = auxiliar->dato;
    free(auxiliar);
    return valor;
}

EntradaCola obtenerFrente(Cola *cola){
    if(cola->frente == NULL){
        //printf("La cola esta vacia");
        return -1;
    }
    return cola->frente->dato;
}

void imprimirCola(Cola *cola){
    Nodo *auxiliar = cola->frente;
    while (auxiliar != NULL) {
        printf("%i\t", auxiliar->dato);
        auxiliar = auxiliar->siguiente;
    }
    printf("\n");
}

void liberarNodosDeCola(Cola *cola, Cola *colaAuxiliar){
    while ((desencolar(cola)) != -2) {
    }
    EntradaCola entrada = desencolar(colaAuxiliar);
    while (entrada != -2) {
        encolar(entrada, cola);
        entrada = desencolar(colaAuxiliar);
    }
}

void limpiarPantalla(){
    system("cls");
}
