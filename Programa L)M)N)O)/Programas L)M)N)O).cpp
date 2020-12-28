#include <stdio.h>
#include <stdlib.h>

typedef struct NODO{
	int dato;
	NODO *hizquierda;
	NODO *hderecha;
	NODO *padre;
}NODO;

NODO *arbol=NULL;

void menu();
NODO *crearnodo(int dato,NODO *padre);
void insertar(NODO *&arbol,int dato,NODO *padre);
void mostrararbol(NODO *arbol,int contador);
bool busqueda(NODO *arbol,int dato);
void preorden(NODO *arbol);
void inorden(NODO *arbol);
void posorden(NODO *arbol);
void eliminar(NODO *arbol,int dato);//busca el dato
void eliminarNodo(NODO *nodoeliminar);//elimina el dato
NODO *minimo(NODO *arbol);//encuentra la parte mas izquierda posible
void reemplazar(NODO *arbol,NODO *nuevo);//aux para hijo izq
void destruir(NODO *nodo);//destruir el nodo que quieras
int contadornodos (NODO *arbol);//contador de nodos
int contarnivel(NODO *arbol);//contador de niveles
NODO *invertir(NODO *arbol);
main(){
	menu();
	return 0;
}
void menu(){
	int opc;
	int n;
	int contador=0;
	int d;
	int k;
	printf("\t\t\t---Arbol binario---.\n");
	printf("1: Insertar un hijo.\n");
	printf("2: Eliminar un hijo.\n");
	printf("3: Imprimir arbol.\n");
	printf("4: Busqueda.\n");
	printf("5: Preorden.\n");
	printf("6: Inorden.\n");
	printf("7: Posorden.\n");
	printf("8: Contar nodos y niveles de un arbol.\n");
	printf("9: Invertir.\n");
	printf("10: salir.\n");
	printf("Seleccione una opcion del menu:\t");
	scanf("%d",&opc);
	switch(opc){
		case 1://inserar
		printf("Digite un numero:");
		scanf("%d",&n);
		insertar(arbol,n,NULL);
		break;
		case 2://eliminar un hijo
	    printf("Digite el valor que desea eliminar:");
		scanf("%d",&n);
		eliminar(arbol,n);
		break;
		case 3://imprimir el arbol como figura
		printf("Raiz: parte central de lado izquierdo.\n");
		printf("Hijo derecho: Parte central superior, contiene hijos y hojas.\n");
		printf("Hijo izquierdo: Parte central inferior, contiene hijos y hojas.\n");
		printf("Arbol\n\n");
		mostrararbol(arbol,contador);
		printf("\n");
		break;
		case 4://busqueda
		printf("Digite el numero que desea buscar:");
		scanf("%d",&n);
		if(busqueda(arbol,n) == true){
			printf("El %d esta en el arbol\n",n);
		}
		else{
			printf("El %d no esta en el arbol.\n",n);
		}
		break;
		case 5://preorden
		printf("\n");	
		printf("Los elementos en Preorden son:\n");
		preorden(arbol);
		printf("\n");
		break;
		case 6://inorden
		printf("\n");	
		printf("Los elementos en Inorden son:\n");
		inorden(arbol);
		break;
		case 7://posorden
		printf("\n");	
		printf("Los elementos en Posorden son:\n");
		posorden(arbol);
		break;
		case 8://contar nodos y niveles
		d= contadornodos(arbol);
		k= contarnivel(arbol);
		if(d == 0 && k ==-1){
			printf("El arbol esta vacio.\n");
			break;
		}
		printf("EL arbol tiene %d nodos\n",d);
		printf("EL arbol tiene %d niveles\n",k);
		break;
		case 9://apuntador que es reflejo a un arbol
		if(arbol==NULL){
			printf("El arbol de referencia esta vacio.\n");
			break;
		}
		printf("Raiz: parte central de lado izquierdo.\n");
		printf("Hijo izquierdo: Parte central superior, contiene hijos y hojas.\n");
		printf("Hijo derecho: Parte central inferior, contiene hijos y hojas.\n");
		mostrararbol(invertir(arbol),contador);
		break;
		case 10://salir
		exit(0);
		break;
	}
	system("PAUSE");
	system("CLS");
	menu();
}
NODO *crearnodo(int dato,NODO *padre){
	NODO *nuevo_nodo=(NODO*)malloc(sizeof(NODO));
	nuevo_nodo->dato=dato;
	nuevo_nodo->hderecha=NULL;
	nuevo_nodo->hizquierda=NULL;
	nuevo_nodo->padre=padre;
	return nuevo_nodo;
}
void insertar(NODO *&arbol,int dato,NODO *padre){
	if(arbol==NULL){
		NODO *nuevo_nodo=crearnodo(dato,padre);
		arbol=nuevo_nodo;
	}
	else{
		int valorRaiz=arbol->dato;
		if(dato<valorRaiz){
			insertar(arbol->hizquierda,dato,arbol);//si el dato es menor se inserta en la izquierda
		}
		else{
			insertar(arbol->hderecha,dato,arbol);//si el dato es mayor se inserta en la derecha
		}
	}//else si el arbol esta vacio
}
void mostrararbol(NODO *arbol,int contador){
	if(arbol==NULL){
		return;
	}
	else{
		mostrararbol(arbol->hderecha,contador+1);
		for(int i=0;i<contador;i++){
			printf("\t");
		}
		printf("%d\t\n",arbol->dato);
		mostrararbol(arbol->hizquierda,contador+1);
	}//else si el arbol esta vacio
}
bool busqueda(NODO *arbol,int dato){
	if(arbol==NULL){
		return false;
	}
	else if(arbol->dato==dato){
		return true;
	}
	else if(dato < arbol->dato){
		return busqueda(arbol->hizquierda,dato);
	}
	else{
		return busqueda(arbol->hderecha,dato);
	}
}
void preorden(NODO *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		printf("%d\t",arbol->dato);
		preorden(arbol->hizquierda);
		preorden(arbol->hderecha);
	}
}
void inorden(NODO *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		inorden(arbol->hizquierda);
		printf("%d\t",arbol->dato);
		inorden(arbol->hderecha);
	}
}
void posorden(NODO *arbol){
	if(arbol==NULL){
		return;
	}
	else{
		posorden(arbol->hizquierda);
		posorden(arbol->hderecha);
		printf("%d\t",arbol->dato);
	}
}
//funciones para eliminar
void eliminar(NODO *arbol,int dato){
	if(arbol==NULL){
		return;
	}
	else if(dato < arbol->dato){
		eliminar(arbol->hizquierda,dato);
	}
	else if(dato > arbol->dato){
		eliminar(arbol->hderecha,dato);
	}
	else{//encontro el elemento
		eliminarNodo(arbol);
	}

}
void eliminarNodo(NODO *nodoeliminar){
	if(nodoeliminar->hizquierda && nodoeliminar->hderecha){//si tiene hijo izquierdo e hijo derecho
		NODO *menor=minimo(nodoeliminar->hderecha);
		nodoeliminar->dato=menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoeliminar->hizquierda){//si tiene hijo izq
		reemplazar(nodoeliminar,nodoeliminar->hizquierda);
		destruir(nodoeliminar);
		
	}
	else if(nodoeliminar->hderecha){//si tiene un hijo derecho
		reemplazar(nodoeliminar,nodoeliminar->hderecha);
		destruir(nodoeliminar);
	}
	else{//nodo hoja o sin hijos
	reemplazar(nodoeliminar,NULL);
	destruir(nodoeliminar);
	}
	
}

NODO *minimo(NODO *arbol){//funcion aux para eliminar un nodo con 2 hijos
	if(arbol==NULL){
		return NULL;
	}
	if(arbol->hizquierda){
		return minimo(arbol->hizquierda);//buscar la parte mas izquierda posible
	}
	else{
		return arbol;//si no tiene retornamos el arbol
	}
}

void reemplazar(NODO *arbol,NODO *nuevo){
	if(arbol->padre){
		//arbol->padre se le asigna un nuevo hijo
		if(arbol->dato==arbol->padre->hizquierda->dato){
			arbol->padre->hizquierda=nuevo;
			
		}
		else if(arbol->dato==arbol->padre->hderecha->dato){
			arbol->padre->hderecha=nuevo;
		}
	}
	if(nuevo){
		//asignamos al padre
		nuevo->padre=arbol->padre;
	}
	
}

void destruir(NODO *nodo){
	nodo->hizquierda=NULL;
	nodo->hderecha=NULL;
	free(nodo);
}
//termina eliminar
 
int contadornodos (NODO *arbol){
	if(arbol != NULL){
		int izq=contadornodos(arbol->hizquierda);
		int der=contadornodos(arbol->hderecha);
		int raiz=1;
		return izq + der + raiz;
	}
	return 0;	
}

int contarnivel(NODO *arbol){
	if(arbol != NULL){
		int izq=contarnivel(arbol->hizquierda) +1;
		int der=contarnivel(arbol->hderecha) +1;
		if(izq>der)
			return izq;
		return der;
	}
	return -1;
}
NODO *invertir(NODO *arbol){//funcion que recibe un la raiz y regrese un arbol binario reflejo
	NODO *nuevo_nodo = crearnodo(arbol->dato,NULL);
	if(arbol == NULL){
		return NULL;
	}
	else{
		nuevo_nodo->hderecha=arbol->hizquierda;
		nuevo_nodo->hizquierda=arbol->hderecha;
	}
	return nuevo_nodo;
}
