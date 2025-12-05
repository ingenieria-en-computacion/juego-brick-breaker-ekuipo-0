#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "score.h"
#include "menu.h"

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

int main() {
    int option;
    
    // Inicializar números aleatorios
    srand(time(NULL));
    
    do {
        // Mostrar menú
        menu_show();
        option = menu_get_option();
        
        switch(option) {
            case 1:  // Jugar
                score_init("scores.txt");
                game_init();
                
                printf("\n¡INICIANDO JUEGO!\n");
                printf("================================\n");
                
                while (!game_is_over()) {
                    game_loop_step();
                }
                
                score_save("scores.txt");
                printf("\nPresiona Enter para volver al menu...");
                clear_input_buffer();
                getchar();
                break;
                
            case 2:  // Instrucciones
                printf("\n=== INSTRUCIONES ===\n");
                printf("Controles EN TIEMPO REAL:\n");
                printf("  A - Mover plataforma a la IZQUIERDA\n");
                printf("  D - Mover plataforma a la DERECHA\n");
                printf("  Q - Salir del juego inmediatamente\n");
                printf("\nNOTA: Manten presionada la tecla para movimiento continuo\n");
                printf("\nPresiona Enter para continuar...");
                clear_input_buffer();
                getchar();
                break;
                
            case 3:  // Salir
                printf("\n¡Gracias por jugar!\n");
                break;
                
            default:
                printf("\nOpcian no valida. Intenta de nuevo.\n");
                printf("Presiona Enter para continuar...");
                clear_input_buffer();
                getchar();
                break;
        }
        
    } while (option != 3);
    
    return 0;
}
