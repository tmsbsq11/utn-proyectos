#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "turnos.h"
#include "Jugador.h"


void turnoJugador(stJugador jugador, int pos, char tablero[3][3]){
    int isCPU = 0;

    if(pos == -1) {
        isCPU = 1;
        pedirPosicion(isCPU);
    } else { pos = pedirPosicion(isCPU); }

    buscarPosicion(jugador, pos, tablero, isCPU);

}
void buscarPosicion(stJugador jugador, int pos, char tablero[3][3], int isCPU){
    int count = 1, f = 0;

    while(!f){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(pos == count){
                    if(tablero[i][j] == ' '){
                        printf("%c", jugador.figura);
                        f = 1;
                    } else { pos = pedirPosicion(isCPU); }
                } else { count++; }
            }
        }
    }
}

int pedirPosicion(int isCpu){
    int f = 0, pos;

    if(isCpu){ pos = rand()%8+1; }
    else {
        printf("\nSeleccione posicion 1-9..\n");
        while(!f){
            scanf("%d", &pos);
            if(pos >48 && pos <58){
                f = 1;
            } else { printf("\nSeleccion incorrecta ingrese entre 1-9..\n"); }
        }

    }

    return pos;
}
