#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//punto 1
void punto1();
int rando();

//punto 2
void punto2();
void mayorYMenor(int, int, int);

//punto 3
void punto3();
int sumatoriaMenores(int);

//punto 4
void punto4();
void tablaMultiplicar();

//punto 5
void punto5();
void menu();
void opciones(float, float);
float suma(float,float);
float resta(float,float);
float multiplicacion(float,float);
float division(float,float);

//punto 6
void punto6();
int cambioDeSigno(int*);

//punto 7
void punto7();
void cargaDeValores(int*,int*);


int main()
{
    srand(time(NULL));
    /**1- Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.
    punto1();*/
    /**2- Diseñe una función que reciba 3 números enteros y muestre el mayor y el menor.
    punto2();*/
    /**3- Diseñe una función que reciba un número entero N y realice la suma de los números
    enteros positivos menores que N y lo retorne. N es un  dato ingresado por el usuario en el main.
    punto3();*/
    /**4- Desarrollar una función que muestre la tabla de multiplicar de un número entero recibido por parámetro.
    punto4();*/
    /**5- Realice una pequeña calculadora, utilizando funciones (una función de suma, una de multiplicación,
    una de resta, una de división…)
    punto5();*/
    /**6- Realizar una función que reciba un número positivo entero por parámetro por referencia, y cambie su signo a negativo.
    punto6();*/
    /**7- Realizar una función que reciba dos números enteros por parámetro por referencia y cargue sus valores el
    usuario dentro de la función.
    punto7();*/
    return 0;
}


//punto 7
void punto7() {
    int num1, num2;
    cargaDeValores(&num1, &num2);
    printf("\nValor cargado en num1: %d", num1);
    printf("\nValor cargado en num2: %d\n", num2);
}
void cargaDeValores(int*num1,int*num2) {
    printf("\nnum1: ");
    scanf("%d", &*num1);
    printf("\nnum2: ");
    scanf("%d", &*num2);
}


//punto 6
void punto6() {
    int num;

    printf("Ingrese un numero positivo entero: ");
    scanf("%d", &num);
    printf("\n%d\n", cambioDeSigno(&num));
}
int cambioDeSigno(int*num) {
    return *num * (-1);
}


//punto 5
void punto5() {
    float n, m;
    printf("Primer termino: ");
    scanf("%f", &n);
    printf("Segundo termino: ");
    scanf("%f", &m);
    opciones(n, m);
}
void menu() {
    printf("\n\n1- Sumar");
    printf("\n2- Restar");
    printf("\n3- Multiplicar");
    printf("\n4- Dividir");
    printf("\n5- SALIR");
}
void opciones(float n, float m) {
    int opcion;
    menu();
    printf("\nIngrese un numero: ");
    scanf("%d", &opcion);
    switch (opcion) {
    case 1:
        printf("%.2f", suma(n,m));
        return opciones(n, m);
    case 2:
        printf("%.2f",resta(n,m));
        return opciones(n, m);
    case 3:
        printf("%.2f",multiplicacion(n,m));
        return opciones(n, m);
    case 4:
        printf("%.2f",division(n,m));
        return opciones(n, m);
    case 5:
        printf("Saliendo del programa\n");
        break;
    default:
        printf("Ingrese un numero correcto");
        return opciones(n, m);
    }

}
float suma(float n, float m) {
    return n + m;
}
float resta(float n, float m) {
    return n - m;
}
float multiplicacion(float n, float m) {
    return n * m;
}
float division(float n, float m) {
    return n / m;
}


//punto 4
void punto4() {
    int n;
    printf("Ingrese un numero entero: ");
    scanf("%d", &n);
    tablaMultiplicar(n);
    printf("\n");
}
void tablaMultiplicar(int n) {
    printf("\nTabla de %d", n);
    for(int i=1; i<=10; i++) {
        printf("\n|%d * %d = %d|", n, i, n*i);
    }
}


//punto 3
void punto3() {
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);

    printf("\nSumatoria final: %d\n", sumatoriaMenores(n));
}
int sumatoriaMenores(int n) {
    int acum = 0, limite = n;

    for (int i = 0; i <= limite; i++) {
        acum = acum + n;
        n--;
    }
    return acum;
}


//punto 2
void punto2() {
    int n1,n2,n3;

    printf("Numero 1: ");
    scanf("%d", &n1);
    printf("\nNumero 2: ");
    scanf("%d", &n2);
    printf("\nNumero 3: ");
    scanf("%d", &n3);

    mayorYMenor(n1,n2,n3);

}
void mayorYMenor(int n1, int n2, int n3) {
    int mayor = n1;
    int menor = n1;

    if (n2 > mayor) {
        mayor = n2;
    }
    if (n2 < menor) {
        menor = n2;
    }
    if (n3 > mayor) {
        mayor = n3;
    }
    if (n3 < menor) {
        menor = n3;
    }

    printf("\nMayor: %d", mayor);
    printf("\nMenor: %d", menor);
}


//punto 1
void punto1() {
    printf("%d\n", rando());
}
int rando() {
    return rand()%101;
}

