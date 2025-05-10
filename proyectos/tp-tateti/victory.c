#include "victory.h"


void victoria(int n, char name[]){
    if (n == 1){
        printf("victoria!! %s", name);
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

