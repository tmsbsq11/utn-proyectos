#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stAlumno.h"
#include "compat.h"

#define DIM 20


//punto 1, hacer una función que cargue alumnos hasta que el usuario decida cuando parar
int cargaAlumnos(stAlumno Alumnos[]) {
    int aux, limite=0;
    char control = 'x', gen = 'x';

    int i=0;
    while((control != 's')&&(limite<DIM)) {
        printf("\nIngrese numero de matricula: ");
        fflush(stdin);
        scanf("%d", &Alumnos[i].matricula);
        getchar();
        printf("\nIngrese nombre del alumno: ");
        fflush(stdin);
        fgets(Alumnos[i].nombre, sizeof(Alumnos[i].nombre), stdin);
        Alumnos[i].nombre[strcspn(Alumnos[i].nombre, "\n")] = '\0'; //borra el enter

        printf("\nIngrese genero del alumno (m, f, o): ");
        do {
            scanf(" %c", &gen);
        }while((gen!='m')&&(gen!='f')&&(gen!='o'));
        Alumnos[i].genero = gen;

        printf("\n's':SALIR: ");
        fflush(stdin);
        control = getch();
        i++;
    }
    return i;
}


//punto 2
void mostrarArregloAlumnos(stAlumno Alumnos[], int validos) {
        printf("\nSe cargaron %d alumnos.\n", validos);
        for (int i = 0; i < validos; i++) {
        printf("\nAlumno %d:\n", i + 1);
        printf("Matrícula: %d\n", Alumnos[i].matricula);
        printf("Nombre: %s\n", Alumnos[i].nombre);
        printf("Género: %c\n", Alumnos[i].genero);
    }
}

//punto 3
void mostrarAlumnoPorMatricula(stAlumno Alumnos[], int validos) {
    int matriculaBuscada;
    int encontrado = 0;

    printf("\nIngrese la matrícula a buscar: ");
    scanf("%d", &matriculaBuscada);

    for (int i = 0; i < validos; i++) {
        if (Alumnos[i].matricula == matriculaBuscada) {
            printf("\nAlumno encontrado:\n");
            printf("Matrícula: %d\n", Alumnos[i].matricula);
            printf("Nombre: %s\n", Alumnos[i].nombre);
            printf("Género: %c\n", Alumnos[i].genero);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNo se encontró un alumno con esa matrícula.\n");
    }
}


//punto 4
void ordenarPorMatricula(stAlumno Alumnos[], int cantidad) {
    int i, j, min;
    stAlumno aux;

    for (i = 0; i < cantidad - 1; i++) { //bucle ordenados
        min = i;    //min = posicion inicial, luego, verificar a partir de i + 1 los no ordenados
        for (j = i + 1; j < cantidad; j++) { //bucle sin ordenar
            if (Alumnos[j].matricula < Alumnos[min].matricula) {
                min = j;
            }
        }
        if (min != i) { //si min no está ya en la pos. i, realizar intercambio
            aux = Alumnos[i];
            Alumnos[i] = Alumnos[min];
            Alumnos[min] = aux;
        }
    }
}



