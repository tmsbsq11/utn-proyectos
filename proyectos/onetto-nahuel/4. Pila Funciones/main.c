#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <math.h>
#include "pila.h"

void viewPila(Pila *p); /// ver pila
void pilOrdenada(Pila * h); /// ordenar pila
Pila genPilaRandom(); /// genera pila con contenido aleatorio

Pila carPila(); /// Punto 1
Pila passPila(Pila * h); /// Punto 2
Pila passPilaOrd(Pila * h); /// Punto 3
int menorPila(Pila * h); /// Punto 4
Pila eliminarMenor(Pila * h, int k);
int posicionPila(); /// Punto 5
int valorAgregar();
Pila* pilaAgregadoManual(Pila * h, int v,int p);
Pila* ordenarValor(Pila * h, int g); /// Punto 6
void ordenarPila(Pila * h); /// Punto 7
void sumarTope(Pila * h, int *result1, int *result2); /// Punto 8
int sumaFinalTope(int a, int b);
int sumaPila(Pila * h); /// Punto 9
int contador(Pila * h);
float divirPila(int a, int b);
float porcentajePila(int a);
void promedio(int a, int b, float d, float f);
int convertirPilaChar(Pila * h); /// Punto 10
void mostraNumConvertido(int a);


int main()
{
    int option;

    printf("Seleccione el ejercicio a continuaci%cn del 1 al 10: ", 162);
    scanf("%i", &option);
    system("cls");

    switch(option) {
        case 1 : {
            printf("Punto 1: Hacer una funci%cn que permita ingresar varios elementos a una pila, tanto como quiera el usuario.\n", 162);
            Pila DADA = carPila();
            viewPila(&DADA);

            system("pause");
            system("cls");
            break;
        }
        case 2: {
            printf("Punto 2: Hacer una funci%cn que pase todos los elementos de una pila a otra.\n", 162);
            Pila DADA = genPilaRandom();
            Pila COPIA = passPila(&DADA);
            viewPila(&DADA);
            viewPila(&COPIA);

            system("pause");
            system("cls");
            break;
        }
        case 3: {
            printf("Punto 3: Hacer una funci%cn que pase todos los elementos de una pila a otra, pero conservando el orden.\n", 162);
            Pila DADA = genPilaRandom();
            printf("\nPila Original\n");
            viewPila(&DADA);

            Pila COPIA = passPilaOrd(&DADA);
            printf("\nPila Desfino");
            viewPila(&COPIA);

            system("pause");
            system("cls");
            break;
        }
        case 4: {
            printf("Punto 4: Hacer una funci%cn que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.\n", 162);
            Pila DADA = genPilaRandom();
            printf("\nPila Original\n");
            viewPila(&DADA);

            int menor = menorPila(&DADA);
            printf("\nMenor valor de la pila: %i\n", menor);

            DADA = eliminarMenor(&DADA, menor);
            printf("\nPila Final\n");
            viewPila(&DADA);

            system("pause");
            system("cls");
            break;
        }
        case 5: {
            printf("Punto 5: Hacer una funci%cn que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funci%cn del ejercicio 4. (Ordenamiento por selecci%cn).\n", 162, 162, 162);
            Pila DADA = genPilaRandom();
            printf("\nPila Original:\n");
            viewPila(&DADA);

            int valor = valorAgregar();
            int posi = posicionPila();

            pilaAgregadoManual(&DADA, valor , posi);
            printf("\nPila Final con el valor agregado\n");
            viewPila(&DADA);

            system("pause");
            system("cls");
            break;
        }
        case 6: {
            printf("Punto 6: Hacer una funci%cn que inserta en una pila ordenada un nuevo elemento, conservando el orden de %csta.\n", 162, 130);
            Pila DADA = genPilaRandom();
            pilOrdenada(&DADA);
            printf("\nPila Original:\n");
            viewPila(&DADA);

            int valor = valorAgregar();

            ordenarValor(&DADA, valor);
            viewPila(&DADA);

            system("pause");
            system("cls");
            break;
        }/*
        case 7: {
            printf("Punto 7: Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funci%cn del ejercicio 6.  (Ordenamiento por inserci%cn).", 162, 162);


        }*/
        case 8: {
            printf("Punto 8: Hacer una funci%cn que sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,  sin alterar el contenido de la pila.\n", 162);
            Pila DADA = genPilaRandom();
            pilOrdenada(&DADA);
            printf("\nPila Original:\n");
            viewPila(&DADA);

            int valor1, valor2;
            sumarTope(&DADA, &valor1, &valor2);
            int resultadoSuma = sumaFinalTope(valor1, valor2);
            printf("La suma de los dos primeros valores de la pila es: %i\n\n", resultadoSuma);

            system("pause");
            system("cls");
            break;

        }
        case 9: {
            printf("Punto 9: Hacer una funci%cn que calcule el promedio de los elementos de una pila, para ello hacer tambi%cn una funci%cn que calcule la suma, otra para la cuenta y otra que divida.\n", 162, 130, 162);
            printf("En total son cuatro funciones, y la funci%cn que calcula el promedio invoca a las otras 3.\n", 162);
            Pila DADA = genPilaRandom();
            pilOrdenada(&DADA);
            printf("\nPila Original:\n");
            viewPila(&DADA);

            int sumi = sumaPila(&DADA);
            int conter = contador(&DADA);
            float calcu = divirPila(sumi, conter);
            float porcen = porcentajePila(sumi);
            promedio(sumi, conter, calcu, porcen);

            system("pause");
            system("cls");
            break;
        }
        case 10: {
            printf("Punto 10: Hacer una funci%cn que reciba una pila con n%cmeros de un solo dígito (es responsabilidad de quien usa el programa) y que transforme esos dígitos en un número decimal.\n", 163, 162);
            Pila DADA = genPilaRandom();
            pilOrdenada(&DADA);
            printf("\nPila Original:\n");
            viewPila(&DADA);

            int numString = convertirPilaChar(&DADA);
            mostraNumConvertido(numString);

            system("pause");
            system("cls");
            break;
        }
    }
    return 0;
}





void viewPila(Pila *h) {
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(h)) {
        apilar(&aux, desapilar(h));
    }
    printf("\nBase .............................................. Tope\n\n");

    while(!pilavacia(&aux)) {
        int valor = desapilar(&aux);
        printf("|| %i ", valor);
        apilar(h, valor);
    }

    printf("\n\nBase .............................................. Tope\n\n");
}

void pilOrdenada(Pila * h) {
    Pila aux, orden;
    inicpila(&aux);
    inicpila(&orden);

    while(!pilavacia(h)) {
        int comp = desapilar(h);
        while (!pilavacia(&orden) && tope(&orden) < comp) {
            apilar(&aux, desapilar(&orden));
        }
        apilar(&orden, comp);
        while (!pilavacia(&aux)) {
            apilar(&orden, desapilar(&aux));
        }
    }
    while (!pilavacia(&orden)) {
        apilar(h, desapilar(&orden));
    }
}

Pila genPilaRandom() {
    Pila Pilinha;
    inicpila(&Pilinha);
    srand(time(NULL));

    int n_ale = rand() % 7 + 3;

    for (int r = 0; r < n_ale; r++) {
        int num = rand() % 9 + 1;
        apilar(&Pilinha, num);
    }
    return Pilinha;
}




/// -------------------------------- PUNTO 1 --------------------------------

Pila carPila() {
    Pila pilin;
    inicpila(&pilin);

    int num;
   do {
        printf("\nIngrese un n%cmero: ", 163);
        if(scanf("%i", &num) == 1) {
            apilar(&pilin, num);
        } else {
            break;
        }
    } while (1);

    printf("\nPresione ENTER para continuar...");
    fflush(stdin);
    getchar(); getchar();

    return pilin;
}

/// -------------------------------- PUNTO 2 --------------------------------

Pila passPila(Pila * h) {
    Pila aux = *h;
    Pila ultima;
    inicpila(&ultima);

    while(!pilavacia(&aux)) {
        apilar(&ultima, desapilar(&aux));
    }

    return ultima;
}

/// -------------------------------- PUNTO 3 --------------------------------

Pila passPilaOrd(Pila * h) {
    Pila aux, dest;
    inicpila(&aux);
    inicpila(&dest);

    if(pilavacia(h)) {
        printf("La pila est%c vac%ca. No se puede continuar...\n", 160, 161);
        return dest;
    }
    while (!pilavacia(h)) {
        apilar(&aux, desapilar(h));
    }
    while (!pilavacia(&aux)) {
        int valor = desapilar(&aux);
        apilar(&dest, valor);
    }
    return dest;
}

/// -------------------------------- PUNTO 4 --------------------------------

int menorPila(Pila * h) {
    int menor = tope(h);
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(h)) {
        if(menor > tope(h)) {
            menor = tope(h);
        }
        apilar(&aux, desapilar(h));
    }

    while (!pilavacia(&aux)) {
        apilar(h, desapilar(&aux));
    }

     return menor;
}

Pila eliminarMenor(Pila * h, int k) {
    Pila aux, nuevaPila;
    inicpila(&aux);
    inicpila(&nuevaPila);

    while(!pilavacia(h)) {
        int valor = desapilar(h);
        if(valor != k) {
            apilar(&aux, valor);
        }
        apilar(&aux, desapilar(h));
    }

    while(!pilavacia(&aux)) {
        apilar(&nuevaPila, desapilar(&aux));
    }

    return nuevaPila;
}

/// -------------------------------- PUNTO 5 --------------------------------

int posicionPila() {
    int posc = 0;

    printf("\nEn qu%c lugar desea agregar el nuevo valor? (Se cuenta desde 0, de tope a base): ", 130);
    scanf("%i", &posc);

    return posc;
}

int valorAgregar() {
    int valor;

    printf("Valor que desea ingresar: ");
    scanf("%i", &valor);

    return valor;
}

Pila* pilaAgregadoManual(Pila * h, int v,int p) {
    int flag = 0;
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(h) && flag < p) {
        apilar(&aux, desapilar(h));
        flag++;
    }
    apilar(&aux, v);

    while (!pilavacia(&aux)) {
        apilar(h, desapilar(&aux));
    }

    return h;
}

/// -------------------------------- PUNTO 6 --------------------------------

Pila* ordenarValor(Pila * h, int g) {
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(h) && tope(h) > g) {
        apilar(&aux, desapilar(h));
    }
    apilar(&aux, g);

    while(!pilavacia(h)) {
        apilar(&aux, desapilar(h));
    }

    while(!pilavacia(&aux)) {
        apilar(h, desapilar(&aux));
    }

    return h;
}

/// -------------------------------- PUNTO 7 --------------------------------

void meterValor(Pila * h) {
    Pila aux, orden;
    inicpila(&aux);
    inicpila(&orden);

    while(!pilavacia(h)) {
        int comp = desapilar(h);
        while (!pilavacia(&orden) && tope(&orden) < comp) {
            apilar(&aux, desapilar(&orden));
        }
        apilar(&orden, comp);
        while (!pilavacia(&aux)) {
            apilar(&orden, desapilar(&aux));
        }
    }
    while (!pilavacia(&orden)) {
        apilar(h, desapilar(&orden));
    }

    printf("Pila Ordenada:\n");
    viewPila(h);
}

/// -------------------------------- PUNTO 8 --------------------------------

void sumarTope(Pila * h, int *result1, int *result2) {
    int tor1 = tope(h), tor2 = 0;
    Pila aux;
    inicpila(&aux);

    apilar(&aux, desapilar(h));

    if(!pilavacia(h)) {
        tor2 = tope(h);
    }

    apilar(h, desapilar(&aux));

    *result1 = tor1;
    *result2 = tor2;
}

int sumaFinalTope(int a, int b) {
    int suma = a + b;

    return suma;
}

/// -------------------------------- PUNTO 9 --------------------------------

int sumaPila(Pila * h) {
    int sumas = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(h)) {
        sumas = sumas + tope(h);
        apilar(&aux, desapilar(h));
    }
    while(!pilavacia(&aux)) {
        apilar(h, desapilar(&aux));
    }
    return sumas;
}

int contador(Pila * h) {
    int contar = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(h)) {
        apilar(&aux, desapilar(h));
        contar++;
    }
    while(!pilavacia(&aux)) {
        apilar(h, desapilar(&aux));
    }
    return contar;
}

float divirPila(int a, int b) {
    float divid = (float) a / b;
    return divid;
}

float porcentajePila(int a) {
    float porce = (float) (a * 100) / 75;
    return porce;
}

void promedio(int a, int b, float d, float f) {
    printf("\nLos valores del promedio son: %i de la suma total de la Pila - || - %i cantidad elementos de la Pila\n", a, b);
    printf("\nEl c%clculo del promedio es: (%i)/(%i) = %.2f\n", 160, a, b, d);
    printf("\nEl porcentaje total en base a 75 es de %.2f%%\n", f);
}

/// -------------------------------- PUNTO 10 --------------------------------

int convertirPilaChar(Pila * h) {
    long int exponente = 0, numFinal = 0;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(h)) {
        apilar(&aux, desapilar(h));
        exponente++;
    }

    int posicion = 0;

    while (!pilavacia(&aux)) {
        numFinal += tope(&aux) * pow(10, posicion);
        posicion++;
        apilar(h, desapilar(&aux));
    }
    return numFinal;
}

void mostraNumConvertido(int a) {
    printf("El n%cmero generado a partir de la Pila es: %i", 163, a);
}
