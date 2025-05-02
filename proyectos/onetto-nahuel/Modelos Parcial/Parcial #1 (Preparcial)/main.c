#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <conio.h>
#include "pila.h"

int cargarArreglo(int arreglo[], int v, int dim);
void viewArreglo(int A[], int v);
int contarArreglo(int A[], int v);
int sumarArreglo(int A[], int v);
float promedioAreeglo(int sum, int cont);
void pasarPilaMenores(int A[], int v, Pila *h, float promedio);
int menorValorPila(Pila modelo);
int valorAltoArray(int A[], int v);
int posArregloAlto(int A[], int v, int max);

const int DIM = 24;

int main()
{
    int temperaturas[DIM];
    int validos = 0;
    Pila menorTemp;
    inicpila(&menorTemp);


    /// ------------------------------ 1 ------------------------------
    validos = cargarArreglo(temperaturas, validos, DIM);

    /// ------------------------------ 2 ------------------------------
    viewArreglo(temperaturas, validos);

    /// ------------------------------ 3 ------------------------------
    int contx = 0, sum = 0;
    float promex = 0;
    contx = contarArreglo(temperaturas, validos);
    printf("\n\nTotal datos arreglo: %i", contx);
    sum = sumarArreglo(temperaturas, validos);
    printf("\nTotal suma de todos los elementos: %i", sum);
    promex = promedioAreeglo(sum, contx);
    printf("\nEl promedio del arreglo es: %.2f", promex);

    /// ------------------------------ 4 ------------------------------
    pasarPilaMenores(temperaturas, validos, &menorTemp, promex);

    printf("\n\nLa Pila de menores temperaturas:\n");
    mostrar(&menorTemp);

    /// ------------------------------ 5 ------------------------------
    int menorix = 0;
    menorix = menorValorPila(menorTemp);

    printf("El menor valor de la Pila es: %i", menorix);

    /// ------------------------------ 6 ------------------------------
    int mayorTemp = 0, posTempMax = 0;
    mayorTemp = valorAltoArray(temperaturas, validos);
    posTempMax = posArregloAlto(temperaturas, validos, mayorTemp);

    printf("\n\nLa mayor temperatura es %i y se encuentra en la posici%cn %i", mayorTemp, 162, posTempMax);


    return 0;
}


int cargarArreglo(int arreglo[], int v, int dim) {
    char option = 0;
    int i = v;
    int temp;

    while(i < dim && option != 27) {
        printf("Ingrese una temperatura para la hora %i: ", i);
        scanf("%i", &temp);

        if(-45 < temp && 60 > temp) {
            arreglo[i] = temp;
            i++;
        }
        else {
            printf("\ntemperatura err%cnea\n", 162);
        }

        printf("\nQuiere seguir cargando datos? ESC para salir");
        fflush(stdin);
        option = getch();
        system("cls");
    }

    return i;
}


void viewArreglo(int A[], int v) {
    for(int i = 0; i < v; i++) {
        printf("|%i| ", A[i]);

        if((i+1) % 8 == 0) {
            printf("\n");
        }
    }
}


int contarArreglo(int A[], int v) {
    int flag = 0;

    for(int i = 0; i < v; i ++) {
        flag++;
    }

    return flag;
}

int sumarArreglo(int A[], int v) {
    int sum = 0;

    for(int i = 0; i < v; i++) {
        sum = sum + A[i];
    }

    return sum;
}


float promedioAreeglo(int sum, int cont) {
    float promer = 0;

    promer = (float) sum / cont;

    return promer;
}


void pasarPilaMenores(int A[], int v, Pila *h, float promedio) {
    int valor = 0;

    for(int i = 0; i < v; i++) {
        if(A[i] < promedio) {
            valor = A[i];
            apilar(h, valor);
        }
    }
}


int menorValorPila(Pila modelo) {
    Pila aux;
    inicpila(&aux);
    int menorinho = tope(&modelo);

    while(!pilavacia(&modelo)) {
        if(menorinho > tope(&modelo)) {
            menorinho = tope(&modelo);
        }
        apilar(&aux, desapilar(&modelo));
    }
    return menorinho;
}


int valorAltoArray(int A[], int v) {
    int max = A[0];

    for(int i = 0; i < v; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }

    return max;
}


int posArregloAlto(int A[], int v, int max) {
    int flag = -1;

    for(int i = 0; i < v; i++) {
        if(max == A[i]) {
            flag = i;
        }
    }

    return flag;
}
