#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <math.h>

typedef float StackEntry;
typedef char Operator;

typedef struct Node
{
	StackEntry entry;
	struct Node *next;
}Node;

typedef struct Stack
{
	Node *top;
}Stack;

void Create(Stack *s);
void Push(StackEntry item, Stack *s);
Node *MakeNode(StackEntry item);
StackEntry *Pop(Stack *s);
int StackEmpty(Stack *s);
StackEntry *Operation(Stack *s, int typeOp);
StackEntry StackTop(Stack *s);
void AddOperator(Stack *s, Operator oper);
void Delete(Stack *s);

main()
{
	Stack pilita;
	Stack *s = &pilita;
	StackEntry entry;
	int op, trash;
	Operator oper;
	
	printf("Bienvenido. Creando pila...\n");
	Create(s);
	
	while(op != 7)
	{
		system("cls");
		printf("\nElige una opcion:\n"
			"[1].Agregar elemento.\n"
			"[2].Agregar operador.\n"
			"[3].Tope de pila.\n"
			"[4].Pila vacia.\n"
			"[5].Eliminar tope\n" 
			"[6].Salir.\n");
		scanf("%d", &op);
		
		switch(op)
		{
			case 1:
				printf("\nIngrese un dato:\t");
				scanf("%f", &entry);
				
				Push(entry, s);
				printf("\n");
				system("pause");
				break;
				
			case 2:
				printf("\nIngrese un operador:\n"
						"'s' = Suma.\n"
						"'r' = Resta.\n"
						"'m' = Multiplicacion.\n"
						"'d' = Division.\n"
						"'e' = Exponente.\n");
				scanf("%d", &trash);
				scanf("%c", &oper);
				
				AddOperator(s, oper);
				printf("\n");
				system("pause");
				break;
				
			case 3:
				if(StackEmpty(s))
					printf("\nNo hay tope, pues la pila esta vacia.\n");
				else
					printf("\nEl tope es: %f\n", StackTop(s));
				 
				 printf("\n");
				 system("pause");		
				break;
				
			case 4:
				if(StackEmpty(s))
					printf("\nLa pila esta vacia.\n");
				else
					printf("\nLa pila contiene elementos.\n");
				printf("\n");
				system("pause");	
				break;
				
			case 5:
				Delete(s);
				printf("\n");
				system("pause");
				break;		
				
			default:
				printf("\nVuelva pronto\n");
				printf("\n");
				system("pause");
				exit(0);					
		}	
	}		
}

void Create(Stack *s)
{
	s->top = NULL;
	
	printf("\tPila Creada.\n");
}

void Push(StackEntry item, Stack *s)
{
	Node *ptr_node = MakeNode(item);
	
	if(ptr_node == NULL)
		printf("\tError, se intento agregar un nodo que no existe.\n");
	else
	{
		ptr_node->next = s->top;
		s->top = ptr_node;
	}	
}

Node *MakeNode(StackEntry item)
{
	Node *ptr_node;
	
	if((ptr_node = (Node*)malloc(sizeof(Node))) == NULL)
	{
		printf("\tError, no se puede asignar a la memoria.\n");
		return NULL;
	}
	else
	{
		ptr_node->entry = item;
		ptr_node->next = NULL;
		
		return ptr_node;
	}	
}

StackEntry *Pop(Stack *s)
{
	Node *current_Node;
	StackEntry *item = (StackEntry*)malloc(sizeof(StackEntry));
	
	if(StackEmpty(s))
		return NULL;
	else
	{
		current_Node = s->top;
		*item = current_Node->entry;
		s->top = current_Node->next;
		free(current_Node);
		
		return item;
	}	
}

int StackEmpty(Stack *s)
{
	return (s->top == NULL);
}

StackEntry *Operation(Stack *s, int typeOp)
{
	StackEntry *num1, *num2;
	StackEntry *res = (StackEntry*)malloc(sizeof(StackEntry));
	num2 = Pop(s);
	num1 = Pop(s);
	
	if(num2 == NULL)
		return NULL;
	else if(num2 != NULL && num1 == NULL)
	{
		Push(*num2, s);
		return NULL;
	}
	else
	{
		switch(typeOp)
		{
			case 1:
				*res = *num1 + *num2;
				break;
				
			case 2:
				*res = *num1 - *num2;
				break;
				
			case 3:
				*res = *num1 * *num2;
				break;
				
			case 4:
				*res = *num1 / *num2;
				break;
				
			case 5:
				*res = pow(*num1, *num2);
				break;
				
			default:
				res = NULL;					
		}
		
		return res;
	}	
}

StackEntry StackTop(Stack *s)
{
	return s->top->entry;
}

void AddOperator(Stack *s, Operator oper)
{
	StackEntry *res = NULL;
	
	switch(oper)
	{
		case 's':
			res = Operation(s, 1);
			break;
			
		case 'r':
			res = Operation(s, 2);
			break;
			
		case 'm':
			res = Operation(s, 3);
			break;
			
		case 'd':
			res = Operation(s, 4);
			break;
			
		case 'e':
			res = Operation(s, 5);
			break;
			
		default:
			printf("\tError, se ingreso un caracter no valido.\n");			
	}
	
	if(res == NULL)
		printf("\tError, no se pudo realizar la operacion.\n");
	else
	{
		Push(*res, s);
		
		printf("\nSe realizo con exito la operacion.\n");
	}		
}

void Delete(Stack *s)
{
	StackEntry *temp = Pop(s);
	
	if(temp == NULL)
		printf("\tError, no hay elementos que borrar.\n");
	else
		printf("\nSe elimino el elemento: %f\n", *temp);
}




