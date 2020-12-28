#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef int QueveEntry;
	
QueveEntry dato[N];
	int rear= 0;
	int front= 0;

void enqueve(void);
void menu();
void delete1(void);
void display(void);


main(){
	
menu();
	
}

void menu(){

int opc;
	
	printf("\t\t\t\t\t---Pila Estatica---\n");
	printf("Seleccione una opcion del menu.\n\n");
	printf("\t1: Agregar a la cola.\n ");
	printf("\t2: Sacar de la cola. \n ");
	printf("\t3: Imprimir la cola. \n");
	printf("\t4: Salir.\n");
	scanf("%d",&opc);
	
	switch(opc){
		case 1://Encolar
		enqueve();
		break;
		case 2://desencolar
		delete1();
		break;
		case 3://imprimir la cola
		display();
		break;
		case 4://salir
		exit(0);
		break;
	
	}
	system("PAUSE");
	system("cls");
	menu();
}

void enqueve(void){
	int t;
	if(rear<N){
	printf("Ingrese el valor: \n");
	scanf("%d",&t);
	dato[rear]=t;
	rear++;
	}
	else{
		printf("Cola llena.\n");
	}
}
void delete1(void){
	int i;
	printf("\n Se elimino: %d  \n",dato[front]);
	dato[front]=0;
	front++;
}
void display(void){
	int i;
	for(i=front; i<=rear; i++){
		printf("\n %d \n",dato[i]);
	}
}


