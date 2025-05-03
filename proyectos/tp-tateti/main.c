#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void mostrarTablero(char tablero[3][3]);
void turnoJugador(char tablero[3][3]);
void turnoMaquina(char tablero[3][3]);
void checkVictory(char tablero[3][3], char letra);

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
    int tTotal = 0;
    while(tTotal < 9){

        turnoJugador(tablero);
        system("cls");
        mostrarTablero(tablero);
        checkVictory(tablero, 'x');

        Sleep(500);
        turnoMaquina(tablero);
        system("cls");
        mostrarTablero(tablero);
        checkVictory(tablero, 'o');

        tTotal++;
    }
    printf("Empate, juego terminado.\n");

}
void turnoJugador(char tablero[3][3]){
    int aux, flag = 0;

    while(!flag){
        printf("seleccione\n");
        fflush(stdin);
        scanf("%d", &aux);
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

void checkVictory(char tablero[3][3], char letra){

    for(int i=0; i<3; i++){ ///Revision horizontal.
        if(tablero[i][0] == letra && tablero[i][1] == letra && tablero[i][2] == letra) {
            printf("VICTORIA\n");
            system("pause");
        }
    }
    for(int i=0; i<3; i++){ ///Revision vertical.
        if(tablero[0][i] == letra && tablero[1][i] == letra && tablero[2][i] == letra) {
            printf("VICTORIA\n");
            system("pause");
        }
    }
    if(tablero[0][0] == letra && tablero[1][1] == letra && tablero[2][2] == letra){
        printf("VICTORIA\n"); ///Revision diagonal principal.
        system("pause");
    }
    if(tablero[0][2] == letra && tablero[1][1] == letra && tablero[2][0] == letra){
        printf("VICTORIA\n"); ///Revision diagonal secundaria.
        system("pause");
    }
}
