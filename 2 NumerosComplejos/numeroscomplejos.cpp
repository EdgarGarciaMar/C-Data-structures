#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include <math.h>

typedef struct complejo{
    float real;
    float imaginario;
} complejo;

complejo escanearComplejo(void);
float obtenerValorReal(complejo x);
float obtenerValorImaginario(complejo x);
complejo suma(complejo x, complejo y);
complejo resta(complejo x, complejo y);
complejo multiplicacion(complejo x, complejo y);
complejo division(complejo x, complejo y);
complejo magnitud(complejo x);
complejo angulo(complejo x);
void escanearComplejos(void);
void escanCom(void);
int n=0;

complejo complejoUno;
complejo complejoDos;
complejo resultado;
complejo com;

int main(int argc, const char * argv[]) {
	while(n=!0)
	{
    int p,h;
    int opc = 0;
    system("cls");
    printf("\n\n--------------Numeros complejos-------------\n");
    printf("Operaciones:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Magnitud\n");
    printf("6. Angulo\n");
    printf("7.Valor real\n");
    printf("8.Valor imaginario\n");
	printf("9. Salir\n");
    printf("Digite una opcion\n");
    printf("\n");
    scanf("%d", &opc);
    
    switch (opc) {
        case 1://suma
            escanearComplejos();
            resultado = suma(complejoUno, complejoDos);
            printf("El numero complejo es: %.2f + %.2f i \n", resultado.real, resultado.imaginario);
            printf("Parte real: %.2f\n", resultado.real);
            printf("Parte imaginaria: %.2f i\n", resultado.imaginario);
            break;
        case 2://resta
            escanearComplejos();
            resultado = resta(complejoUno, complejoDos);
            printf("El numero complejo es: %.2f + %.2f i \n", resultado.real, resultado.imaginario);
            printf("Parte real: %.2f\n", resultado.real);
            printf("Parte imaginaria: %.2f i\n", resultado.imaginario);
            break;
        case 3://multiplicacion
            escanearComplejos();
            resultado = multiplicacion(complejoUno, complejoDos);
            printf("El numero complejo es: %.2f * %.2f i \n", resultado.real, resultado.imaginario);
            printf("Parte real: %.2f\n", resultado.real);
            printf("Parte imaginaria: %.2f i\n", resultado.imaginario);
            break;
        case 4://division
            escanearComplejos();
            resultado = division(complejoUno, complejoDos);
            printf("El numero complejo es: %.2f / %.2f i \n", resultado.real, resultado.imaginario);
			printf("Parte real: %.2f\n", resultado.real);
            printf("Parte imaginaria: %.2f i\n", resultado.imaginario);
            break;
        case 5://magnitud
        	escanCom();
        	resultado = magnitud(com);
        	printf("La magnitud o modulo del numero complejo es: %.2f \n", resultado.real);
        	break;
        	
        case 6://angulo
        	escanCom();
        	resultado = angulo(com);
        	printf("El angulo o argumento del numero complejo es: %.2f \n", resultado.real);
        	break;
        	
		case 7://valor real
            escanCom();
            printf("\nEl valor real del numero es %.2f\t" ,com.real);
            break;
        case 8://valor imaginario
            escanCom();
            printf("\nEl valor imaginario del numero es %.2f i \t" ,com.imaginario);
            break;
        case 9://numerador
            exit(0);
            break;
        default:
            printf("Elija una opcion del menu\n");
            break;
    }
    printf("\n");
    system("pause");
}
	getch();
    return 0;
    
}

complejo escanearComplejo(){
    complejo numero;
    printf("Escribe el valor real del numero:\n");
    scanf("%f", &numero.real);
    printf("Escribe el valor imaginario del numero:\n");
    scanf("%f", &numero.imaginario);
    return numero;
}

void escanCom(){
    printf("Escribe el valor real del numero:\n");
    scanf("%f", &com.real);
    printf("Escribe el valor imaginario del numero:\n");
    scanf("%f", &com.imaginario);
}

void escanearComplejos(){
    printf("Primer numero\n");
    printf("Escribe el valor real del numero:\n");
    scanf("%f", &complejoUno.real);
    printf("Escribe el valor imaginario del numero:\n");
    scanf("%f", &complejoUno.imaginario);
    printf("Segundo numero\n");
    printf("Escribe el valor real del numero:\n");
    scanf("%f", &complejoDos.real);
    printf("Escribe el valor imaginario del numero:\n");
    scanf("%f", &complejoDos.imaginario);
}

complejo suma(complejo x, complejo y){
    complejo res;
    res.real = x.real + y.real;
    res.imaginario = x.imaginario + y.imaginario;
    return res;
}

complejo resta(complejo x, complejo y){
    y.real = y.real * -1;
    y.imaginario = y.imaginario * -1;
    return suma(x, y);
}

complejo multiplicacion(complejo x, complejo y){
    complejo auxiliar, auxiliar2;
    auxiliar.real = x.real * y.real;
    auxiliar.imaginario = x.real * y.imaginario;
    //parte imaginaria donde se convierte real por i a la segunda
    auxiliar2.imaginario = x.imaginario * y.real;
    auxiliar2.real = (x.imaginario * y.imaginario) * -1;
    return suma(auxiliar, auxiliar2);
}

complejo division(complejo x, complejo y){
    complejo numerador, denominador, conjugado, resultado;
    conjugado.real = y.real;
    conjugado.imaginario = y.imaginario * -1;
    numerador = multiplicacion(x, conjugado);
    denominador = multiplicacion(y, conjugado);
    resultado.real = numerador.real / denominador.real;
    resultado.imaginario = numerador.imaginario / denominador.real;
    return resultado;
}

complejo magnitud(complejo x){
	complejo aux, aux2, aux3, resultado;
	aux.real = x.real * x.real;
	aux.imaginario = x.imaginario * x.imaginario;
	aux2.real= aux.real + aux.imaginario;
	aux3.real= fabs(aux3.real);   
	resultado.real = sqrt(aux2.real); 
	return resultado; 
}

complejo angulo(complejo x){
	if (x.real<=0){
	complejo aux, aux2, aux3, resultado, aux4;
	aux.real= x.imaginario / x.real;
	aux2.real = atan(aux.real);
	aux3.real = aux2.real + 180;
	aux4.real = aux3.real * 180;
	resultado.real = aux4.real / 3.1416; 
	return resultado;
	}
	if (x.real>0){
	complejo aux, aux2, aux3, resultado;
	aux.real= x.imaginario / x.real;
	aux2.real = atan(aux.real);
	aux3.real = aux2.real * 180;
	resultado.real = aux3.real / 3.1416; 
	return resultado; 
	}
}


float obtenerValorReal(complejo x){
    return x.real;
}

float obtenerValorImaginario(complejo x){
    return x.imaginario;
}
