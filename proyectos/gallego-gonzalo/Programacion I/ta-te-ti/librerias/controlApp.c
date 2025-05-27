#include <time.h>
#include "controApp.h"
#include "Jugador.h"
#include "tablero.h"
#include "victory.h"
#include "menus.h"
#include "turnos.h"


void inicializarApp(){
    char tablero[3][3];
    srand(time(NULL));
    rellenarTablero(tablero);
    controlApp(tablero);
}

void controlApp(char tablero[3][3]){
    int select = 0;

    stJugador Player1 = {"Gonzalo", "Gallego", "email@gmail.com", "1234", 'G'};
    stJugador Player2 = {"Romina", "Gimenez", "email@gmail.com", "1234", 'R'};
    stJugador CPU = {"CPU", "PC", "email@gmail.com", "1234", 'X'};
    select = seleccionModo();

    mostrarTablero(tablero);
    if(select == 1){ modoDeJuego(Player1, Player2, tablero, 0); }
    else { modoDeJuego(Player1, Player2, tablero, -1); }

    resetApp();
}

void modoDeJuego(stJugador player1, stJugador player2, char tablero[3][3], int isCPU){
    int tTotal = 0, vic = 0, turno = 1;

    while(tTotal < 9 && !vic){
        if(turno){ accionesPorTurno(player1, tablero, vic, 0); }
        else{ accionesPorTurno(player2, tablero, vic, isCPU); }
        turno = 1 - turno;
    }
    if(!vic) { printf("EMPATE!\n"); }
}

void accionesPorTurno(stJugador player, char tablero[3][3], int vic, int isCPU){
    turnoJugador(player, isCPU, tablero);
    mostrarTablero(tablero);
    vic = checkVictory(tablero, player.figura);
    victoria(vic, player.nombre);
}
