#ifndef STALUMNO_H_INCLUDED
#define STALUMNO_H_INCLUDED

typedef struct {
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

int cargaAlumnos(stAlumno Alumnos[]);
void mostrarAlumnoPorMatricula(stAlumno Alumnos[], int validos);
void ordenarPorSeleccionMatricula(stAlumno Alumnos[], int validos);
void mostrarArregloAlumnos(stAlumno Alumnos[], int validos);
void imprimirDatosEncontrado(stAlumno Alumnos[], int i);
void mostrarAlumnosPorGenero(stAlumno Alumnos[], int validos, char genero);
void buscarAlumnosPorGenero(stAlumno Alumnos[], int validos);
int compararStrings(stAlumno a, stAlumno b);
void ordenarPorInsercionNombre(stAlumno Alumnos[], int validos);
int contadorGenero(stAlumno Alumnos[], int validos, char genero);
void contarAlumnosPorGenero(stAlumno Alumnos[], int validos);
void insertarNuevoElemento(stAlumno Alumnos[], int validos);
void menuPrint();
void menuSwitch(stAlumno Alumnos[], int validos);

#endif // STALUMNO_H_INCLUDED
