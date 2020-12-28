#include<stdio.h>
#include<stdlib.h>

typedef int Valor_en_Lista;

typedef struct nodo{
	
	Valor_en_Lista valor;
	struct nodo* siguiente;
	
}nodo;

nodo* inicio_lista = NULL;
nodo* final_lista = NULL;

void Introducir_valor_al_inicio_en_la_lista();
void insertar_en_medio();
void Introducir_valor_al_final_en_la_lista();
void Mostrar_lista();
void Eliminar_valor_de_la_lista();
void vaciar_lista();
void Verificar_estado_de_la_lista();
void Buscar_elemento_en_la_lista();

main(){
	
	int op;
    
    do
	{
    	
    printf("\n\n--------------BIENVENIDO AL PROGRAMA DE LISTAS DINAMICAS--------------");
	printf("\n Puedes realizar las siguientes tareas: \n   ");
	printf("\n  1. INSERTAR ELEMENTO AL INICIO.            ");
	printf("\n  2. INSERTAR ELEMENTO EN POSICION DEFINIDA. ");
	printf("\n  3. INSERTAR ELEMENTO AL FINAL.             ");
	printf("\n  4. ELIMINAR ELEMENTO.                      ");
	printf("\n  5. REPORTAR LISTA.                         ");
	printf("\n  6. VERIFICAR EL ESTADO DE LISTA.           ");
	printf("\n  7. VACIAR LA LISTA.                        "); 
	printf("\n  8. BUSCAR EN LA LISTA.                     ");
	printf("\n  9. SALIR.                                  ");
    printf("\n\n   POR FAVOR INGRESE OPCION: ");
    
    scanf("%d",&op);
    	
        switch(op){
        	
            case 1:
            	Introducir_valor_al_inicio_en_la_lista();
            break;
 
 
            case 2:
            	insertar_en_medio();
            break;
            
            
			case 3:
            	Introducir_valor_al_final_en_la_lista();
            break;
 
 
            case 4:   
            	Eliminar_valor_de_la_lista();
            break;
 
 
            case 5:
          		Mostrar_lista();
            break;
            
            
            case 6:
            	Verificar_estado_de_la_lista();
            break;
            
            
            case 7:
            	vaciar_lista();
            break;
            
            
            case 8:
            	Buscar_elemento_en_la_lista();
            break;
            
            case 9:
            	printf("\n\n\n\t\tHasta la proxima :v \n\n\n");
            return 0 ;

        }
 
        system("pause");
        system("cls");
 
    }while(op<=7);
 
   system("pause");
   return 0;
}




void Introducir_valor_al_final_en_la_lista(){   

	nodo* nuevo_nodo = (nodo*)malloc(sizeof(nodo));
	printf("\n\nIngrese el elemento que desea agregar: ");
	scanf("%d",&nuevo_nodo->valor);
	
	if (inicio_lista == NULL){
		inicio_lista = nuevo_nodo;   // igualamos el inicio de la lista con el nuevo nodo, ya que es el primer nodo en la lista.
		inicio_lista -> siguiente = NULL; // apuntamos siguiente a null
		final_lista = nuevo_nodo;  // el final de la lista se iguala con el nuevo nodo
	} 
	else{
		final_lista -> siguiente = nuevo_nodo; // 
		nuevo_nodo -> siguiente = NULL ;
		final_lista = nuevo_nodo;
	}
	printf("\n Elemento ingresado con exito \n\n" );
	printf("\n\n");
}


void Introducir_valor_al_inicio_en_la_lista(){
	
	nodo* nuevo_nodo = (nodo*) malloc(sizeof(nodo));
	printf("\n\nIngrese el elemento que desea agregar: ");
	scanf("%d", &nuevo_nodo->valor);
	if(inicio_lista == NULL){
		inicio_lista = nuevo_nodo;
		final_lista = nuevo_nodo;
		inicio_lista->siguiente = NULL;
	}
	else{
		nuevo_nodo->siguiente = inicio_lista;
		inicio_lista = nuevo_nodo;
	}
	printf("\n Elemento ingresado con exito \n\n" );
}



void Mostrar_lista(){
	
	nodo* visual = (nodo*) malloc(sizeof(nodo));
	visual = inicio_lista;
	
	if(inicio_lista!=NULL){
		int posicion = 1;
		while(visual!=NULL){	
			printf("%d .- [ %d ] \n",posicion, visual->valor);
			visual = visual -> siguiente;
			++posicion;
		}
	}
	else{
		printf("\n   La lista esta vacia.\n\n");
	}
	printf("\n\n");
}



void Eliminar_valor_de_la_lista(){
	
	nodo *nodo_eliminador = (nodo*) malloc(sizeof(nodo));
	nodo_eliminador = inicio_lista;
	
	nodo* nodo_anterior = (nodo*) malloc(sizeof(nodo));
	nodo_anterior = NULL;
	
	int valor_buscado = 0;
	int encontrado = 0;   // variable para indicar al programa si encontro el valor
	printf("\n\n Ingrese el valor que desea eliminar: ");
	scanf("%d", &valor_buscado);
	
	if(inicio_lista!=NULL){
		while(nodo_eliminador != NULL && encontrado != 1){
			
				if(nodo_eliminador->valor == valor_buscado){
					
					if(nodo_eliminador == inicio_lista){
						inicio_lista = inicio_lista->siguiente;
						
				}else 
				
				if(nodo_eliminador == final_lista){
					nodo_anterior -> siguiente = NULL;
					final_lista = nodo_anterior;
				}else{
					nodo_anterior -> siguiente = nodo_eliminador -> siguiente;
				}
				
				encontrado = 1;
			}
			nodo_anterior = nodo_eliminador;
			nodo_eliminador = nodo_eliminador -> siguiente;
		}
		if(encontrado == 0){
			
			printf("\n Elemento no encontrado\n\n");
			
		}else{
			
			free(nodo_anterior);
			printf("\n Elemento eliminado\n\n");
			
		}
		
	}else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void insertar_en_medio(){
		
	nodo *nodo_insercion = (nodo*) malloc(sizeof(nodo));
	
	nodo* nodo_anterior = (nodo*) malloc(sizeof(nodo));
	
	nodo* nodo_posterior = (nodo*) malloc(sizeof(nodo));
	nodo_posterior = inicio_lista;
	
	int posicion_para_insertar = 0;
	int posicion_encontrada = 0;   // variable para indicar al programa si encontro el valor
	printf("\n\n Ingrese despues de que posicion desea insertar el elemento: ");
	scanf("%d", &posicion_para_insertar);
	
	if(inicio_lista!=NULL){
		
		int posicion = 0;
		
		while(nodo_insercion != NULL && posicion_encontrada != 1){
			
			if(posicion == posicion_para_insertar){
				posicion_encontrada = 1;
			}
			for (posicion; posicion < posicion_para_insertar ; posicion++){
				nodo_anterior = nodo_posterior;
				nodo_posterior = nodo_posterior -> siguiente;
				
			}
			
			posicion_encontrada = 1;
				
			}

		}
		
		if(posicion_encontrada == 0){
			
			printf("\n El Elemento no se puede introducir\n\n");
			
		}else{
			
		
			int valor_a_insertar = 0;
			
			printf("\n\n Ingrese elemento que desea insertar: ");
			scanf("%d", &valor_a_insertar);
			
			nodo_insercion->valor = valor_a_insertar;
			nodo_anterior -> siguiente = nodo_insercion;
			nodo_anterior = nodo_insercion;
			nodo_anterior -> siguiente = nodo_posterior;
			
			
		}
}


void Buscar_elemento_en_la_lista(){
	
	nodo *nodo_buscador = (nodo*) malloc(sizeof(nodo));
	nodo_buscador = inicio_lista;
	
	int valor_buscado = 0;
	int encontrado = 0;   // variable para indicar al programa si encontro el valor
	printf("\n\n Ingrese el valor que desea buscar: ");
	scanf("%d", &valor_buscado);
	
	if(inicio_lista!=NULL){
		while(nodo_buscador != NULL && encontrado != 1){
			
			if(nodo_buscador->valor == valor_buscado){
				encontrado = 1;
				break;
			}else{
				nodo_buscador = nodo_buscador -> siguiente;
			}
			
		}
		if(encontrado == 0){
			
			printf("\n Elemento no encontrado\n\n");
			
		}
		else{
			
			printf("\n Elemento encontrado\n\n");
			printf("El elemento es: %d \n\n",nodo_buscador->valor);
		}
		
	}//1er if
	else{
		printf("\n La lista se encuentra vacia\n\n");
	}
}

void Verificar_estado_de_la_lista(){
	
	if(inicio_lista == NULL){
		printf("\nLa Lista esta vacia.\n\n");
	} else {
		printf("\nLa Lista contiene valores.\n\n");
	}
	
}


void vaciar_lista(){
	
	while(inicio_lista != NULL){
		
		nodo *nodo_eliminador = (nodo*) malloc(sizeof(nodo));
		nodo_eliminador = inicio_lista;
		
		int n;
		if(inicio_lista != NULL){
			n = nodo_eliminador -> valor;   // CREAMOS UNA VARIABLE n PARA ALMACENAR EL VALOR EN LA POSICION DE MEMORIA DEL NODO QUE SE DESEA ELIMINAR
			inicio_lista = nodo_eliminador -> siguiente;  
			free(nodo_eliminador);
		}else{
			printf("\n La pila se encuentra Vacia.\n\n");
		}
	}

}
