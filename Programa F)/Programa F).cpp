#include <stdio.h>
#include <stdlib.h>

typedef struct NODO{
	int dato;
	NODO *sig;
}NODO;
//inicios de las listas
NODO *nodo_0=NULL;
NODO *nodo_1=NULL;
NODO *nodo_2=NULL;
NODO *nodo_3=NULL;
NODO *nodo_4=NULL;
//finales de las listas
NODO *final_0=NULL;
NODO *final_1=NULL;
NODO *final_2=NULL;
NODO *final_3=NULL;
NODO *final_4=NULL;


void menu();
int hash1(int valor);
void insertar();
void imprimir();
void eliminar();
void buscar();

main(){
	menu();
	return 0;
}
void menu(){
	int opc;
	printf("\t\t\t---Tabla hash abierta---\n");
	printf("1: Insertar en la tabla\n");
	printf("2: Buscar en la tabla\n");
	printf("3: Eliminar\n");
	printf("4: Imprimir\n");
	printf("5: Salir\n");
	printf("Seleccione una opcion del menu:\n");
	scanf("%d",&opc);
	switch(opc){
		case 1:
		insertar();
		break;
		case 2:
		buscar();
		break;
		case 3:
		eliminar();
		break;
		case 4:
		imprimir();
		break;
		case 5:
		exit(0);
		break;
	}
	system("pause");
	system("cls");
	menu();
}
int hash1(int valor){
	return (valor % 5);
}
void insertar(){
	NODO *nuevo_nodo=(NODO*)malloc(sizeof(NODO));
	int valor;
	int clave;

	printf("Ingrese el dato a guardar en la tabla.\n");
	scanf("%d",&valor);
	clave= hash1(valor);
	printf("clave: %d \n",clave);
	
	switch(clave){
		case 0:
	nuevo_nodo->dato=valor;
    
	if(nodo_0==NULL){
		nodo_0=nuevo_nodo;
		final_0=nuevo_nodo;
		nodo_0->sig=NULL;
	}
	else{
		final_0->sig=nuevo_nodo;
		nuevo_nodo->sig=NULL;
		final_0=nuevo_nodo;
	}
		break;
		case 1:
	nuevo_nodo->dato=valor;
    
	if(nodo_1==NULL){
		nodo_1=nuevo_nodo;
		final_1=nuevo_nodo;
		nodo_1->sig=NULL;
	}
	else{
		final_1->sig=nuevo_nodo;
		nuevo_nodo->sig=NULL;
		final_1=nuevo_nodo;
	}
		break;
		case 2:
	nuevo_nodo->dato=valor;
    
	if(nodo_2==NULL){
		nodo_2=nuevo_nodo;
		final_2=nuevo_nodo;
		nodo_2->sig=NULL;
	}
	else{
		final_2->sig=nuevo_nodo;
		nuevo_nodo->sig=NULL;
		final_2=nuevo_nodo;
	}
		break;
		case 3:
	nuevo_nodo->dato=valor;
    
	if(nodo_3==NULL){
		nodo_3=nuevo_nodo;
		final_3=nuevo_nodo;
		nodo_3->sig=NULL;
	}
	else{
		final_3->sig=nuevo_nodo;
		nuevo_nodo->sig=NULL;
		final_3=nuevo_nodo;
	}
		break;
		case 4:
	nuevo_nodo->dato=valor;
    
	if(nodo_4==NULL){
		nodo_4=nuevo_nodo;
		final_4=nuevo_nodo;
		nodo_4->sig=NULL;
	}
	else{
		final_4->sig=nuevo_nodo;
		nuevo_nodo->sig=NULL;
		final_4=nuevo_nodo;
	}
		break;
	}
}
void imprimir(){
	printf("CLAVE --DATOS\n\n");
	//impirmir la clave 0
	int clave0 =0;
	if(nodo_0==NULL){
	 printf("%d->NULO\n",clave0);
	}
	else{
	NODO *aux=nodo_0;
	printf("%d-> ",clave0);
	while (aux!= NULL){
		printf("%d-> ",aux->dato);
		aux=aux->sig;
	}
	printf("NULO");
	printf("\n");
    }
    printf("\n");
//imprimir clave 1
    int clave1=1;
	if(nodo_1==NULL){
	 printf("%d->NULO\n",clave1);
	}
	else{
	NODO *aux=nodo_1;
	printf("%d-> ",clave1);
	while (aux!= NULL){
		printf("%d-> ",aux->dato);
		aux=aux->sig;
	}
	printf("NULO");
	printf("\n");
    }
    printf("\n");
//imprimir clave 2
    int clave2=2;
	if(nodo_2==NULL){
	 printf("%d->NULO\n",clave2);
	}
	else{
	NODO *aux=nodo_2;
	printf("%d-> ",clave2);
	while (aux!= NULL){
		printf("%d-> ",aux->dato);
		aux=aux->sig;
	}
	printf("NULO");
	printf("\n");
    }
    printf("\n");
//imrpimir clave 3
    int clave3=3;
	if(nodo_3==NULL){
	 printf("%d->NULO\n",clave3);
	}
	else{
	NODO *aux=nodo_3;
	printf("%d-> ",clave3);
	while (aux!= NULL){
		printf("%d-> ",aux->dato);
		aux=aux->sig;
	}
	printf("NULO");
	printf("\n");
    }
    printf("\n");
//imprimir clave 4
    int clave4=4;
	if(nodo_4==NULL){
	 printf("%d->NULO\n",clave4);
	}
	else{
	NODO *aux=nodo_4;
	printf("%d-> ",clave4);
	while (aux!= NULL){
		printf("%d-> ",aux->dato);
		aux=aux->sig;
	}
	printf("NULO");
	printf("\n");
    }
 printf("\n");
}
void eliminar(){
	    int el;
	    int clave;
		printf("Introduzca el valor a eliminar\n");
		scanf("%d",&el);
		clave=hash1(el);
		switch(clave){
			case 0:
			if(nodo_0==NULL){
		printf("Esta vacia la CLAVE:0.\n");
	}
	else{
		NODO *borrar=(NODO*)malloc(sizeof(NODO));
		borrar=nodo_0;
		NODO *anterior=(NODO*)malloc(sizeof(NODO));
		anterior=nodo_0;
		while (borrar->dato != el && borrar->sig !=NULL){
	 	borrar=borrar->sig;
	    }
	    if(borrar->dato == el){
	    	while( anterior->sig != borrar && anterior->sig != NULL){
	    		anterior=anterior->sig;
			}
			if( nodo_0 == borrar ){
				nodo_0=nodo_0->sig;
				
			}
			else{
				if(borrar->sig ==NULL){
                   anterior->sig=NULL;
                   final_0=anterior;
				}
				else{
					anterior->sig=borrar->sig;
				}
			
		 }
		 free(borrar);
		 printf("Se elimino con exito.\n");
		}
		else{
		printf("El elemento no esta en la tabla.\n");
		}
	}//pregunta si esta vacia la tabla
			break;
			case 1:
	if(nodo_1==NULL){
		printf("Esta vacia la CLAVE:1.\n");
	}
	else{
		NODO *borrar=(NODO*)malloc(sizeof(NODO));
		borrar=nodo_1;
		NODO *anterior=(NODO*)malloc(sizeof(NODO));
		anterior=nodo_1;
		while (borrar->dato != el && borrar->sig !=NULL){
	 	borrar=borrar->sig;
	    }
	    if(borrar->dato == el){
	    	while( anterior->sig != borrar && anterior->sig != NULL){
	    		anterior=anterior->sig;
			}
			if( nodo_1 == borrar ){
				nodo_1=nodo_1->sig;
				
			}
			else{
				if(borrar->sig ==NULL){
                   anterior->sig=NULL;
                   final_1=anterior;
				}
				else{
					anterior->sig=borrar->sig;
				}
			
		 }
		 free(borrar);
		 printf("Se elimino con exito.\n");
		}
		else{
		printf("El elemento no esta en la tabla.\n");
		}
	}//pregunta si esta vacia la tabla
			break;
			case 2:
	if(nodo_2==NULL){
		printf("Esta vacia la CLAVE:2.\n");
	}
	else{
		NODO *borrar=(NODO*)malloc(sizeof(NODO));
		borrar=nodo_2;
		NODO *anterior=(NODO*)malloc(sizeof(NODO));
		anterior=nodo_2;
		while (borrar->dato != el && borrar->sig !=NULL){
	 	borrar=borrar->sig;
	    }
	    if(borrar->dato == el){
	    	while( anterior->sig != borrar && anterior->sig != NULL){
	    		anterior=anterior->sig;
			}
			if( nodo_2 == borrar ){
				nodo_2=nodo_2->sig;
				
			}
			else{
				if(borrar->sig ==NULL){
                   anterior->sig=NULL;
                   final_2=anterior;
				}
				else{
					anterior->sig=borrar->sig;
				}
			
		 }
		 free(borrar);
		 printf("Se elimino con exito.\n");
		}
		else{
		printf("El elemento no esta en la tabla.\n");
		}
	}//pregunta si esta vacia la tabla
			
			break;
			case 3:
	if(nodo_3==NULL){
		printf("Esta vacia la CLAVE:3.\n");
	}
	else{
		NODO *borrar=(NODO*)malloc(sizeof(NODO));
		borrar=nodo_3;
		NODO *anterior=(NODO*)malloc(sizeof(NODO));
		anterior=nodo_3;
		while (borrar->dato != el && borrar->sig !=NULL){
	 	borrar=borrar->sig;
	    }
	    if(borrar->dato == el){
	    	while( anterior->sig != borrar && anterior->sig != NULL){
	    		anterior=anterior->sig;
			}
			if( nodo_3 == borrar ){
				nodo_3=nodo_3->sig;
				
			}
			else{
				if(borrar->sig ==NULL){
                   anterior->sig=NULL;
                   final_3=anterior;
				}
				else{
					anterior->sig=borrar->sig;
				}
			
		 }
		 free(borrar);
		 printf("Se elimino con exito.\n");
		}
		else{
		printf("El elemento no esta en la tabla.\n");
		}
	}//pregunta si esta vacia la tabla
			break;
			case 4:
		if(nodo_4==NULL){
		printf("Esta vacia la CLAVE:4.\n");
	}
	else{
		NODO *borrar=(NODO*)malloc(sizeof(NODO));
		borrar=nodo_4;
		NODO *anterior=(NODO*)malloc(sizeof(NODO));
		anterior=nodo_4;
		while (borrar->dato != el && borrar->sig !=NULL){
	 	borrar=borrar->sig;
	    }
	    if(borrar->dato == el){
	    	while( anterior->sig != borrar && anterior->sig != NULL){
	    		anterior=anterior->sig;
			}
			if( nodo_4 == borrar ){
				nodo_4=nodo_4->sig;
			}
			else{
				if(borrar->sig ==NULL){
                   anterior->sig=NULL;
                   final_4=anterior;
				}
				else{
					anterior->sig=borrar->sig;
				}
			
		 }
		 free(borrar);
		 printf("Se elimino con exito.\n");
		}
		else{
		printf("El elemento no esta en la tabla.\n");
		}
	}//pregunta si esta vacia la tabla
			break;
		}
		
}
void buscar(){
	int dato;
	int clave;
	printf("Introduzca el dato que desea buscar:\n");
	scanf("%d",&dato);
	clave=hash1(dato);

	switch(clave){
		case 0:
			if(nodo_0==NULL){
				printf("La tabla esta vacia CLAVE:0\n");
			}
			else{
		NODO *buscador=(NODO*)malloc(sizeof(NODO));
		buscador=nodo_0;
		while(buscador->dato != dato && buscador->sig != NULL ){
			buscador=buscador->sig;
		}
		if(buscador->dato==dato){
			printf("El dato esta registrado. CLAVE:0 DATO:%d\n",dato);
		}
		else{
			if(buscador->sig==NULL){
				printf("EL dato no esta registrado. CLAVE:0 DATO:%d\n",dato);
			}
		}
				
			}
		break;
		case 1:
		if(nodo_1==NULL){
				printf("La tabla esta vacia CLAVE:1\n");
			}
			else{
		NODO *buscador=(NODO*)malloc(sizeof(NODO));
		buscador=nodo_1;
		while(buscador->dato != dato && buscador->sig != NULL ){
			buscador=buscador->sig;
		}
		if(buscador->dato==dato){
			printf("El dato esta registrado. CLAVE:1 DATO:%d\n",dato);
		}
		else{
			if(buscador->sig==NULL){
				printf("EL dato no esta registrado. CLAVE:1 DATO:%d\n",dato);
			}
		}
				
			}
		break;
		case 2:
		if(nodo_3==NULL){
		printf("La tabla esta vacia CLAVE:2\n");
		}
		else{
		NODO *buscador=(NODO*)malloc(sizeof(NODO));
		buscador=nodo_2;
		while(buscador->dato != dato && buscador->sig != NULL ){
			buscador=buscador->sig;
		}
		if(buscador->dato==dato){
			printf("El dato esta registrado. CLAVE:2 DATO:%d\n",dato);
		}
		else{
			if(buscador->sig==NULL){
				printf("EL dato no esta registrado. CLAVE:2 DATO:%d\n",dato);
			}
		}	
			}
		break;
		case 3:		
		if(nodo_3==NULL){
		printf("La tabla esta vacia CLAVE:3\n");
		}
		else{
		NODO *buscador=(NODO*)malloc(sizeof(NODO));
		buscador=nodo_3;
		while(buscador->dato != dato && buscador->sig != NULL ){
			buscador=buscador->sig;
		}
		if(buscador->dato==dato){
			printf("El dato esta registrado. CLAVE:3 DATO:%d\n",dato);
		}
		else{
			if(buscador->sig==NULL){
				printf("EL dato no esta registrado. CLAVE:3 DATO:%d\n",dato);
			}
		}	
			}
		break;
		case 4:
		if(nodo_4==NULL){
		printf("La tabla esta vacia CLAVE:4\n");
		}
		else{
		NODO *buscador=(NODO*)malloc(sizeof(NODO));
		buscador=nodo_4;
		while(buscador->dato != dato && buscador->sig != NULL ){
			buscador=buscador->sig;
		}
		if(buscador->dato==dato){
			printf("El dato esta registrado. CLAVE:4 DATO:%d\n",dato);
		}
		else{
			if(buscador->sig==NULL){
				printf("EL dato no esta registrado. CLAVE:4 DATO:%d\n",dato);
			}
		}	
			}
		break;
	}
}




