#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
    /* 1.- Sumar los elementos de una pila (usar variables enteras) */

    /**
    Pila A;
    inicpila(&A);
    int cant = rand()%20 + 5, res = 0;

    for(int i=0; i<cant; i++){
        apilar(&A, rand()%50 + 1);
    }

    mostrar(&A);

    while(!pilavacia(&A)){
        res = tope(&A) + res;
        desapilar(&A);
    }

    printf("Suma total de la pila = %i", res);

    */

    /* 2.- Contar los elementos de una pila (usar variables enteras) */

    /**

    Pila A;
    inicpila(&A);
    int cant = rand()%20 + 5, count = 0;

    for(int i=0; i<cant; i++){
        apilar(&A, rand()%50 + 1);
    }

    mostrar(&A);

    while(!pilavacia(&A)){
        count++;
        desapilar(&A);
    }

    printf("Cantidad de elementos: %i", count);

    */

    /* 3.- Calcular el promedio de los valores de una pila (usar variables) */

    /**

    Pila A;
    inicpila(&A);
    int cant = rand()%20 + 5, count, sum = 0;
    float prom = 0;

    for(int i=0; i<cant; i++){
        apilar(&A, rand()%50 + 1);
    }

    mostrar(&A);

    while(!pilavacia(&A)){
        sum = tope(&A) + sum;
        desapilar(&A);
        count++;

        if(pilavacia(&A)) prom = (float) sum/count;
    }

    printf("El promedio es de: %.2f", prom);
    */

    /* 4.- Determinar si un elemento buscado está dentro de una pila. Al encontrarlo, finalizar la búsqueda.*/

    /**
    Pila A;
    inicpila(&A);
    int cant = rand()%20 + 5, bus, count=0;

    for(int i=0; i<cant; i++){
        apilar(&A, rand()%50 + 1);
        count++;
    }

    mostrar(&A);

    printf("Ingrese numero a buscar en la Pila: ");
    fflush(stdin);
    scanf("%i", &bus);

    for(int i=0; i<count; i++){
        printf("buscando.. %i \n", tope(&A));
        if(tope(&A) == bus) {
            printf("Encontrado! \n");

            mostrar(&A);
            return;
        }
            else desapilar(&A);
    }

    */

    /* 5.- Eliminar un elemento de una pila. Al eliminarlo, finalizar el recorrido y dejar el resto de los elementos de la pila en el mismo orden.*/

    /**
    Pila A;
    inicpila(&A);
    int cant = rand()%20 + 5;
    char selection;

    for(int i=0; i<cant; i++){
        apilar(&A, rand()%50 + 1);
    }

    mostrar(&A);

    while(!pilavacia(&A)){
        printf("Desea eliminar %i? s/n \n", tope(&A));
        fflush(stdin);
        scanf("%c", &selection);
        if(selection == 's'){
            desapilar(&A);
        } else {
            mostrar(&A);
            return;
        }
    }

    printf("No quedan elementos en la pila..");

    */

    /* 6.- Verificar si una pila DADA es capicúa.*/

    /**

    Pila a, aAux1, aAux2;
    inicpila(&a);
    inicpila(&aAux1);
    inicpila(&aAux2);
    apilar(&a, 1);
    apilar(&a, 2);
    apilar(&a, 2);
    apilar(&a, 3);
    apilar(&a, 2);
    apilar(&a, 2);
    apilar(&a, 1);

    mostrar(&a);

    while(!pilavacia(&a)){
        int num;
        num = tope(&a);
        apilar(&aAux1, num);
        apilar(&aAux2, desapilar(&a));
    }

    while(!pilavacia(&aAux2)){
        apilar(&a, desapilar(&aAux2));
    }

    while(!pilavacia(&aAux1)){
        if(tope(&aAux1) == tope(&a)){
            desapilar(&aAux1);
            desapilar(&a);
        } else return printf("La pila no es capicua");

    }
    printf("La pila es capicua!");
    */

    /* 7.- Dadas dos pilas A y B que simulan conjuntos (cada conjunto no tiene elementos repetidos sobre sí mismo), realizar un programa que
    calcule en la pila C la operación de unión.*/


    Pila A, B, C, aux, aux2;
    inicpila(&A);
    inicpila(&B);
    inicpila(&C);
    inicpila(&aux);
    inicpila(&aux2);

    apilar(&A, 1), apilar(&A, 1), apilar(&A, 7), apilar(&A, 2), apilar(&A, 2), apilar(&A, 4);
    apilar(&B, 2), apilar(&B, 4),apilar(&B, 4),apilar(&B, 1), apilar(&B, 72), apilar(&B, 1);


    while(!pilavacia(&A)){
            while(!pilavacia(&B)){
                if(tope(&A) == tope(&B)) apilar(&aux2, desapilar(&B));
                else apilar(&aux, desapilar(&B));
            }
            while(!pilavacia(&aux)) apilar(&B, desapilar(&aux));
            desapilar(&A);
    }

    mostrar(&aux2);

    while(!pilavacia(&aux2)){
        int valor = desapilar(&aux2);
        int yaExiste = 0;

        while(!pilavacia(&C)){
            if(tope(&C) == valor){
                yaExiste = 1;
                break;
            }
            apilar(&aux, desapilar(&C));
        }

        if(!yaExiste){
            apilar(&C, valor);
        }

        while(!pilavacia(&aux)) apilar(&C, desapilar(&aux));



    }








    mostrar(&C);



/* 8.- Intercalar dos pilas ordenadas en forma creciente (ORDENADA1 y ORDENADA2) dejando el resultado en una pila
también ordenada en forma creciente (ORDENADAFINAL).*/

    /*

    Pila ORD1, ORD2, ORDF, aux, aux2;
    inicpila(&ORD1);
    inicpila(&ORD2);
    inicpila(&ORDF);

    apilar(&ORD1, 3), apilar(&ORD1, 1);
    apilar(&ORD2, 6), apilar(&ORD2, 4), apilar(&ORD2, 2);

    mostrar(&ORD1);
    mostrar(&ORD2);

    while(!pilavacia(&ORD1) && !pilavacia(&ORD2)){
        if(tope(&ORD1) <= tope(&ORD2)) apilar(&ORDF, desapilar(&ORD1));
        else apilar(&ORDF, desapilar(&ORD2));
    }
    while(!pilavacia(&ORD1)) apilar(&ORDF, desapilar(&ORD1));
    while(!pilavacia(&ORD2)) apilar(&ORDF, desapilar(&ORD2));

    printf("Resultado final: ");
    mostrar(&ORDF);
    */


return 0;
}
