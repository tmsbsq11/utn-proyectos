#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

typedef struct{
    char nombre[20];
    char apellido[20];
    char email[40];
    char contra[50];
    char figura;
}stJugador;

void mostrarJugador(stJugador data);

#endif // JUGADOR_H_INCLUDED
