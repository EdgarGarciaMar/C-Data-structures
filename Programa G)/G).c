//
//  main.c
//  radar
//
//  Created by Caleb on 16/06/20.
//  Copyright © 2020 Caleb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct que almacena las matriculas de los automoviles con el numero de veces que han excedido la velocidad
typedef struct automoviles{
    struct automoviles *anterior;
    char matricula[6];
    int infracciones;
    struct automoviles *siguiente;
}automovil;

//este struct lista será para construir una tabla hash abierta, por si se llegan a dar colisiones
typedef struct lista{
    automovil *raiz;
}lista;

void menu(void);
lista *crearLista(void);
int listaVacia(lista * lista);
automovil *crearNodoAutomovil(char matricula[6], int infracciones);
void insertar(lista *lista, automovil *nuevoAuto);
void imprimirLista(lista *lista);
void reportarAutomovil(void);
void imprimirTabla(void);
int buscar(lista *lista, char matricula[6]);
int obtenerTamanoLista(lista *lista);
void inicializarTabla(void);
void buscarDetalle(int clave, char matricula[6]);
int hash(char matricula[6]);
void borrar(int clave, char matricula[6]);
int obtenerPosicion(lista *lista, char matricula[6]);


//tabla hash abierta
int tamanoTabla = 30;
lista **tabla;

int main(int argc, const char * argv[]) {
    inicializarTabla();
    menu();
    return 0;
}

void menu(){
    int opc = 0;
    char matricula[6];
    int clave;
    printf("\nOpciones\n");
    printf("1. Reportar Automovil\n");
    printf("2. Buscar Automovil\n");
    printf("3. Borrar Automovil\n");
    printf("4. Visualizar Tabla\n");
    printf("5. Salir\n");
    printf("Digite una opcion\n");
    scanf("%d", &opc);
    switch (opc) {
        case 1:
            reportarAutomovil();
            break;
        case 2:
            printf("Escribe la matricula del automovil\n");
            scanf(" %s", matricula);
            clave = hash(matricula);
            buscarDetalle(clave, matricula);
            break;
        case 3:
            printf("Escribe la matricula del automovil a borrar\n");
            scanf(" %s", matricula);
            clave = hash(matricula);
            borrar(clave, matricula);
            break;
        case 4:
            imprimirTabla();
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


/*
 FUNCIONES DE TABLA HASH ABIERTA
 */
//regresa la posicion en donde se encuentra la lista con el automovil
int hash(char matricula[6]){
    //sumamos los primeros tres digitos y los dividimos entre 3;
    int sumaDigitos = ((matricula[0]- '0') + (matricula[1]- '0') + (matricula[2]- '0'))/3;
    //luego sumamos los valores ASCII de cada una de las letras multiplicadas
    int sumaCaracteres = ((int)matricula[3]*2) + ((int)matricula[4]*3) + ((int)matricula[5]*4);
    int clave = (sumaDigitos + sumaCaracteres) % tamanoTabla;
    return clave;
}

void inicializarTabla(){
    tabla = calloc(tamanoTabla, sizeof(lista));
    int i;
    for(i=0; i<tamanoTabla; i++) {
        tabla[i] = crearLista();
    }
}

void reportarAutomovil(){
    char matricula[6];
    printf("Escribe la matricula del automovil\n");
    scanf(" %s", matricula);
    int clave = hash(matricula);
    printf("clave %d\n", clave);
    lista *slot = tabla[clave];
    if(listaVacia(slot)){//el slot no tiene ningun automovil, por lo que se le asigna uno
        insertar(slot, crearNodoAutomovil(matricula, 1));
    }
    else{
        //si el auto ya tiene reporte sumar nuevo reporte, de lo contrario se guarda uno nuevo
        //para eso se debe de buscar si el auto existe
        if(buscar(slot, matricula) < 0){//si es menor a cero significa que es la primera vez que el auto comete una infraccion
            insertar(slot, crearNodoAutomovil(matricula, 1));
        }
    }
}

void imprimirTabla(){
    printf("Tabla de reportes:\n");
    int i;
    for(i=0; i<tamanoTabla; i++) {
        printf("Clave %d", i);
        imprimirLista(tabla[i]);
        printf("\n");
    }
}

/*
 FUNCIONES DE LISTAS (las listas guardan datos de tipo automovil.
 Estas listas van dentro de cada uno de los slots de las tablas hash)
 */

//funcion que crea una lista, estas serviran para inicializar los slots de la tabla hash
lista *crearLista(){
    lista *listax;
    if((listax = (lista *)malloc(sizeof(lista))) == NULL){
        printf("No se pudo asignar lista a la memoria");
    }
    listax->raiz = NULL;
    return listax;
}

//crea los nodos que van dentro de la lista, la asigna el valor
//de su dato y por defecto pone los apuntadores anterior y siguiente a NULL
automovil *crearNodoAutomovil(char matricula[6], int infracciones){
    automovil *autox;
    if((autox = (automovil *)malloc(sizeof(automovil))) == NULL){
        printf("No se pudo asignar nodo a la memoria");
    }
    autox->anterior = NULL;
    strncpy(autox->matricula, matricula, 6);
    autox->infracciones = infracciones;
    autox->siguiente = NULL;
    return autox;
}


//Funcion para insertar automoviles en el slot de la tabla hash, en caso de que haya colision lo guardara en el mismo slot ya que es una tabla hash abierta
void insertar(lista *lista, automovil *nuevoAuto){
    if(lista->raiz==NULL){//
        nuevoAuto->anterior = NULL;
        nuevoAuto->siguiente = NULL;
        lista->raiz = nuevoAuto;
    }
    else{
        automovil *ultimoAuto = lista->raiz;//llegara al ultimo nodo de la lista
        while(ultimoAuto->siguiente != NULL){
            ultimoAuto = ultimoAuto->siguiente;
        }
        nuevoAuto->anterior = ultimoAuto;
        nuevoAuto->siguiente = NULL;
        ultimoAuto->siguiente = nuevoAuto;
    }
}

void borrar(int clave, char matricula[6]){
    lista *lista = tabla[clave];
    int posicion = obtenerPosicion(lista, matricula);
    int tamano = obtenerTamanoLista(lista);
    if(posicion < 0){
        printf("No se encontro la matricula en la tabla");
        return;
    }
    if(posicion > 0 && posicion <= tamano){
        if(posicion == 1){//operando con la raiz
            if(posicion == tamano){//unico elemento en la lista
                free(lista->raiz);
                lista->raiz = NULL;
                printf("Se borro la matricula %s\n:", matricula);
                return;
            }
            automovil *autoBorrar = lista->raiz;
            lista->raiz = lista->raiz->siguiente;
            lista->raiz->anterior = NULL;
            free(autoBorrar);
            printf("Se borro la matricula %s\n:", matricula);
        }
        else{
            automovil *auxiliar = lista->raiz;
            int i;
            for (i = 1; i<posicion; i++) {
                auxiliar = auxiliar->siguiente;
            }
            automovil *autoBorrar = auxiliar;
            automovil *anterior = auxiliar->anterior;//izquierda
            auxiliar = auxiliar->siguiente;//derecha
            anterior->siguiente = auxiliar;
            auxiliar->anterior = anterior;
            free(autoBorrar);
            printf("Se borro la matricula %s\n:", matricula);
        }
    }
    
}

int buscar(lista *lista, char matricula[6]){
    automovil *auxiliar = lista->raiz;
    int i = 1;
    if(!listaVacia(lista)){
        do{
            printf("%s", auxiliar->matricula);
            if(strcmp(matricula, auxiliar->matricula) == 0){//esta dentro de la lista
                printf("Este automovil ya ha excedido la velocidad permitida mas de una vez\n");
                int infraccionesActualizadas = (auxiliar->infracciones)+1;
                auxiliar->infracciones = infraccionesActualizadas;
                printf("Infracciones totales: %d\n", auxiliar->infracciones);
                return i;
            }
            auxiliar = auxiliar->siguiente;
            i++;
        }while(auxiliar != NULL);
    }
    return -1;//no se encuentra dentro de la lista
}

int obtenerPosicion(lista *lista, char matricula[6]){
    automovil *auxiliar = lista->raiz;
    int i = 1;
    if(!listaVacia(lista)){
        do{
            printf("%s", auxiliar->matricula);
            if(strcmp(matricula, auxiliar->matricula) == 0){//esta dentro de la lista
                return i;
            }
            auxiliar = auxiliar->siguiente;
            i++;
        }while(auxiliar != NULL);
    }
    return -1;//no se encuentra dentro de la lista
}

void buscarDetalle(int clave, char matricula[6]){
    lista *lista = tabla[clave];
    automovil *auxiliar = lista->raiz;
    int i = 1;
    if(!listaVacia(lista)){
        do{
            printf("%s", auxiliar->matricula);
            if(strcmp(matricula, auxiliar->matricula) == 0){//esta dentro de la lista
                printf("Datos del Automovil: \n");
                printf("Matricula:%s\tInfracciones:%d\t", auxiliar->matricula, auxiliar->infracciones);
                return;
            }
            auxiliar = auxiliar->siguiente;
            i++;
        }while(auxiliar != NULL);
    }
    printf("La matricula del automovil no existe \n");
    return;//no se encuentra dentro de la lista
}

int obtenerTamanoLista(lista *lista){
    automovil *auxiliar = lista->raiz;
    int i = 0;
    if(!listaVacia(lista)){
        while (auxiliar != NULL) {
            i++;
            auxiliar = auxiliar->siguiente;
        }
    }
    return i;
}

int listaVacia(lista * lista){
    return lista->raiz == NULL;
}

void imprimirLista(lista *lista){
    automovil *auxiliar = lista->raiz;
    int i = 1;
    if(!listaVacia(lista)){
        while (auxiliar != NULL) {
            printf("|   Matricula:%s\tInfracciones:%d\t", auxiliar->matricula, auxiliar->infracciones);
            i++;
            auxiliar = auxiliar->siguiente;
        }
        printf("\n");
    }
}

