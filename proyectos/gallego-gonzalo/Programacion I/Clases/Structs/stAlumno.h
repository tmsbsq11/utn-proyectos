#ifndef STALUMNO_H_INCLUDED
#define STALUMNO_H_INCLUDED

typedef struct{
    int matricula;
    char nombre[30];
    char genero;
} stAlumno;

void mostrarAlumno(stAlumno);
stAlumno crearAlumno();
char genero();
int matricula();

#endif // STALUMNO_H_INCLUDED
