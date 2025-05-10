#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void turnoJugador(char tablero[3][3], char symbol){
    int flag = 0;
    char aux;

    while(!flag){
        printf("seleccione\n");
        fflush(stdin);
        aux = getch() - '0';

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
