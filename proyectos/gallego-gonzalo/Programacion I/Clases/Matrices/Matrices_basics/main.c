#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define ESC 27

void menu_principal();
void carga_manual_matriz(int x, int y, int[x][y], int val);
void carga_aleatoria_matriz(int x, int y, int[x][y]);
void mostrar_matriz_int(int x, int y, int[x][y]);
void mostrar_matriz_string(char*[], int);
void ingresar_matriz_string(char[5][20]);
int suma_mat(int x, int y, int[x][y]);
int busqueda_int(int x, int y, int[x][y], int dato);
float prom_mat(int suma, int val);

int main()
{
    srand(time(NULL));
    menu_principal();
    return 0;
}

void menu_principal(){
    char option;
    do{
        printf("\nIngrese un ejercicio a verificar: \n");
        option = getch();
        switch(option){
            case '1' :{
                int x = 2, y = 2;
                int data[x][y], val;
                printf("Ingresar datos\n");

                carga_manual_matriz(x, y, data, val);
                mostrar_matriz_int(x, y, data);
            break;
            }
            case '2':
            case '3': {
                int x = 2;
                int y = 5;
                int data[x][y];

                carga_aleatoria_matriz(x, y, data);
                mostrar_matriz_int(x, y, data);
            break;
            }
            case '4':
            case '5': {
                int x = 2;
                int y = 2;
                int data[x][y];

                carga_aleatoria_matriz(x, y, data);
                mostrar_matriz_int(x, y, data);

                printf("suma total = %d\n", suma_mat(x, y, data));
                printf("Promedio = %.2f\n", prom_mat(suma_mat(x, y, data), x*y));
            break;
            }
            case '6':{
                int x = 25;
                int y = 25;
                int data[x][y];
                int dato_busqueda;

                system("cls");
                carga_aleatoria_matriz(x, y, data);
                mostrar_matriz_int(x, y, data);
                printf("Ingrese dato a buscar en la matriz.. \n");
                scanf("%d", &dato_busqueda);
                /*if(busqueda_int(x, y, data, dato_busqueda)) { printf("dato encontrado"); }
                else { printf("dato no encontrado"); }*/
                if(busqueda_int(x, y, data, dato_busqueda) > 0) { printf("Dato encontrado %d veces", (busqueda_int(x, y, data, dato_busqueda))); }
                else { printf("Dato no encontrado"); }

            break;
            }
            case '7':{
                char data[5][20];

                printf("ingrese 5 frases\n");
                ingresar_matriz_string(data[5][20]);
            break;
            }
        }
    } while(option != ESC);
}

//----------------------------Funciones------------------------------//
void ingresar_matriz_string(char data[5][20]){
    for(int i=0; i<5; i++){
        gets(data[i]);
    }
}
int busqueda_int(int x, int y, int mat[x][y], int dato){
    int res = 0;
    int flag = 0;
    //while(!flag){
        for(int i=0; i<x; i++){
            for(int j=0; j<y; j++){
                if(mat[i][j] == dato){
                    res++;
                    //flag = 1;
                }

            }
        }
        //flag = 1;
    //}
    return res;
}

void carga_manual_matriz(int x, int y, int mat[x][y], int val){
    val = 0;

    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            printf("%d restantes..\n", (x*y)-val);
            scanf("%d", &mat[i][j]);
            val++;
        }
    }
}
void carga_aleatoria_matriz(int x, int y, int mat[x][y]){
    for(int i=0; i<x; i++){
        for(int j=0; j<y; j++){
            mat[i][j] = rand()%100;
        }
    }
}
void mostrar_matriz_string(char *mat[], int filas){
    printf("\n");
    for(int i=0; i<filas; i++){
        printf(" %s\n", mat[i]);
    }
}
void mostrar_matriz_int(int x, int y, int mat[x][y]){
    for(int i=0; i < x; i++){
        for(int j=0; j<y; j++){
            printf(" %2d ", mat[i][j]);
           if(j+1 == y){ printf("\n"); }
        }
    }
}
int suma_mat(int x, int y, int mat[x][y]){
    int res = 0;
    for(int i=0; i < x; i++){
        for(int j=0; j < y; j++){
            res += mat[i][j];
        }
    }
    return res;
}
float prom_mat(int suma, int val){ return (float)suma/val; }

