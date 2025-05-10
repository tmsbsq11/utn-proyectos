#ifndef CONTROAPP_H_INCLUDED
#define CONTROAPP_H_INCLUDED
#include "stPlayer.h"

void controlApp(char tablero[3][3]);
void inicializarApp();
void JvsCPU(stPlayer Player, stPlayer CPU, char tablero[3][3]);
void JvsJ(stPlayer Player1, stPlayer Player2, char tablero[3][3]);

#endif // CONTROAPP_H_INCLUDED
