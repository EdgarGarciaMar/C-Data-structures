#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>


 struct nodo {
    char simbolo;
    struct nodo *sig;
};

struct nodo* raiz = NULL;


int b=0;
int err=0;
char formula[100];

void IngresarFormula(char *formula);
int verificarExpresion(char *formula);
void insertar(int x);
char extraer();
void liberar();
int vacia();

main()
{
    while (b=!0) 
    {
     	system("cls");
      IngresarFormula(formula);
    
	    if (verificarExpresion(formula))
	    {
	    	system("cls");
	        printf("\n\nLa expresion ingresada \"%s\" es correcta",formula);
	    }
	    else
	    {
	    	system("cls");
	        printf("\n\nLa expresion ingresada \"%s\" es incorrecta error en la pocision %d",formula,err+1);
	    }
	    liberar();
	    printf("\n\n");
	    system("pause");
   }
    getch();
    return 0;	
}

void IngresarFormula(char *formula)
{
   printf("\nIngresa una expresion que contenga delimitadores (), [], {}\n\n");
   scanf("%s",formula);
}

void insertar(char x)
{
     struct nodo *nuevo;
    nuevo = ( struct nodo*)malloc(sizeof( struct nodo));
    nuevo->simbolo = x;
    if (raiz == NULL)
    {
        raiz= nuevo;
        nuevo->sig = NULL;
    }
    else
    {
        nuevo->sig = raiz;
        raiz = nuevo;
    }
}

char extraer()
{
	
    if (raiz != NULL)
    {
    	char extr;
    	extr=raiz->simbolo;
    	struct nodo *bor=raiz;
    	raiz=raiz -> sig;
         free(bor);
         return extr;
    }
    else
    {
        return -1;
    }
}

void liberar()
{
    struct nodo *aux = raiz;
    struct nodo *bor;
    while (aux != NULL)
    {
        bor = aux;
        aux = aux->sig;
        free(bor);
    }
}

int vacia()
{
    if (raiz == NULL)
        return 1;
    else
        return 0;
}

int verificarExpresion(char *formula)
{
	
    for (int i=0;i<strlen(formula);i++)
    {
        if (formula[i]=='(' || formula[i]=='[' || formula[i]=='{')
        {
            insertar(formula[i]);
        }
        else
        {
            if (formula[i]==')')
            {
                if (extraer()!='(')
                {
                    return 0;
                }
                else{err=i;}
            
			}
            else
            {
                if (formula[i]==']')
                {
                    if (extraer()!='[')
                    {
                        return 0;
                    }
                	else{err=i;}
                }
                else
                {
                    if (formula[i]=='}')
                    {
                        if (extraer()!='{')
                        {
                            return 0;
                        }
               			else{err=i;}
                    }
                }
            }
        } 
        
    }
    if (vacia())
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

