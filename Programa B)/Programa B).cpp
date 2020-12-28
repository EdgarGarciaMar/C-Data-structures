#include <stdio.h>
#include <stdlib.h>




void menu();
void quicksort(int *obj, int iz, int de);

main(){		   
	menu();
	return 0;
}

void menu(){
	int opc;
	int valor[10];
	printf("\t\t\t\t\t\t\t\t\t---QUIKSORT---\n");
	printf("Seleccione una opcion:\n");
	printf("1: Introduce los datos para ordenarlos.\n");
	printf("2: Salir\n");
	scanf("%d",&opc);
	

	    switch(opc){
		case 1://introduccir los datos al arreglo
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
		
		printf("Los valores ordenados son:\n");
		quicksort(valor,0,10-1);//arreglo,izquierda,derecha
		
		for(int i=0; i<10;i++)
		{
			printf("%i\n",valor[i]);

		}
		break;	
		case 2://salir
		exit(0);
		break;
	}
	system("PAUSE");
	system("CLS");
	menu();
}
void quicksort(int *obj, int iz, int de) {//arreglo,izquierda,derecha
  if(iz >= de) return;
  int i = iz, j = de;
  int tmp, pivot = obj[i];
  for(;;) {
    while(obj[i] < pivot) i++;
    while(pivot < obj[j]) j--;
    if(i >= j) break;
    tmp = obj[i]; obj[i] = obj[j]; obj[j] = tmp;
    i++; j--;
  }
  quicksort(obj, iz, i-1);
  quicksort(obj, j+1, de);
}








