#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
#include <string.h>




typedef struct{
    int id;
    char name[30];
    char dni[10];
} stPacientes;

int busqueda_binaria(int[], int, int);
stPacientes nuevoPaciente();

int main()
{
    srand(time(NULL));
    menu();
    return 0;
}
void menu(){
    int opt = 0;
    scanf("%d", &opt);
    stPacientes Gonzalo = nuevoPaciente();

    switch(opt){
        case 1:{
            int v = 100000;
            int data_bin[v];

            for(int i=0; i<v; i++){data_bin[i] = i; }

            int res = busqueda_binaria(data_bin, v, 70000);

            if(res != -1){ printf("la posicion esta en: %d", res); }
            else { printf("posicion no encontrada"); }
        break;
        }
        case 2:{

            printf("Nombre: %s\n", Gonzalo.name);
            printf("ID: %d\n", Gonzalo.id);
            printf("DNI: %s\n", Gonzalo.dni);
        break;
        }
    }
}
stPacientes nuevoPaciente(){

    stPacientes obj;

    printf("Ingrese el nombre del paciente: \n");
    fflush(stdin);
    gets(obj.name);
    printf("DNI: \n");
    fflush(stdin);
    gets(obj.dni);
    printf("ID: \n");
    scanf("%d", obj.id);

    return obj;

}

int busqueda_binaria(int data[], int tam, int objetivo){
    int izquierda = 0;
    int derecha = tam-1;
    int res = -1;
    while(izquierda <= derecha){
        int medio = izquierda + (derecha-izquierda)/2;

        if(data[medio] == objetivo){
                res = medio;
        }
        if(data[medio] < objetivo) {
            izquierda = medio+1;
        } else {
            derecha = medio-1;
        }

    }
        return res;
}
