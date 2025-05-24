#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED

#include "Jugador.h"

stJugador dataLogin();
void login();
int validarPassword(stJugador data, char pass[]);
int buscarJugadorLogin(stJugador data[], int vData, stJugador aux);
void ocultarPassw(char *pass, int tmax);

#endif // LOGIN_H_INCLUDED
