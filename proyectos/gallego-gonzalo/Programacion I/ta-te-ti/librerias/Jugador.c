#include <stdio.h>
#include "Jugador.h"

void mostrarJugador(stJugador data){
    printf("Nombre -> %s %s\n", data.nombre, data.apellido);
    printf("Email -> %s\n", data.email);
    printf("pass -> %s\n", data.contra);
    printf("Figura -> %c\n", data.figura);
    printf("--------------------------------\n");
}

