#include <stdio.h>
#include <stdlib.h>

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
void escanearComplejos(void);

complejo complejoUno;
complejo complejoDos;
complejo resultado;

int main(int argc, const char * argv[]) {
    
    int opc = 0;
    printf("Numeros complejos\n");
    printf("Operaciones:\n");
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Multiplicacion\n");
    printf("4. Division\n");
    printf("5. Salir\n");
    printf("Digite una opcion\n");
    printf("\n");
    scanf("%d", &opc);
    
    switch (opc) {
        case 1://suma
            escanearComplejos();
            resultado = suma(complejoUno, complejoDos);
            printf("Parte real: %f\n", resultado.real);
            printf("Parte imaginaria: %f i\n", resultado.imaginario);
            break;
        case 2://resta
            escanearComplejos();
            resultado = resta(complejoUno, complejoDos);
            printf("Parte real: %f\n", resultado.real);
            printf("Parte imaginaria: %f i\n", resultado.imaginario);
            break;
        case 3://multiplicacion
            escanearComplejos();
            resultado = multiplicacion(complejoUno, complejoDos);
            printf("Parte real: %f\n", resultado.real);
            printf("Parte imaginaria: %f i\n", resultado.imaginario);
            break;
        case 4://division
            escanearComplejos();
            resultado = division(complejoUno, complejoDos);
            printf("Parte real: %f\n", resultado.real);
            printf("Parte imaginaria: %f i\n", resultado.imaginario);
            break;
        case 5://numerador
            exit(0);
            break;
        default:
            printf("Elija una opcion del menu\n");
            break;
    }
    
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

float obtenerValorReal(complejo x){
    return x.real;
}

float obtenerValorImaginario(complejo x){
    return x.imaginario;
}
