#include<stdio.h>
#include <stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>

#define MAX 20

typedef struct nodo { 
    char dato; 
    struct nodo *izquierdo; 
    struct nodo *derecho;
} nodo;

char* agregar(nodo** p, char* a) 
{ 
  
    
    if (*a == '\0') 
        return '\0'; 
  
    while (1) { 
        char* q = "NULL"; 
        if (*p == NULL) { 
  
            
            nodo* nn = (nodo*)malloc(sizeof(nodo)); 
            nn->dato = *a; 
            nn->izquierdo = NULL; 
            nn->derecho = NULL; 
            *p = nn; 
        } 
        else { 
  			 if (*a >= 'a' && *a <= 'z') { 
                return a; 
            } 
            q = agregar(&(*p)->izquierdo, a + 1); 
            q = agregar(&(*p)->derecho, q + 1); 
  
            return q; 
        } 
    } 
} 
  
void pre_orden(nodo *p){
	if(p!=NULL){
		printf("%c ",p->dato);
		pre_orden(p->izquierdo);
		pre_orden(p->derecho);
	}
}


void infijo(nodo* p) 
{ 
    if (p == NULL) { 
        return; 
    } 
    else { 
        infijo(p->izquierdo); 
        printf("%c ", p->dato); 
        infijo(p->derecho); 
    } 
} 
  

void postfijo(nodo* p) 
{ 
    if (p == NULL) { 
        return; 
    } 
    else { 
        postfijo(p->izquierdo); 
        postfijo(p->derecho); 
        printf("%c ", p->dato); 
    } 
} 

//

void push(int);
char pop();
void infi_to_prefi();
int precedencia (char);
char stack[20],a[20],prefi[20];
int top = -1;



void push(int pos)
{
    if(top == MAX-1)
    {
        printf("\npila llena\n");
    }
    else {
        top++;
        stack[top] = a[pos];
    }}


char pop()
{
    char ch;
    if(top < 0)
    {
        printf("\npila vacia\n");
        exit(0);
    }
    else
    {
        ch = stack[top];
        stack[top] = '\0';
        top--;
        return(ch);
    }
    return 0;
}


void infijotoprefijo()
{
    int i = 0,j = 0;
    strrev(a); 
    while(a[i] != '\0')
    {
        
        if(a[i] >= 'a' && a[i] <= 'z')
        {
            prefi[j] = a[i];
            j++;
            i++;
        }
        
        else if(a[i] == ')' || a[i] == '}' || a[i] == ']')
        {
            push(i);
            i++;
        }
        
        else if(a[i] == '(' || a[i] == '{' || a[i] == '[') 
        {
            if(a[i] == '(')
            {
                while(stack[top] != ')') 
                {
                    prefi[j] = pop();
                    j++;
                }
                pop();
                i++;
            }
            else if(a[i] == '[')
            {
                while(stack[top] != ']') 
                {
                    prefi[j] = pop();
                    j++;
                }
                pop();
                i++;
            }
            else if(a[i] == '{')
            {
                while(stack[top] != '}') 
                {
                    prefi[j] = pop();
                    j++;
                }
                pop();
                i++;
            }}
        else
        {
            
            if(top == -1)
            {
                push(i);
                i++;
            }
            
            else if( precedencia(a[i]) < precedencia(stack[top]))
            {
                prefi[j] = pop();  
                j++;
                
                while(precedencia(stack[top]) > precedencia(a[i])){
                    prefi[j] = pop();  
                    j++;
                    if(top < 0) {
                        break;
                    }}
                push(i);
                i++;
            }
            
            else if(precedencia(a[i]) >= precedencia(stack[top]))
            {
                push(i); 
                i++;
            }}}
    
    while(top != -1)
    {
        prefi[j] = pop();
        j++;
    }
    
    strrev(prefi);
    prefi[j] = '\0';
    
}


int precedencia(char operador)
{
    if(operador == '+' || operador =='-')
    {
        return(1);
    }
    if(operador == '*' || operador =='/')
    {
        return(2);
    }

    return 0;
}

int main() 
{ 
    system("cls");
    nodo* s = NULL; 
    int op;
    printf("----Cambio de notacion mediante un Arbol de expresion----\n\n");
    printf("..:::MENU:::..\n\n");
    printf("[1].De infija a Postfija\n\n");
    printf("[2].De infija a Prefija\n\n");
    printf("[3].Salir\n\n");
    printf("OPCION:");
    scanf("%d",&op);
    switch(op)
    {
      case 1:
	  {
	    printf("\nINGRESE LA EXPRESION INFIJA : ");
        scanf("%s",a);
        infijotoprefijo();
 	    agregar(&s, prefi);
		printf("\n\n");
		system("pause"); 
		system("cls");
        printf("LA EXPRESION INFIJA ES:\n ");
        infijo(s);
        printf("\n"); 
        printf("LA EXPRESION POSFIJA ES:\n "); 
        postfijo(s);
        printf("\n\n");
        system("pause");
        main();
        break;
	  }	 
	  
	  case 2:
	  {
	  	printf("\nINGRESE LA EXPRESION INFIJA : ");
        scanf("%s",a);
        infijotoprefijo();
 	    agregar(&s, prefi);
		printf("\n\n");
		system("pause"); 
		system("cls");
		printf("LA EXPRESION INFIJA ES:\n "); 
        infijo(s);
		printf("\n");
        printf("LA EXPRESION PREFIJA ES:\n "); 
        pre_orden(s);
        printf("\n\n");
        system("pause");
		main();	
	  }
	  
	  case 3:
	  	{
	  	  system("cls");	
	  	  printf("Hasta Pronto =D\n\n");
		  system("pause");
		  exit(0);	
		}
		
		default:
		{
		  printf("Opcion equivocada :( \n\n");
		  system("pause");
		  main();
		}
	}

    
    getch();
    return 0; 
}  

