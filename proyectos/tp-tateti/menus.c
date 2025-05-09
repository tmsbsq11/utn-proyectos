#include "menus.h"
#include "tablero.h"

int seleccionModo(int select){
    printf("Seleccione modo de juego:\n");
    printf("01 - JvsJ\n");
    printf("02 - JvsCPU\n");
    scanf("%d", &select);
    system("cls");
    return select;
}
void inicializarApp(){
    char tablero[3][3];

    rellenarTablero(tablero);
    mostrarTablero(tablero);
    ingresarValor(tablero);
}
