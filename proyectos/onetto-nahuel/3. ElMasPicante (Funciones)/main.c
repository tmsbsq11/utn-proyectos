#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int num_gen(); /// Punto 1
void nA_B(int arreglo[]); /// Punto 2
int sumas(int a); /// Punto 3
void multip(int tabla); /// Punto 4
float calculadora(); /// Punto 5
int negar(int ent); /// Punto 6
void cargarNum(int *a, int *b); /// Punto 7



int main()
{

    /// -------------------------------- PUNTO 1
    int random = num_gen();
    printf("N%cmero random del d%ca: %i\n", 163, 161, random);

    system("pause");
    system("cls");



    /// -------------------------------- PUNTO 2
    int a[3];

    printf("Escriba tres n%cmeros\n", 163);

    for(int i=0; i<3; i++) {
        printf("Ingrese el n%cmero ", 163);
        scanf("%i", &a[i]);
    }

    nA_B(a);

    system("pause");
    system("cls");



    /// -------------------------------- PUNTO 3
    int nu, sum1;

    printf("Ingrese un valor X que sumar%c todos sus posteriores n%cmeros: ", 160, 163);
    scanf("%i", &nu);


    sum1 = sumas(nu);

    printf("\nLa suma total es: %i\n\n", sum1);

    system("pause");
    system("cls");



    /// PUNTO 4
    int tabla;

    printf("Ingrese un valor para mostrar su tabla de multiplicar: ");
    scanf("%i", &tabla);

    multip(tabla);

    system("pause");
    system("cls");



    /// -------------------------------- PUNTO 5
    float resultado = calculadora();
    printf("Resultado: %.2f", resultado);

    system("pause");
    system("cls");



    /// -------------------------------- PUNTO 6
    int ent;

    printf("Ingrese un n%cmero entero y positivo: ", 163);
    scanf("%i", &ent);

    int nn = negar(ent);

    printf("El n%cmero antes %i y despu%cs %i", 163, ent, 130, nn);

    system("pause");
    system("cls");



    /// -------------------------------- PUNTO 7
    int num1, num2;
    cargarNum(&num1, &num2);
    printf("Los valores son %i y %i", num1, num2);

    return 0;
}







/// -------------------------------- PUNTO 1

int num_gen() {
    srand(time(NULL));
    int num = rand() % 100 + 1;
    return num;
}

/// -------------------------------- PUNTO 2

void nA_B(int arreglo[])
{
    int menor=arreglo[0];
    int mayor=arreglo[0];

    for(int i=0; i<3; i++) {
        if(menor > arreglo[i]) {
            menor = arreglo[i];
        }
        else {
            mayor = arreglo[i];
        }
    }

    printf("\nNum. m%cs chico: %i\n", 160, menor);
    printf("Num. m%cs grande: %i\n\n", 160, mayor);
}

/// -------------------------------- PUNTO 3

int sumas(int nu) {
    int num=0;
    for(int i=0; i<=nu; i++) {
        num = num + i;
    }
    return num;
}

/// -------------------------------- PUNTO 4

void multip(int tabla) {
    printf("Tabla del %i \n", tabla);
    for(int i=0; i<11; i++){
        int resu = tabla*i;
        printf("%i X %i = %i\n", tabla, i, resu);
    }
}

/// -------------------------------- PUNTO 5

float calculadora() {
    int option;
    int result = 0;
    double num1, num2;

    do {
        printf("Seleccione una opci%cn: ", 162);
        printf("\n1) Sumar");
        printf("\n2) Restar");
        printf("\n3) Multiplicar");
        printf("\n4) Dividir");
        printf("\n5) Ra%cz", 161);
        printf("\n6) Exponente");
        printf("\n7) Salir\n");
        scanf("%i", &option);

        switch(option) {
            case 1: {
                printf("\nIngrese dos n%cmeros", 163);
                printf("\nPrimer n%cmero: ", 163);
                scanf("%lf", &num1);
                printf("Segundo n%cmero: ", 163);
                scanf("%lf", &num2);
                float result = num1 + num2;
                printf("Resultado: %.2lf\n", result);

                system("pause");
                system("cls");
                break;
            }
            case 2: {
                printf("\nIngrese dos n%cmeros", 163);
                printf("\nPrimer n%cmero: ", 163);
                scanf("%lf", &num1);
                printf("Segundo n%cmero: ", 163);
                scanf("%lf", &num2);
                float result = num1 - num2;
                printf("Resultado: %.2lf\n", result);

                system("pause");
                system("cls");
                break;
            }
            case 3: {
                printf("\nIngrese dos n%cmeros", 163);
                printf("\nPrimer n%cmero: ", 163);
                scanf("%lf", &num1);
                printf("Segundo n%cmero: ", 163);
                scanf("%lf", &num2);
                float result = num1 * num2;
                printf("Resultado: %.2lf\n", result);

                system("pause");
                system("cls");
                break;
            }
            case 4: {
                printf("\nIngrese dos n%cmeros", 163);
                printf("\nPrimer n%cmero: ", 163);
                scanf("%lf", &num1);
                printf("Segundo n%cmero: ", 163);
                scanf("%lf", &num2);
                float result = num1 / num2;
                printf("Resultado: %.2lf\n", result);

                system("pause");
                system("cls");
                break;
            }
            case 5: {
                float raiz;
                printf("\nIngrese un n%cmero: ", 163);
                scanf("%lf", &num1);

                if(num1 < 0) {
                    printf("No existe la ra%cz de n%cmeros negativos\n", 161, 163);
                    break;
                }
                else {
                    raiz = sqrt(num1);
                    printf("La ra%cz de %.0lf es: %.2lf\n", 161, num1, raiz);
                }

                system("pause");
                system("cls");
                break;
            }
            case 6: {
                float result = pow(num1, num2);
                printf("\nIngrese un n%cmero: ", 163);
                scanf("%lf", &num1);
                printf("\nIngrese el exponente; ");
                scanf("%lf", &num2);

                printf("\n%lf^%lf = %lf\n", num1, num2, result);

                system("pause");
                system("cls");
                break;
            }
            case 7: {
                printf("Saliendo de la calculadora...");
                break;
            }
            default: {
                printf("Opción no v%clida", 160);
            }
        }
    }
    while (option != 7);
    return result;
}

/// -------------------------------- PUNTO 6

int negar(int ent) {
    int ng = (ent)*(-1);
    return ng;
}

/// -------------------------------- PUNTO 7

void cargarNum(int *a, int *b) {
    printf("Ingrese un n%cmero: ", 163);
    scanf("%i", a);
    printf("Ingrese un n%cmero: ", 163);
    scanf("%i", b);
}
