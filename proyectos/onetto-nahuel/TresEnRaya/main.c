#include <stdio.h>
#include <stdlib.h>

#define ESC 27

int valorIngresarJugador(char tablero[3][3], char player);
void mostrarTablero();

int main()
{
    char tablero[3][3];
    mostrarTablero(tablero); /// ----------------------------muestra el logo de reproducir en la casilla 2 xD.

    system("pause");

    return 0;
}

int valorIngresarJugador(char tablero[3][3], char player) {
    int opi = 0;
    int fila, columna;

    printf("Ingresar una posici%cn del 1 al 9 (se lee de izq. a der.)", 162);
    scanf("%i", &opi);

    if(1 > &opi && &opi > 9) { /// ----------------------------Duda si deberia poner || o esta bien con &&.
        printf("Opci%cn inv%clida, ingrese nuevamente", 162, 160);
    }


}

void mostrarTablero(char tablero[3][3]) {
    for (int fila = 0; fila < 3; fila++) {
        for (int linea = 0; linea < 3; linea++) {
            for (int columna = 0; columna < 3; columna++) {
                if (linea == 1) {
                    printf(" %c ", tablero[fila][columna]);
                } else {
                    printf("   ");
                }
                if (columna < 2) printf("|");
            }
            printf("\n");
        }
        if (fila < 2) {
            printf("---+---+---\n");
        }
    }
}
