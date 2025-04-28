#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL)); //semilla para rand().
    printearMenu(); //Carga el menu de los ejercicios.

    return 0;
}
void printearMenu(){
    printf("Trabajo practico Nro 3 - Funciones\n\n");
    printf("Menu de ejercicios, seleccione un ejercicio a mostrar..\n\n");
    printf("1 - Funcion que devuelve valor random entre 0 y 100.\n");
    printf("2 - Funcion que recibe 3 enteros, muestra mayor y menor.\n");
    printf("3 - Funcion que recibe entero y realiza suma de anteriores.\n");
    printf("4 - Funcion que muestra tabla de multiplicar.\n");
    printf("5 - Funcion que muestra una calculadora.\n");
    printf("6 - Funcion que recibe positivo por ref. y cambia a negativo.\n");
    printf("7 - Funcion que recibe enteros por parametro y muestra sus valores dentro de una funcion.\n\n");
    menuEjercicios();
}

void menuEjercicios(){
    int option;
    scanf("%i", &option);
    system("cls");


    switch(option){
        case 1: {
            int randomizer(){
                int num = rand()%100;
                return num;
            }
            printf("Numero aleatoreo entre 0 y 100: %i", randomizer());
            break;
        }
        case 2: {
            int num[3];

            printf("Ingrese tres numeros enteros \n");
            for(int i=0; i<3; i++){
                scanf("%i", &num[i]);
            }
            int numMin(int *num){
                int auxMin = num[0];
                for(int i=0; i<3; i++) if(auxMin > num[i]) auxMin = num[i];
                return auxMin;
            }

            int numMax(int *num){
                int auxMax = num[0];
                for(int i=0; i< 3; i++) if(auxMax < num[i]) auxMax = num[i];
                return auxMax;
            }

            printf("Numero menor: %i \n", numMin(num));
            printf("Numero mayor: %i \n", numMax(num));
            break;
        }

        case 3: {

        int n;

        printf("Ingrese un dato entero: \n");
        scanf("%d", &n);

        int sumaMenores(int num){
            int res=0;
            for(int i= num-1; i>0; i--) if(i%2 == 0) res += i;
            return res;
        }

        printf("Suma de anteriores positivos a N es: %i \n", sumaMenores(n));
        break;
        }

        case 4: {
            int n, mult = 1;
            int tablaMul(int num, int multi){return n * multi;}

            printf("Ingrese un numero entero.. \n");
            scanf("%d", &n);
            system("cls");

            printf("Tabla de multiplicar de %d \n\n", n);
            for(int i = 1; i<=10; i++){printf("%d x %d = %d\n", n, i, tablaMul(n, i));}
        break;
        }

        case 5: {
            int option; //Se puede quitar si llamo a data() en el switch.

            int     suma(int n1, int n2)    {return n2+n1;}
            int     resta(int n1, int n2)   {return n2-n1;}
            int     multi(int n1, int n2)   {return n2*n1;}
            float   div(int n1, int n2)     {return (float)n2/n1;}
            int     data(){
                int var;
                printf("dato.. \n");
                scanf("%d", &var);
                return var;
            }

            printf("Indique operacion deseada: \n\n");
            printf("* 1 - Suma \n");
            printf("* 2 - Resta \n");
            printf("* 3 - Multiplicacion \n");
            printf("* 4 - Division \n");
            printf("Otro - Salir\n");
            scanf("%d", &option);

                switch(option){
                    case 1:{
                        system("cls");
                        printf("Resultado = %d", suma(data(), data()));
                    break;
                    }
                    case 2:{
                        system("cls");
                        printf("Resultado = %d", resta(data(), data()));
                    break;
                    }
                    case 3:{
                        system("cls");
                        printf("Resultado = %d", multi(data(), data()));
                    break;
                    }
                    case 4:{
                        system("cls");
                        printf("Resultado = %.2f", div(data(), data()));
                    break;
                    }
                    default:{
                        printf("Cerrando programa.. ");
                    break;
                    }
                }
            break;
        }

        case 6: {
            int n = 0;
            printf("\nIngrese numero positivo: \n\n");
            scanf("%i", &n);

            int aNegativo(int *n){
                int data = n;
                return data*-1;
            }
            printf("\nNumero en negativo: %d", aNegativo(n));
            break;
        }

        case 7: {
        int a,b;

        void cargaData(int *a, int *b){
            printf("ingrese dato.. \n");
            scanf("%d", &a);
            printf("segundo dato \n");
            scanf("%d", &b);


            printf("primer dato: %d \n", a);
            printf("primer dato: %d \n", b);
        }
        cargaData(a,b);
        break;
        }
    }
}
