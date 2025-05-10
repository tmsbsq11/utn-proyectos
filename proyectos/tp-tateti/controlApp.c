#include "controApp.h"
#include "turnos.h"
#include "stPlayer.h"
#include "tablero.h"
#include "victory.h"
#include "menus.h"


void inicializarApp(){
    char tablero[3][3];

    rellenarTablero(tablero);
    controlApp(tablero);
}
void controlApp(char tablero[3][3]){ ///agregar un int que recuerde la selección de jugador que se enviara al ser llamada, esa selección decidirá a qué función llamar (máquina o jugador 2)
    int select = 0;

    stPlayer Player1 = {"Player 1", 120, 0};
    stPlayer Player2 = {"Player 2", 111, 1};
    stPlayer CPU = {"Player CPU", 111, 1};
    select = seleccionModo();

    mostrarTablero(tablero);
    if(select == 1){ JvsJ(Player1, Player2, tablero); }
    else { JvsCPU(Player1, CPU, tablero); }

    resetApp();
}

void JvsCPU(stPlayer Player, stPlayer CPU, char tablero[3][3]){
    int tTotal = 0, vic = 0, turno = 0;

    while(tTotal < 9 && !vic){
        if(turno == Player.turn){
            turnoJugador(tablero, Player.symbol);
            mostrarTablero(tablero);
            vic = checkVictory(tablero, Player.symbol);
            victoria(vic, Player.id);
        }
        else {
            turnoMaquina(tablero, CPU.symbol);
            mostrarTablero(tablero);
            vic = checkVictory(tablero, CPU.symbol);
            victoria(vic, CPU.id);
        }
        tTotal++;
        turno = 1 - turno;
    }
}
void JvsJ(stPlayer Player1, stPlayer Player2, char tablero[3][3]){
    int tTotal = 0, vic = 0, turno = 0;

    while(tTotal < 9 && !vic){
        if(turno == Player1.turn){
            turnoJugador(tablero, Player1.symbol);
            mostrarTablero(tablero);
            vic = checkVictory(tablero, Player1.symbol);
            victoria(vic, Player1.id);
        } else {
            turnoJugador(tablero, Player2.symbol);
            mostrarTablero(tablero);
            vic = checkVictory(tablero, Player2.symbol);
            victoria(vic, Player2.id);
        }
        tTotal++;
        turno = 1 - turno;
    }
}

