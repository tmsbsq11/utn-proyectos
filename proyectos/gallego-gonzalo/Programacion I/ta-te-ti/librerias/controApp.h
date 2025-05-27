#ifndef CONTROAPP_H_INCLUDED
#define CONTROAPP_H_INCLUDED
#include "Jugador.h"

void controlApp(char tablero[3][3]);
void inicializarApp();
void accionesPorTurno(stJugador player, char tablero[3][3], int vic, int isCPU);
void modoDeJuego(stJugador player1, stJugador player2, char tablero[3][3], int isCPU);


#endif // CONTROAPP_H_INCLUDED
