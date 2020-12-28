#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


 struct nodo {
    char simbolo;
    struct nodo *sig;
};

struct pila{
struct nodo*top;	
};

void crear(pila*s);
void Insertar_elemento(char item,struct pila*s);
struct nodo*Crear_Nodo(char item);
char *Extraer_elemento(struct pila*s);
int pila_vacia(struct pila*s);
char Tope_pila(struct pila*s);
void eliminar(struct pila*s);
void longitud(struct pila*s);

int main()
{
   struct pila pilita;
   struct pila*s = &pilita;
   char simbolo;
   int op, basura;
   char oper;
   
   system("cls");
   printf("Bienvenido. Creando pila...\n\n");
	crear(s);
	
	int longitud_de_la_cadena = 0;
	printf("\nLongitud de la cadena: ");
	scanf("%d", &longitud_de_la_cadena);
	
	char *cadena = (char *)malloc(longitud_de_la_cadena + 1);
	printf("Cadena: ");
	scanf("%s", cadena);
	
	int contador=0;
    int cont2=0;
	
	char delimitadores[]={'(',')','[',']','{','}'};
	
		for(int i=0;i<longitud_de_la_cadena;i++){
		for(int j=0;j<6;j++){
		     
			int temp;
			if(cadena[i]==delimitadores[j]){
				
				//temp=expresion[i]-'0';
				//printf("%d",temp);
				
					if((cadena[i]==')' || cadena[i]==']' || cadena[i]=='}') && (contador==0 && cont2==0)){
										printf("Primer delimitador no valido\n");
											printf("\n Deseas repetir?\n1.Si\n2.No\n");
	int ok=0;
	scanf("%d",&ok);
	if(ok==1){
		main();
	}
										return 1;
					}
					
					else if((cadena[i]==')' || cadena[i]==']' || cadena[i]=='}') && (contador==0 && cont2>0)){
										printf("\nSobran delimitadores de cierre\n");
											printf("\n Deseas repetir?\n1.Si\n2.No\n");
	int ok=0;
	scanf("%d",&ok);
	if(ok==1){
	main();
	}
										return 1;
					}
					
					else if((cadena[i]==')' || cadena[i]==']' || cadena[i]=='}') && Tope_pila(s)!= NULL){
									if(Tope_pila(s)=='[' && cadena[i]==']'){
											eliminar(s);
											contador=contador-1;
									}
									else if(Tope_pila(s)=='{' && cadena[i]=='}'){
										eliminar(s);
										contador=contador-1;
									}
									else if(Tope_pila(s)=='(' && cadena[i]==')'){
										eliminar(s);
										contador=contador-1;
									}
									else{
									printf("\nError, expresion invalida por demilitadores incompatibles. Corregir en delimitador %d\n",contador);
										printf("\n Deseas repetir?\n1.Si\n2.No\n");
	int ok=0;
	scanf("%d",&ok);
	if(ok==1){
		main();
	}
									return 1;
									}
	
									}
									
					else if(cadena[i]=='(' || cadena[i]=='[' || cadena[i]=='{'){
										contador=contador+1;
										cont2++;
										Insertar_elemento(cadena[i], s);
										
					}
					
			}
		}
	}
	
	if(contador>0){
		printf("\nTienes que cerrar %d delimitadores de apertura\n",contador);
	}
	else{
	longitud(s);	
	}
	
	printf("\n Deseas repetir?\n1.Si\n2.No\n");
	int ok=0;
	scanf("%d",&ok);
	if(ok==1){
		main();
	}	

  getch();
  return 0;
}

void crear(struct pila*s)
{
	s->top = NULL;
	printf("\tPila Creada.\n");
}

void Insertar_elemento(char item, struct pila*s)
{
	struct nodo *ptr_node = Crear_Nodo(item);
	
	if(ptr_node == NULL)
		printf("\tError, se intento agregar un nodo que no existe.\n");
	else
	{
		ptr_node->sig = s->top;
		s->top = ptr_node;
		
		printf("\nSe agrego con exito el elemento: %c\n", item);
	}	
}

struct nodo *Crear_Nodo(char item)
{
	struct nodo *ptr_node;
	
	if((ptr_node = (struct nodo*)malloc(sizeof(struct nodo))) == NULL)
	{
		printf("\tError, no se puede asignar a la memoria.\n");
		return NULL;
	}
	else
	{
		ptr_node->simbolo = item;
		ptr_node->sig = NULL;
		
		return ptr_node;
	}	
}

char *Extraer_elemento(struct pila *s)
{
	struct nodo *current_Node;
	char *item = (char*)malloc(sizeof(char));
	
	if(pila_vacia(s))
		return NULL;
	else
	{
		current_Node = s->top;
		*item = current_Node->simbolo;
		s->top = current_Node->sig;
		free(current_Node);
		
		return item;
	}	
}

int pila_vacia(struct pila *s)
{
	return (s->top == NULL);
}

char Tope_pila(struct pila *s)
{
	return s->top->simbolo;
}

void eliminar(struct pila *s)
{
	char *temp = Extraer_elemento(s);
	
	if(temp == NULL)
		printf("\tError, no hay elementos que borrar.\n");
	else
		printf("\nSe elimino el elemento: %c\n", *temp);
}

void longitud(struct pila *s)
{
	struct nodo *ptr_node = s->top;
	int length = 0;
	
	while(ptr_node != NULL)
	{
		ptr_node = ptr_node->sig;
		length++;
	}
	
	printf("\n\nLa longitud de la pila es: %d\n", length);
	
	if(length==0)
	{
		printf("\nLa expresion ingresada es correcta\n");
	}
	
}


