#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct alumno{
    char nombre[50];
    char apellido[50];
    float promedio;
    struct alumno *siguiente;
}Alumno;

typedef struct cola{
    Alumno *frente;
    Alumno *final;
}Cola;

void contadorTiempo(void);
float generarPromedio(void);
Alumno deleteMax(Cola *cola);
void ordenarDescendente(void);
void encolar(Alumno alumno, Cola *cola);
Alumno desencolar(Cola *cola);
Alumno obtenerFrente(Cola *cola);
void liberarNodosDeCola(Cola *cola, Cola *colaAuxiliar);
void imprimirCola(Cola *cola);
void generarAlumnos(void);
void registroAlumno(void);
void inscribirAlumno(void);

Cola AlumnosInscritos;
Cola AlumnosFormados;
Cola Alumnos;

int main(int argc, const char * argv[]) {
    registroAlumno();
    Alumno alumnoInscrito = desencolar(&AlumnosFormados);
    encolar(alumnoInscrito, &AlumnosInscritos);
    printf("Atendiendo a: %s %s\n", alumnoInscrito.nombre, alumnoInscrito.apellido);
    contadorTiempo();
    return 0;
}

void contadorTiempo(){
    int segundos, minutos;
    segundos = minutos = 0;
    for(;;){
        if(segundos == 60) {
            minutos++;
            segundos = 0;
            if(minutos%3 == 0 && segundos == 0) {
                inscribirAlumno();
            }
            registroAlumno();
        }
        printf("%d'  %d\n", minutos, segundos);
        segundos++;
        sleep(1);
    }
}

void generarAlumnos(){
    for (int i =1; i<=60; i++) {
        Alumno alumnox = {"Alumno", "a", generarPromedio(), NULL};
        encolar(alumnox, &AlumnosFormados);
    }
    imprimirCola(&AlumnosFormados);
    printf("\n");
    ordenarDescendente();
    imprimirCola(&AlumnosFormados);
}
           
float generarPromedio() {
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = 10.0 - 0.0;
    float r = random * diff;
    return 0.0 + r;
}

void registroAlumno(){//se invoca cada minuto
    Alumno alumnox;
    printf("Alumno llega a fila - Registro\n");
    printf("Escribe el nombre del alumno: ");
    scanf(" %s", alumnox.nombre);
    printf("\nEscribe el apellido del alumno: ");
    scanf(" %s", alumnox.apellido);
    //fgets(alumnox.apellido, 50, stdin);
    printf("\nEscribe el promedio del alumno: ");
    scanf(" %f", &alumnox.promedio);
    alumnox.siguiente = NULL;
    encolar(alumnox, &AlumnosFormados);
    ordenarDescendente();
    imprimirCola(&AlumnosFormados);
}

void inscribirAlumno(){//se invoca cada tres minutos
    printf("%s %s se ha inscrito correctamente\n", AlumnosInscritos.final->nombre, AlumnosInscritos.final->apellido);
    printf("Alumnos Inscritos:\n");
    imprimirCola(&AlumnosInscritos);
    Alumno alumnoInscrito = desencolar(&AlumnosFormados);
    encolar(alumnoInscrito, &AlumnosInscritos);
    printf("Atendiendo a: %s %s\n", alumnoInscrito.nombre, alumnoInscrito.apellido);
    
}

// funciones de cola

Alumno deleteMax(Cola *cola){//descendente
    Alumno alumnox = {"", "", 0.0, NULL};
    if(cola->frente == NULL){
        //printf("La cola esta vacia\n");
        alumnox.promedio = -1;
        return alumnox;
    }
    Alumno *auxiliar = cola->frente;
    Alumno *borrar = auxiliar;
    float mayor = auxiliar->promedio;
    while (auxiliar != NULL) {
        auxiliar = auxiliar->siguiente;
        if(auxiliar != NULL){
            if(mayor >= 0 && (auxiliar->promedio) >= 0){
                if(!(mayor >= auxiliar->promedio) ){
                    mayor = auxiliar->promedio;
                    borrar = auxiliar;
                }
            }
            if(mayor == -1){
                mayor = auxiliar->promedio;
                borrar = auxiliar;
            }
                
        }
    }
    alumnox = *borrar;
    borrar->promedio = -1;
    return alumnox;
}

void ordenarDescendente(){
    Alumno entrada = deleteMax(&AlumnosFormados);//colita
    while (entrada.promedio != -1) {
        encolar(entrada, &Alumnos);//colaaux
        entrada = deleteMax(&AlumnosFormados);//colita
    }
    liberarNodosDeCola(&AlumnosFormados, &Alumnos);//colita, colaux
    printf("Alumnos formados\n");
}

void encolar(Alumno alumno, Cola *cola){
    Alumno *nuevoAlumno;
    if((nuevoAlumno = (Alumno *)malloc(sizeof(Alumno))) == NULL){
        printf("Error, no se pudo asignar memoria\n");
    }
    else{
        strncpy(nuevoAlumno->nombre, alumno.nombre, 50);
        strncpy(nuevoAlumno->apellido, alumno.apellido, 50);
        nuevoAlumno->promedio = alumno.promedio;
        nuevoAlumno->siguiente = NULL;
        
        if(cola->frente == NULL && cola->final == NULL){
            cola->frente = nuevoAlumno;
            cola->final = nuevoAlumno;
            return;
        }
        else{
            cola->final->siguiente = nuevoAlumno;
            cola->final = nuevoAlumno;
        }
        
    }
}

Alumno desencolar(Cola *cola){
    Alumno alumnox = {"", "", 0.0, NULL};
    Alumno *auxiliar = cola->frente;// nodo que esta en frente
    if(cola->frente == NULL){
        //printf("La cola esta vacia");
        alumnox.promedio = -2;
        return alumnox;
    }
    if(cola->frente == cola->final){
        cola->frente = NULL;
        cola->final = NULL;
    }
    else{
        cola->frente = cola->frente->siguiente;
    }
    alumnox = *auxiliar;
    free(auxiliar);
    return alumnox;
}

Alumno obtenerFrente(Cola *cola){
    Alumno alumnox = {"Vacio", "Vacio", -1, NULL};
    if(cola->frente == NULL){
        //printf("La cola esta vacia");
        
        return alumnox;
    }
    alumnox = *cola->frente;
    return alumnox;
}

void imprimirCola(Cola *cola){
    Alumno *auxiliar = cola->frente;
    int i=1;
    while (auxiliar != NULL) {
        printf("%i %s\t%s\t%f\n", i, auxiliar->nombre, auxiliar->apellido, auxiliar->promedio);
        auxiliar = auxiliar->siguiente;
        i++;
    }
}

void liberarNodosDeCola(Cola *cola, Cola *colaAuxiliar){
    
    while ((desencolar(cola).promedio) != -2) {
    }
    Alumno entrada = desencolar(colaAuxiliar);
    while (entrada.promedio != -2) {
        encolar(entrada, cola);
        entrada = desencolar(colaAuxiliar);
    }
}
