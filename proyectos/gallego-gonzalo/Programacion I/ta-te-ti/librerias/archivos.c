#include <stdio.h>
#include "archivos.h"
#include "Jugador.h"

void cargarArchivo(char name[]){
    FILE *file = fopen(name, "rb");
    if(file){
        stJugador aux;
        while(fread(&aux, sizeof(stJugador), 1, file) > 0){
            mostrarJugador(aux);
        }
        fclose(file);
    } else { printf("ERROR al cargar archivo %s", name); }
}

void cargarArchivoArr(stJugador data[], int *i){
    FILE *file = fopen(DATAJ, "rb");
    if(file){
        stJugador aux;
        while(fread(&aux, sizeof(stJugador), 1, file) > 0){
            data[*i] = aux; (*i)++;
        }
        fclose(file);
    } else { printf("ERROR al cargar archivo %s", DATAJ); }
}

void guardarJugador(stJugador data){
    FILE *file = fopen(DATAJ, "ab");
    if(file){
        fwrite(&data, sizeof(stJugador), 1, file);
        fclose(file);
    }else{ printf("ERROR al guardar jugador\n"); }
}

int cantEntidades(FILE *file, size_t tam){
    int max = 0, size = 0;
    if(file){
        fseek(file, 0, SEEK_END);
        max = ftell(file);
        rewind(file);
    } else { printf("ERROR en cantEtidades\n"); }

    size = max/tam;

    return size;
}
