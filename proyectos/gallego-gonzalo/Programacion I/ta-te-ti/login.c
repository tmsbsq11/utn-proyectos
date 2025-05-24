#include <string.h>
#include <stdio.h>
#include <conio.h>
#include "login.h"
#include "Jugador.h"
#include "archivos.h"

void login(){
    stJugador data[50];
    int vData = 0;
    cargarArchivoArr(data, &vData);
    stJugador aux = dataLogin();

    int login = buscarJugadorLogin(data, vData, aux);

    if(login == 0){ printf("LOGEADO..\n"); }
    else{ printf("ERROR en los datos ingresados..\n"); }
}


int buscarJugadorLogin(stJugador data[], int vData, stJugador aux){
    int res = -1, flag = 0, i = 0;
    while(i<vData && !flag){
            if(strcmp(aux.email, data[i].email) == 0){
                res = validarPassword(data[i], aux.contra);
                flag = 1;
            }
            i++;
        }
    return res;
}

int validarPassword(stJugador data, char pass[]){
    return strcmp(data.contra, pass);
}

stJugador dataLogin(){
    stJugador aux;
    fflush(stdin);
    printf("email? -> \n");
    gets(aux.email);
    fflush(stdin);
    printf("password? -> \n");
    ocultarPassw(aux.contra, sizeof(aux.contra));

    return aux;
}

void ocultarPassw(char *pass, int tmax){
    int i = 0;
    char c;
    while ((c = getch()) != '\r' && i < tmax - 1){   //Si lo introducido es diferente que "enter" y menor a 40 caracteres
        if(c == '\b'){  //si borras vuelve hacia atras una posicion y "simula" un borrado con \b \b
            i--;
            printf("\b \b");
        } else {    // si no borraste implanta en caracter en el string y printea un *..
            pass[i] = c;
            i++;
            printf("*");
        }
    }
    pass[i] = '\0'; //agrega el simbolo de finalizacion del string
    printf("\n");
}
