#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "pila.h"

int main()
{
    /*
    printf("Ejercicio 1) Sumar los elementos de una pila (usar variables enteras) \n");
    Pila DADA;
    int m;
    int sum = 0;
    srand(time(NULL));

    inicpila(&DADA);

    for (m = 0; m < 10; m++) {
        int num = (rand() % 15) + 1;
        apilar(&DADA, num);
    }

    mostrar(&DADA);

    while (!pilavacia(&DADA)) {
        sum = sum + tope(&DADA);
        desapilar(&DADA);
    }

    printf("La suma total es de: %i \n", sum);
    */



    /*
    printf("Ejercicio 2) Contar los elementos de una pila (usar variables enteras) \n");
    Pila DADA, aux;
    int contador = 0;
    int e;
    srand(time(NULL));

    inicpila(&DADA);
    inicpila(&aux);

    int n_ale = rand() % 15;

    for (e = 0; e < n_ale; e++) {
        int num = (rand() % 15) + 1;
        apilar(&DADA, num);
    }

    mostrar(&DADA);

    while (!pilavacia(&DADA)) {
        apilar(&aux, desapilar(&DADA));
        contador++;
    }

    printf("La pila tiene %i elementos \n", contador);
    */


    /*
    printf("Ejercicio 3) Calcular el promedio de los valores de una pila (usar variables) \n");
    Pila DADA;
    float r;
    float contador = 0, sp = 0;
    srand(time(NULL));

    inicpila(&DADA);

    int n_ale = rand() % 15;

    for (r = 0; r < n_ale; r++) {
        int num = (rand() % 15) + 1;
        apilar(&DADA, num);
    }

    mostrar(&DADA);

    while(!pilavacia(&DADA)) {
        sp = sp + tope(&DADA);
        contador++;
        desapilar(&DADA);
    }

    float promedio = sp/contador;

    printf("El promedio total es de: %.2f \n", promedio);
    */



    /*
    printf("Ejercicio 4) Determinar si un elemento buscado est%c dentro de una pila. Al encontrarlo, finalizar la b%csqueda. \n", 160, 163);
    Pila DADA;
    int x, valP = 0;
    int encontrado = 0;
    srand(time(NULL));

    inicpila(&DADA);

    int n_ale = (rand() % 9) + 5;

    for (x = 0; x < n_ale; x++) {
        int num = rand() % 13;
        apilar(&DADA, num);
    }

    mostrar(&DADA);

    printf("\nSeleccione un n%cmero del 1 al 10 para determinar si est%c en la pila: ", 163, 160);
    scanf("%i", &valP);

    while (!pilavacia(&DADA)) {
        if (valP == tope(&DADA)) {
            printf("Se encontr%c el valor %i en la pila.\n", 162, valP);
            encontrado = 1;
            break;
        }
        desapilar(&DADA);
    }
    if (!encontrado) {
        printf("El valor %d no est%c en la pila.\n", valP, 160);
    }
    */


    /*
    printf("Ejercicio 5) Eliminar un elemento de una pila. Al eliminarlo, finalizar el recorrido y dejar el resto de los elementos de la pila en el mismo orden. \n");
    Pila DADA, aux;
    int t, elim = 0;
    int encontrado = 0;
    srand(time(NULL));

    inicpila(&DADA);
    inicpila(&aux);

    int n_ale = (rand() % 9) + 5;

    for (t = 0; t < n_ale; t++) {
        int num = rand() % 12;
        apilar(&DADA, num);
    }

    mostrar(&DADA);

    printf("Determine el valor de la pila a eliminar: ");
    scanf("%i", &elim);

    system("cls");

    while(!pilavacia(&DADA)) {
        if(elim == tope(&DADA)) {
            desapilar(&DADA);
            printf("Se encontro el valor.\n");
            encontrado = 1;
            break;
        }
        else {
            apilar(&aux, desapilar(&DADA));
        }
    }
    while (!pilavacia(&aux)) {
        apilar(&DADA, desapilar(&aux));
    }
    if (!encontrado) {
        printf("El valor no fue encontrado.\n");
    }

    printf("Pila Actualizada: \n");
    mostrar(&DADA);
    */

    printf("Ejercicio 6) Verificar si una pila DADA es capic%ca.\n\n", 163);
    Pila DADA, INVERSA, aux, auxD;
    int n, i, valor;
    int capi = 1;
    srand(time(NULL));

    inicpila(&DADA);
    inicpila(&INVERSA);
    inicpila(&aux);
    inicpila(&auxD);

    printf("Cu%cntos valores deseas ingresar?: ", 160);
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Ingresar un valor: ");
        scanf("%d", &valor);
        apilar(&DADA, valor);
        apilar(&aux, valor);
    }

    while(!pilavacia(&aux)) {
        apilar(&INVERSA, desapilar(&aux));
    }

    while (!pilavacia(&DADA) && !pilavacia(&INVERSA)) {
        if (desapilar(&DADA) != desapilar(&INVERSA)) {
            capi = 0;
            break;
        }
    }

    if (capi) {
        printf("\nLa pila es capic%ca.\n", 163);
    } else {
        printf("\nLa pila no es capic%ca.\n", 163);
    }

    return 0;
}
