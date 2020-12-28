#include <stdio.h>
#include <stdlib.h>

typedef int QueveEntry;



typedef struct node{
	QueveEntry data;
	struct node *next;
}Node;


Node *front =NULL;
Node *rear =NULL;



void menu();
void enqueve(QueveEntry x);
QueveEntry  escaneardato();
void printf(void);
void dequeve(void);
QueveEntry front1(void);




main(){
	menu();
	return 0;
}





void menu(){
	int opc;
	QueveEntry dato;
	printf("\n");
	printf("\t\t\t\t\t\t---Cola dinamica---\n\n");
	printf("Seleccione una opcion del menu\n");
	printf("1: Enqueve\n");
	printf("2: Dequeve\n");
	printf("3: Imprimir la cola\n");
	printf("4: Comprobar el frente\n");
	printf("5: Salir\n");
	scanf("%d",&opc);
	switch(opc){
		case 1://Encolar
		dato = escaneardato();
		enqueve(dato);
		break;
		case 2://Sacar de la cola
		dequeve();
		break;
		case 3://imprimir cola
		printf();
		break;
		case 4://comprobar el frente
		front1();
		break;
		case 5://Salir
		exit(0);
		break;
	}
	system("pause");
	system("cls");
	menu();
}



void enqueve(QueveEntry x){
	
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	if(front==NULL&&rear==NULL){
		front=rear=temp;
		return;
	}
	rear->next=temp;
	rear=temp;
}


void dequeve(void){
	Node *temp=front;
	if(front==NULL){
		printf("\n La cola esta vacia. \n");
		return;
	}
	if(front==rear){
		front=rear=NULL;
	}
	else{
		front=front->next;
	}
	
	printf("\n Se elimino el frente de la cola.\n");
	
	free(temp);
}



QueveEntry  escaneardato(){
	QueveEntry dato;
	printf("Escribe un dato:\n");
    scanf("%d", &dato);
    return dato;
}



void printf(void){
	Node *temp=front;
	while(temp!=NULL){
		printf("\n %d \n",temp->data);
		temp=temp->next;
	}
	printf("\n");
	if (front==NULL){
		printf("la cola esta vacia\n");
	}
	
}



QueveEntry front1(void){
	if(front==NULL){
		printf("La cola esta vacia \n");
		return NULL;
	}
	printf("\nLa cola no esta vacia\n");
	printf("El frente es: \n");
	printf("%d \n\n",front->data);
	return front->data;
}


