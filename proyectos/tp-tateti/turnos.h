#ifndef TURNOS_H_INCLUDED
#define TURNOS_H_INCLUDED

void turnoJugador(char tablero[3][3], char);
void turnoMaquina(char tablero[3][3], char);
int checkVictory(char tablero[3][3], char letra);
void victoria(int n, char name[]);

#endif // TURNOS_H_INCLUDED
