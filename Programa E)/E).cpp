#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#define SIZE 10
#define VACIO NULL


int menu(int *tabla);
void buscarElemento(int *tabla);
void imprimirclave(int *tabla);
void inser(int *tabla);


int hash1(int valor){
	return (valor % SIZE);
}

int main(){
	int tabla[SIZE];
	int i;
	for (i=0;i<SIZE;i++)
    tabla[i]=VACIO;
  	menu(tabla);
}

int menu(int *tabla){
	int index,valor,inde,i,opc,b,hold1,hold2,t,xo;
	printf("\t\t\t---Tabla hash cerrada---\n");
	printf("1: Insertar en la tabla\n");
	printf("2: Eliminar mediante clave\n");
	printf("3: Eliminar mediante valor\n");
	printf("4: Buscar mediante valor\n");
	printf("5: Buscar mediante clave\n");
	printf("6: Imprimir tabla\n");
	printf("7: Salir\n");
	printf("Seleccione una opcion del menu:\n");
	scanf("%d",&opc);
	switch(opc){
		case 1:	
			inser(tabla);
		break;
		case 2:
			printf("Ingrese la clave que desea borrar \n");
			scanf("%d",&valor);
			inde = hash1(valor);
			index = fabs(inde);
			if(tabla[index]==VACIO){
						printf("Esta casilla no tiene valor\n");
					}
			else{		
				tabla[index] = VACIO;
				}
			printf("La tabla queda asi: \n");
			printf("\n\tClave \t Valores \n");
				for(i=0; i<SIZE; i++){
		    		printf("\n\t%d \t %d \n",i, tabla[i]);
		  		}
		break;
		case 3:
				printf("Ingrese el valor que desea borrar \n");
				scanf("%d",&valor);
				for(i=0; i<SIZE; i++){
		            if(valor == tabla[i]){
		                hold1 = tabla[i];
		                hold2 = i;
		                b=1;
		            }
	        	}
	        	if(b==1){
	        		tabla[hold2]=VACIO;	
				}
				else{
					printf("El valor %d no se encuentra en la tabla\n",valor);
				}
			
			printf("La tabla queda asi: \n");
			printf("\n\tClave \t Valores \n");
				for(i=0; i<SIZE; i++){
		    		printf("\n\t%d \t %d \n",i, tabla[i]);
		  		}
		break;
		case 4:
			buscarElemento(tabla);
		break;
		case 5:
			imprimirclave(tabla);
		break;
		case 6:
			printf("La tabla queda asi: \n");
			printf("\n\tClave \t Valores \n");
				for(i=0; i<SIZE; i++){
		    		printf("\n\t%d \t %d \n",i, tabla[i]);
		  		}
		break;
		case 7:
			exit(0);
		break;
	}
	system("pause");
	system("cls");
	menu(tabla);
}

void imprimirclave(int *tabla){
	int elemento;
	printf("Ingrese una clave \n");
	scanf("%d",&elemento);
	if(tabla[elemento]==VACIO){
		printf("La clave %d esta vacia\n",elemento);
	}
	else{
		printf("El valor de la clave %d es %d \n",elemento,tabla[elemento]);
	}
}

void buscarElemento(int *tabla){
    int j;
    int b = 0;
    int hold1,hold2,elemento;
	printf("Ingrese el valor a buscar en la tabla: \n");
    scanf("%d",&elemento);
        for(j=0; j<SIZE; j++)
        {
            if(elemento == tabla[j])
            {
                hold1 = tabla[j];
                hold2 = j;
                b=1;
            }
        }
    if(b==1)
    {
    	printf("El valor solicitado es %d y se encuentra en la clave %d\n",hold1,hold2);
    }
    else{
    	printf("No se encontro el valor %d en la tabla\n",elemento);
    }
}

void inser(int *tabla){
	int index,valor,inde,i,hold,j,k,hold1,hold2,b,c,l,y,oy,ji,w,ti;
	printf("Ingrese el valor a guardar \n");
	scanf("%d",&valor);
	inde = hash1(valor);
	index = fabs(inde);
	printf("Clave: %d \n",index);
	for(y=0;y<SIZE;y++){
		if(tabla[y] == valor)
	    {
	        
			oy=3;
	    }
	}
	if(oy!=3){
		if(tabla[index]==VACIO){
			tabla[index] = valor;
		}
		else{
			for(k=0;k<SIZE;k++){
				if(VACIO == tabla[k])
	            {
	                w=1;
	            }
			}
			if(w==1){
				for(j=index;j<SIZE;j++){
					if(tabla[j]==VACIO){
						tabla[j]=valor;
						hold=j;
						ti=1;
						break;	
					}
				}
				if(ti!=1){
						for(j=0;j<SIZE;j++){
						if(tabla[j]==VACIO){
						tabla[j]=valor;
						hold=j;
						break;	
						}
					}
				}
			}
			else{
				printf("La tabla esta llena por lo que no se pueden agregar mas valores\n");
			}
			for(k=0;k<SIZE;k++){
				if(valor == tabla[k])
	            {
	                hold1 = tabla[k];
	                hold2 = k;
	                b=1;
	            }
			}
			if(b==1)
	    	{
	    		printf("La clave %d esta ocupada, se paso a la clave %d\n",index,hold2);
			}
	    		
			}
			printf("La tabla queda asi: \n");
				printf("\n\tClave \t Valores \n");
					for(i=0; i<SIZE; i++){
			    		printf("\n\t%d \t %d \n",i, tabla[i]);
			  		}
	}
	else{
		printf("El valor %d ya esta dentro de la tabla, digite otro\n",valor);
	}
}

