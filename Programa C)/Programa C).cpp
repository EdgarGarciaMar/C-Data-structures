#include <stdio.h>
#include <stdlib.h>


typedef struct NODO{
	int dato;
	struct NODO *siguiente;
}NODO;

NODO* inicio=NULL;
NODO* final=NULL;



void menu();
void incertarinicio();
void incertarfinal();
void imprimir();
void incertarmedio();
void buscar();
void eliminar();

main(){
	menu();
	return 0;
}

void menu(){
	int opc;
	printf("\t\t\t---Busqueda secuencial---\n");
	printf("1: Insertar al inicio\n");
	printf("2: Insertar en medio\n");
	printf("3: Insertar al final\n");
	printf("4: Buscar\n");
	printf("5: imprimir lista\n");
	printf("6: eliminar\n");
	printf("7: salir\n");
	printf("Seleccione una opcion del menu:\n");
	scanf("%i",&opc);
	
	switch(opc){
		    case 1:
            incertarinicio();
			break;
			case 2:
			incertarmedio();
			break;
			case 3:
			incertarfinal();	
			break;
			case 4:
			buscar();			
		    break;
		    case 5:
		    imprimir();
		    break;
		    case 6:
		    eliminar();
		    break;
		    case 7:
		    exit(0);
		    break;
	}
	system("pause");
	system("cls");
	menu();
}
void incertarinicio(){
	NODO *nuevo_nodo= (NODO*) malloc(sizeof(NODO));
	printf("Introduzca el dato que desea insertar al inicio: \n");
	scanf("%i",&nuevo_nodo->dato);
	if(inicio==NULL){
		inicio=nuevo_nodo;
		final=nuevo_nodo;
		inicio->siguiente=NULL;
	}
	else{
		nuevo_nodo->siguiente=inicio;
		inicio=nuevo_nodo;
	}
}
void incertarfinal(){
	NODO *nuevo_nodo= (NODO*) malloc(sizeof(NODO));
	printf("Introduzca el dato que desea insertar al final: \n");
	scanf("%i",&nuevo_nodo->dato);
	if(inicio==NULL){
		inicio=nuevo_nodo;
		final=nuevo_nodo;
		inicio->siguiente=NULL;
	}
	else{
		final->siguiente=nuevo_nodo;
		nuevo_nodo->siguiente=NULL;
		final=nuevo_nodo;
	}
}
void imprimir(){
	
	if(inicio==NULL){
		printf("La lista esta vacia.\n");
	}
	else{
	NODO *aux=inicio;
	int posicion=1;
	while (aux!= NULL){
		printf("%d: %d\n",posicion,aux->dato);
		aux=aux->siguiente;
		posicion++;
	}	
	
	}
}
void incertarmedio(){
	int n;
	NODO *nuevo_nodo= (NODO*) malloc(sizeof(NODO));
	printf("Introduzca la posicion: \n");
	scanf("%i",&n);
	printf("Introduzca el dato que desea insertar en la posicion: \n");
	scanf("%i",&nuevo_nodo->dato);
	if(inicio==NULL){
		inicio=nuevo_nodo;
		final=nuevo_nodo;
		inicio->siguiente=NULL;
	}
	else{
	NODO *aux=inicio;
	int posicion=1;
	while (posicion <n && aux!= NULL){
		aux=aux->siguiente;
		posicion++;
	}
	nuevo_nodo->siguiente=aux->siguiente;
	aux->siguiente=nuevo_nodo;	
	}
}
void buscar(){
     NODO *buscador= (NODO*) malloc(sizeof(NODO));
     buscador=inicio;
     NODO *respaldo=(NODO*)malloc(sizeof(NODO));
     int dato1;
     int contadorbusquedas;
     if(buscador==NULL){
     	printf("La lista esta vacia.\n");
	 }
	 else{	 	
	 printf("Introduzca el dato a buscar: ");
     scanf("%d",&dato1); 
     printf("Introduzca si es 1,2 o 3 vez que busca el dato:");
     scanf("%d",&contadorbusquedas); 
     //algoritmo de busqueda
	 int posicion=1;
	 while (buscador->dato != dato1 && buscador->siguiente !=NULL){
	 	buscador=buscador->siguiente;
        posicion++;
	 }	//sale del bucle
	 if(buscador->dato==dato1){
	 	//si encontro el dato
	 	printf("El elemento esta en la lista : %d.- %d \n\n",posicion,buscador->dato);
	 	
	 	if(contadorbusquedas == 3){//funcion de mover inicio despues de 3 veces
	 	  respaldo=inicio;
          while(respaldo->siguiente != buscador&& respaldo->siguiente != NULL){
          respaldo=respaldo->siguiente;	
		  }
	 	  if(buscador->siguiente==NULL && buscador == respaldo){
         	printf("\nsolo hay 1 elemento en la lista: %d\n",buscador->dato);
		  }
		  else{
		  NODO *aux1=(NODO*)malloc(sizeof(NODO));
	 	  aux1->dato=inicio->dato;
	 	  inicio->dato=buscador->dato;
	 	  buscador->dato=aux1->dato;
		  }
		 }//termina el mover inicio despues de 3
		 else{//mover con cada busqueda
		  respaldo=inicio;
          while(respaldo->siguiente != buscador&& respaldo->siguiente != NULL){
          respaldo=respaldo->siguiente;	
		  }    
		     
          if(buscador->siguiente==NULL && buscador == respaldo){
         	printf("\nsolo hay 1 elemento en la lista: %d\n",buscador->dato);
		  }
		  else{
		  	if(buscador==inicio){
		  		buscador->dato=inicio->dato;
			  }
			  else{
			  NODO *aux=(NODO*)malloc(sizeof(NODO));
	 		  aux->dato=respaldo->dato;
	 		  respaldo->dato=buscador->dato;
	 		  buscador->dato=aux->dato;
			  }
		  }//else que determina si solo hay 1 dato
		 }//termina mover
	 }
	 else{
	 	printf("El elemento no esta en la lista.\n");
	 }
	 }//else del caso que no este vacia la lista
}
void eliminar(){
	int el;
	if(inicio==NULL){
		printf("La lista esta vacia.\n");
	}
	else{
		printf("Introduzca el valor a eliminar\n");
		scanf("%d",&el);
		NODO *borrar=(NODO*)malloc(sizeof(NODO));
		borrar=inicio;
		NODO *anterior=(NODO*)malloc(sizeof(NODO));
		anterior=inicio;
		while (borrar->dato != el && borrar->siguiente !=NULL){
	 	borrar=borrar->siguiente;
	    }
	    if(borrar->dato == el){
	    	while( anterior->siguiente != borrar && anterior->siguiente != NULL){
	    		anterior=anterior->siguiente;
			}
			if( inicio == borrar ){
				borrar=anterior;
				inicio=inicio->siguiente;
				
			}
			else{
				if(borrar->siguiente==NULL){
					anterior->siguiente=NULL;
					final=anterior;
				}
				else{
					anterior->siguiente=borrar->siguiente;
				}
		 }
		 free(borrar);
		}
		else{
		printf("El elemento no esta en la lista.\n");
		}
	}//pregunta si esta vacia la lista
}
