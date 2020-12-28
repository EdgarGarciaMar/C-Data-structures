#include<stdio.h>
#include<stdlib.h>
#include<conio.h>


int a[30];
int  pasada, aux;
int TAM=0, comienzo=1;
bool bandera;
int direccion=1, actual=0;

void escanearcadena();
void impresionnormal();
void impresioncreciente();
main()
{
   printf("---Metodo de la Burbuja Mejorado---\n\n\n");
   escanearcadena();
   system("cls");
  printf("\nLos datos en orden original son:\n");
  impresionnormal();
  int fin =TAM-1;
do
{
  bandera=false;
  while(((direccion==1) && (actual<fin)) || ((direccion==-1) && (actual>comienzo)))
  {
  	actual+=direccion;
  	if(a[actual]<a[actual-1])
  	{
  	  aux=a[actual];
	  a[actual]=a[actual-1];
	  a[actual-1]=aux;
	  bandera=true;	
	}
  }	
    if (direccion==1) 
	fin--; 
    else comienzo++;
    direccion = -direccion;
}while(bandera);
 
 printf("\n\nLos datos en orden creciente son:\n");
 impresioncreciente();
  
 	

getch();
return 0;	
}

void escanearcadena()
{
  printf("Ingresa la longitud de el arreglo:\t");
   scanf("%d",&TAM);	
   for(int i=0;i<TAM;i++)
   {
   	 printf("\nIngresa el elemento [%d]:",i+1);
   	 scanf("%d",&a[i]);
   }	
     printf("\n");
    system("pause");
}

void impresionnormal()
{
	
  for (int i=0;i<=TAM-1;i++)
  {
    printf("%d,",a[i]);	
  }	
	
}

void impresioncreciente()
{
 
 for (int i=0;i<= TAM-1;i++)
 {
 	printf("%d,",a[i]);
 }	
}
