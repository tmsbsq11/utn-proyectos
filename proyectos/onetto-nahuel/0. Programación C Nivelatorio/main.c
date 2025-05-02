#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int option;

    do {
        printf("\nSeleccione del 1 al 16 para ver los ejercicios respectivos o presione 0 para terminar: ");
        scanf("%d", &option);

        switch (option) {

            case 1: {
                printf("\nEjercicio 1) Una persona va a invertir su capital en un banco y desea saber cu%cnto dinero ganar%c despu%cs de un mes si el banco paga el 2%c mensual.\n\n", 160, 160, 130, 37);
                float dinero = 0;

                printf("Insertar suma total: ");
                scanf("%f", &dinero);

                float interes = (2*dinero)/100;
                printf("El interes es igual a: %.2f  \n", interes);

                system("pause");
                system("cls");
                break;
            }

            case 2: {
                printf("\nEjercicio 2) Una tienda ofrece un descuento del 15%c sobre el total de la compra y un cliente desea saber cu%cnto deber%c \npagar finalmente por su compra.\n\n", 37, 160, 160);
                float compra = 0;

                printf("Precio compra: ");
                scanf("%f", &compra);

                float total_compra = (15*compra)/100;
                printf("Total de la compra con descuento: %.2f \n", total_compra);

                system("pause");
                system("cls");
                break;
            }

            case 3: {
                printf("\nEjercicio 3) Un maestro desea saber qu%c porcentaje de hombres y de mujeres hay en un grupo de estudiantes.\n\n", 130);
                float total_H = 0;
                float total_M = 0;

                printf("Cantidad Hombres: ");
                scanf("%f", &total_H);

                printf("Cantidad Mujeres: ");
                scanf("%f", &total_M);

                int alumnos = total_H + total_M;
                printf("Total Alumnos: %i\n", alumnos);

                float promedio_H = (total_H*100)/alumnos;
                float promedio_M = (total_M*100)/alumnos;
                printf("El promedio de Hombres es: %.2f\n", promedio_H);
                printf("El promedio de Mujeres es: %.2f", promedio_M);

                system("pause");
                system("cls");
                break;
            }

            case 4: {
                 printf("\nEjercicio 4) Determinar si un estudiante aprueba o reprueba un curso, sabiendo que aprobar%c si su promedio de tres \ncalificaciones es mayor o igual a 7. Caso contrario reprueba.\n\n", 160);
                float nota1 = 0;
                float nota2 = 0;
                float nota3 = 0;

                printf("Nota parcial 1: ");
                scanf("%f", &nota1);
                printf("Nota parcial 2: ");
                scanf("%f", &nota2);
                printf("Nota parcial 3: ");
                scanf("%f", &nota3);

                float nota_total = (nota1+nota2+nota3)/3;
                if (nota_total >= 7) {
                    printf("La nota es %.2f suficiente para APOROBAR", nota_total);
                }
                else {
                    printf("La nota final es %.2f y no es suficiente para APROBAR", nota_total);
                }

                system("pause");
                system("cls");
                break;
            }

            case 5: {
                printf("\nEjercicio 5) En un almacén se hace un 20%c de descuento a los clientes cuya compra supere los %c5.000. Se desea saber cu%cl ser%c la cantidad que pagar%c una persona por su compra.\n\n", 37, 36, 160, 160, 160);
                float compra_carrito = 0;

                printf("Valor de Carrito: ");
                scanf("%f", &compra_carrito);

                if (compra_carrito > 5000) {
                    float descuento = (20*compra_carrito)/100;
                    printf("El valor total de su compra es %.2f ", descuento);
                }
                else {
                    printf("El valor total de su compra es %f", compra_carrito);
                }

                system("pause");
                system("cls");
                break;
            }

            case 6: {
                printf("\nEjercicio 6) Un obrero necesita calcular su salario semanal, el cual se obtiene de la siguiente manera: si trabaja 40 \nhoras o menos se le paga %c300 por hora, si trabaja más de 40 horas se le paga %c300 por cada una de las primeras 40 \nhoras y %c400 por cada hora extra.\n\n", 36, 36, 36);
                int horas_trabajo = 0;
                int salario_ext = 0;
                int salario_total = 0;
                printf("Introduzca cantidad de horas semanales: ");
                scanf("%i", &horas_trabajo);

                if (horas_trabajo <= 40) {
                    salario_total = 300*horas_trabajo;
                }
                else {
                    int horas_extras = horas_trabajo - 40;
                    salario_total = (40 * 300) + (horas_extras * 400);
                    salario_ext = horas_extras * 400;
                }

                printf("Total ganado semanal: $%i\n", salario_total);
                printf("El Salario extra total fue de: $%i", salario_ext);

                system("pause");
                system("cls");
                break;
            }

            case 7: {
                printf("\nEjercicio 7) Desarrolle un algoritmo que lea dos n%cmeros y los imprima en forma ascendente.\n\n", 163);
                int num1 = 0;
                int num2 = 0;

                printf("Ingrese el primer n%cmero: ", 163);
                scanf("%i", &num1);

                printf("Ingrese el segundo n%cmero: ", 163);
                scanf("%i", &num2);

                if (num1 < num2) {
                printf("N%cmeros en orden: %i, %d\n", 163, num1, num2);
                }
                else {
                    printf("N%cmeros en orden: %i, %d\n", 163, num2, num1);
                }

                system("pause");
                system("cls");
                break;
            }

            case 8: {
                printf("\nEjercicio 8) Hacer un algoritmo que calcule el total a pagar por la compra de camisas. Si se compran tres camisas o m%cs se aplica un descuento del 20%c sobre el total de la compra, y si son menos de tres camisas un descuento del 10%c.\n\n", 160, 37, 37);
                int n_cami = 0;
                int p_cami = 1500;
                int tot_cami = 0, desc = 0;

                printf("N%cmero de camisas a comprar: ", 163);
                scanf("%i", &n_cami);

                tot_cami = n_cami * p_cami;

                if (n_cami >= 3) {
                    desc = (20*tot_cami)/100;
                }
                else {
                    desc = (10*tot_cami)/100;
                }

                printf("El precio total es: $%.2i\n", tot_cami);
                printf("El descuento equivale a: $%.2i", desc);

                system("pause");
                system("cls");
                break;
            }

            case 9: {
                printf("\nEjercicio 9) Leer 2 n%cmeros. Si son iguales, multiplicarlos, si el primero es mayor que el segundo, restarlos, y si no, sumarlos.\n\n", 163);
                int pvalor1 = 0;
                int pvalor2 = 0;

                printf("Ingrese el primer n%cmero: ", 163);
                scanf("%i", &pvalor1);
                printf("Ingrese el segundo n%cmero: ", 163);
                scanf("%i", &pvalor2);

                if (pvalor1 == pvalor2) {
                    printf("Ambos valores son iguales");
                }
                else if (pvalor1 > pvalor2) {
                    printf("El primer valor es mayor");
                }
                if (pvalor1 < pvalor2) {
                    printf("El segundo valor es mayor");
                }

                system("pause");
                system("cls");
                break;
            }

            case 10: {
                printf("\nEjercicio 10) Leer tres n%cmeros diferentes e imprimir el mayor de ellos.\n\n", 163);
                int vat1, vat2, vat3;
                int mayor = 0;

                printf("Ingrese el primer n%cmero: ", 163);
                scanf("%i", &vat1);
                printf("Ingrese el segundo n%cmero: ", 163);
                scanf("%i", &vat2);
                printf("Ingrese el tercer n%cmero: ", 163);
                scanf("%i", &vat3);

                if (mayor < vat1) {
                    mayor = vat1;
                }
                if (mayor < vat2) {
                    mayor = vat2;
                }
                if (mayor < vat3) {
                    mayor = vat3;
                }

                printf("Este es el mayor n%cmero %i", 163, mayor);

                system("pause");
                system("cls");
                break;
            }

            case 11: {
                printf("\nEjercicio 11) Calcular el promedio de un estudiante que tiene 7 calificaciones en la materia Programaci%cn A.\n\n", 162);
                float nt1, nt2, nt3, nt4, nt5, nt6 , nt7;
                float prom_7 = 0;

                printf("TP1: ");
                scanf("%f", &nt1);
                printf("TP2: ");
                scanf("%f", &nt2);
                printf("Parcial 1: ");
                scanf("%f", &nt3);
                printf("TP3: ");
                scanf("%f", &nt4);
                printf("TP4: ");
                scanf("%f", &nt5);
                printf("Parcial 2: ");
                scanf("%f", &nt6);
                printf("TP Final: ");
                scanf("%f", &nt7);

                prom_7 = (nt1 + nt2 + nt3 + nt4 + nt5 + nt6 + nt7)/7;

                if (prom_7 > 7.51) {
                    printf("El promedio de todas las notas es: %.2f y est%c para PROMOCIONAR", prom_7, 160);
                }
                else if (prom_7 <= 6.4) {
                    printf("El promedio de todas las notas es: %.2f y est%c para DESAPROBAR", prom_7, 160);
                }
                else {
                    printf("El promedio de todas las notas es: %.2f y est%c para APROBAR la cursada", prom_7, 160);
                }

                system("pause");
                system("cls");
                break;
            }

            case 12: {
                printf("\nEjercicio 12) Leer 10 n%cmeros y obtener su cubo y su cuarta.\n\n", 163);
                int nt10[10];
                int i;

                printf("Ingrese 10 n%cmeros aleatorios:\n", 163);
                for (i=0; i<10; i++) {
                    printf("N%cmero %i: ", 163, i + 1);
                    scanf("%i", &nt10[i]);
                }

                printf("Resultados:\n");
                for (i=0; i<10; i++) {
                    int cubo = nt10[i] * nt10[i] * nt10[i];
                    int cuarta = nt10[i] * nt10[i] * nt10[i] * nt10[i];
                    printf("N%cmero: %i --- Al Cubo: %i --- A la Cuarta: %i\n", 163, nt10[i], cubo, cuarta);
                }

                system("pause");
                system("cls");
                break;
            }

            case 13: {
                printf("\nEjercicio 13) Leer 10 n%cmeros e imprimir solamente los positivos.\n\n", 163);
                int nt10[10];
                int i;
                int positivos[10];
                int p = 0;

                printf("Ingrese 10 n%cmeros aleatorios:\n", 163);
                for (i=0; i<10; i++) {
                    printf("N%cmero %i: ", 163, i + 1);
                    scanf("%i", &nt10[i]);
                }

                for (i=0; i<10; i++) {
                    if (nt10[i] > 0) {
                        positivos[p] = nt10[i];
                        p++;
                    }
                }

                if (p > 0) {
                    printf("N%cmeros positivos: \n", 163);
                    for (i = 0; i < p; i++) {
                        printf("%i ", positivos[i]);
                    }
                } else {
                    printf("No se encontraron n%cmeros positivos\n", 163);
                }

                system("pause");
                system("cls");
                break;
            }

            case 14: {
                printf("\nEjercicio 14) Leer 15 n%cmeros, convertirlos en positivos e imprimirlos.\n\n", 163);
                int nt15 [15];
                int f;

                printf("Ingrese 15 n%cmeros aleatorios:\n", 163);
                for (f=0; f<15; f++) {
                    printf("N%cmero %i: ", 163, f + 1);
                    scanf("%i", &nt15[f]);
                }

                for (f=0; f<15; f++){
                    if (nt15[f] < 0) {
                        nt15[f] = nt15[f] * (-1);
                    }
                }

                printf("Los valores reconvertidos a Positivos:\n");
                for (f=0; f<15; f++) {
                    printf("%i ", nt15[f]);
                }

                system("pause");
                system("cls");
                break;
            }

            case 15: {
                printf("\nEjercicio 15) Suponga que se tiene un conjunto de calificaciones de un grupo de 40 estudiantes. Realizar un algoritmo \npara calcular la calificaci%cn promedio y la calificaci%cn m%cs baja de todo el grupo.\n\n", 162, 162, 160);
                float gne40[40];
                float minp = 10;
                float summ = 0;
                int x;

                srand(time(NULL));

                for (x = 0; x < 40; x++) {
                    gne40[x] = 4 + pow(((float)rand() / RAND_MAX), 2) * 6; //Aumenta la cantidad de notas superiores a 6.
                    printf("%.2f ", gne40[x]);

                    summ += gne40[x];
                    if (gne40[x] < minp) {
                        minp = gne40[x];
                    }
                }
                printf("\n\nEl promedio del curso es de: %.2f", summ / 40);
                printf("\nLa peor nota del curso fue: %.2f\n", minp);

                system("pause");
                system("cls");
                break;
            }

            case 16: {
                printf("\nEjercicio 16) Calcular e imprimir la tabla de multiplicar de un n%cmero cualquiera. Imprimir el multiplicando, \nel multiplicador y el producto.\n\n", 163);
                int v;
                srand(time(NULL));
                int ale1 = (rand() % 100) + 1;

                printf("Tabla de multiplicar del %i:\n", ale1);
                for (v = 1; v <= 10; v++) {
                    printf("%d x %d = %d\n", ale1, v, ale1 * v);
                }
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
