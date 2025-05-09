#include "tablero.h"


void mostrarTablero(char tablero[3][3]) {
    system("cls");
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
void rellenarTablero(char tablero[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tablero[i][j] = 32;
            }
        }
}
