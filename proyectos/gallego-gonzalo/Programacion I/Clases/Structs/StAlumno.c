#include "stAlumno.h"
#include <stdio.h>
#include <string.h>

void mostrarAlumno(stAlumno Alumno){
    printf("\n");
    printf("Nombre: %s\n", Alumno.nombre);
    printf("Genero: %c\n", Alumno.genero);
    printf("Matricula: %d\n", Alumno.matricula);
    printf("---------------------------------------------");
}
stAlumno crearAlumno(){
    stAlumno Alumno;


    printf("Nombre:\n");
    fflush(stdin);
    gets(Alumno.nombre);

    Alumno.genero = genero();
    Alumno.matricula = matricula();


    return Alumno;
}

int matricula(){
    int mat = 0;

    while(!mat){
        int aux = 0;
        printf("Matricula:\n");
        if(scanf("%d", &aux) && aux < 1000000){ mat = aux; }
        else {
            fflush(stdin);
            system("cls");
            printf("Error, ingrese nuevamente.\n\n");
        }
    }
    return mat;
}

char genero(){
    char g;
    int fGen = 0;

    while(!fGen){
        printf("Genero(M/F):\n");
        g = getch();
        if(toupper(g) == 77 || toupper(g) == 70){
            fGen = 1;
        } else {
            fflush(stdin);
            system("cls");
            printf("Opcion incorrecta, ingrese nuevamente.\n");
        }
    }
    return g;
}
