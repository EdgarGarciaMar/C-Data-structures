#include <stdio.h>
#include <stdlib.h>

void menu();
int conbinatoria(int n,int k);

main(){
	menu();
	return 0;
}

void menu(){
		int opc;
		int n;
		int k;
        int x;
	printf("\t\t\t---nCk recursivo---\n\n");
	printf("1: Obtener nCk.\n");
	printf("2: Salir.\n");
	printf("Seleccione una opcion del menu: \n");
	scanf("%i",&opc);
	switch(opc){
		case 1:
		printf("Ingrese n:\n");
		scanf("%d",&n);
		printf("Ingrese k:\n");
		scanf("%d",&k);
		x = conbinatoria(n,k);
		printf("EL resultado de %dC%d es: %d\n",n,k,x);
		break;
		case 2:
		exit(0);
		break;
	}
	system("pause");
	system("cls");
	menu();
}
int conbinatoria(int n,int k){
	if(k==0 || k==n){
		return 1;
	}
	else{
		return conbinatoria(n-1,k-1)+conbinatoria(n-1,k);
	}
}
