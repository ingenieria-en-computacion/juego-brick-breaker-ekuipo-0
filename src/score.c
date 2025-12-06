#include "score.h"
#include <stdio.h>
#include <stdlib.h>


static int score = 0;

void score_init(const char *filename) {
    // Crear archivo si no existe o cargar mejores puntajes
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        int max_score;
        if (fscanf(file, "%d", &max_score) == 1) {
            printf("Puntaje maximo: %d\n", max_score);
        }
        fclose(file);
    }
    
}

// Reiniciar puntaje actual
    score = 0;

void score_add(int points) {
    //Sumar puntos al puntaje actual
    score += points;
}

int score_get() {
    return score;
}

void score_save(const char *filename) {
    // Guardar puntaje final del jugador en el archivo
    FILE *file = fopen(filename, "r+");
    int max_score = 0;
    
    // Leer puntaje máximo existente
    if (file != NULL) {
        fscanf(file, "%d", &max_score);
        fclose(file);
    }
    
    // Actualizar si el puntaje actual es mayor
    if (score > max_score) {
        file = fopen(filename, "w");
        if (file != NULL) {
            fprintf(file, "%d", score);
            fclose(file);
            printf("\n¡Nuevo record! Puntaje: %d\n", score);
        }
    } else {
        printf("\nPuntaje final: %d | Mejor puntaje: %d\n", score, max_score);
    }
}
