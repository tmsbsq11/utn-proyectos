#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "stAlumno.h"
#include "compat.h"

#define DIM 20

//funciones generales (no son los puntos)
void imprimirDatosEncontrado(stAlumno Alumnos[], int i) {
    printf("\nAlumno encontrado:\n");
    printf("Matrícula: %d\n", Alumnos[i].matricula);
    printf("Nombre: %s\n", Alumnos[i].nombre);
    printf("Género: %c\n", Alumnos[i].genero);
}


//punto 1, hacer una función que cargue alumnos hasta que el usuario decida cuando parar
int cargaAlumnos(stAlumno Alumnos[]) {
    int aux, limite=0;
    char control = 'x', gen = 'x';

    int i=0;
    while((control != 's')&&(limite<DIM)) {
        printf("Ingrese numero de matricula: ");
        Alumnos[i].matricula = leerEntero();

        printf("Ingrese nombre del alumno: ");
        fgets(Alumnos[i].nombre, sizeof(Alumnos[i].nombre), stdin);
        Alumnos[i].nombre[strcspn(Alumnos[i].nombre, "\n")] = '\0'; //borra el enter


        printf("Ingrese genero del alumno (m, f, o): ");
        do {
            scanf(" %c", &gen);
            limpiarBuffer();
        }while((gen!='m')&&(gen!='f')&&(gen!='o'));
        Alumnos[i].genero = gen;

        printf("\n's':SALIR: \n");
        fflush(stdin);
        control = getch();
        //limpiarBuffer();
        i++;
        clearsc();
    }
    return i;
}


//punto 2
void mostrarArregloAlumnos(stAlumno Alumnos[], int validos) {
        printf("\nSe cargaron %d alumnos.\n", validos);
        for (int i = 0; i < validos; i++) {
        printf("\nAlumno %d:\n", i + 1);
        printf("Matrícula: %d\n", Alumnos[i].matricula);
        printf("Nombre: %s\n", Alumnos[i].nombre);
        printf("Género: %c\n", Alumnos[i].genero);
    }
}


//punto 3
void mostrarAlumnoPorMatricula(stAlumno Alumnos[], int validos) {
    int matricula_buscada;
    int encontrado = 0;

    printf("\nIngrese la matrícula a buscar: ");
    scanf("%d", &matricula_buscada);

    for (int i = 0; i < validos; i++) {
        if (Alumnos[i].matricula == matricula_buscada) {
            imprimirDatosEncontrado(Alumnos, i);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("\nNo se encontró un alumno con esa matrícula.\n");
    }
}


//punto 4 ordenación por selección
void ordenarPorSeleccionMatricula(stAlumno Alumnos[], int validos) {
    int i, j, min;
    stAlumno aux;

    for (i = 0; i < validos - 1; i++) { //bucle ordenados
        min = i;    //min = posicion inicial, luego, verificar a partir de i + 1 los no ordenados
        for (j = i + 1; j < validos; j++) { //bucle sin ordenar
            if (Alumnos[j].matricula < Alumnos[min].matricula) {
                min = j;
            }
        }
        if (min != i) { //si min no está ya en la pos. i, realizar intercambio
            aux = Alumnos[i];
            Alumnos[i] = Alumnos[min];
            Alumnos[min] = aux;
        }
    }
}


//punto 5
void mostrarAlumnosPorGenero(stAlumno Alumnos[], int validos, char genero_buscando) {

    for(int i = 0; i < validos; i++) {
        if(Alumnos[i].genero == genero_buscando) {
            imprimirDatosEncontrado(Alumnos, i);
        }
    }
}
void buscarAlumnosPorGenero(stAlumno Alumnos[], int validos) {
        char genero_buscando = 'x';

        printf("\nIngrese genero a buscar (m, f, o): ");
        do {
            scanf(" %c", &genero_buscando);
        }while((genero_buscando!='m')&&(genero_buscando!='f')&&(genero_buscando!='o'));
        mostrarAlumnosPorGenero(Alumnos, validos, genero_buscando);
}

//punto 6 insertar elemento en un arreglo ordenado
void insertarNuevoElemento(stAlumno Alumnos[], int validos) {
    stAlumno nuevo;
    char gen = 'x';

    printf("Ingrese numero de matricula: ");
    fflush(stdin);
    nuevo.matricula = leerEntero();

    printf("Ingrese nombre del alumno: ");
    fgets(nuevo.nombre, sizeof(nuevo.nombre), stdin);
    nuevo.nombre[strcspn(nuevo.nombre, "\n")] = '\0';

    printf("Ingrese genero del alumno (m, f, o): ");
    do {
        scanf(" %c", &gen);
        limpiarBuffer();
    } while (gen != 'm' && gen != 'f' && gen != 'o');
    nuevo.genero = gen;

    // Hhcer espacio para insertar ordenado
    int i = validos - 1;
    while (i >= 0 && nuevo.matricula < Alumnos[i].matricula) {
        Alumnos[i + 1] = Alumnos[i]; // desplaza hacia la derecha
        i--;
    }

    Alumnos[i + 1] = nuevo; // inserta en la posición correcta
}


//punto 7 ordenación por inserción, criterio -> nombre (alfabetico imagino)
int compararStrings(stAlumno a, stAlumno b) {
    int k = 0;
    char c1, c2;

    while(a.nombre[k] != '\0' && b.nombre[k] != '\0') {
        c1 = tolower(a.nombre[k]);
        c2 = tolower(b.nombre[k]);

        if (c1 < c2) return -1; //alumnos i < alumnos j
        if (c1 > c2) return 1; //alumnos j > alumnos i

        k++;
    }

    if(a.nombre[k] == '\0' && b.nombre[k] == '\0') return 0; //si son iguales, retorno 0
    if(a.nombre[k] == '\0') return -1; //alumnos i es menor (menos letras)
    return 1;   //alumnos j es menor (menos letras)
}
void ordenarPorInsercionNombre(stAlumno Alumnos[], int validos) {
    int i, j;
    stAlumno aux;

    for(i = 0; i < validos; i++) {
        aux = Alumnos[i];
        j = i - 1;

        while(j >= 0 && compararStrings(Alumnos[j], aux) > 0) {
            Alumnos[j+1] = Alumnos[j];
            j--;
        }

        Alumnos[j+1] = aux;
    }
}


//punto 7 contar cantidad de alumnos de tal genero
int contadorGenero(stAlumno Alumnos[], int validos, char genero) {
    int contador = 0;
    for(int i=0; i<validos; i++) {
        if(Alumnos[i].genero == genero) contador++;
    }
    return contador;
}
void contarAlumnosPorGenero(stAlumno Alumnos[], int validos) { //buscar cantidad de alumnos de un genero
    char genero;
    printf("\nIngrese genero para buscar gantidad de alumnos: ");
    do {
        scanf(" %c", &genero);
    }while((genero!='m')&&(genero!='f')&&(genero!='o'));
    printf("Hay %d alumnos %c\n", contadorGenero(Alumnos, validos, genero), genero);
}


//menu
void menuPrint() {
    printf("\n+------MENU------+");
    printf("\n\n1- Mostrar alumnos");
    printf("\n2- Buscar alumno por matricula");
    printf("\n3- Ordenar por matricula");
    printf("\n4- Buscar alumnos por genero");
    printf("\n5- Insertar nuevo alumno");
    printf("\n6- Ordenar por orden alfabetico");
    printf("\n7- Buscar cantidad de alumnos de un genero");
}


//switch
void menuSwitch(stAlumno Alumnos[], int validos) {
    int control = -1;
    while(control!=0) {
        menuPrint();
        printf("\n\nIngrese una opcion: ");
        control = leerEntero();
        switch(control) {
        case 1:
            getch_clrsc();
            mostrarArregloAlumnos(Alumnos, validos);
            getch_clrsc();
            break;
        case 2:
            getch_clrsc();
            mostrarAlumnoPorMatricula(Alumnos, validos);
            getch_clrsc();
            break;
        case 3:
            getch_clrsc();
            ordenarPorSeleccionMatricula(Alumnos, validos);
            getch_clrsc();
            break;
        case 4:
            getch_clrsc();
            buscarAlumnosPorGenero(Alumnos, validos);
            getch_clrsc();
            break;
        case 5:
            getch_clrsc();
            limpiarBuffer();
            ordenarPorSeleccionMatricula(Alumnos, validos);
            insertarNuevoElemento(Alumnos, validos);
            getch_clrsc();
            break;
        case 6:
            getch_clrsc();
            ordenarPorInsercionNombre(Alumnos, validos);
            getch_clrsc();
            break;
        case 7:
            getch_clrsc();
            contarAlumnosPorGenero(Alumnos, validos);
            getch_clrsc();
            break;
        case 8:
            printf("\nSaliendo...\n");
            control = 0;
            break;
        default:
            printf("\nerror\n");
            control = -1;
            break;
        }
    }
}









