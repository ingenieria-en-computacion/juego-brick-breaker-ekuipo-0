#include "menu.h"
#include <stdio.h>

// TODO: El estudiante debe completar el menú
void menu_show() {
    // Limpiar pantalla
    printf("\033[2J\033[H");

    printf("\n======== BRICK BREAKER ========\n");
    printf("1) Jugar\n");    
    printf("2) Instrucciones\n");
    printf("3) Salir\n");
    printf("=================================\n");
    printf("Seleccione una opcion (1-3): ");
}

int menu_get_option() {
    int opt;
    // Lee la opción ingresada y devuelve su valor, o -1 si es inválida.
    char buffer[100];
    
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        if (sscanf(buffer, "%d", &opt) == 1) {
            return opt;
        }
    }
    
    return -1;  // Opción inválida
}

