#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>

#define FILAS 4
#define COLUMNAS 3
#define MAX_WORDS 15
#define MAX_LENGTH 100

void cargarMatrizUsuario(int a[FILAS][COLUMNAS]); /// Punto 1
void mostrarMatriz(int a[FILAS][COLUMNAS]); /// Punto 2
void cargarMatrizAleatorio(int a[FILAS][COLUMNAS]); /// Punto 3
int sumarElementosMatriz(int a[FILAS][COLUMNAS]); /// Punto 4
float promedioMatriz(int a[FILAS][COLUMNAS], int * sum); /// Punto 5
int valorBuscarMatriz(); /// Punto 6
int buscarValor(int a[FILAS][COLUMNAS], int * valor);
int cantidadPalabrasParaIngresar(); /// Punto 7
void cargarMatrizCaracteresUsuario(char a[][MAX_LENGTH], int cantidad);
void mostrarMatrizStrings(char a[][MAX_LENGTH], int cantidad); /// Punto 8



int main()
{
    int option;
    srand(time(NULL));

    do {
        printf("Seleccione el ejercicio a continuaci%cn del 1 al 13: ", 162);
        scanf("%i", &option);

        switch(option) {
        case 1: {
            printf("\n1) Cargar una matriz de %d filas y %d columnas ingresados por el usuario.\n", FILAS, COLUMNAS);
            int matrix[FILAS][COLUMNAS];
            cargarMatrizUsuario(matrix);
            printf("Matriz Resultante:\n");
            mostrarMatriz(matrix);

            system("pause");
            system("cls");
            break;
        }
        case 2: {
            printf("\n2) Cargar una matriz de %d filas y %d columnas de manera aleatoria.\n", FILAS, COLUMNAS);
            int matrix[FILAS][COLUMNAS];
            cargarMatrizAleatorio(matrix);
            printf("Matriz Resultante:\n");
            mostrarMatriz(matrix);

            system("pause");
            system("cls");
            break;
        }
        case 3: {
            printf("\n3) La suma de todos los valores de una matriz (aleatoria).\n");
            int matrix[FILAS][COLUMNAS];
            cargarMatrizAleatorio(matrix);
            printf("Matriz Resultante:\n");
            mostrarMatriz(matrix);

            int sum = sumarElementosMatriz(matrix);
            printf("La suma total de sus elementos es igual a: %i\n", sum);

            system("pause");
            system("cls");
            break;
        }
        case 4: {
            printf("\n4) El promedio de una matriz (aleatioria).\n");
            int matrix[FILAS][COLUMNAS];
            cargarMatrizAleatorio(matrix);
            printf("Matriz Resultante:\n");
            mostrarMatriz(matrix);

            int sum = sumarElementosMatriz(matrix);
            float prom = promedioMatriz(matrix, &sum);
            printf("El promedio de la matriz es igual a: %.2f", prom);

            system("pause");
            system("cls");
            break;
        }
        case 5: {
            printf("\n5) Buscar un valor en una matriz.\n");
            int matrix[FILAS][COLUMNAS];
            cargarMatrizAleatorio(matrix);
            printf("Matriz Resultante:\n");
            mostrarMatriz(matrix);

            int val = valorBuscarMatriz();
            int cant = buscarValor(matrix, &val);
            printf("El valor ingresado se encontr%c %i veces en la matriz\n", 162, cant);

            system("pause");
            system("cls");
            break;
        }
        case 6: {
            printf("\n6) Muestra la cantidad de palabras que contiene un arreglo de strings\n");
            char matrix[MAX_WORDS][MAX_LENGTH];

            int cant = cantidadPalabrasParaIngresar();
            cargarMatrizCaracteresUsuario(matrix, cant);
            printf("\n\nContenido Matriz: \n");
            mostrarMatrizStrings(matrix, cant);

            system("pause");
            system("cls");
            break;
        }
        case 0: {
                printf("\nSaliendo del programa...\n");
                break;
            }
            if (option != 0) {
                system("pause");
            }
        }
    }
    while (option != 0);

    return 0;
}



void cargarMatrizUsuario(int a[FILAS][COLUMNAS]) {
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            printf("Cargar valor en la posici%cn [%d][%d]: ", 162, i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void mostrarMatriz(int a[FILAS][COLUMNAS]) {
    for(int i = 0; i < FILAS; i++) {
        printf("| ");
        for(int j = 0; j < COLUMNAS; j++) {
            printf("%d ", a[i][j]);
        }
        printf("|\n");
    }
}

void cargarMatrizAleatorio(int a[FILAS][COLUMNAS]) {
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            a[i][j] = rand() % 10 + 1;
        }
    }
}

void mostrarMatrizStrings(char a[][MAX_LENGTH], int cantidad) {
    for(int i = 0; i < cantidad; i++) {
        printf("%s", a[i]);
    }
    printf("\n");
}


/// --------------------- PUNTO 4  ---------------------
int sumarElementosMatriz(int a[FILAS][COLUMNAS]) {
    int sumas = 0;
    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            sumas += a[i][j];
        }
    }
    return sumas;
}



/// --------------------- PUNTO 5  ---------------------
float promedioMatriz(int a[FILAS][COLUMNAS], int * sum) {
    float promedio = (float)(*sum) / (FILAS * COLUMNAS);

    return promedio;
}



/// --------------------- PUNTO 6  ---------------------
int valorBuscarMatriz() {
    int valor;

    printf("\nCu%cl es el valor que desea buscar?: ", 160);
    scanf("%i", &valor);

    return valor;
}

int buscarValor(int a[FILAS][COLUMNAS], int * valor) {
    int cantidad = 0;

    for(int i = 0; i < FILAS; i++) {
        for(int j = 0; j < COLUMNAS; j++) {
            if(a[i][j] == *valor) {
                cantidad++;
            }
        }
    }

    return cantidad;
}



/// --------------------- PUNTO 7  ---------------------
int cantidadPalabrasParaIngresar() {
    int total = 0;

    printf("Cu%cntas palabras desea ingrear? (m%cximo %i): ", 160, 160, MAX_WORDS);
    scanf("%i", &total);

    return total;
}

void cargarMatrizCaracteresUsuario(char a[][MAX_LENGTH], int cantidad) {
    getchar();
    for(int i = 0; i < cantidad; i++) {
        printf("Palabra %i: ", i+1);
        fgets(a[i], MAX_LENGTH, stdin);
    }
}
