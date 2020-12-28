#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 10

typedef int stackEntry;

typedef struct stack{
int top;
stackEntry entry [MAXSTACK];
}stack;

stack pila;

void menu();
int stackempty(stack *s);
int stackfull(stack *s);
void createstack (stack *s);
void push (stackEntry item, stack *s);
void pop(stackEntry *item, stack *s);
void imprimirStack(void);
stackEntry ultimoElemento(stack *s);


int main(int argc, char const *argv[])
{
    createstack(&pila);
	menu();
    return 0;
}



void menu(){
	int opc=0;
	stackEntry dato;
	printf("----Pilas.----\n");
	printf("Seleciones una opcion del menu.\n");
	printf("1: Hacer un Push.\n");
	printf("2: Hacer un Pop.\n");
	printf("3: Comprobar si la pila esta vacia.\n");
	printf("4: Comprobar si la pila esta llena.\n");
	printf("5: Comprobar el ultimo elemento de la pila.\n");
	printf("6: Salir.\n");
	scanf("%i",&opc);
	
	switch (opc)
	{
	    case 1://Push
	    dato = escaneardato();
	    push(dato, &pila);
	    imprimirStack();
	    break;
	    case 2://Pop
	    //dato = escaneardato();
		pop(&dato, &pila);
		imprimirStack();
	    break;
	    case 3://Pila vacia
	    if(stackempty(&pila)){
	    	printf("La pila esta vacia\n");
		}
		else{
			printf("La pila no esta vacia\n");
		}
	    break;
	    case 4://pila llena
	    if(stackfull(&pila)){
	    	printf("La pila esta llena\n");
		}
		else{
			printf("La pila no esta llena\n");
		}
	    break;
	    case 5://Comprobar el ultimo elemento de la pila
	    printf("El ultimo elemento de la pila es : %d", ultimoElemento(&pila));
	    break;
	    case 6:
	    printf("Hasta la procccsssiimaaaaaaaaa");
	    exit(0);
	    break;
	    default:
	    	printf("Escriba una opcion del menu");
	    break;
	}
	
	system("pause");
	system("cls");
	menu();
}

int stackempty(stack *s){
    return s->top<=0;
}

int stackfull(stack *s){
    return s->top>=MAXSTACK;
}

void createstack (stack *s){
    s->top=0;
}

void push (stackEntry item, stack *s){
    if(stackfull(s)){
        printf("\nError, la pila esta llena\n");
    }
    else
    {
        s->entry[s->top++]=item;
    }
}

void pop(stackEntry *item, stack *s){
    if(stackempty(s)){
        printf("Error,la pila esta vacia");
    }
    else
    {
        *item=s->entry[--(s->top)];
    }
}

stackEntry  escaneardato(){
	stackEntry dato;
	printf("Escribe un dato:\n");
    scanf("%d", &dato);
    return dato;
}

void imprimirStack(){
	printf("\n\n");
	if(pila.top == MAXSTACK){
	 printf(" <-- tope\n");
	}
	int i;
	for(i=MAXSTACK-1; i>=0; i--){
		printf("%d", pila.entry[i]);
		if(i == pila.top){
			printf("<-- tope");
		}
		printf("\n");
	}
	
	printf("Tope: %d\n", pila.top);
}

stackEntry ultimoElemento(stack *s){
	if(s->top == 0){
		return 0;
	}
    return s->entry[s->top -1];
}


