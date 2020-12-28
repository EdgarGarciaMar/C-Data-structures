#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <math.h>

typedef struct nodo{
	int dato;
	struct nodo* siguiente;
} nodo;

nodo* primero = NULL;
nodo* fin = NULL;

void insertaNodo(int aux);
void Lista();
int prueba(char const *cadena,char const *cadena1,int aux,int aux2,int maxaux,int maxaux2);

int main()
{

int op=0;
int longC = 0;
int longC2 = 0;
printf("----Recursividad B dentro de A------\n\n");
printf("Ingresa la longitud de la cadena 1: ");
scanf("%d", &longC);
fflush(stdin);

printf("\n\nIngresa la longitud de la cadena 2: ");
scanf("%d", &longC2);
fflush(stdin);

char *cadena = (char *)malloc(longC + 1);
char *cadena1 = (char *)malloc(longC2 + 1);
system("cls");
printf("Cadena 1: ");
scanf("%[^\n]", cadena);
fflush(stdin);
printf("\n\nCadena 2: ");
scanf("%[^\n]", cadena1);
fflush(stdin);	

int resul=prueba(cadena,cadena1,0,0,longC,longC2);

if(resul==0){
	system("cls");
	printf("\nLas pocisiones en donde se encuentran %s en %s son:", cadena1,cadena);
	Lista();
	printf("\n\n\n");
	system("pause");
	system("cls");
	printf("Desea intentarlo nuevamente:");
	printf("\n\n1.Si\n");
	printf("\n2.No\n\n");
	scanf("%d", &op);
	switch(op){
		case 1:
			system("cls");
			main();
			break;
		case 2:
			system("cls");
			printf("Hasta Pronto =D\n\n");
			printf("\n");
			system("pause");
			exit (0);
			break;
		default:
			printf("Adios");
			
	}	

}
else{
	printf("\nLa longitud de la cadena 1 es menor a la longitud de la cadena 2; intente nuevamente\n\n\n");	
	system("pause");
	system("cls");
	main();
}	
	
return 0;
}

int prueba(char const *cadena,char const *cadena1,int aux,int aux2,int maxaux,int maxaux2){
	if(maxaux<maxaux2){
		return 1;
	}
	if(aux>maxaux){
		return 0;
	}
	else if(cadena[aux]==cadena1[aux2]){
		if(aux2==(maxaux2-1)){
			insertaNodo(aux-aux2);
			prueba(cadena,cadena1,aux+1,0,maxaux,maxaux2);
		}
		else{
			prueba(cadena,cadena1,aux+1,aux2+1,maxaux,maxaux2);
		}
	}
	else if(cadena[aux]!=cadena1[aux2]){
		prueba(cadena,cadena1,aux+1,aux2,maxaux,maxaux2);
	}
	
}

void insertaNodo(int n){
	nodo* nuevo = (nodo*) malloc(sizeof(nodo));
	nuevo->dato=n;
	if(primero==NULL){
		primero = nuevo;
		primero->siguiente = NULL;
		fin = nuevo;
	}else{
		fin->siguiente = nuevo;
		nuevo->siguiente = NULL;
		fin = nuevo;
	}
}

void Lista(){
	nodo* actual = (nodo*) malloc(sizeof(nodo));
	actual = primero;
	if(primero!=NULL){
		while(actual != NULL){
			printf("\n %d", actual->dato);
			actual = actual->siguiente;
		}
	}else{
		printf("\n La lista se encuentra vacia\n");
		printf("\n Verifique que los elementos de la lista coincida con la longitud\n\n");
	}
}


