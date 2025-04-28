#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>

int carga_data(int*, int);
int suma_arr(int*, int);
float promedio(int*, int);
void carga_pila(int*, int, Pila*);
int buscar_menor(Pila);
int pos_mayor(int*, int);

int main()
{
    int temp[24];
    int val = 0;
    Pila DATA;
    inicpila(&DATA);

    printf("Ingrese 24 temperaturas entre -45 y 60 Centigrados. Ingrese cualquier letra para salir\n");
    val = carga_data(temp, val);
    mostrar_data(temp, val);
    carga_pila(temp, val, &DATA);

    printf("El promedio es de %.2f \n", promedio(temp,val));
    mostrar(&DATA);
    printf("El menor en la pila es %d \n", buscar_menor(DATA));
    printf("La mayor temperatura se encuentra en la %d posicion \n", pos_mayor(temp, val));

    return 0;
}
int pos_mayor(int *temp, int val){
    int pos = 0, mayor = temp[0];
    for(int i=0; i<val; i++){
        if(mayor < temp[i]){
            mayor = temp[i];
            pos = i;
        }
    }
    return pos;
}
int buscar_menor(Pila pila){
    int res = desapilar(&pila);
    while(!pilavacia(&pila)){
        if(tope(&pila) < res){
            res = desapilar(&pila);
        }
        else{
            desapilar(&pila);
        }
    }
    return res;
}
void carga_pila(int *arr, int val, Pila *DATA){
    int cond = promedio(arr, val);
    for(int i=0; i<val; i++){
        if(arr[i] <= cond){
            apilar(DATA, arr[i]);
        }
    }

}
int suma_arr(int *arr, int val){
    int res=0;
    for(int i=0; i< val; i++){
       res += arr[i];
    }
    return res;
}
float promedio(int *arr, int val){
    int suma = suma_arr(arr, val);
    return (float)suma/val;
}

int carga_data(int *temp, int val){
    int flag = 0;
    int i = 0;
    while(!flag){
            if(scanf("%d", &temp[i]) && i < 24) {
                if(temp[i] > -45 && temp[i] <= 60){
                    val++;
                    i++;
                }
                else {
                    printf("Temperatura incorrecta \n");
                }
            }
            else {
                flag = 1;
            }
    }
    return val;
}

void mostrar_data(int *arr, int val){
    int count = 0;
    for(int i=0; i<val; i++){
        printf(" %2.d |", arr[i]);
        count++;
        if(count == 8) {
            printf("\n");
            count = 0;
        }
    }
    printf("\n");
}
