#ifndef CONTROAPP_H_INCLUDED
#define CONTROAPP_H_INCLUDED
#include "Jugador.h"

void controlApp(char tablero[3][3]);
void inicializarApp();
void JvsCPU(stJugador Player, stJugador CPU, char tablero[3][3]);
void JvsJ(stJugador Player1, stJugador Player2, char tablero[3][3]);

#endif // CONTROAPP_H_INCLUDED
