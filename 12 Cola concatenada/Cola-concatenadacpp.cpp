#include <stdio.h>
#include <stdlib.h>

typedef int QueveEntry;


typedef struct node{
	QueveEntry data;
	struct node *next;
	struct node* siguiente;
}Node;

Node* base_pila = NULL;
Node *front =NULL;
Node *rear =NULL;
Node *r =NULL;
Node *f =NULL;

void menu();
void enqueve(QueveEntry x);


void enq(QueveEntry x); 


QueveEntry  escaneardato();
void printf(void);
void Introducir_valor_en_la_pila();
void Eliminar_valor_de_la_pila();
void pri(void);
void p(void);
void pr(void);
void imprimirin(void);
void invertir(void);
void impri(void);

void pila_cola(void);
void cola_pila(void);
void Mostrar_pila(void);
void dequeve(void);
QueveEntry front1(void);




main(){
	menu();
	return 0;
}





void menu(){
	int opc;
	int o;
	QueveEntry dato;
	printf("\n");
	printf("\t\t\t\t\t\t---Pilas dinamicas---\n\n");
	printf("Seleccione una opcion del menu\n");
	printf("1: Enqueve\n");
	printf("2: Imprimir la cola\n");
	printf("3: Enqueve 2da cola\n");
	printf("4: Imprimir la 2da cola\n");
	printf("5: Unir las dos colas\n");
	printf("6: Invertir primera cola\n");
	printf("7: imprimir Invertir primera cola\n");
	printf("8: Salir\n");
	scanf("%d",&opc);
	switch(opc){
		case 1://Encolar
		dato = escaneardato();
		enqueve(dato);
		break;
		case 2://imprimir cola
		printf();
		break;
		case 3:
			dato = escaneardato();
			enq(dato);
			break;
		case 4:
			pri();
			break;
		case 5:
			system("pause");
			system("cls");
			printf("Elija una opcion\n");
			printf("1: Poner al inicio la primera cola\n");
			printf("2: Poner al inicio la segunda cola\n");
			printf("3: Salir\n");
			scanf("%d",&o);
			switch(o){
				case 1:
					p();
					break;
				case 2:
					pr();
					break;
				case 3:
					exit(0);
					break;
			}
			break;
		case 6:
			cola_pila();
			break;
		case 7:
			Mostrar_pila();
			break;
		case 8://Salir
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

void enq(QueveEntry x){
	
	Node *temp=(Node *)malloc(sizeof(Node));
	temp->data=x;
	temp->next=NULL;
	if(f==NULL&&r==NULL){
		f=r=temp;
		return;
	}
	r->next=temp;
	r=temp;
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
	//free(temp);
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


void pri(void){
	Node *temp=f;
	while(temp!=NULL){
		printf("\n %d \n",temp->data);
		temp=temp->next;
	}
	printf("\n");
	if (f==NULL){
		printf("la cola esta vacia\n");
	}
	
}


void p(void){
	Node *temp=front;
	Node *tem=f;
	while(temp!=NULL){
		printf("\n %d \n",temp->data);
		temp=temp->next;
	}
	printf("\n");
	if (front==NULL){
		printf("la primer cola esta vacia\n");
	}
	while(tem!=NULL){
		printf("\n %d \n",tem->data);
		tem=tem->next;
	}
	printf("\n");
	if (f==NULL){
		printf("la segunda cola esta vacia\n");
	}
}

void pr(void){
	Node *temp=front;
	Node *tem=f;
	while(tem!=NULL){
		printf("\n %d \n",tem->data);
		tem=tem->next;
	}
	printf("\n");
	if (f==NULL){
		printf("la segunda cola esta vacia\n");
	}
	while(temp!=NULL){
		printf("\n %d \n",temp->data);
		temp=temp->next;
	}
	printf("\n");
	if (front==NULL){
		printf("la primer cola esta vacia\n");
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




void cola_pila(){
	///se borra de la cola
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
	/// se pasa a la pila
	temp -> siguiente = base_pila;
	base_pila = temp;
}


void Mostrar_pila(){
	
	Node* visual = (Node*) malloc(sizeof(Node));
	visual = base_pila;
	if(base_pila!=NULL){
		while(visual!=NULL){	
			printf("   [ %d ] \n",visual->data);
			visual = visual -> siguiente;
		}
	}
	else{
		printf("\n   La lista esta vacia.\n\n");
	}
	printf("\n\n");
}

