#include <stdio.h>
#include <stdlib.h>

void menu();
void BIN();
void quicksort(int *target, int left, int right);
void BINDES();

main(){
	menu();
	return 0;
}

void menu(){
	int opc;
	printf("\t\t\t--Busqueda binaria---\n");
	printf("Seleccione una opcion del menu:\n");
	printf("1: Buscar con datos desordenados\n");
	printf("2: Buscar con datos ordenados\n");
	printf("3: Salir\n");
	scanf("%i",&opc);
	switch(opc){
		        case 1://datos desordenados
			    BINDES();
			    break;
			    case 2://Buscar en un arreglo de datos ordenados
			    system("cls");
				BIN();
				break;
				case 3://salir
				exit(0);
				break;
	}
	system("pause");
	system("cls");
	menu();
}
void BIN(){
	int numeros[]={0,1,2,3,4,5,6};
	int inf,sup,mitad,dato;
	int posicion=0;
	char band;//comprueba si esta o no en el arreglo
	//Imprimir el arreglo en pantalla
	printf("Arreglo:");
	printf("\n");
	for(int i=0;i<7;i++)
	{
		printf("%d:\t%i\n",posicion,numeros[i]);
		posicion++;
	}
	//Introducir el valor que se desea buscar
	printf("\n");
	printf("Indroduzca el dato que desea buscar:\n");
	scanf("%i",&dato);

	//Algoritmo de la busqueda binaria
	inf=-1;//limite inferior
	sup=7;//limite superior
	band='F';
	
	while((inf+1)!=sup){
		mitad=(inf+sup)/2;
		
		if(numeros[mitad]==dato){
			band='V';
			break;
		}
		if(numeros[mitad]>dato){
			sup=mitad;
			mitad=(inf+sup)/2;
		}
		if(numeros[mitad]<dato){
			inf=mitad;
			mitad=(inf+sup)/2;
		}
	}//fin del while
	
	if(band=='V'){
	printf("Se encontro el dato en el arreglo en la posicion: \n%i\n",mitad);	
	}
	else{
	printf("El elemento no esta en el arreglo.\n");
	}
	printf("\n");
}

void BINDES(){
	int valor[10];
	//Introducir los datos en un arreglo de 10elementos
	for(int i=0; i<10;i++)
	    {
	    	printf("Introdusca el dato en el arrelo: \n");
	    	scanf("%i",&valor[i]);
		}
		system("CLS");        		
		printf("Los valores del arreglo son:\n");
        for(int i=0; i<10; i++)
        {
        	printf("%i\n",valor[i]);
		}
		printf("\n");
		//Datos ordenados de forma asendente
		printf("Los valores ordenados de forma asendente son:\n");
		//Algoritmo de quicksort para ordenar los datos asendentemente
		quicksort(valor,0,10-1);//arreglo,LIMITE izquierdo,LIMITE derecho
		for(int i=0; i<10;i++)
		{
			printf("%i\n",valor[i]);

		}
		system("pause");
		system("cls");
		
		//busqueda binaria
	int inf,sup,mitad,dato;
	char band;
	
		printf("Introdusca un dato para realizar la busqueda en el arreglo ordenado\n");
		scanf("%i",&dato);
		
		inf=-1;
		sup=10;
		band='F';
		
		while((inf+1)!=sup){
		mitad=(inf+sup)/2;
		
		if(valor[mitad]==dato){
			band='V';
			break;
		}
		if(valor[mitad]>dato){
			sup=mitad;
			mitad=(inf+sup)/2;
		}
		if(valor[mitad]<dato){
			inf=mitad;
			mitad=(inf+sup)/2;
		}
	}//fin del while
	
	if(band=='V'){
	printf("Se encontro el dato en el arreglo en la posicion: %i\n",mitad);
	}
	else{
		printf("No se encontro el dato en el arreglo\n");
	}

	printf("\n");
	printf("Arreglo:\n");
	for(int i=0; i<10;i++)
		{
			printf("\t%i\n",valor[i]);

		}	
}
void quicksort(int *target, int left, int right) {//arreglo,izquierda,derecha
  if(left >= right) return;
  int i = left, j = right;
  int tmp, pivot = target[i];
  for(;;) {
    while(target[i] < pivot) i++;
    while(pivot < target[j]) j--;
    if(i >= j) break;
    tmp = target[i]; target[i] = target[j]; target[j] = tmp;
    i++; j--;
  }
  quicksort(target, left, i-1);
  quicksort(target, j+1, right);
}

