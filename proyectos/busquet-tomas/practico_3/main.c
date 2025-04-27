#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

//FUNCION GETCH
#include <unistd.h>
#include <termios.h>
char getch(void) {
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
#define DIM_STRING 20


//funciones generales
void menuPrint();
void menuSwitch(int*, int);
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void mostrarArregloEntero(int*, int);
void limpiarArreglo(int*, int*);

//punto 1
void punto1(int*, int*);
int cargarArregloEnteroUsuario(int*, int, int);
int cargarArregloEnteroRandom(int*, int, int);

//punto 2
void punto2(int*, int*);

//punto 3
void punto3(int*, int*);
int sumatoriaArregloEntero(int*, int);

//punto 4
void punto4(int*, int*);
Pila arregloAPila(int*, int, Pila);

//punto 5
void punto5();
void cargarArregloFloatRandom(float*);
void mostrarArregloFloat(float*);
float sumatoriaArregloFloat(float*);

//punto 6
void punto6();
int busquedaCaracter(char*, char);

int main() {
    int arreglo[DIM];
    int v_arreglo = 0;

    srand(time(NULL));
    menuSwitch(arreglo, v_arreglo);
    return 0;
}


//funciones generales
void menuPrint() {
    printf("\n\n------MENU------\n\n");
    printf("1- Funcion que reciba un arreglo, agregue enteros por input y lo retorne\n");
    printf("2- Mostrar en pantalla un arreglo random\n");
    printf("3- Sumar todos los elementos de un arreglo\n");
    printf("4- Copiar elementos de un arreglo a una pila\n");
    printf("5- Cargar, sumar y mostrar arreglo float\n");
    printf("6- Indicar si un elemento dado se encuentra en un arreglo de caracteres. \n");
    printf("7- \n");
    printf("8- \n");
    printf("9- \n");
    printf("0- SALIR\n");
}
void menuSwitch(int arreglo[], int validos) {
    int opcion;
    do {
        menuPrint();
        printf("\n\nElegir opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion) {
            case 0:
                printf("Saliendo del programa.");
                break;
            case 1:
                punto1(arreglo, &validos);
                fflush(stdin);
                getch();
                limpiarPantalla();
                limpiarArreglo(arreglo, &validos);
                break;
            case 2:
                punto2(arreglo, &validos);
                fflush(stdin);
                getch();
                limpiarPantalla();
                limpiarArreglo(arreglo, &validos);
                break;
            case 3:
                punto3(arreglo, &validos);
                fflush(stdin);
                getch();
                limpiarPantalla();
                limpiarArreglo(arreglo, &validos);
                break;
            case 4:
                punto4(arreglo, &validos);
                fflush(stdin);
                getch();
                limpiarPantalla();
                limpiarArreglo(arreglo, &validos);
                break;
            case 5:
                punto5();
                fflush(stdin);
                getch();
                limpiarPantalla();
                break;
            case 6:
                punto6();
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
        validos++;
    }

    return validos;
}
void limpiarArreglo(int arreglo[], int *validos) {
    for(int i=0; i<*validos; i++) {
        arreglo[i] = 0;
    }
    *validos = 0;
}


//punto 1
void punto1(int arreglo[], int *v_arreglo) {
    *v_arreglo = cargarArregloEnteroUsuario(arreglo, *v_arreglo, DIM);
    printf("\n");
    mostrarArregloEntero(arreglo, *v_arreglo);
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
void punto2(int arreglo[], int *v_arreglo) {
    *v_arreglo = cargarArregloEnteroRandom(arreglo, *v_arreglo, DIM);
    printf("\n");
    mostrarArregloEntero(arreglo, *v_arreglo);
}


//punto 3
void punto3(int arreglo[], int *v_arreglo) {
    *v_arreglo = cargarArregloEnteroRandom(arreglo, *v_arreglo, DIM);
    printf("\nArreglo generado de forma aleatoria: \n");
    mostrarArregloEntero(arreglo, *v_arreglo);
    printf("\nSUMATORIA DEL ARREGLO: %d", sumatoriaArregloEntero(arreglo, *v_arreglo));
}
int sumatoriaArregloEntero(int arreglo[], int validos) {
    int suma = 0;
    for(int i=0; i<validos; i++) {
        suma = suma + arreglo[i];
    }
    return suma;
}


//punto 4
void punto4(int arreglo[], int *v_arreglo) {
    Pila PILA;
    inicpila(&PILA);

    *v_arreglo = cargarArregloEnteroUsuario(arreglo, *v_arreglo, DIM);
    printf("\nArreglo a pasar a pila: ");
    mostrarArregloEntero(arreglo, *v_arreglo);

    PILA = arregloAPila(arreglo, *v_arreglo, PILA);
    mostrar(&PILA);
}
Pila arregloAPila(int arreglo[], int validos, Pila PILA) {
    for(int i=0; i<validos; i++) {
        apilar(&PILA, arreglo[i]);
        //printf("arreglo[%d]\n", arreglo[i]);
        //mostrar(&PILA);
    }
    return PILA;
}


//punto 5
void punto5() {
    float arreglo_float[100];


    cargarArregloFloatRandom(arreglo_float);
    mostrarArregloFloat(arreglo_float);
    printf("\nSumatoria: %.2f", sumatoriaArregloFloat(arreglo_float));
}
void cargarArregloFloatRandom(float arreglo[]) {
    for(int i=0; i<100; i++) {
        arreglo[i] = (float)(rand()%101)/(rand()%4+1);
    }
}
void mostrarArregloFloat(float arreglo[]) {
    for(int i=0; i<100;i++) {
        if((i + 1) == 100) {
            printf(" %.2f", arreglo[i]);
        } else {
            printf(" %.2f |", arreglo[i]);
        }
    }
}
float sumatoriaArregloFloat(float arreglo[]) {
    float suma = 0;
    for(int i=0; i<100; i++) {
        suma += arreglo[i];
    }
    return suma;
}


//punto 6
void punto6() {
    //Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.
    char cadena[DIM_STRING];
    char buscar;

    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", cadena);
    printf("\nIngrese un caracter a buscar: ");
    scanf("%c", &buscar);

    if ( busquedaCaracter(cadena, buscar) == 1 ) {
        printf("\nSe encontro el caracter dentro del arreglo");
    } else {
        printf("\nNo se encontro el caracter dentro del arreglo");
    }
}
int busquedaCaracter(char cadena[], char buscar) {
    int flag = 0;
    int i = 0;

    do {
        if(cadena[i]==buscar) {
            flag = 1;
        }
        i++;
    } while(cadena[i] != buscar);

    return flag;
}
