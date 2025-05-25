#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED

#include "Jugador.h"

void turno(stJugador jugador, int pos, char tablero[3][3]);
int pedirPosicion(int pos, int isCPU);

#endif // TURNOS_H_INCLUDED
