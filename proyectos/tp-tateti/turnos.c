#include "turnos.h"
#include "stPlayer.h"
#include <stdio.h>
#include <stdlib.h>
#include "stPlayer.h"

void ingresarValor(char tablero[3][3]){ ///agregar un int que recuerde la selección de jugador que se enviara al ser llamada, esa selección decidirá a qué función llamar (máquina o jugador 2)
    int tTotal = 0, vic = 0;
    int turno = 0;
    int selec = 2;
    char winner;

    stPlayer Player1 = {"Player 1", 120, 0};
    stPlayer Player2 = {"Player 2", 111, 1};
    stPlayer CPU = {"Player CPU", 111, 1};


    while(tTotal < 9 && !vic){

        if(turno == Player1.turn){
            turnoJugador(tablero, Player1.symbol);
            tTotal++;
            mostrarTablero(tablero);
            vic = checkVictory(tablero, Player1.symbol);
            victoria(vic, Player1.id);
        }
        if(turno == CPU.turn) {
            turnoMaquina(tablero, CPU.symbol);
            tTotal++;
            mostrarTablero(tablero);
            vic = checkVictory(tablero, CPU.symbol);
            victoria(vic, CPU.id);
        }
        turno = 1 - turno;
        }


}

void victoria(int n, char name[]){
    if (n == 1){
        printf("victoria!! %s", name);
    }
}
void turnoJugador(char tablero[3][3], char symbol){
    int flag = 0;
    char aux;

    while(!flag){
        printf("seleccione\n");
        fflush(stdin);
        aux = getch() - '0'; ///al restarle el ascii de 0 al numero seleccionado en ascii, te queda el mismo numero como si fuera int.

        int count = 1;

        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                    if(count == aux){
                        if(tablero[i][j] != 120 && tablero[i][j] != 111){
                            tablero[i][j] = symbol;
                            flag = 1;
                        }
                    }
                    count++;
            }
        }
    }
}
void turnoMaquina(char tablero[3][3], char symbol){ ///fijarse que la maquina aveces pierde turno.
    int flag = 0;

    while(!flag){
        int count = 0;
        int pos = rand()%10;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(pos == count){
                        if(tablero[i][j] != 120 && tablero[i][j] != 111){
                            tablero[i][j] = symbol;
                            flag = 1;
                        }
                    }
                    count++;
                }
            }
    }
}

int checkVictory(char tablero[3][3], char letra){ ///Las flag estan para que en caso de doble condicion de victoria, solo salte 1.
    int res = 0, flag = 0;
    while(!flag){
        for(int i=0; i<3; i++){
            if(tablero[i][0] == letra && tablero[i][1] == letra && tablero[i][2] == letra) {
                res = 1;
                flag = 1;
            }
        }///Revision horizontal.
        for(int i=0; i<3; i++){
            if(tablero[0][i] == letra && tablero[1][i] == letra && tablero[2][i] == letra) {
                res = 1;
                flag = 1;
            }
        }///Revision vertical.
        if(tablero[0][0] == letra && tablero[1][1] == letra && tablero[2][2] == letra){
            res = 1;
            flag = 1;
        } ///Revision diagonal principal.
        if(tablero[0][2] == letra && tablero[1][1] == letra && tablero[2][0] == letra){
            res = 1;
            flag = 1;
        } ///Revision diagonal secundaria.
        flag = 1;
    }
    return res;
}

