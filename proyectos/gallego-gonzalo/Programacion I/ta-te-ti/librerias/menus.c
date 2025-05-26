#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "menus.h"
#include "controApp.h"

int seleccionModo(){
    system("cls");
    int select;
    printf("Seleccione modo de juego:\n");
    printf("01 - JvsJ\n");
    printf("02 - JvsCPU\n");
    scanf("%d", &select);
    system("cls");
    return select;
}

void resetApp(){
    char select = 0;
    printf("\nRESET? ESC para salir.\n");
    select = getch();
    if(select != 27){ inicializarApp(); }
}
