//
//  main.c
//  evaluadorPosfija
//
//  Created by Caleb on 10/02/20.
//  Copyright © 2020 Caleb. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int numero;
    struct node *siguiente;
}nodo;

typedef struct stack{
    nodo *tope;
}pila;

nodo *hacerNodo(int item);
void push(int item, pila *p);
int pop(pila *p);
int pilaVacia(pila *p);
void imprimirPila(pila *p);
void menu(void);

void conversion(void);
int esNumero(char caracter);
int hacerOperacion(int x, int y, char operacion);

pila numeros;


int main(int argc, const char * argv[]) {
    conversion();
}

void conversion(){
    char expresion[50];
    printf("Escribe la expresion posfija\n");
    scanf("%s", expresion);

    int i;
    for (i=0; expresion[i] != 0; i++) {
        if(esNumero(expresion[i])){
            int valor = (int)expresion[i]-48;
            push(valor, &numeros);
        }
        else{
            int x = pop(&numeros);
            int y = pop(&numeros);
            push(hacerOperacion(x, y, expresion[i]), &numeros);
        }
    }
    printf("Resultado: ");
    imprimirPila(&numeros);
}

int esNumero(char caracter){
    switch (caracter) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 0;
            break;
        default:
            return 1;
            break;
    }
}

int hacerOperacion(int x, int y, char operacion){
    int resultado = 0;
    switch (operacion) {
        case '+':
            resultado = x+y;
            break;
        case '-':
            resultado = x-y;
            break;
        case '*':
            resultado = x*y;
            break;
        case '/':
            resultado = x/y;
            break;
        default://falta exponente
            break;
    }
    return resultado;
}


nodo *hacerNodo(int item){
    nodo *punteroNodo;
    if((punteroNodo = (nodo*)malloc(sizeof(nodo))) == NULL){
        printf("Error, no se pudo asignar memoria\n");
    }
    else{
        punteroNodo->numero = item;
        punteroNodo->siguiente = NULL;
    }
    return punteroNodo;
}

void push(int item, pila *p){
    nodo *punteroNodo = hacerNodo(item);
    if(punteroNodo == NULL){
        printf("Error, se intento ingresar un nodo que no existe\n");
    }
    else{
        punteroNodo->siguiente = p->tope;
        p->tope=punteroNodo;
    }
}

int pop(pila *p){
    if(pilaVacia(p)){
        printf("Error la pila esta vacia\n");
        return 0;
    }
    else{
        nodo *antiguo = p->tope;
        int valor = antiguo->numero;
        p->tope = antiguo->siguiente;
        free(antiguo);
        return valor;
    }
}

int pilaVacia(pila *p){
    return p->tope == NULL;
}

void imprimirPila(pila *p){
    if(pilaVacia(p)){
        printf("La pila esta vacia\n");
    }else{
        nodo *auxiliar = p->tope;
        int valor;
        while(auxiliar->siguiente != NULL){
            valor = auxiliar->numero;
            printf("%d\n", valor);
            auxiliar = auxiliar->siguiente;
        }
        valor = auxiliar->numero;//ultimo valor
        printf("%d\n\n", valor);
    }
    
}
