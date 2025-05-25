#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "turnos.h"
#include "Jugador.h"


void turno(stJugador jugador, int pos, char tablero[3][3]){
    int count = 1;
    int isCPU = 0;
    int f = 0;

    if(pos == -1) {
        isCPU = 1;
        pedirPosicion(pos, isCPU);
    }

    while(!f){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(pos == count){
                    if(tablero[i][j] == ' '){
                        printf("%c", jugador.figura);
                        f = 1;
                    } else { pedirPosicion(pos, isCPU); }
                } else { count++; }
            }
        }
    }
}

int pedirPosicion(int pos, int isCpu){
    int f = 0;

    if(isCpu){ pos = rand()%8+1; }
    else {
        printf("\nPosicion ocupada, elija nuevamente 1-9 ..\n");
        while(!f){
            scanf("%d", &pos);
            if(pos >48 && pos <58){
                f = 1;
            } else { printf("\nSeleccion incorrecta ingrese entre 1-9..\n"); }
        }

    }

    return pos;
}
