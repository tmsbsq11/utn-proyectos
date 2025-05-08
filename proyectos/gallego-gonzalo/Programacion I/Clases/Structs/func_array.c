#include "func_array.h"
#include "stAlumno.h"
#define ESC 27

void arrAlumno(stAlumno *arr, int tam, int *val){
    char tecla = 0;

    printf("Carge en un array hasta 30 Alumnos..\n\n");
    while(tecla != ESC && *val < tam){
        arr[*val] = crearAlumno();
        (*val)++;
        printf("Desea continuar?. ESC para salir\n");
        tecla = getch();
        system("cls");
    }
}
void buscarAlumno(stAlumno *arr, int v, int bus){
    for(int i=0; i< v; i++){
        if(bus == arr[i].matricula){
            mostrarAlumno(arr[i]);
        }
        else { printf("Alumno inexistente.\n"); }
    }
}
