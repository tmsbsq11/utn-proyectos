#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ESC 27

typedef struct{
    int matricula;
    char nombre[30];
    char genero;
} stAlumno;

void menu();
void mostrarAlumno(stAlumno);
void arrAlumno(stAlumno*, int, int*);
char genero();
int matricula();
stAlumno crearAlumno();


int main()
{
    menu();
    return 0;
}

void menu(){
    char opt = 0;

    printf("Seleccione ejercicio a revisar..\n");
    opt = getch();

    switch(opt){
        case '1':{
            stAlumno Salon[30];
            int tam = sizeof(Salon)/ sizeof(Salon[0]);
            int Salonval = 0;
            system("cls");
            printf("Carge en un array hasta 30 Alumnos..\n\n");
            system("pause");
            arrAlumno(&Salon, tam, &Salonval);
            for(int i=0; i<Salonval; i++){ mostrarAlumno(Salon[i]); }

            break;
        }
        case '2': {
            stAlumno Gonzalo;
            Gonzalo = crearAlumno();
            mostrarAlumno(Gonzalo);
        break;}
    }
}
void arrAlumno(stAlumno *arr, int tam, int *val){
    char tecla = 0;
    while(tecla != ESC && *val < tam){
        system("cls");
        arr[*val] = crearAlumno();
        (*val)++;
        printf("Desea continuar?. ESC para salir\n");
        tecla = getch();
    }
}
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
