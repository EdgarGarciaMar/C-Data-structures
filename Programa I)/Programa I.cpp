#include <stdlib.h>
#include <stdio.h>

void menu();
int potencia(int base, int exponente);

main(){
	menu();
	return 0;
}
void menu(){
		int opc;
		int base;
		int exponente;
        int x;
	printf("\t\t\t---a^b recursivo---\n\n");
	printf("1: elebar a^b.\n");
	printf("2: Salir.\n");
	printf("Seleccione una opcion del menu: \n");
	scanf("%i",&opc);
	switch(opc){
		case 1:
		printf("Digite la base: \n");
	    scanf("%i",&base);
	    printf("Digite el exponente: \n");
		scanf("%i",&exponente);
		printf("\n");
		printf("\n");
		x= potencia(base,exponente);
		printf("El resultado de %d elevado a la %d es: %d \n\n",base,exponente,x);
		break;
		case 2:
		exit(0);
		break;
	}
	system("pause");
	system("cls");
	menu();
}

int potencia(int base, int exponente){
int pot;
if(exponente == 0){
	pot=1;
	return 1;
}

if(exponente==1) {
pot=base;	
}
else{
	pot= base*potencia(base,exponente-1);
}
 
 return pot;
 
}

