#include <stdio.h>
#include <stdlib.h>
#include "archivos.h"
#include "login.h"


int main()
{
    //stJugador data3 = {"Test", "Test", "email", "1234", 'O'};

    cargarArchivo(DATAJ);
    login();

    return 0;
}
