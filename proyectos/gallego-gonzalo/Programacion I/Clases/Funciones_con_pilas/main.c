#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <time.h>
#include <conio.h>
#define ESC 27

// PROTOTIPADOS.
int cargaData();
int invertirPila(Pila*);
int cargaAleatoria(Pila*, int);
int menor(Pila);
int sumaPriEle(Pila);
int suma(Pila);
int cantDatos(Pila);
long long int pilaEntero(Pila);
float division(float, float);
float porcentajeTotal(Pila, int);
void imprimirPila(Pila);
void generarCopia(Pila, Pila*);
void ordenarPila(Pila*);
void pasarDataPila(Pila*, Pila*);
void printearMenu();
void menu();
void cargaPila(Pila*);
void traspasarData(Pila*, Pila*);
void pasajeTerminos(Pila*, Pila*);
void eliminarNum(Pila*, int);
void ordenarPilas(Pila*, Pila*);
void ingresarDataEnPila(Pila*, int, int);
void promedio(Pila);
int main(){
    srand(time(NULL));
    menu();
    return 0;
}

// FUNCIONES GENERALES.
int cargaData(){
    int data;
    scanf("%d", &data);
    return data;
}
int invertirPila(Pila *pila){
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);
    while(!pilavacia(pila)) {apilar(&aux, desapilar(pila));}
    while(!pilavacia(&aux)) {apilar(&aux2, desapilar(&aux));}
    while(!pilavacia(&aux2)) {apilar(pila, desapilar(&aux2));}
    return pila;
}
int cargaAleatoria(Pila *pila, int n){
    for(int i=0; i< n; i++) {apilar(pila, rand()%10);}
    return pila;
}
void imprimirPila(Pila data){
    printf("Tope ---------------------------------------------------------- Base\n\n");
    while(!pilavacia(&data)){
        printf(" %d |", desapilar(&data));
    }
    printf("\n\nTope ---------------------------------------------------------- Base\n");
}
void generarCopia(Pila original, Pila *copia){
    while(!pilavacia(&original)){
        apilar(copia, desapilar(&original));
    }
    invertirPila(copia);
}
void ordenarPila(Pila *origen){
                int aux;
                Pila pilaAux;
                inicpila(&pilaAux);
                while(!pilavacia(origen)){
                    aux = desapilar(origen);
                    if(tope(&pilaAux) < aux && !pilavacia(&pilaAux)){
                        while(!pilavacia(&pilaAux)) { apilar(origen, desapilar(&pilaAux)); }
                        apilar(&pilaAux, aux);
                    } else {
                        apilar(&pilaAux, aux);
                     }
                }
                while(!pilavacia(&pilaAux)) { apilar(origen, desapilar(&pilaAux)); }
                invertirPila(origen);
            }
void pasarDataPila(Pila *origen, Pila *destino){
    while(!pilavacia(origen)) { apilar(destino, desapilar(origen)); }
    }
void printearMenu(){


    printf("\nHacer una funcion que: ..");
    printf("\n1  - Permita ingresar varios elementos a una pila, tanto como quiera el usuario. ");
    printf("\n2  - Pase todos los elementos de una pila a otra.");
    printf("\n3  - Pase todos los elementos de una pila a otra, pero conservando el orden. ");
    printf("\n4  - Encuentre el menor elemento de una pila y lo retorna. La misma debe eliminar ese dato de la pila.");
    printf("\n5  - Pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funcion del ejercicio 4. (Ordenamiento por seleccion)");
    printf("\n6  - Inserta en una pila ordenada un nuevo elemento, conservando el orden de esta. ");
    printf("\n7  - Pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada. Usar la funcion del ejercicio 6.  (Ordenamiento por insercion)");
    printf("\n8  - Sume los dos primeros elementos de una pila (tope y anterior), y retorne la suma,  sin alterar el contenido de la pila.");
    printf("\n9  - Calcule el promedio de los elementos de una pila, para ello hacer también una funcion que calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la funcion que calcula el promedio invoca a las otras 3.");
    printf("\n10 - Reciba una pila con numeros de un solo digito (es responsabilidad de quien usa el programa) y que transforme esos digitos en un numero decimal.\n\n");
}
void menu(int data){
    int option = 0;
    printf("Ingrese ejercicio a revisar: \n");
    printearMenu();
    scanf("%d", &option);

    system("cls");
    switch(option){
        case 1: {
            Pila pila;
            inicpila(&pila);

            printf("Ingrese la cantidad de datos deseados a la pila.. \n\n");
            cargaPila(&pila);
            system("cls");
            imprimirPila(pila);
        }
        break;

        case 2: {
                Pila data1, data2;
                inicpila(&data1);
                inicpila(&data2);

                for(int i=0; i<10; i++){
                    apilar(&data1, rand()%100);
                    apilar(&data2, rand()%100);
                }

                printf("  Pila Nro 1 \n");
                mostrar(&data1);
                printf("\n\n  Pila Nro 2 \n");
                mostrar(&data2);

                traspasarData(&data1, &data2);
        break;
        }

        case 3: {
            Pila data, data2;
            inicpila(&data);
            inicpila(&data2);
            cargaAleatoria(&data, 6);
            cargaAleatoria(&data2, 6);

            printf("  Origen\n");
            imprimirPila(data);
            printf("  Destino\n");
            imprimirPila(data2);
            printf("  Despues del traspaso\n");
            pasajeTerminos(&data, &data2);


        break;
        }

        case 4: {
            Pila data;
            inicpila(&data);
            cargaAleatoria(&data, 10);

            imprimirPila(data);
            printf("numero menor de la pila: %d\n", menor(data));
            printf("Pila con numero eliminado: \n");
            eliminarNum(&data, menor(data));
            imprimirPila(data);
            break;
        }

        case 5: {
            Pila original, destino;
            inicpila(&original);
            inicpila(&destino);
            cargaAleatoria(&original, 40);
            cargaAleatoria(&destino, 5);
            printf("  Origen\n");
            imprimirPila(original);
            printf("\n Destino\n");
            imprimirPila(destino);

            printf("\nPila DESTINO ordenada: \n\n");
            ordenarPilas(&original, &destino);
            imprimirPila(destino);
        break;
        }

        case 6: {
            Pila data;
            inicpila(&data);
            cargaAleatoria(&data, 10);
            //ordenarPila(&data);
            int num, pos;


            printf("  Pila ORIGEN.. \n\n");
            imprimirPila(data);
            printf("Que dato desea ingresar?\n");
            scanf("%d", &num);
            printf("En que posicion desea ponerlo? (desde base a tope)\n");
            scanf("%d", &pos);
            ingresarDataEnPila(&data, num, pos);
            printf("\n  Pila con dato ingresado.. \n\n");
            imprimirPila(data);


        break;
        }

        case 7: {
            Pila origen, destino, fusion;
            inicpila(&origen);
            inicpila(&destino);
            inicpila(&fusion);
            cargaAleatoria(&origen, 7);
            cargaAleatoria(&destino, 4);

            printf("  Pila ORIGEN: \n");
            imprimirPila(origen);
            printf("  Pila DESTINO: \n");
            imprimirPila(destino);
            pasarDataPila(&origen, &destino);
            printf("\n  Pila FUSION ordenada\n\n");
            pasarDataPila(&destino, &fusion);
            ordenarPila(&fusion);
            imprimirPila(fusion);
        break;
        }

        case 8: {
            Pila data;
            inicpila(&data);
            cargaAleatoria(&data, 10);

            printf(" Antes de la suma.. \n");
            imprimirPila(data);
            printf("\n\nSuma de primeros 2 elementos tope de la pila = %d\n", sumaPriEle(data));
            printf("\n\n Despues de la suma..\n");
            imprimirPila(data);
        break;
        }

        case 9: {
            Pila data;
            inicpila(&data);
            cargaAleatoria(&data, 15);
            imprimirPila(data);

            printf("Cantidad de datos.. %d \n", cantDatos(data));
            promedio(data);
            printf("\n %% TOTAL de aprobados es del %.1f%%", porcentajeTotal(data, 7));
        break;
        }

        case 10: {
            Pila data;
            inicpila(&data);

            cargaAleatoria(&data, 10);
            imprimirPila(data);
            printf("\n Pila a numero entero = %lli", pilaEntero(data));
        break;
        }
    }
    //} while(option != 27);
}

// FUNCIONES ESPECIFICAS DE CADA CASO.
// case 1
void cargaPila(Pila *pila){
    int data = 0;
    while(scanf("%d \n", &data) == 1){
    apilar(pila, data);
    }
}
// case 2
void traspasarData(Pila *pila1, Pila *pila2)
{
    while(!pilavacia(pila1))
    {
        apilar(pila2, desapilar(pila1));
    }
    printf(" Resultado final.. \n");
    mostrar(pila2);
}
// case 3
void pasajeTerminos(Pila *origen, Pila *destino)
{
    invertirPila(origen);
    while(!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
    imprimirPila(*destino);
}
// case 4
int menor(Pila pila)
{
    int number = tope(&pila);
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(&pila))
    {
        if(number > tope(&pila))
        {
            number = tope(&pila);
            apilar(&aux, desapilar(&pila));
        }
        else
        {
            apilar(&aux, desapilar(&pila));
        }
    }
    invertirPila(&pila);
    return number;
}

void eliminarNum(Pila *pila, int number)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(pila))
    {
        if(tope(pila) == number)
        {
            desapilar(pila);
        }
        else
        {
            apilar(&aux, desapilar(pila));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(pila, desapilar(&aux));
    }
}
// case 5
void ordenarPilas(Pila *origen, Pila *destino)
{
    int aux;
    while(!pilavacia(origen))
    {
        aux = desapilar(origen);
        if(tope(destino) < aux && !pilavacia(destino))
        {
            while(!pilavacia(destino))
            {
                apilar(origen, desapilar(destino));
            }
            apilar(destino, aux);
        }
        else
        {
            apilar(destino, aux);
        }
    }
}
// case 6
void ingresarDataEnPila(Pila *pila, int num, int pos)
{
    Pila aux;
    inicpila(&aux);
    int count=1;
    invertirPila(pila);
    while(!pilavacia(pila) && count < pos)
    {
        apilar(&aux, desapilar(pila));
        count++;
    }
    apilar(&aux, num);
    pasarDataPila(pila, &aux);
    pasarDataPila(&aux, pila);
    invertirPila(pila);
}
// case 8
int sumaPriEle(Pila pila)
{
    int res=0;
    for(int i=0; i<2; i++)
    {
        res += tope(&pila);
        desapilar(&pila);
    }
    return res;
}
// case 9
int suma(Pila pila)
{
    int sumaTotal = desapilar(&pila);
    while(!pilavacia(&pila))
    {
        sumaTotal += desapilar(&pila);
    }
    return sumaTotal;
}
int cantDatos(Pila pila)
{
    int count = 0;
    while(!pilavacia(&pila))
    {
        desapilar(&pila);
        count++;
    }
    return count;
}
float division(float sumaTotal, float numDatos)
{
    float prom;
    prom = sumaTotal/ numDatos;
    return prom;
}
float porcentajeTotal(Pila pila, int num)
{
    int count = 0;
    int cantMax = cantDatos(pila);
    float res = 0;

    while(!pilavacia(&pila))
    {
        if(tope(&pila) >= num)
        {
            count++;
            desapilar(&pila);
        }
        else
        {
            desapilar(&pila);
        }
    }
    res = (float)count/cantMax;
    return res*100;
}
void promedio(Pila data)
{
    printf("\n El promedio entre los datos de la pila es de = %.2f \n", division(suma(data), cantDatos(data)));
}
// case 10
long long int pilaEntero(Pila data)
{
    long long int mult = 1, res = 0, numb, aux;

    invertirPila(&data);
    while(!pilavacia(&data))
    {
        numb = desapilar(&data);
        if(numb != 0)
        {
            aux = numb * mult;
            res += aux;
        }
        mult*=10;
    }
    return res;
}
