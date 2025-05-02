#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>
#include <time.h>
#include "pila.h"

#define DIM 100

void generarArregloAle(int arreglo[], int dim);
void generarArregloLetras(char arreglo[], int dim);
void muestraArreglo(int arreglo[], int v);
void muestraArregloCarac(char arreglo[], int v);
int valorUsuarioDimension();
void ordenarChar(char arreglo[]);

int cargaElementosArreglo(int arreglo[], int v, int dim); /// Punto 1 & 2
int sumaArreglo (int arreglo[], int v); /// Punto 3
void copiaArregloEnPila (int arreglo[], int v ,Pila *p); /// Punto 4
void cargarArregloAleatorio(float arreglito[], int dim); /// Punto 5
void mostrarArreglo(float arreglito[], int dim);
float sumarArreglo(float arreglito[], int dim);
int valorBuscar();/// Punto 6
int buscarCaracterArr(char arreglo[], char caracter, int dimen);
void cantidadVecesEncontradoCaracter(int cantidad);
char caracterUsuario(); /// Punto 7
void agregarCaracterArray(char arreglo[], char caracter, int *dim);
int insertarCaractOrdenado(char A[], int v, char dato); /// Punto 8
void mayorCaracter(char arreglo[], int v);
void cargarArregloManual(char A[], int dim); /// Punto 9
int caractCapicua(char A[], int v);
void esCapicuaPrintf(int a);
void invertirArreglo(char A[], int dim); /// Punto 10
void arregloInsercion(char Arreg[], int dim); /// Punto 11
void arregloSeleccion(char Arreg[], int dim);
int numAlePara2Arreglos(); /// Punto 12
void ordenar2ArrayChar(char A[], char B[], char resultado[]);


int main()
{
    srand(time(NULL));

    int arreglo[10];
    int validos = 0;
    int suma = 0;
    Pila dada;
    inicpila(&dada);
    float arreglito[100];

    /// --------------------- PUNTO 1 & 2  ---------------------
    validos = cargaElementosArreglo(arreglo, validos, 10);
    printf("\n");
    muestraArreglo(arreglo, validos);

    system("pause");
    system("cls");


    /// --------------------- PUNTO 3  ---------------------
    suma = sumaArreglo(arreglo, validos);
    printf("La suma total de los elementos del arreglo es: %d\n", suma);

    system("pause");
    system("cls");


    /// --------------------- PUNTO 4  ---------------------
    copiaArregloEnPila(arreglo, validos ,&dada);
    printf("La pila con los valores del arreglo es: ");
    muestraPila(dada);

    system("pause");
    system("cls");


    /// --------------------- PUNTO 5  ---------------------
    cargarArregloAleatorio(arreglito, DIM);
    printf("Elementos del arreglo:\n");
    mostrarArreglo(arreglito, DIM);

    float sumaFloat = sumarArreglo(arreglito, DIM);
    printf("\nLa suma de los elementos del arreglo es: %.2f\n", sumaFloat);

    system("pause");
    system("cls");


    /// --------------------- PUNTO 6  ---------------------
    int dimension = valorUsuarioDimension();
    char arreglis[DIM];
    generarArregloLetras(arreglis, dimension);
    ordenarChar(arreglis);
    muestraArregloCarac(arreglis, dimension);

    char carac = valorBuscar();
    int cantidad = buscarCaracterArr(arreglis, carac, dimension);

    cantidadVecesEncontradoCaracter(cantidad);

    system("pause");
    system("cls");


    /// --------------------- PUNTO 7  ---------------------
    int dimer = valorUsuarioDimension();
    char arreglinho[DIM];
    generarArregloLetras(arreglinho, dimer);
    ordenarChar(arreglinho);
    muestraArregloCarac(arreglinho, dimer);

    char letra = caracterUsuario();
    agregarCaracterArray(arreglinho, letra, &dimer);
    muestraArregloCarac(arreglinho, dimer);

    system("pause");
    system("cls");


    /// --------------------- PUNTO 8  ---------------------
    int dimmm = valorUsuarioDimension();
    char arreF[DIM];
    generarArregloLetras(arreF, dimmm);
    ordenarChar(arreF);
    muestraArregloCarac(arreF, dimmm);

    mayorCaracter(arreF, dimmm);

    system("pause");
    system("cls");


    /// --------------------- PUNTO 9  ---------------------
    int opcion;
    int dimA = valorUsuarioDimension();
    char arreH[DIM];

    printf("1. Carga manual\n");
    printf("2. Carga aleatoria\n");
    printf("Opci%cn: ", 162);
    scanf("%d", &opcion);

    system("cls");

    if(opcion == 1) {
        cargarArregloManual(arreH, dimA);
    } else if(opcion == 2) {
        generarArregloLetras(arreH, dimA);
    }

    muestraArregloCarac(arreH, dimA);

    int capicua;
    capicua = caractCapicua(arreH, dimA);
    esCapicuaPrintf(capicua);

    system("pause");
    system("cls");


    /// --------------------- PUNTO 10  ---------------------
    int dAM = valorUsuarioDimension();
    char arreXx[DIM];
    generarArregloLetras(arreXx, dAM);
    muestraArregloCarac(arreXx, dAM);

    invertirArreglo(arreXx, dAM);
    printf("\nArreglo Invertido:\n");
    muestraArregloCarac(arreXx, dAM);

    system("pause");
    system("cls");


    /// --------------------- PUNTO 11  ---------------------
    int dimPP = valorUsuarioDimension();
    char fArreglo[DIM];
    generarArregloLetras(fArreglo, dimPP);

    printf("Arreglo Inserci%cn\n", 162);
    arregloInsercion(fArreglo, dimPP);
    muestraArregloCarac(fArreglo, dimPP);
    printf("\nArreglo Selecci%cn\n", 162);
    arregloSeleccion(fArreglo, dimPP);
    muestraArregloCarac(fArreglo, dimPP);

    system("pause");
    system("cls");


    /// --------------------- PUNTO 12  ---------------------
    int dimar = numAlePara2Arreglos();
    char xArreglo[DIM];
    char zArreglo[DIM];
    char resultado[DIM];
    generarArregloLetras(xArreglo, dimar);
    generarArregloLetras(zArreglo, dimar);

    printf("Arreglo Aleatorio 1:\n");
    muestraArregloCarac(xArreglo, dimar);
    printf("\nArreglo Aleatorio 2:\n");
    muestraArregloCarac(zArreglo, dimar);

    ordenar2ArrayChar(xArreglo, zArreglo, resultado);
    printf("\nNuevo Arreglo Conjunto\n");
    muestraArregloCarac(resultado, strlen(resultado));

    return 0;
}



int valorUsuarioDimension() {
    int dim;

    printf("Ingrese la cantidad de elementos (m%cximo %d): ", 160, DIM);
    scanf("%i", &dim);

    while (dim <= 0 || dim > DIM) {
        printf("Error: La dimensi%cn debe estar entre 1 y %d. Intente nuevamente: ", 162, DIM);
        scanf("%d", &dim);
    }

    return dim;
}

void generarArregloAle(int arreglo[], int dim) {
    for (int i = 0; i < dim; i++) {
        arreglo[i] = rand() % 20 + 1;
    }
}

void generarArregloLetras(char arreglo[], int dim) {
    for (int i = 0; i < dim; i++) {
            int letra = 'a' + (rand() % 26);
            arreglo[i] = (char)letra;
    }
}

void muestraArregloCarac(char arreglo[], int v) {
    for(int i = 0; i < v; i++) {
        printf("%c |", arreglo[i]);
    }
}

void muestraArreglo(int arreglo[], int v) {
    for(int i = 0; i < v; i++) {
        printf("%d |", arreglo[i]);
    }
}

void ordenarChar(char arreglo[]) {
    char cTemporal;
    int dimension = strlen(arreglo);

    for (int i = 0; i < dimension - 1; i++) {
        for (int j = 0; j < dimension - i - 1; j++) {
            if (arreglo[j] > arreglo[j + 1]) {
                cTemporal = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = cTemporal;
            }
        }
    }
}



/// --------------------- PUNTO 1 & 2  ---------------------
int cargaElementosArreglo(int arreglo[], int v, int dim){
    char option = 's';

    while(v < dim && option != 27) {
        printf("Ingrese un valor al arreglo, a la posici%cn a[%d]: \n", 162, v);
        scanf("%d", &arreglo[v]);
        v++;

        printf("Desea continuar? ESC para salir \n");
        option = getch();
    }

    return v;
}



/// --------------------- PUNTO 3  ---------------------
int sumaArreglo (int arreglo[], int v){
    int suma = 0;
    for(int i = 0; i < v; i++){
        suma = suma + arreglo[i];
    }
    return suma;
}



/// --------------------- PUNTO 4  ---------------------
void copiaArregloEnPila (int arreglo[], int v ,Pila *p){
    for(int i = 0; i < v; i++){
        apilar(p, arreglo[i]);
    }
}

void muestraPila(Pila p){
    Pila aux;
    inicpila(&aux);
    int cont = 0;
    while(!pilavacia(&p)){
        if(cont % 15 == 0){
            printf("  \n");
        }
        printf(" %d \n", tope(&p));
        apilar(&aux, desapilar(&p));
        cont++;
    }
}



/// --------------------- PUNTO 5  ---------------------
void cargarArregloAleatorio(float arreglo[], int dim) {
    for (int i = 0; i < dim; i++) {
        arreglo[i] = (rand() % 101) + ((rand() % 100) / 100.0);
    }
}


void mostrarArreglo(float arreglo[], int dim) {
    for (int i = 0; i < dim; i++) {
        printf("%.2f - ", arreglo[i]);
    }
    printf("\n");
}

float sumarArreglo(float arreglo[], int dim) {
    float sumaFloat = 0;
    for (int i = 0; i < dim; i++) {
        sumaFloat += arreglo[i];
    }
    return sumaFloat;
}



/// --------------------- PUNTO 6  ---------------------
int valorBuscar() {
    char letra;

    printf("\nIngrese el car%ccter a buscar: ", 160);
    scanf(" %c", &letra);

    return letra;
}

int buscarCaracterArr(char arreglo[], char caracter, int dimen) {
    int cantidad = 0;

    for(int a=0; a<dimen; a++) {
        if(arreglo[a] == caracter) {
            cantidad++;
        }
    }

    return cantidad;
}

void cantidadVecesEncontradoCaracter(int cantidad) {
    if(cantidad != 0){
        printf("\nSe encontr%c %i veces el car%ccter en el arreglo\n", 162, cantidad, 160);
    }
    else {
        printf("\nNo se encontr%c ninguna coincidencia en el arreglo\n", 162);
    }
}



/// --------------------- PUNTO 7  ---------------------
char caracterUsuario() {
    char letra;

    printf("\nQu%c car%cter desea ingresar? ",130, 160);
    scanf(" %c", &letra);

    return letra;
}

void agregarCaracterArray(char arreglo[], char caracter, int *dim) {
    int i = *dim - 1;
    while (i >= 0 && arreglo[i] > caracter) {
        arreglo[i + 1] = arreglo[i]; // desplaza a la derecha
        i--;
    }
    arreglo[i + 1] = caracter; // inserta el nuevo carácter en su lugar
    (*dim)++; // aumenta el contador de elementos
}



/// --------------------- PUNTO 8  ---------------------
int insertarCaractOrdenado(char A[], int v, char dato) {
    int posi = v - 1;
    while(posi >= 0 && A[posi] > dato) {
        A[posi+1] = A[posi];
        posi--;
    }
    A[posi + 1] = dato;

    return v + 1;
}


void mayorCaracter(char arreglo[], int v) {
    char mayor = arreglo[0];

    for (int i = 1; i < v; i++) {
        if (arreglo[i] > mayor) {
            mayor = arreglo[i];
        }
    }

    printf("\nEl mayor car%ccter es: %c\n", 130, mayor);
}



/// --------------------- PUNTO 9  ---------------------
void cargarArregloManual(char A[], int dim) {
    printf("Ingrese %d caracteres:\n", dim);
    for(int i = 0; i < dim; i++) {
        printf("Car%ccter %d: ", 130, i + 1);
        scanf(" %c", &A[i]);
    }
}

int caractCapicua(char A[], int v) {
    int i = 0;
    int f = v-1;
    int flag = 1;

    while(i <= f) {
        if(A[i] == A[f]) {
            i++;
            f--;
        }
        else {
            flag = 0;
            break;
        }
    }

    return flag;
}

void esCapicuaPrintf(int a) {
    if(a != 0) {
        printf("Es capicua el arreglo\n");
    }
    else {
        printf("No es capicua\n");
    }
}



/// --------------------- PUNTO 10  ---------------------
void invertirArreglo(char A[], int dim) {
    int temporal;

    for (int i = 0; i < dim / 2; i++) {
        temporal = A[i];
        A[i] = A[dim - 1 - i];
        A[dim - 1 - i] = temporal;
    }
}



/// --------------------- PUNTO 11  ---------------------
void arregloInsercion(char Arreg[], int dim) {
    for (int vActual = 1; vActual < dim; vActual++) {
        int temp = Arreg[vActual];
        int vAux = vActual - 1;
        while (vAux >= 0 && Arreg[vAux] > temp) {
            Arreg[vAux + 1] = Arreg[vAux];
            vAux--;
        }
        Arreg[vAux + 1] = temp;
    }
}

void arregloSeleccion(char Arreg[], int dim) {
    for (int vActual = 0; vActual < dim - 1; vActual++) {
        int minIdx = vActual;
        for (int vMin = vActual + 1; vMin < dim; vMin++) {
            if (Arreg[vMin] < Arreg[minIdx])
                minIdx = vMin;
        }
        int temp = Arreg[minIdx];
        Arreg[minIdx] = Arreg[vActual];
        Arreg[vActual] = temp;
    }
}



/// --------------------- PUNTO 12  ---------------------
int numAlePara2Arreglos() {
    int num = rand() % 5 + 1;

    return num;
}

void ordenar2ArrayChar(char A[], char B[], char resultado[]) {
    strcpy(resultado, A);
    strcat(resultado, B);

    int dimension = strlen(resultado);
    char cTemporal;

    for (int i = 0; i < dimension - 1; i++) {
        for (int j = 0; j < dimension - i - 1; j++) {
            if (resultado[j] > resultado[j + 1]) {
                cTemporal = resultado[j];
                resultado[j] = resultado[j + 1];
                resultado[j + 1] = cTemporal;
            }
        }
    }
}
