#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void mostrarTablero(char tablero[3][3]);
void turnoJugador(char tablero[3][3]);
void turnoMaquina(char tablero[3][3]);
int checkVictory(char tablero[3][3], char letra);

int main()
{
    srand(time(NULL));
    char tablero[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = 32;
        }
    }

    mostrarTablero(tablero);
    ingresarValor(tablero);

    return 0;
}

void mostrarTablero(char tablero[3][3]) {
    for (int fila = 0; fila < 3; fila++) {
        for (int linea = 0; linea < 3; linea++) {
            for (int columna = 0; columna < 3; columna++) {
                if (linea == 1) {
                    printf("   %c   ", tablero[fila][columna]);
                } else {
                    printf("       ");
                }
                if (columna < 2) printf("|");
            }
            printf("\n");
        }
        if (fila < 2) {
            printf("-------+-------+-------\n");
        }
    }
}

void ingresarValor(char tablero[3][3]){
    int tTotal = 0, vic = 0;
    while(tTotal < 9 && vic != 1){

        turnoJugador(tablero);
        tTotal++;
        system("cls");
        mostrarTablero(tablero);
        vic = checkVictory(tablero, 'x');
        if(vic == 1 || tTotal >= 9) { break; }

        Sleep(500);
        turnoMaquina(tablero);
        tTotal++;
        system("cls");
        mostrarTablero(tablero);
        vic = checkVictory(tablero, 'o');
    }
    if(vic == 1) { printf("Victoria!.\n"); }
    else { printf("Empate.\n"); }

}
void turnoJugador(char tablero[3][3]){
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
                            tablero[i][j] = 'x';
                            flag = 1;
                        }
                    }
                    count++;
            }
        }
    }
}
void turnoMaquina(char tablero[3][3]){ ///fijarse que la maquina aveces pierde turno.
    int flag = 0;

    while(!flag){
        int count = 0;
        int pos = rand()%10;
            for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                    if(pos == count){
                        if(tablero[i][j] != 120 && tablero[i][j] != 111){
                                tablero[i][j] = 'o';
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
