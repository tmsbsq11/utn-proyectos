#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Pila.h"
#include <time.h>
#include <math.h>

#define ESC 27
#define DIM 100

void cargaPilaTemperatura(Pila*temperatura);
void muestraPila(Pila temperatura);
void pilaMenoresYMayores(Pila temperatura, Pila* mayor, Pila* menor);
int buscaMenorPila(Pila* temperatura);
void borraMenorPila(Pila* temperatura);
int valorParametroSuma();
int contarTemp(Pila *temperatura, int dato);
int sumarValoresPilas(Pila *temperatura, int dato);
void ordenarPila(Pila *temperatura);
void pasarPilaToArreglo(Pila temperatura, int A[], int v);
void viewArray(int A[], int v);


int main()
{
    Pila temperatura, mayores, menores;
    inicpila(&temperatura);
    inicpila(&mayores);
    inicpila(&menores);

    /// ------------------------------ 1 ------------------------------
    cargaPilaTemperatura(&temperatura);

    /// ------------------------------ 2 ------------------------------
    muestraPila(temperatura);

    system("pause");
    system("cls");

    /// ------------------------------ 3 ------------------------------
    pilaMenoresYMayores(temperatura, &mayores, &menores);
    printf("Pila Mayores a 0:");
    mostrar(&mayores);
    printf("Pila Menores o iguales a 0:");
    mostrar(&menores);

    system("pause");
    system("cls");

    /// ------------------------------ 4 ------------------------------
    printf("La pila original: \n");
    muestraPila(temperatura);
    printf("\nEl menor valor de la pila es: %d \n", buscaMenorPila(&temperatura));
    borraMenorPila(&temperatura);
    printf("\nLa pila sin el menor: \n");
    muestraPila(temperatura);

    system("pause");
    system("cls");

    /// ------------------------------ 5 ------------------------------
    muestraPila(temperatura);
    int valor = valorParametroSuma();
    int cont = contarTemp(&temperatura, valor);
    printf("\nLa cantidad de valores por encima de %i es igual a: %i (sin contar el mismo)\n", valor, cont);

    /// ------------------------------ 6 ------------------------------
    int sumax = sumarValoresPilas(&temperatura, valor);
    printf("\nLa suma de todos los valores mayores a %i es igual a: %i (sin contar el mismo)\n", valor, sumax);

    system("pause");
    system("cls");

    /// ------------------------------ 7 ------------------------------
    ordenarPila(&temperatura);
    int arreglinho[DIM];
    int validos = 15;
    pasarPilaToArreglo(temperatura, arreglinho, validos);

    printf("El arreglo de la Pila:");
    viewArray(arreglinho, validos);

    return 0;
}



/**punto 1
Hacer una función para cargar una pila de temperaturas con intervención del usuario validando
que estén dentro del rango de valores elegido por el usuario. Las temperaturas deben ser de tipo
entero y estar en el rango de -10 a 40.
*/

void cargaPilaTemperatura(Pila*temperatura) {
    int temp;
    char opcion=0;
    while(opcion!=ESC) {
        printf("Ingrese una temperatura: ");
        scanf("%d", &temp);

        if(temp>=-10 && temp <=40) {
            apilar(temperatura, temp);
        }
        else {
            printf("Error, una cosa te pedi lcm\n");
        }

        printf("Presione ESC para salir, o cualquier tecla para continuar");
        opcion = getch();
        system("cls");
    }
}



/**punto 2
Hacer una función que muestre la pila de las temperaturas (sin utilizar la función mostrar() de la
librería de pilas) Se deberán mostrar 4 temperaturas por línea.
*/
void muestraPila(Pila temperatura) {
    int i=0;
    while(!pilavacia(&temperatura)) {
        printf("|%3d| ", desapilar(&temperatura));
        i++;

        if(i%4==0) {
            printf("\n");
        }
    }
    printf("\n");
}


/**punto 3
Hacer una función que copie a una pila menores las temperaturas <= 0 y a
una pila mayores el resto de las temperaturas. No se deben perder los datos de la pila original.
*/
void pilaMenoresYMayores(Pila temperatura, Pila* mayor, Pila* menor) {
    while(!pilavacia(&temperatura)) {
        if(tope(&temperatura) <= 0) {
            apilar(menor, desapilar(&temperatura));
        }
        else {
            apilar(mayor, desapilar(&temperatura));
        }
    }
}


/**punto 4
Hacer una función que encuentre la temperatura mínima en la pila y la retorne
(la temperatura mínima debe quitarse de la pila).
*/

int buscaMenorPila(Pila* temperatura) {
    Pila aux;
    inicpila(&aux);
    int menor = tope(temperatura);

    while(!pilavacia(temperatura)) {
        if(menor > tope(temperatura)) {
            menor= tope(temperatura);
        }
        else {
            apilar(&aux, desapilar(temperatura));
        }
    }

    while(!pilavacia(&aux)) {
        apilar(temperatura, desapilar(&aux));
    }

    return menor;
}

void borraMenorPila(Pila* temperatura) {
    Pila aux;
    inicpila(&aux);
    int menor = buscaMenorPila(temperatura);
    while(!pilavacia(temperatura)) {
        if(tope(temperatura)== menor) {
            desapilar(temperatura);
        }
        else {
            apilar(&aux, desapilar(temperatura));
        }
    }

    while(!pilavacia(&aux)){
        apilar(temperatura, desapilar(&aux));
    }
}


/**punto 5
Hacer una función que cuente las temperaturas de una pila, mayores a un valor dado y lo retorne.
(el valor se recibe por parámetro).
*/

int valorParametroSuma() {
    int valor = 0;

    printf("Ingrese el valor para sumar los mayores n%cmeros de este mismo: ", 163);
    scanf("%i", &valor);

    return valor;
}

int contarTemp(Pila *temperatura, int dato) {
    int flag = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(temperatura)) {
        if(dato < tope(temperatura)) {
            flag++;
        }
        apilar(&aux, desapilar(temperatura));
    }

    while(!pilavacia(&aux)){
        apilar(temperatura, desapilar(&aux));
    }

    return flag;
}


/**punto 6
Hacer una función que sume las temperaturas de una pila, mayores a un valor dado y lo retorne.
(el valor se recibe por parámetro).
*/

int sumarValoresPilas(Pila *temperatura, int dato) {
    Pila aux;
    inicpila(&aux);
    int sumas = 0;

    while(!pilavacia(temperatura)) {
        if(dato < tope(temperatura)) {
            sumas = sumas + tope(temperatura);
        }
        apilar(&aux, desapilar(temperatura));
    }

    while(!pilavacia(&aux)){
        apilar(temperatura, desapilar(&aux));
    }

    return sumas;
}


/**punto 7
Hacer una función que cargue un arreglo de temperaturas ordenado de menor a mayor a
partir de la pila de temperaturas.
*/

void ordenarPila(Pila *temperatura) {
    Pila aux, ordenada;
    inicpila(&aux);
    inicpila(&ordenada);

    while(!pilavacia(temperatura)) {
        int comparate = desapilar(temperatura);
        while(!pilavacia(&ordenada) && comparate < tope(&ordenada)) {
            apilar(&aux, desapilar(&ordenada));
        }
        apilar(&ordenada, comparate);
        while(!pilavacia(&aux)) {
            apilar(&ordenada, desapilar(&aux));
        }
    }
    while(!pilavacia(&ordenada)) {
        apilar(temperatura, desapilar(&ordenada));
    }
}

void pasarPilaToArreglo(Pila temperatura, int A[], int v) {
    while(!pilavacia(&temperatura)) {
        for(int i = 0; i < v && !pilavacia(&temperatura); i++) {
            A[i] = desapilar(&temperatura);
        }
    }
}


/**punto 8
Hacer una función que muestre un arreglo de temperaturas pero solo 5 por línea.
*/

void viewArray(int A[], int v) {
    for(int i = 0; i < v; i++) {
        printf("- %i -", A[i]);
        if((i+1) % 5 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}
