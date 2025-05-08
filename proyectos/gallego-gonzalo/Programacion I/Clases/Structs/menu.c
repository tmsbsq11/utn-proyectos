#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "menu.h"
#include "stAlumno.h"

void menu(){
    char opt = 0;
    opt = getch();
    stAlumno Salon[30];
    int tam = sizeof(Salon)/ sizeof(Salon[0]);
    int Salonval = 0;

    printf("Seleccione ejercicio a revisar..\n");

    switch(opt){
        case '1':{
            arrAlumno(Salon, tam, &Salonval);
            for(int i=0; i<Salonval; i++){ mostrarAlumno(Salon[i]); }
        break;
        }
        case '2': {
            int bus;
            system("cls");
            printf("Ingrese matricula a buscar: \n");
            scanf("%d", &bus);

            buscarAlumno(Salon, Salonval, bus);
        break;}
    }
}
