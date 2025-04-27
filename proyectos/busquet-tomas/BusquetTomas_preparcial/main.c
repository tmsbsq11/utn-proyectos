#include <stdio.h>
#include <stdlib.h>
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

//Funciones
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
void menuPrint();
void menuSwitch();
int ingresoTemperaturasUsuario(int*); //le mando un arreglo vacio a la funcion y me devuelve un entero con la cantidad de validos
void mostrarArreglo(int*, int);
float promedioTemperaturas(int*, int);
void pasarAPilaDebajoPromedio(int*, int, Pila*);
int buscarMinPila(Pila);
int posicionArregloTempMax(int*, int);


int main()
{
    menuSwitch();
    return 0;
}

void menuSwitch() {
    int control, v_arreglo, flag=0, min_flag=0;
    int arreglo[24];

    Pila PILA;
    inicpila(&PILA);

    do {
        menuPrint();
        scanf("%d", &control);
        switch(control) {
        case 0:
            printf("\n\nSaliendo del programa\n");
            break;
        case 1:
            limpiarPantalla();
            v_arreglo = ingresoTemperaturasUsuario(arreglo);
            mostrarArreglo(arreglo, v_arreglo);
            flag = 1;
            getch();
            limpiarPantalla();
            break;
        case 2:
            if(flag==1) {
                limpiarPantalla();
                printf("\nPromedio de las temperaturas: %.2f", promedioTemperaturas(arreglo,v_arreglo));
                getch();
                limpiarPantalla();
            } else {
                printf("\nIngresar arreglo primero");
                limpiarPantalla();
            }
            break;
        case 3:
            if(flag==1) {
                limpiarPantalla();
                pasarAPilaDebajoPromedio(arreglo, v_arreglo, &PILA);
                printf("\nBuscar temperatura más baja? SI:1 NO:0 \n");
                scanf("%d", &min_flag);
                if(min_flag == 1) {
                    printf("\nLa temperatura minima es: %d", buscarMinPila(PILA));
                }
            } else {
                printf("\nIngresar arreglo primero");
                limpiarPantalla();
            }
            break;
        case 4:
            if(flag==1) {
                limpiarPantalla();
                printf("\nPosicion en el arreglo de la temp. maxima: %d", posicionArregloTempMax(arreglo, v_arreglo));
                getch();
                limpiarPantalla();
            } else {
                printf("\nIngresar arreglo primero");
                limpiarPantalla();
            }
            break;
        default:
            printf("\nerror");
            break;
        }
    } while(control != 0);
}

void menuPrint() {
    printf("\n----MENU----");
    printf("\n1- Ingresar temperaturas");
    printf("\n2- Promedio de temperaturas");
    printf("\n3- Pasar temperaturas debajo del promedio a pila"); //usar funcion del punto 1 acá
    printf("\n4- Mostrar la posición de la temperatura más alta en el arreglo\n");
}


int ingresoTemperaturasUsuario(int temperaturas[]) {
    char control = 'x';
    int aux, limite = 0, validos = 0;

    do {
        printf("\n\nIngrese un numero entero entre -45 y 60: ");
        scanf("%d", &aux);

        //verifico intervalo
        if((aux>=-45)&&(aux<=60)) {
            temperaturas[validos] = aux;
            validos++;
            limite++;
        } else {
            printf("Ingrese un numero valido");
        }

        printf("\n's':SALIR: \n");
        fflush(stdin);
        control = getch();
    } while((control != 's')&&(limite<24));

    return validos;
}

void mostrarArreglo(int temperaturas[], int validos) {
    int salto = -1;

    for(int i=0; i<validos;i++) {
        salto++;
        if(salto % 8 == 0) {
            printf("\n");
            printf(" %d", temperaturas[i]);
        } else {
            printf(" %d", temperaturas[i]);
        }
    }
}

float promedioTemperaturas(int temperaturas[], int validos) {
    float aux = 0;

    for(int i=0; i<validos; i++) {
        aux = aux + temperaturas[i];
    }
    aux = (float) (aux/validos);

    return aux;
}

void pasarAPilaDebajoPromedio(int temperaturas[], int validos, Pila* PILA) {
    float promedio = promedioTemperaturas(temperaturas, validos);

    for(int i=0; i<validos; i++) {
        if(temperaturas[i]<promedio) {
            apilar(PILA, temperaturas[i]);
        }
    }
}

int buscarMinPila(Pila PILA) {
    int aux = desapilar(&PILA);

    while(pilavacia(&PILA)==0) {
        if(tope(&PILA)<aux) {
            aux = desapilar(&PILA);
        } else {
            desapilar(&PILA);
        }
    }

    return aux;
}

int posicionArregloTempMax(int temperaturas[], int validos) {
    int aux = temperaturas[0];
    int posicion = 0;

    for(int i=0; i<validos; i++) {
        if(temperaturas[i]>aux) {
            aux = temperaturas[i];
            posicion = i;
        }
    }

    return posicion;
}
