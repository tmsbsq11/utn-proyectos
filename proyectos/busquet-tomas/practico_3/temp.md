#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

//FUNCION GETCH
#include <unistd.h>
#include <termios.h>
char getch(void)
{
    char buf = 0;
    struct termios old = {0};
    fflush(stdout);
    if(tcgetattr(0, &old) < 0)
        perror("tcsetattr()");
    old.c_lflag &= ~ICANON;
    old.c_lflag &= ~ECHO;
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;
    if(tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");
    if(read(0, &buf, 1) < 0)
        perror("read()");
    old.c_lflag |= ICANON;
    old.c_lflag |= ECHO;
    if(tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");
    //printf("%c\n", buf);
    return buf;
 }

#define DIM 15


//funciones generales
void menuPrint();
void menuSwitch();
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void mostrarArregloEntero(int*, int);

//punto 1
void punto1();
int cargarArregloEnteroUsuario(int*, int, int);
int cargarArregloEnteroRandom(int*, int, int);

//punto 2
void punto2();

//punto 3
void punto3();
int sumatoriaArreglo(int*, int);


int main() {
    srand(time(NULL));
    menuSwitch();
    return 0;
}


//funciones generales
void menuPrint() {
    printf("\n\n------MENU------\n\n");
    printf("1- Funcion que reciba un arreglo, agregue enteros por input y lo retorne\n");
    printf("2- Funcion que muestre en pantalla un arreglo\n");
    printf("3- Funcion que sume todos los elementos de un arreglo\n");
    printf("4- \n");
    printf("5- \n");
    printf("6- \n");
    printf("7- \n");
    printf("8- \n");
    printf("9- \n");
    printf("0- SALIR\n");
}
void menuSwitch() {
    int opcion;
    do {
        menuPrint();
        printf("\n\nElegir opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                punto1();
                fflush(stdin);
                getch();
                limpiarPantalla();
                break;
            case 2:
                punto2();
                fflush(stdin);
                getch();
                limpiarPantalla();
                break;
            case 3:
                punto3();
                fflush(stdin);
                getch();
                limpiarPantalla();
                break;
            default:
                printf("\nerror\n");
                fflush(stdin);
                getch();
                limpiarPantalla();
                break;
        }
    } while(opcion!=0);
}
void mostrarArregloEntero(int arreglo[], int validos) {
    for(int i=0; i<validos;i++) {
        if((i + 1) == validos) {
            printf(" %d", arreglo[i]);
        } else {
            printf(" %d |", arreglo[i]);
        }
    }
}
int cargarArregloEnteroRandom(int arreglo[], int validos, int dim) {
    for(int i=0; i<dim; i++) {
        arreglo[i] = rand()%101;
    }
}


//punto 1
void punto1() {
    int arreglo[DIM];
    int v_arreglo = 0;

    v_arreglo = cargarArregloEnteroUsuario(arreglo, v_arreglo, DIM);
    printf("\n");
    mostrarArregloEntero(arreglo, v_arreglo);
}
int cargarArregloEnteroUsuario(int arreglo[], int validos, int dim) {
    char option = 'x';
    int aux;

    while (option != 's' && validos < 10) {
        printf("\nIngrese un numero entero: ");
        fflush(stdin);
        scanf("%d", &aux);
        arreglo[validos] = aux;
        validos++;

        printf("'s' PARA SALIR \n");
        option = getch();
    }

    return validos;
}


//punto 2
void punto2() {
    int arreglo[DIM];
    int v_arreglo = 0;

    v_arreglo = cargarArregloEnteroRandom(arreglo, v_arreglo, DIM);
    printf("\n");
    mostrarArregloEntero(arreglo, v_arreglo);
}


//punto 3
void punto3() {
    int arreglo[DIM];
    int v_arreglo = 0;

    v_arreglo = cargarArregloEnteroRandom(arreglo, v_arreglo, DIM);
    printf("Arreglo generado de forma aleatoria: \n");
    mostrarArregloEntero(arreglo, v_arreglo);
    printf("\nSUMATORIA DEL ARREGLO: %d", sumatoriaArreglo(arreglo, v_arreglo));
}
int sumatoriaArreglo(int arreglo[], int validos) {
    int suma = 0;
    for(int i=0; i<validos; i++) {
        suma = suma + arreglo[i];
    }

    return suma;
}
