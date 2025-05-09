#ifndef STALUMNO_H_INCLUDED
#define STALUMNO_H_INCLUDED

typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

int cargaAlumnos(stAlumno Alumnos[]);
void mostrarAlumnoPorMatricula(stAlumno Alumnos[], int validos);
void ordenarPorMatricula(stAlumno Alumnos[], int validos);
void mostrarArregloAlumnos(stAlumno Alumnos[], int validos);

#endif // STALUMNO_H_INCLUDED
