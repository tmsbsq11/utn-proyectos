#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "pila.h"

int main()
{
    int option;

    do {
        printf("\nSeleccione del 1 al 14 para ver los ejercicios respectivos o presione 0 para terminar: ");
        scanf("%d", &option);

        switch (option) {

            case 1: {
                system("cls");
                printf("Ejercicio 1: Cargar desde el teclado una pila llamada DADA con 5 elementos. Pasar los tres primeros elementos que se \nencuentren en el tope a la pila AUX1 y los restantes a la pila AUX2, ambas pilas inicializadas.\n");
                Pila pilita,aux1,aux2;

                inicpila(&pilita);
                inicpila(&aux1);
                inicpila(&aux2);

                printf("\nIngrese 5 valores aleatorios:\n");
                leer(&pilita);
                leer(&pilita);
                leer(&pilita);
                leer(&pilita);
                leer(&pilita);

                system("cls");

                apilar(&aux1, desapilar(&pilita));
                apilar(&aux1, desapilar(&pilita));
                apilar(&aux1, desapilar(&pilita));

                apilar(&aux2, desapilar(&pilita));
                apilar(&aux2, desapilar(&pilita));

                printf("Pila Aux1:");
                mostrar(&aux1);
                printf("Pila Aux2:");
                mostrar(&aux2);

                system("pause");
                system("cls");
                break;
            }

            case 2: {
                system("cls");
                printf("Ejercicio 2: Cargar desde el teclado una pila llamada ORIGEN e inicializar en vacío la pila DESTINO. Pasar todos los \nelementos de la pila ORIGEN a la pila DESTINO.\n");
                Pila ORIGEN, DESTINO;
                inicpila(&ORIGEN);
                inicpila(&DESTINO);

                leer(&ORIGEN);
                leer(&ORIGEN);
                leer(&ORIGEN);
                leer(&ORIGEN);
                leer(&ORIGEN);

                mostrar(&ORIGEN);
                mostrar(&DESTINO);

                while (!pilavacia(&ORIGEN)) {
                    apilar(&DESTINO, desapilar(&ORIGEN));
                }

                mostrar(&ORIGEN);
                mostrar(&DESTINO);

                system("pause");
                system("cls");
                break;
            }

            case 3: {
                system("cls");
                printf("Ejercicio 3: Cargar desde teclado una pila DADA y pasar a la pila DISTINTOS todos aquellos elementos distintos \nal valor 8.\n");
                Pila DADA, DESTINO, aux;
                inicpila(&DADA);
                inicpila(&DESTINO);
                inicpila(&aux);

                printf("\nIngrese 7 valores aleatorios:\n");
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);

                while (!pilavacia(&DADA)) {
                    if (tope(&DADA) != 8) {
                        apilar(&aux, desapilar(&DADA));
                    }
                    else {
                        apilar(&DESTINO, desapilar(&DADA));
                    }
                }

                mostrar(&aux);
                mostrar(&DESTINO);

                system("pause");
                system("cls");
                break;
            }

            case 4: {
                system("cls");
                printf("Ejercicio 4: Cargar desde el teclado la pila ORIGEN e inicializar en vacío la pila DESTINO. Pasar los elementos de la \npila ORIGEN a la pila DESTINO, pero dej%cndolos en el mismo orden.\n", 160);
                Pila DADA, DESTINO, aux;
                inicpila(&DADA);
                inicpila(&DESTINO);
                inicpila(&aux);

                leer(&DADA);
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);

                printf("Pila DADA:");
                mostrar(&DADA);

                while (!pilavacia(&DADA)) {
                    apilar(&aux, desapilar(&DADA));
                }

                printf("Pila aux:");
                mostrar(&aux);

                while (!pilavacia(&aux)) {
                    apilar(&DESTINO, desapilar(&aux));
                }

                printf("Pila DESTINO:");
                mostrar(&DESTINO);

                system("pause");
                system("cls");
                break;
            }

            case 5: {
                system("cls");
                printf("Ejercicio 5: Cargar desde el teclado la pila DADA. Invertir la pila de manera que DADA contenga los elementos cargados \noriginalmente en ella, pero en orden inverso.\n");
                Pila DADA, aux1, aux2;

                inicpila(&DADA);
                inicpila(&aux1);
                inicpila(&aux2);

                printf("Ingresar 4 valores aleatorios:\n");
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);

                printf("\nPila Original:");
                mostrar(&DADA);

                while (!pilavacia(&DADA))
                {
                    apilar(&aux1, desapilar(&DADA));
                }

                mostrar(&aux1);
                system("pause");

                while (!pilavacia(&aux1)) {
                    apilar(&aux2, desapilar(&aux1));
                }

                while (!pilavacia(&aux2)) {
                    apilar(&DADA, desapilar(&aux2));
                }

                printf("Pila Final:");
                mostrar(&DADA);

                system("pause");
                system("cls");
                break;
            }

            case 6: {
                system("cls");
                printf("Ejercicio 6: Pasar el primer elemento (tope) de la pila DADA a su %cltima posici%cn (base), dejando los restantes\n elementos en el mismo orden.\n", 163, 162);
                Pila DADA, aux1, topFila;

                inicpila(&DADA);
                inicpila(&aux1);
                inicpila(&topFila);

                leer(&DADA);
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);

                printf("Pila Origen:");
                mostrar(&DADA);

                apilar(&topFila, desapilar(&DADA));

                while (!pilavacia(&DADA)) {
                    apilar(&aux1, desapilar(&DADA));
                }

                    apilar(&DADA, desapilar(&topFila));

                while (!pilavacia(&aux1)) {
                    apilar(&DADA, desapilar(&aux1));
                }

                printf("Pila Final:");
                mostrar(&DADA);

                system("pause");
                system("cls");
                break;
            }

            case 7: {
                system("cls");
                printf("Ejercicio 7: Pasar el %cltimo elemento (base) de la pila DADA a su primera posici%cn (tope), dejando los restantes \nelementos en el mismo orden.\n", 163, 162);
                Pila DADA, aux, base;

                inicpila(&DADA);
                inicpila(&aux);
                inicpila(&base);

                printf("Ingresar 4 valores aleatorios:\n");
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);
                leer(&DADA);

                printf("Pila Origen");
                mostrar(&DADA);

                while(!pilavacia(&DADA)) {
                    apilar(&aux, desapilar(&DADA));
                }

                apilar(&base, desapilar(&aux));

                while(!pilavacia(&aux)) {
                    apilar(&DADA, desapilar(&aux));
                }

                apilar(&DADA, desapilar(&base));

                printf("Pilas Finales");
                mostrar(&DADA);

                system("pause");
                system("cls");
                break;
            }

            case 8: {
                system("cls");
                printf("Ejercicio 8: Repartir los elementos de la pila MAZO en las pilas JUGADOR1 y JUGADOR2 en forma alternativa.\n");
                Pila MAZO, Jugador1, Jugador2;
                int f;

                inicpila(&MAZO);
                inicpila(&Jugador1);
                inicpila(&Jugador2);

                for (f = 0; f < 10; f++) {
                    int carta = (rand() % 10) + 1;
                    apilar(&MAZO, carta);
                }

                while (!pilavacia(&MAZO)) {
                    if (!pilavacia(&MAZO)) {
                        apilar(&Jugador1, desapilar(&MAZO));
                    }
                    if (!pilavacia(&MAZO)) {
                        apilar(&Jugador2, desapilar(&MAZO));
                    }
                }

                printf("\nMano Jugador 1:");
                mostrar(&Jugador1);

                printf("Mano Jugador 2:");
                mostrar(&Jugador2);

                system("pause");
                system("cls");
                break;
            }

            case 9: {
                system("cls");
                printf("Ejercicio 9: Comparar la cantidad de elementos de las pilas A y B. Mostrar por pantalla el resultado.");
                Pila A, B;
                int t, cantidad1, cantidad2, numero;

                inicpila(&A);
                inicpila(&B);

                printf("\nCu%cntos elementos deseas ingresar en la primera pila? ", 160);
                scanf("%i", &cantidad1);

                for (int i = 0; i < cantidad1; i++) {
                    printf("\nN%cmero %i: ", 163, i + 1);
                    scanf("%i", &numero);
                    apilar(&A, numero);
                }

                printf("\nCu%cntos elementos deseas ingresar en la segunda pila? ", 160);
                scanf("%i", &cantidad2);

                for (t = 0; t < cantidad2; t++) {
                    printf("\nN%cmero %i: ", 163, t + 1);
                    scanf("%i", &numero);
                    apilar(&B, numero);
                }

                system("cls");

                printf("Pila 1: ");
                mostrar(&A);
                printf("Pila 2: ");
                mostrar(&B);

                while (!pilavacia(&A) && !pilavacia(&B)) {
                    desapilar(&A);
                    desapilar(&B);
                }

                if (!pilavacia(&A)) {
                    printf("La pila A tiene m%cs elementos\n", 160);
                } else if (!pilavacia(&B)) {
                    printf("La pila B tiene m%cs elementos\n", 160);
                } else {
                    printf("Ambas pilas tienen la misma cantidad\n");
                }

                system("pause");
                system("cls");
                break;
            }

            case 10: {
                system("cls");
                printf("Ejercicio 9: Cargar las pilas A y B y luego compararlas, evaluando si son completamente iguales (en cantidad de \nelementos, valores que contienen y posici%cn de los mismos). Mostrar por pantalla el resultado.\n", 162);
                Pila PILA1, PILA2, aux1, aux2;
                int cantidad1, cantidad2, numero;
                int t, no_son_iguales;

                inicpila(&PILA1);
                inicpila(&PILA2);
                inicpila(&aux1);
                inicpila(&aux2);

                printf("Cu%cntos elementos deseas ingresar en la primera pila? ", 160);
                scanf("%i", &cantidad1);

                for (t = 0; t < cantidad1; t++) {
                    printf("\nN%cmero %i: ", 163, t + 1);
                    scanf("%i", &numero);
                    apilar(&PILA1, numero);
                }

                printf("\nCu%cntos elementos deseas ingresar en la segunda pila? ", 160);
                scanf("%i", &cantidad2);

                for (t = 0; t < cantidad2; t++) {
                    printf("\nN%cmero %i: ", 163, t + 1);
                    scanf("%i", &numero);
                    apilar(&PILA2, numero);
                }

                system("cls");

                while (!pilavacia(&PILA1) && !pilavacia(&PILA2)) {
                    if ((tope(&PILA1))==(tope(&PILA2))) {
                        apilar(&aux1, desapilar(&PILA1));
                        apilar(&aux2, desapilar(&PILA2));
                    } else {
                        printf("\nNo son iguales.\n");
                        no_son_iguales = 1;
                        break;
                    }
                }

                if(no_son_iguales != 1) {
                    printf("\nPila 1: ");
                    mostrar(&aux1);
                    printf("\nPila 2: ");
                    mostrar(&aux2);
                }

                system("pause");
                system("cls");
                break;
            }

            case 11: {
                system("cls");
                printf("Ejercicio 11: Suponiendo la existencia de una pila MODELO que no est%c vac%ca, eliminar de la pila DADA todos los \nelementos que sean iguales al TOPE de la pila MODELO.\n", 130, 161);
                Pila DADA, MODELO, aux;
                int m, numero, tp1;

                inicpila(&DADA);
                inicpila(&MODELO);
                inicpila(&aux);


                for (m = 0; m < 5; m++) {
                    printf("\nN%cmero %i: ", 163, m + 1);
                    scanf("%i", &numero);
                    apilar(&DADA, numero);
                }

                system("cls");
                mostrar(&DADA);

                printf("\nIngrese el valor a eliminar de la Pila: ");
                scanf("%i", &tp1);


                while (!pilavacia(&DADA)) {
                    if (tope(&DADA) != tp1) {
                        apilar(&aux, desapilar(&DADA));
                    }
                    else {
                        desapilar(&DADA);
                    }
                }

                while (!pilavacia(&aux)) {
                    apilar(&DADA, desapilar(&aux));
                }

                printf("\nLa pila actualizada: ");
                mostrar(&DADA);

                system("pause");
                system("cls");
                break;
            }

            case 12: {
                system("cls");
                 printf("Ejercicio 12: Suponiendo la existencia de una pila MODELO (vac%ca o no), eliminar de la pila DADA todos los elementos que existan en la pila MODELO.\n", 161);
                Pila DADA, MODELO, aux, auxMod;
                int numero, num2, cant;
                int r, h;

                inicpila(&DADA);
                inicpila(&MODELO);
                inicpila(&aux);
                inicpila(&auxMod);


                printf("Ingrese 7 valores aleatorios\n");
                for (r = 0; r < 7; r++) {
                    printf("\nN%cmero %i: ", 163, r + 1);
                    scanf("%i", &numero);
                    apilar(&DADA, numero);
                }

                system("cls");

                mostrar(&DADA);

                printf("Cu%cntos elementos tendr%c la pila? ", 160, 160);
                scanf("%i", &cant);

                for (h = 0; h < cant; h++) {
                    printf("\nN%cmero %i: ", 163, h + 1);
                    scanf("%i", &num2);
                    apilar(&MODELO, num2);
                }

                while(!pilavacia(&MODELO)) {
                    while(!pilavacia(&DADA)) {
                        if(tope(&DADA)==tope(&MODELO)) {
                            desapilar(&DADA);
                        }
                        else {
                            apilar(&aux,desapilar(&DADA));
                        }
                    }
                    while(!pilavacia(&aux)) {
                        apilar(&DADA,desapilar(&aux));
                    }
                    apilar(&auxMod,desapilar(&MODELO));
                }

                while(!pilavacia(&auxMod)) {
                    apilar(&MODELO,desapilar(&auxMod));
                }

                system("cls");

                printf("Pila actualizada:");
                mostrar(&DADA);
                printf("\nPila creada:");
                mostrar(&MODELO);

                system("pause");
                system("cls");
                break;
            }

            case 13: {
                system("cls");
                printf("Ejercicio 13: Suponiendo la existencia de una pila L%cMITE, pasar los elementos de la pila DADA que sean mayores o \niguales que el tope de LIMITE a la pila MAYORES, y los elementos que sean menores a la pila MENORES.\n", 214);
                Pila DADA, MAYORES, MENORES;
                int limite, x, numero;

                inicpila(&MAYORES);
                inicpila(&MENORES);
                inicpila(&DADA);

                printf("Ingrese 8 valores aleatorios\n");
                for (x = 0; x < 8; x++) {
                    printf("\nN%cmero %i: ", 163, x + 1);
                    scanf("%i", &numero);
                    apilar(&DADA, numero);
                }

                printf("\nIngres el valor del l%cmite: ", 161);
                scanf("%i", &limite);

                while (!pilavacia(&DADA)) {
                    if (tope(&DADA) >= limite) {
                        apilar(&MAYORES, desapilar(&DADA));
                    }
                    else {
                        apilar(&MENORES, desapilar(&DADA));
                    }
                }

                system("cls");

                printf("N%cmeros mayores:\n", 163);
                mostrar(&MAYORES);
                printf("N%cmeros menores:\n", 163);
                mostrar(&MENORES);

                system("pause");
                system("cls");
                break;
            }

            case 14: {
                system("cls");
                printf("Ejercicio 14: Determinar si la cantidad de elementos de la pila DADA es par. Si es par, pasar el elemento del tope de la pila DADA a la pila PAR y si es impar pasar el tope a la pila IMPAR (el ejercicio debe ser realizado SIN contar \nlos elementos)\n");
                Pila DADA, PAR, IMPAR;
                int g, numero;

                inicpila(&DADA);
                inicpila(&PAR);
                inicpila(&IMPAR);

                printf("Ingrese 6 valores aleatorios\n");
                for (g = 0; g < 6; g++) {
                    printf("\nN%cmero %i: ", 163, g + 1);
                    scanf("%i", &numero);
                    apilar(&DADA, numero);
                }

                while (!pilavacia(&DADA)) {
                    if (tope(&DADA) % 2 == 0) {
                        apilar(&PAR, desapilar(&DADA));
                    }
                    else if (tope(&DADA) % 2 == 1) {
                        apilar(&IMPAR, desapilar(&DADA));
                    }
                }

                system("cls");

                printf("Pila N%cmeros Pares:", 163);
                mostrar(&PAR);
                printf("Pilas N%cmeros Impares", 163);
                mostrar(&IMPAR);

                system("pause");
                system("cls");
                break;
            }

            case 0: {
                printf("\nSaliendo del programa...\n");
                break;
            }
            if (option != 0) {
                system("pause");
            }
        }
    }
    while (option != 0);
    return 0;
}
