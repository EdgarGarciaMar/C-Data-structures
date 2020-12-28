#include <stdio.h>
#include <stdlib.h>
//Torres de Hanoi.
/*TORREA = TORRE1, TORREB = TORRE 2, TORREC = TORRE3*/


void hanoi(int disco, int torreA, int torreB, int torreC);


int main() {
	printf("Torres de Hanoi\n");
	int torreA=1;
	int torreB=2;
	int torreC=3;
	int disco = 0; 
	printf("Numero de discos: ");
	scanf("%d",&disco);
	printf("torre 1 = A\n");
    printf("torre 2 = B\n");
    printf("torre 3 = C\n");
	hanoi( disco,  torreA,  torreB,  torreC);
    system("pause");
    
	return 0;
}

void hanoi(int disco, int torreA, int torreB, int torreC){
	
	if(disco==1){
    printf("Mueve de %d a %d\n",torreA,torreC);
	}
	else{
		hanoi(disco-1,torreA, torreC, torreB);
        printf("Mueve de %d a %d\n",torreA,torreC);
		hanoi(disco-1,torreB, torreA, torreC);
		
	}
	
}
