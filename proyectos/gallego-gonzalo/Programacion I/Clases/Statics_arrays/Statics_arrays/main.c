#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "pila.h"
#include <string.h>

int suma_array(int*, int);
int buscar_pos(char *arr, int tam, char buscado);
void insertarElem(char*, int, char, int);
int size_array(int[]);
void menu_principal(int);
void carga_aleatoria(int*, int);
void float_carga_aleatoria(float*, int);
void mostrar_arr_int(int*, int);
void mostrar_arr_float(float*, int);
void mostrar_arr_char(char*, int);
void clear_screen();
void carga_manual(int*, int);
void array_a_pila(int*, int, Pila*);
void search_char(char*, int , char);
void ordenar_alfabeticamente(char*, int);
void caracter_maximo(char*, int);
void es_capicua(char*, int);
void invertir_arr(char*, int);
int cant_elem_pila(Pila);
int search_pos(char*, int, char);
void insertar_char_arr(char*, int, char);
void desplazar_char_arr(char*, int);
void intercalar_arr(char*, char*, int, int);
void suma_por_indice(int*, int*,int);

int main()
{
    int option;
    srand(time(NULL));
    printf("Seleccion ejercicio: \n");
    scanf("%d", &option);
    menu_principal(option);

    return 0;
}
void suma_por_indice(int *arr, int *res, int tam){
    int aux = 0;

    for(int i=0; i< tam; i++){
        for(int j=0; j< i; j++){
            aux += arr[j];
        }
        res[i] = aux;
        aux = 0;
    }
}
void carga_aleatoria(int *arr, int numb){
   for(int i=0;i<numb;i++){ arr[i]=rand()%100; }
}
void float_carga_aleatoria(float *arr, int numb){
    for(int i=0;i<numb;i++){
        float res;
        int n1, n2;
        n1 = rand()%100;
        n2 = rand()%10+1;
        res = (float)n1/n2;
        arr[i] = res;
    }
}
void carga_manual(int *arr, int size) {
    int flag = 0, aux = 0, count=0;
    while(flag != 1){
        for(int i=0; i < size; i++){
            printf("%d valores restantes. Ingrese un caracter para salir \n\n", size - i);
            if(scanf("%d", &aux) == 1) {
                arr[i] = aux;
                count++;
            } else flag = 1;
            clear_screen();
        }
    }
    for(int i = count; i< size; i++) { arr[i] = 0; }

}
void mostrar_arr_int(int *arr, int size){
    printf("| ");
    for(int i=0; i < size; i++) {
            printf("%d | ", arr[i]); }
    printf("\n");
}
void mostrar_arr_float(float *arr, int size){
    for(int i=0; i < size; i++) {
            printf("| %5.2f ", arr[i]); }
    printf("\n");
}
void mostrar_arr_char(char *arr, int size){
    for(int i=0; i < size; i++) {
            printf("%c", arr[i]); }
    printf("\n");
}
void clear_screen(){
    system("cls");
}
int suma_array(int arr[], int size){
    int res=0;
    for(int i=0; i< size; i++){
        res += arr[i];
    }
    return res;
}
void array_a_pila(int *arr, int size, Pila *PILA){
    for(int i=0; i < size; i++){
        apilar(PILA, arr[i]);
    }
}
void array_a_pila2(int *arr, int size, Pila *PILA){
    int cant_pila = cant_elem_pila(*PILA);
    int count = 0;

    if(size < cant_pila) { printf("Espacio de memoria insuficiente."); }
    else {
        while(!pilavacia(PILA)){
            arr[size-count] = desapilar(PILA);
            count++;
        }
    }
}
int cant_elem_pila(Pila PILA){
    int count=0;
    while(!pilavacia(&PILA)){
        desapilar(&PILA);
        count++;
    }
    return count;
}
void search_char(char *arr, int size, char letra){
    char *aux = (char *)malloc(size-1);
    int count = 0;

    if(aux == NULL){
        printf("Error al asignar memoria.\n");
        return;
    }

    for(int i=0; i< size; i++){
        if(toupper(arr[i]) == toupper(letra)){
            aux[count] = letra;
            count++;
        }
    }
    printf("Letra seleccionada -> %c <-\n", letra);
    printf("Array Original ->");
    mostrar_arr_char(arr, size);
    printf("\ncoincidencias encontradas: %d\n", count);
    if(count!=0){
        printf("Letras totales encontradas ->");
        mostrar_arr_char(aux, count);
    }
    free(aux);
}
int search_pos(char *arr, int size, char letra){
    int pos = -1;
    for(int i=0; i<size; i++){
        if(toupper(arr[i]) == toupper(letra)){
            pos = i;
        }
    }
    return pos;
}
void ordenar_alfabeticamente(char *arr, int size){
    char aux;
    for(int i= 0; i< size; i++){
        int j = i;
        for(j; j< size; j++){
            aux = arr[i];
            if(arr[i] > arr[j]){
                arr[i] = arr[j];
                arr[j] = aux;
            }
        }
    }
}

void caracter_maximo(char *arr, int size){
    char caracter = arr[0];

    for(int i= 0; i< size; i++){
        if(caracter < arr[i]) {
            if( (arr[i] > 65 && arr[i] < 91) || (arr[i] > 97 && arr[i] < 123) ){
                caracter = arr[i];
            }
        }
    }
    printf("Caracter maximo -> %c", caracter);
}
void es_capicua(char *arr, int size){
    int flag = 0;

    for(int i=0; i<size/2; i++){
        char L1, L2;
        L1 = tolower(arr[i]);
        L2 = tolower(arr[(size-1)-i]);

        printf("%c -> %c\n", L1, L2);
        if(L1 != L2) { flag=1; }
    }

    if(flag == 0) { printf("\na oracion es capicua\n"); }
    else { printf("\nLa oracion no es capicua\n"); }

}
void invertir_arr(char *arr, int size){
    for(int i=5; i<10; i++){
        arr[i]         = arr[i] + arr[size-i-1];
        arr[size-i-1]  = arr[i] - arr[size-i-1];
        arr[i]         = arr[i] - arr[size-i-1];
    }
}
void desplazar_char_arr(char *arr, int pos){
        arr[pos] = arr[pos] + arr[pos+1];
        arr[pos+1] = arr[pos] - arr[pos+1];
        arr[pos] = arr[pos] - arr[pos+1];
}
void intercalar_arr(char *arr1, char *arr2, int tam1, int tam2){
    int size_res = tam1+tam2;
    int flag = 0, count = 0;
    char res[size_res];

    for(int i=0; i< size_res; i++){
        if(flag){
            res[i] = arr1[count];
            flag = 0;
            count++;
        } else {
            res[i] = arr2[count];
            flag = 1;
        }

    }
    mostrar_arr_char(res, size_res);
}
void menu_principal(int option) {
    clear_screen();
    switch(option){
        case 1: {
            int data[15];
            int size = sizeof(data)/ sizeof(data[0]);

            carga_manual(data, size);
            mostrar_arr_int(data, size);
        break;
        }
        case 2: {
            int data[5];
            int size = sizeof(data)/ sizeof(data[0]);
            carga_aleatoria(data, size);
            mostrar_arr_int(data, size);

        break;
        }
        case 3: {
            int data[15];
            int size = sizeof(data)/ sizeof(data[0]);
            carga_aleatoria(data, size);

            mostrar_arr_int(data, size);
            printf("\n\nSuma total de los elementos = %d\n", suma_array(data, size));
        break;
        }
        case 4: {
            int data[20];
            int size = sizeof(data)/ sizeof(data[0]);
            Pila DADA;
            inicpila(&DADA);

            carga_aleatoria(data, size);
            printf("Elementos del array\n\n");
            mostrar_arr_int(data, size);
            array_a_pila(data, size, &DADA);
            printf("\n\nPila DADA con los elementos del array\n\n");
            mostrar(&DADA);
        break;
        }
        case 5: {
            float data[100];
            int size = sizeof(data)/ sizeof(data[0]);

            float_carga_aleatoria(data, size);
            mostrar_arr_float(data, size);
        break;
        }
        case 666: {
            int *data;
            int size = 10;

            void ampliar(int **arr, int cantidad) {
                int temp = realloc(*arr, cantidad * sizeof(int));
                if(temp == NULL) {
                    printf("Error al reasignar memoria.");
                    return 1;
                }
            }

            void crear_array_dinamico(int **arr, int tam){
                *arr = (int *)malloc(tam * sizeof(int));
                if(*arr == NULL) {
                    printf("Error al asignar memoria.");
                    return;
                }
            }

            crear_array_dinamico(&data, size);


            carga_aleatoria(data, 10);
            mostrar_arr_int(data, 10);
            printf("\nAmpliando memoria..\n\n\n");
            ampliar(&data, 20);

            for(int i = 10; i<20; i++) {
                data[i] = i + 1 * 10;
            }
            mostrar_arr_int(data, 20);


            free(data);
        break;
        }
        case 6: {
            char data[13] = {"Hola haa.HHH"};
            char caracter;
            int size = sizeof(data)-1;

            printf("Ingrese Caracter a buscar en el array..\n");
            fflush(stdin);
            caracter = getch();
            clear_screen();
            search_char(data, size, caracter);

        break;
        }
        case 7: {
            char data[] = "Hola Mundo!.";
            int size = sizeof(data)-1;
            char letra;

            fflush(stdin);
            printf("Letra a ingresar..\n");
            letra = getch();
            mostrar_arr_char(data, size);
            printf("%c encontrada en posicion %d",letra, search_pos(data, size, letra));

        break;
        }
        case 8: {
            char data[] =   "Segun la tabla ascii las MINUSCULAS son mayores a las MAYUSCULAS, "
                            "pero si se quiere cambiar eso para que muestre las mayusculas como "
                            "mayores hay que poner un tolower() en la funcion.\n"
                            "Ademas este ejercicio lo hice para que no cuente los caracteres que "
                            "no sean letras.\n\n";

            int size = sizeof(data)-1;

            mostrar_arr_char(data, size);
            caracter_maximo(data, size);
        break;
        }
        case 9: {
            char data[] = "aaaAMenemaaAa";
            int size = sizeof(data)-1;

            printf("Oracion original -> ");
            mostrar_arr_char(data, size);
            es_capicua(data, size);
        break;
        }
        case 10: {
            char data[] = "Oracion a invertir.";
            int size = sizeof(data)-1;

            mostrar_arr_char(data, size);
            printf("Oracion invertida -> ");
            invertir_arr(data, size);
            mostrar_arr_char(data, size);

        break;
        }
        case 11: {
            char data1[] = "1234567890";
            int tam_data1 = sizeof(data1)-1;




        break;
        }
        case 12: {
            char data1[] = "abcdefg";
            char data2[] = "abcdefg";

            ordenar_alfabeticamente(data1, sizeof(data1)-1);
            ordenar_alfabeticamente(data2, sizeof(data2)-1);

            mostrar_arr_char(data1, sizeof(data1)-1);
            mostrar_arr_char(data2, sizeof(data2)-1);

            intercalar_arr(data1, data2, sizeof(data1)-1, sizeof(data2)-1);
        break;
        }
        case 13:{
            int data[] = {1,5,6,7,8};
            int tam = sizeof(data)/ sizeof(data[0]);
            int res[tam];

            suma_por_indice(data, res, tam);
            mostrar_arr_int(res, tam);
        break;
        }
        case 14: {
            char buf1 [ ] = "aaa AAA", buf2 [ ] = "AAA";
            char des[20];
            int res;
            res = strcmpi (buf2, buf1);
            printf ("string2 es: \"%s\" y string1 es: \"%s\"\n", buf2, buf1);

            if (res == 0)
                printf ("\n\nstring2 es igual a string1 ------> res = %d\n\n\n\n\n\t", res);
            else if (res > 0)
                printf ("\n\nstring2 es mayor que string1 ------> res = %d\n\n\n\n\n\t", res);
            else printf ("\n\nstring2 es menor que string1 ------> res = %d\n\n\n\n\n\t", res);

            printf("%s", strcpy(des, buf1));

        break;
        }
        case 15: {
            char data[15] = "abcdfghi";
            int tam = sizeof(data)-1;

            char buscado = 'e';

            printf("%c posicion encontrada -> %d\n", buscado, buscar_pos(data, tam, buscado));
            insertarElem(data, tam, buscado, buscar_pos(data, tam, buscado));
            mostrar_arr_char(data, tam);



        break;
        }

    }
}

int buscar_pos(char *arr, int tam, char buscado){
    int pos = -1;
    for(int i=0; i< tam; i++){
        if(buscado > arr[i] && buscado <= arr[i+1]){
            pos = i+1;
        }
    }
    return pos;
}

void insertarElem(char *arr, int tam, char buscado, int pos){
    for(int i = tam; i > pos ; i--){
        arr[i] = arr[i-1];
    }
    arr[pos]= buscado;
    arr[tam+1]= '\0';
}
