#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED
#define DATAJ "dataJugadores.dat"

#include "Jugador.h"

void guardarJugador(stJugador data);
void cargarArchivo(char name[]);
void cargarArchivoArr(stJugador data[], int *i);
int cantEntidades(FILE *file, size_t tam);


#endif // ARCHIVOS_H_INCLUDED
