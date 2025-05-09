#include <stdio.h>
#include <stdlib.h>
#include "compat.h"
#include "stAlumno.h"

#define DIM 20

int main() {
    stAlumno Alumnos[DIM];
    int validos = cargaAlumnos(Alumnos);

    printf("\nLista de alumnos sin ordenar:\n");
    mostrarArregloAlumnos(Alumnos, validos);

    clearsc();
    printf("\nBuscar alumno por matricula\n");
    mostrarAlumnoPorMatricula(Alumnos, validos);

    ordenarPorMatricula(Alumnos, validos);
    printf("\nLista de alumnos ordenada por matrícula:\n");
    mostrarArregloAlumnos(Alumnos, validos);

    return 0;
}

