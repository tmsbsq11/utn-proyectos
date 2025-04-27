#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "pila.h"
//FUNCION GETCH (estoy en linux por lo tanto no tengo la libreria conio)
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

#define DIM 20
#define M_DIM 10
#define S_DIM 10
#define MAX_LEN 30

//Funciones
void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}
int cargarDatos(int*, int*);
void clasificarPorGenero(int*, int*, int, Pila*, Pila*, Pila*, int* n_policial, int* n_romance, int* n_terror); //dentro 3 punteros con cantidad de genero
int posicionMenor(int*, int, int);
void ordenarISBN(int*, int*, int);
void muestraInversa(int*, int*, int, int);
void generaMatrizRandom(int matriz[M_DIM][M_DIM]);
void imprimirMatrizRandom(int matriz[M_DIM][M_DIM]);
void cantidadesPorCodigo(int codigos[], int matriz[M_DIM][M_DIM], int validos);
int cantidadApariciones(int valor, int matriz[M_DIM][M_DIM]);
int informaPorPal(char misPalabras[S_DIM][MAX_LEN], char letra);


int main()
{
    int codigosISBN[DIM]; //contendrá los codigos ISBN de los libros
    int generosLibros[DIM]; //1 Policial, 2 Romance, 3 Terror
    int opcion, validos, n_policial = 0, n_romance = 0, n_terror = 0, limite;
    int matrizRandom[M_DIM][M_DIM];
    char misPalabras[S_DIM][MAX_LEN] = {
        "Alma", "Montaña", "Sol", "Verano", "Amor", "Nieve", "Flor", "Aventura", "Arco", "Miel"
    };
    char letra;

    Pila POLICIAL, ROMANCE, TERROR;
    inicpila(&POLICIAL);
    inicpila(&ROMANCE);
    inicpila(&TERROR);

    validos = cargarDatos(codigosISBN, generosLibros);
    clasificarPorGenero(codigosISBN, generosLibros, validos, &POLICIAL, &ROMANCE, &TERROR, &n_policial, &n_romance, &n_terror);
    ordenarISBN(codigosISBN, generosLibros, validos);

    printf("\nIngrese numero limite a buscar entre 1 y 100: ");
    do {
        scanf("%d", &limite);
    } while(limite>100 || limite<0);
    muestraInversa(codigosISBN, generosLibros, validos, limite);

    generaMatrizRandom(matrizRandom);
    imprimirMatrizRandom(matrizRandom);
    cantidadesPorCodigo(codigosISBN, matrizRandom, validos);

    printf("\n\nIngrese una letra para usar como parametro: ");
    do {
        scanf("%c", &letra);
    } while(!isalpha(letra));
    informaPorPal(misPalabras, letra);

    return 0;
}


int cargarDatos(int codigos[], int generos[]) {
    char control = 'x';
    int limite = 0, validos = 0, aux;

    srand(time(NULL));
    while((control != 's')&&(limite<DIM)) {
        codigos[validos] = rand()%100+1;
        printf("\n\nCodigo generado para libro en pos. %d: %d", validos, codigos[validos]);

        do {
            printf("\nGenero del libro (1.POLICIAL, 2.ROMANCE, 3.TERROR): ");
            scanf("%d", &aux);
        } while (aux < 1 || aux > 3);


        generos[validos] = aux;
        printf("CODIGO: %d", codigos[validos]);
        if(generos[validos]==1) {
            printf("\nGENERO: POLICIAL");
        } else if (generos[validos]==2) {
            printf("\nGENERO: ROMANCE");
        } else {
            printf("\nGENERO: TERROR");
        }
        validos++;
        limite++;

        printf("\nContinuar?: 's':SALIR ");
        fflush(stdin);
        control = getch();
    }

    return validos;
}

//void mostrarDatos(int codigos[], int generos[])

void clasificarPorGenero(int codigos[], int generos[], int validos, Pila* POLICIAL, Pila* ROMANCE, Pila* TERROR, int* n_policial, int* n_romance, int* n_terror) {

    for(int i=0; i<validos; i++) {
        if(generos[i]==1) {
            apilar(POLICIAL, codigos[i]);
            *n_policial++;
        } else if (generos[i]==2) {
            apilar(ROMANCE, codigos[i]);
            *n_romance++;
        } else {
            apilar(TERROR, codigos[i]);
            *n_terror++;
        }
    }

    printf("\n\nCantidad de libros policiales: %d", *n_policial);
    printf("\nCantidad de libros de romance: %d", *n_romance);
    printf("\nCantidad de libros de terror: %d", *n_terror);
    printf("\n\nCodigos en cada pila: ");
    printf("Policial");
    mostrar(POLICIAL);
    printf("Romance");
    mostrar(ROMANCE);
    printf("Terror");
    mostrar(TERROR);
}

int posicionMenor(int arreglo[], int pos, int validos) {
    int menor = arreglo[pos];
    int pos_menor = pos;
    int index = pos + 1;

    while(index < validos) {
        if(menor > arreglo[index]) {
            menor = arreglo[index];
            pos_menor = index;
        }
        index++;
    }
    return pos_menor;
}


void ordenarISBN(int codigos[], int generos[], int validos) {
    int pos_menor, aux_codigos, aux_generos, i = 0;

    while(i<validos-1) {
        pos_menor = posicionMenor(codigos, i, validos);
        aux_codigos = codigos[pos_menor];
        aux_generos = generos[pos_menor];
        codigos[pos_menor] = codigos[i];
        generos[pos_menor] = generos[i];
        codigos[i] = aux_codigos;
        generos[i] = aux_generos;
        i++;
    }
}

void muestraInversa(int codigos[], int generos[], int validos, int limite) {
    int i = validos - 1;

    while(i>=0 && codigos[i] > limite) {
        printf("\nCodigo: %d", codigos[i]);
        i--;
    }

    if(i>=0) {
        printf("\nCodigo: %d", codigos[i]);
    }

}

void generaMatrizRandom(int matriz[M_DIM][M_DIM]) {
    srand(time(NULL));

    for(int i=0; i<M_DIM; i++) {
        for(int j=0; j<M_DIM; j++) {
            matriz[i][j] = rand()%100+1;
        }
    }
}

void imprimirMatrizRandom(int matriz[M_DIM][M_DIM]) {
    printf("\n");
    for(int j=0; j<M_DIM; j++) {
        printf("+-----");
    }
    printf("+\n");

    for(int i=0; i<M_DIM; i++) {
        for(int j=0; j<M_DIM; j++) {
            printf("| %3d ", matriz[i][j]);
        }
        printf("|\n");

        for(int j=0; j<M_DIM; j++) {
            printf("+-----");
        }
        printf("|\n");
    }
}

//cuenta cuantas veces aparece un valor de codigoISBN en la matriz
int cantidadApariciones(int valor, int matriz[M_DIM][M_DIM]) {
    int contador = 0;

    for(int i=0; i<M_DIM; i++) {
        for(int j=0; j<M_DIM; j++) {
            if(matriz[i][j] == valor) {
                contador ++;
            }
        }

    }

    return contador;
}

//recorre codigoISBN y llama a cantidadApariciones
void cantidadesPorCodigo(int codigos[], int matriz[M_DIM][M_DIM], int validos) {
    int cantidad;
    for(int i=0; i<validos; i++) {
        cantidad = cantidadApariciones(codigos[i], matriz);
        printf("\nCodigo %d aparece %d veces en la matriz.", codigos[i], cantidad);
    }
}

int informaPorPal(char misPalabras[S_DIM][MAX_LEN], char letra) {
    int contador = 0, lenght;
    char primera, ultima;
    letra = tolower(letra);

    for(int i=0; i<S_DIM; i++) {
        lenght = strlen(misPalabras[i]);

        primera =  tolower(misPalabras[i][0]);
        ultima =  tolower(misPalabras[i][lenght - 1]);

        if((primera == letra)||(ultima == letra)) {
            printf("-> %s\n", misPalabras[i]);
            contador ++;
        }
    }
    return contador;
}












