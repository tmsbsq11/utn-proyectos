#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

//main
void menu();
void menuSwitch();
void limpiarPantalla() {    //limpiar pantalla compatible con winblows y linux
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void cargarRandom(Pila*);
void mostrarPila(Pila);
void borrarElementoUnico(Pila*, int);

//punto 1
void punto1();
void cargarElementos(Pila*);

//punto 2
void punto2();
void pasarPila(Pila*,Pila*);

//punto 3
void punto3();
void pasarPilaConservarOrden(Pila*,Pila*);

//punto 4
void punto4();
int menorPila(Pila);
void borrarElemento(Pila*, int);

//punto 5
void punto5();
Pila ordenarPila(Pila);

//punto 6
void punto6();

int main() {
    srand(time(NULL));
    menuSwitch();
    return 0;
}

//main
void menu() {
    printf("\n---MENU---");
    printf("\n11- LIMPIAR PANTALLA");
    printf("\n0- SALIR");
    printf("\n\n1- Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario.");
    printf("\n2- Hacer una función que pase todos los elementos de una pila a otra.");
    printf("\n3- Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.");
    printf("\n4- Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.");
    printf("\n5- Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.");
    printf("\n6- Hacer una función que inserta en una pila ordenada un nuevo elemento, conservando el orden de ésta. ");
    printf("\n");
}
void menuSwitch() {
    int opcion;
    do {
        menu();
        printf("\n\nIngrese un numero: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion) {
        case 11:
            limpiarPantalla();
            break;
        case 0:
            break;
        case 1:
            /**1. Hacer una función que permita ingresar varios elementos a una pila, tanto como quiera el usuario. */
            limpiarPantalla();
            punto1();
            break;
        case 2:
            /**2. Hacer una función que pase todos los elementos de una pila a otra. */
            limpiarPantalla();
            punto2();
            break;
        case 3:
            /**3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden. */
            limpiarPantalla();
            punto3();
            break;
        case 4:
            /**4. Hacer una función que encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.*/
            limpiarPantalla();
            punto4();
            break;
        case 5:
            /**5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.*/
            limpiarPantalla();
            punto5();
            break;
        case 6:
            limpiarPantalla();
            punto6();
            break;
        default:
            limpiarPantalla();
            printf("error\n");
            break;
        }
    } while(opcion!=0);
}
void cargarRandom(Pila *PILA) {
    int n;
    printf("\nIngrese cantidad de elementos: ");
    fflush(stdin);
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        apilar(&*PILA, rand()%10);
    }
}
void mostrarPila(Pila PILA) {
    printf("\nTope ----------------------------------------------- Base\n");
    printf("|");
    while(pilavacia(&PILA)==0) {
        printf(" %d |", desapilar(&PILA));
    }

}
void borrarElementoUnico(Pila *PILA, int objetivo) {
    int flag=0;
    Pila AUX;
    inicpila(&AUX);
    while(pilavacia(&*PILA)==0) {
        if((tope(&*PILA)==objetivo)&&(flag==0)) {
            desapilar(&*PILA);
            flag=1;
        } else {
            apilar(&AUX, desapilar(&*PILA));
        }
    }
    while(pilavacia(&AUX)==0) {
        apilar(&*PILA, desapilar(&AUX));
    }
}

//punto 6
void punto6(){
    int aux;
    Pila A;
    inicpila(&A);
    cargarRandom(&A);

    //esta mal, se ingresa una pila y se inserta elemento en posicion deseada
    printf("\nIngrese un numero entero para apilar: ");
    scanf("%d", &aux);
    apilar(&A, aux);
    mostrarPila(ordenarPila(A));
}


//punto 5
void punto5() {
    Pila A;
    inicpila(&A);
    cargarRandom(&A);
    mostrarPila(ordenarPila(A));
    printf("\n");
}
Pila ordenarPila(Pila PILA) {
    Pila AUX;
    inicpila(&AUX);
    while(pilavacia(&PILA)==0) {
        apilar(&AUX, menorPila(PILA));
        borrarElementoUnico(&PILA, menorPila(PILA));
    }
    return AUX;
}


//punto 4
void punto4() {
    int menor;
    Pila A;
    inicpila(&A);
    cargarRandom(&A);

    printf("Numero menor: %d", menorPila(A));
    borrarElemento(&A, menorPila(A));
    printf("\nPila sin el numero menor: ");
    mostrar(&A);
}
int menorPila(Pila PILA) {
    int menor=tope(&PILA);
    Pila AUX;
    inicpila(&AUX);
    while(pilavacia(&PILA)==0) {
        if (tope(&PILA)<menor) {
            menor = tope(&PILA);
            //desapilar(&PILA);
        } else {
            apilar(&AUX, desapilar(&PILA));
        }
    }
    while(pilavacia(&AUX)==0) {
        apilar(&PILA, desapilar(&AUX));
    }

    return menor;
}
void borrarElemento(Pila *PILA, int objetivo) {
    Pila AUX;
    inicpila(&AUX);
    while(pilavacia(&*PILA)==0) {
        if(tope(&*PILA)==objetivo) {
            desapilar(&*PILA);
        } else {
            apilar(&AUX, desapilar(&*PILA));
        }
    }
    while(pilavacia(&AUX)==0) {
        apilar(&*PILA, desapilar(&AUX));
    }
}


//punto 3
void punto3() {
    Pila A, B;
    inicpila(&A);
    inicpila(&B);
    cargarRandom(&A);

    pasarPilaConservarOrden(&A, &B);
    printf("\nA");
    mostrar(&A);
    printf("\nB:");
    mostrar(&B);
}
void pasarPilaConservarOrden(Pila *A, Pila *B) {
    Pila AUX;
    inicpila(&AUX);

    while(pilavacia(&*A)==0) {
        apilar(&AUX, desapilar(&*A));
    }
    while(pilavacia(&AUX)==0) {
        apilar(&*B, desapilar(&AUX));
    }
}


//punto 2
void punto2() {
    Pila A, B;
    inicpila(&A);
    inicpila(&B);
    cargarRandom(&A);

    pasarPila(&A, &B);
    printf("\nA");
    mostrar(&A);
    printf("\nB:");
    mostrar(&B);
}
void pasarPila(Pila *A, Pila *B) {
    while(pilavacia(&*A)==0) {
        apilar(&*B, desapilar(&*A));
    }
}


//punto 1
void punto1() {
    Pila PILA;
    inicpila(&PILA);
    cargarElementos(&PILA);
    mostrar(&PILA);
}
void cargarElementos(Pila *PILA) {
    int n, aux, limite = 0;
    do {
        printf("\nPILA: Ingrese un numero entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        apilar(&*PILA, aux);

        printf("\n0:SALIR ");
        fflush(stdin);
        scanf("%d", &n);
    } while (n != 0 && limite<50);
}
