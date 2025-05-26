#include "controApp.h"
#include "Jugador.h"
#include "tablero.h"
#include "victory.h"
#include "menus.h"
#include "turnos.h"


void inicializarApp(){
    char tablero[3][3];

    rellenarTablero(tablero);
    controlApp(tablero);
}
void controlApp(char tablero[3][3]){
    int select = 0;

    stJugador Player1 = {"Gonzalo", "Gallego", "email@gmail.com", "1234", 'G'};
    stJugador Player2 = {"Romina", "Gimenez", "email@gmail.com", "1234", 'G'};
    stJugador CPU = {"CPU", "PC", "email@gmail.com", "1234", 'X'};
    select = seleccionModo();

    mostrarTablero(tablero);
    if(select == 1){ JvsJ(Player1, Player2, tablero); }
    else { JvsCPU(Player1, CPU, tablero); }

    resetApp();
}

void JvsCPU(stJugador Player, stJugador CPU, char tablero[3][3]){
    int tTotal = 0, vic = 0, turno = 1;

    while(tTotal < 9 && !vic){
        if(turno == 1){
            turnoJugador(Player, 0, tablero);
            mostrarTablero(tablero);
            vic = checkVictory(tablero, Player.figura);
            victoria(vic, Player.nombre);
        }
        else { turnoJugador(CPU, -1, tablero); }

        tTotal++;
        turno = 1 - turno;
    }
}
void JvsJ(stJugador Player1, stJugador Player2, char tablero[3][3]){

}

