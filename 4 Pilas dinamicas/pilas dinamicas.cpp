#include<stdio.h>
#include<stdlib.h>

typedef int Valor_en_Pila;

typedef struct nodo{
	
	Valor_en_Pila valor;
	struct nodo* siguiente;
	
}nodo;

nodo* base_pila = NULL;

void Introducir_valor_en_la_pila();
void Mostrar_pila();
void Eliminar_valor_de_la_pila();
void Verificar_estado_de_la_pila();
int Verificar_tope_de_la_pila();

main(){
	
	int op;
    
    do
	{
    	
    printf("\n\n--------------BIENVENIDO AL PROGRAMA DE PILAS DINAMICAS--------------");
	printf("\n Puedes realizar las siguientes tareas: \n ");
	printf("\n  1. INSERTAR ELEMENTO.                      ");
	printf("\n  2. ELIMINAR ELEMENTO.                      ");
	printf("\n  3. REPORTAR LISTA.                         ");
	printf("\n  4. VERIFICAR SI LA PILA ESTA VACIA.        ");
	printf("\n  5. VERIFICAR SI LA PILA CONTIENE DATOS.    ");
	printf("\n  6. VERIFICAR EL TOPE DE LA PILA.           ");
	printf("\n  7. SALIR.                                  ");
    printf("\n\n   POR FAVOR INGRESE OPCION: ");
    
    scanf("%d",&op);
    	
        switch(op){
        	
            case 1:
            	Introducir_valor_en_la_pila();
            break;
 
 
            case 2:
            	Eliminar_valor_de_la_pila();
            break;
 
 
            case 3:   
            	Mostrar_pila();
            break;
 
 
            case 4:
          		Verificar_estado_de_la_pila();
            break;
            
            
            case 5:
            	Verificar_estado_de_la_pila();
            break;
            
            
            case 6:
            	Verificar_tope_de_la_pila();
            break;
            
            
            case 7:
            	printf("\n\n\n\t\tHasta la proxima :v \n\n\n");
            	return 0;

        }
 
        system("pause");
        system("cls");
 
    }while(op<=7);
 
   system("pause");
   return 0;
}




void Introducir_valor_en_la_pila(){
	
	nodo *nuevo_nodo;

	if((nuevo_nodo = (nodo*) malloc(sizeof(nodo))) == NULL){
		printf("\n\n  Error, no se a podido asignar memoria.\n\n");
		
	}else{
		printf("\n    Ingrese un valor: ");
		scanf("%d",&nuevo_nodo -> valor);
		nuevo_nodo -> siguiente = base_pila;
		base_pila = nuevo_nodo;
	}
	printf("\n\n");
}



void Mostrar_pila(){
	
	nodo* visual = (nodo*) malloc(sizeof(nodo));
	visual = base_pila;
	printf("\n         <---- Tope\n");
	if(base_pila!=NULL){
		while(visual!=NULL){	
			printf("   [ %d ] \n",visual->valor);
			visual = visual -> siguiente;
		}
	}
	else{
		printf("\n   La lista esta vacia.\n\n");
	}
	printf("\n\n");
}



void Eliminar_valor_de_la_pila(){
	nodo *nodo_eliminador = (nodo*) malloc(sizeof(nodo));
	nodo_eliminador = base_pila;
	int n;
	if(base_pila != NULL){
		n = nodo_eliminador -> valor;   // CREAMOS UNA VARIABLE n PARA ALMACENAR EL VALOR EN LA POSICION DE MEMORIA DEL NODO QUE SE DESEA ELIMINAR
		base_pila = nodo_eliminador -> siguiente;  
		free(nodo_eliminador);
	}else{
		printf("\n La pila se encuentra Vacia.\n\n");
	}
}



void Verificar_estado_de_la_pila(){
	if(base_pila == NULL){
		printf("\nLa pila esta vacia.\n\n");
	} else {
		printf("\nLa pila contiene valores.\n\n");
	}
}


int Verificar_tope_de_la_pila(){
	
	if(base_pila == NULL){
		printf("\nLa pila esta vacia.\n\n");
	} else {
		nodo *nodo_mostrador = (nodo*) malloc(sizeof(nodo));
		nodo_mostrador = base_pila;
		int n;
		
		n = nodo_mostrador -> valor;
		printf("\n\n  El tope de la pila es: %d\n\n", n );
		
		
	}
	
	
	
}




