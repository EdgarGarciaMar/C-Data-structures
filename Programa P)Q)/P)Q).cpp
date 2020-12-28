#include <stdio.h>
#include <stdlib.h>

typedef struct NODO{
	int dato;
	NODO *hijo_izquierdo;
	NODO *hijo_derecho;
	NODO *padre;
}NODO;

NODO *arbol = NULL;

//--------------DECLARACION DE LAS FUNCIONES----------------

void menu();

NODO *Crear_nodo(int);
void insertar_dato(NODO *&,int ,NODO *);

void mostrar_arbol(NODO *arbol,int);

bool buscar_dato(NODO* ,int);

NODO *invertir(NODO *);

int contador_de_nodos(NODO* );
int contador_de_nivel(NODO* );

void preorden(NODO *);
void inorden(NODO *);
void posorden(NODO *);

void eliminar_dato(NODO *,int);
void eliminarNODO(NODO*);
NODO *minimo(NODO*);
void reemplazar_nodo(NODO* ,NODO*);
void destruir_nodo(NODO* );

// FUNCION PRINCIPAL

main(){
	menu();
	return 0;
}

// FUNCION DE MENU

void menu(){
	
	int num_nodos;
	int nivel;
	int opc;
	int contador = 0;
	int valor;
	int xd = 0;
		
	printf("\t\t\t---ARBOL BINARIO DE BUSQUEDA---\n\n");
	printf("\t1: Insertar un hijo.\n");
	printf("\t2: Eliminar un hijo.\n");
	printf("\t3: Imprimir arbol.\n");
	printf("\t4: Buscar un valor en el arbol.\n");
	printf("\t5: Preorden.\n");
	printf("\t6: Inorden.\n");
	printf("\t7: Posorden.\n");
	printf("\t8: Contar nodos y niveles de un arbol.\n");
	printf("\t9: Invertir.\n");
	printf("\t10: Agregar una serie de datos desordenador y\n");
	printf("\t    mostrarlos ordenados de manera ascendente\n");
	printf("\t11: Salir.\n");
	printf("\n\t\tSeleccione una opcion del menu:\t");
	
	scanf("%d",&opc);
	
	printf("\n");
	
	switch(opc){
		case 1:
			
			system("CLS");		
			printf("\n\n\t\tIngrese un valor: ");
			scanf("%d",&valor);
			insertar_dato(*&arbol,valor,NULL);
			
		break;
			
		case 2:	
			
			printf("\n\n\t\tIngrese el valor que desea eliminar: ");
			scanf("%d",&valor);
			eliminar_dato(arbol,valor);
			
		break;
		
		case 3:
			mostrar_arbol(arbol,contador);
		break;
		
		case 4:
			printf("\n\n\t\tIngrese el valor que desea buscar: ");
			scanf("%d",&valor);
			buscar_dato(arbol,valor);
		break;
		
		case 5:
			preorden(arbol);
		break;
		
		case 6:
			inorden(arbol);
		break;
		
		case 7:
			posorden(arbol);
		break;
		
		case 8:
			num_nodos = contador_de_nodos(arbol);
			nivel = contador_de_nivel(arbol);
			if(num_nodos == 0 && nivel ==-1){
			printf("El arbol esta vacio.\n");
			break;
			}
			printf("EL arbol tiene %d nodos\n",num_nodos );
			printf("EL arbol tiene %d niveles\n",nivel );
		break;
		
		case 9:
			if(arbol==NULL){
				printf("El arbol de referencia esta vacio.\n");
				break;
			}
			mostrar_arbol(invertir(arbol),contador);
		break;
		
		case 10:
						
			system("CLS");		
			printf("\n\n\t\tIngrese un valor: ");
			scanf("%d",&valor);
			insertar_dato(*&arbol,valor,NULL);
			
			do{
				printf("\n\n\t\tEl dato a sido insertado exitosamente.\n\n");
				printf("\t\t¿Desea agregar otrodato?\n");
				printf("\t\t1. Si\n\n");
				printf("\t\t2. No\n\n");
				printf("\t\tSeleccione una opcion: ");
				scanf("%d",&xd);
				
				if(xd == 1){
					system("CLS");
					printf("\n\n\t\tIngrese un valor: ");
					scanf("%d",&valor);
					insertar_dato(*&arbol,valor,NULL);
				}
			}while(xd == 1);
			
			printf("\n");	
			printf("\t\tLos elementos ordenados de manera ascendente.\n");
			inorden(arbol);
			system("PAUSE");
			
		break;
		
		case 11:
			exit(0);
		break;	
	}
	
	system("PAUSE");
	system("CLS");
	menu();
}


//---------------FUNCIONES DEL PROGRAMA--------------

// FUNCIONES PARA INSERTAR VALORES EN EL ARBOL 

NODO *Crear_nodo(int valor, NODO *padre){
	
	NODO *nuevo_nodo=(NODO*)malloc(sizeof(NODO));
	
	nuevo_nodo->dato = valor;
	nuevo_nodo->hijo_derecho = NULL;
	nuevo_nodo->hijo_izquierdo = NULL;
	nuevo_nodo->padre = padre;
	
	return nuevo_nodo;
}


void insertar_dato(NODO *&arbol,int valor, NODO *padre){
	if(arbol == NULL){
		
		NODO *nuevo_nodo = Crear_nodo(valor,padre);
		arbol = nuevo_nodo;
		
	}else{
		int valor_de_la_raiz;
		
		valor_de_la_raiz = arbol->dato;
		
		if(valor < valor_de_la_raiz){
			insertar_dato(arbol->hijo_izquierdo,valor,arbol);
		}else{
			insertar_dato(arbol->hijo_derecho,valor,arbol);
		}
	}
}

// FUNCION PARA MOSTRAR EL ARBOL

void mostrar_arbol(NODO *arbol,int contador){
	if(arbol == NULL){
		return;
	}else{
		mostrar_arbol(arbol->hijo_derecho,contador+1);
		for(int i=0; i < contador; i++){
			printf("\t");
		}
		printf("%d\n",arbol->dato);
		mostrar_arbol(arbol->hijo_izquierdo,contador+1);
	}
}

// FUNCION PARA BUSCAR UN VALOR

bool buscar_dato(NODO* arbol,int valor){
	if(arbol == NULL){
		printf("\n\n\t\tEl valor no se encuentra en el arbol.\n\n");
		return false;
	}
	else if(arbol->dato == valor){
		printf("\n\n\t\tEl valor se encuentra en el arbol.\n\n");
		return true;
	}
	else if(valor < arbol->dato){
		return buscar_dato(arbol->hijo_izquierdo, valor);
	}
	else if(valor > arbol->dato){
		return buscar_dato(arbol->hijo_derecho, valor);
	}
}


// FUNCION QUE CUENTA EL NIVEL Y EL NUMERO DE NODOS

int contador_de_nodos(NODO *arbol){
	if(arbol != NULL){
		int izq = contador_de_nodos(arbol->hijo_izquierdo);
		int der = contador_de_nodos(arbol->hijo_derecho);
		int raiz = 1;
		return izq + der + raiz;
	}
	return 0;	
}

int contador_de_nivel(NODO *arbol){
	if(arbol != NULL){
		int izq = contador_de_nivel(arbol->hijo_izquierdo) +1;
		int der = contador_de_nivel(arbol->hijo_derecho) +1;
		if(izq > der)
			return izq;
		return der;
	}
	return -1;
}

// FUNCION QUE INVIERTE EL ARBOL

NODO *invertir(NODO *arbol){
	NODO *nuevo_nodo = Crear_nodo(arbol->dato,NULL);
	if(arbol == NULL){
		return NULL;
	}
	else{
		nuevo_nodo->hijo_derecho = arbol->hijo_izquierdo;
		nuevo_nodo->hijo_izquierdo = arbol->hijo_derecho;
	}
	return nuevo_nodo;
}

// FUNCION DE RECORRIDO DE ARBOLES

void preorden(NODO *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		printf("%d\t",arbol->dato);
		preorden(arbol->hijo_izquierdo);
		preorden(arbol->hijo_derecho);
	}
}

void inorden(NODO *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inorden(arbol->hijo_izquierdo);
		printf("%d\t",arbol->dato);
		inorden(arbol->hijo_derecho);
	}
}

void posorden(NODO *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		posorden(arbol->hijo_izquierdo);
		posorden(arbol->hijo_derecho);
		printf("%d\t",arbol->dato);
	}
}

// FUNCIONES PARA ELIMINAR EL ARBOL

void eliminar_dato(NODO *arbol, int valor){
	if(arbol == NULL){
		printf("\n\n\t\tEl arbol esta vacio");
	}else if(valor < arbol->dato){
		eliminar_dato(arbol->hijo_izquierdo,valor);
	}else if(valor > arbol->dato){
		eliminar_dato(arbol->hijo_derecho,valor);
	}else{
		eliminarNODO(arbol);
	}	
}

NODO *minimo(NODO*arbol){
	if(arbol == NULL){
		return NULL;
	}
	if(arbol->hijo_izquierdo){
		return minimo(arbol->hijo_izquierdo);
	}else{
		return arbol;
	}
}

void reemplazar_nodo(NODO* arbol ,NODO* nuevo_nodo){
	if(arbol->padre){
		if(arbol->dato == arbol->padre->hijo_izquierdo->dato){
			arbol->padre->hijo_izquierdo = nuevo_nodo;
		}
		else if(arbol->dato == arbol->padre->hijo_derecho->dato){
			arbol->padre->hijo_derecho = nuevo_nodo;
		}
	}
	if(nuevo_nodo){
		nuevo_nodo->padre = arbol->padre;
	}
}

void destruir_nodo(NODO *Nodo){
	Nodo->hijo_izquierdo = NULL;
	Nodo->hijo_derecho = NULL;
	
	free(Nodo);
}

void eliminarNODO(NODO *nodo_a_eliminar){
	
	if(nodo_a_eliminar->hijo_izquierdo && nodo_a_eliminar->hijo_derecho){
		
		NODO *menor = minimo(nodo_a_eliminar->hijo_derecho);
		nodo_a_eliminar->dato = menor->dato;
		eliminarNODO(menor);
	}
	else if(nodo_a_eliminar->hijo_izquierdo){
		reemplazar_nodo(nodo_a_eliminar, nodo_a_eliminar->hijo_izquierdo);
		destruir_nodo(nodo_a_eliminar);
	}
	else if(nodo_a_eliminar->hijo_derecho){
		reemplazar_nodo(nodo_a_eliminar,nodo_a_eliminar->hijo_derecho);
		destruir_nodo(nodo_a_eliminar);
	}
	else{
		reemplazar_nodo(nodo_a_eliminar,NULL);
		destruir_nodo(nodo_a_eliminar);
	}
}

