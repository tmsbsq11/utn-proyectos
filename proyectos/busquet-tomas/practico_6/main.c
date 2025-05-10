#include <stdio.h>
#include <stdlib.h>
#include "compat.h"
#include "stAlumno.h"

#define DIM 20

int main() {
    stAlumno Alumnos[DIM];
    int validos = cargaAlumnos(Alumnos);
    menuSwitch(Alumnos, validos);
    return 0;
}
