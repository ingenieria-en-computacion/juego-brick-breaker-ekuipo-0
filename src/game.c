#include "game.h"
#include "paddle.h"
#include "ball.h"
#include "brick.h"
#include "render.h"
#include "input.h"
#include "score.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define WIDTH 80
#define HEIGHT 24
#define LIVES 3
#define FRAME_DELAY_MS 30  // Reducir delay para mayor responsividad

static int game_over = 0;
static int lives = LIVES;
static int remaining_bricks = BRICK_ROWS * BRICK_COLS;

// Funciones auxiliares para espera
#ifdef _WIN32
static void wait_milliseconds(int ms) {
    Sleep(ms);
}
#else
static void wait_milliseconds(int ms) {
    usleep(ms * 1000);
}
#endif

void game_init() {
    // Inicializar componentes
    paddle_init();
    ball_init();
    bricks_init();
    
    // Inicializar puntaje
    lives = LIVES;
    remaining_bricks = BRICK_ROWS * BRICK_COLS;
    game_over = 0;
    
    srand(time(NULL));
    
    // Mensaje inicial
    printf("Controles: A (izquierda), D (derecha), Q (salir)\n");
    printf("Presiona cualquier tecla para continuar...\n");
    getchar();
}

void game_loop_step() {
    // 1. Leer entrada MÚLTIPLES veces 
    int direction = 0;
    for (int i = 0; i < 3; i++) {  // Leer entrada 
        int current_direction = input_update();
        if (current_direction != 0) {
            direction = current_direction;
        }
        if (i < 2) {  // Pequeña pausa entre lecturas
            wait_milliseconds(5);
        }
    }
    
    // Si presionó Q para salir
    if (direction == 99) {
        game_over = 1;
        printf("\nJuego terminado por el usuario.\n");
        return;
    }
    
    // 2. Actualizar paddle 
    paddle_update(direction);
    
    // 3. Actualizar pelota
    Ball* ball = ball_get();
    Paddle* paddle = paddle_get();
    Brick (*bricks)[BRICK_COLS] = bricks_get();
    
    // Actualizar posición de la pelota
    ball_update();
    
    // 4. Detectar colisión con paddle (más sensible)
    if (ball->y >= HEIGHT - 3 && ball->y <= HEIGHT - 1) {
        int paddle_start = paddle->x - paddle->width/2;
        int paddle_end = paddle->x + paddle->width/2;
        
        if (ball->x >= paddle_start && ball->x <= paddle_end) {
            ball->dy = -1;  // Rebote hacia arriba
            
            // Efecto de rebote lateral según donde golpee
            int hit_pos = ball->x - paddle_start;
            int paddle_size = paddle->width;
            float relative_pos = (float)hit_pos / paddle_size;
            
            if (relative_pos < 0.3) {
                ball->dx = -1;
            } else if (relative_pos > 0.7) {
                ball->dx = 1;
            } else if (relative_pos < 0.5) {
                ball->dx = 0;
            }
            
            // Asegurar que la pelota no quede atrapada en el paddle
            ball->y = HEIGHT - 3;
        }
    }
    
    // 5. Detectar colisión con ladrillos
    int brick_row = ball->y;
    int brick_col = ball->x / 2;
    
    if (brick_row >= 0 && brick_row < BRICK_ROWS && 
        brick_col >= 0 && brick_col < BRICK_COLS) {
        if (bricks[brick_row][brick_col].active) {
            brick_destroy(brick_row, brick_col);
            ball->dy = -ball->dy;
            score_add(100);
            remaining_bricks--;
            
            if (remaining_bricks == 0) {
                game_over = 1;
                printf("\n¡Felicidades! ¡Has ganado!\n");
                return;
            }
        }
    }
    
    // 6. Verificar si la pelota cayó
    if (ball->y >= HEIGHT) {
        lives--;
        if (lives > 0) {
            printf("\n¡Pelota perdida! Vidas restantes: %d\n", lives);
            printf("Presiona Enter para continuar...");
            getchar();  // Esperar confirmación del usuario
            
            ball_init();
            paddle_init();
        } else {
            game_over = 1;
            printf("\n¡Game Over! Sin vidas restantes.\n");
            return;
        }
    }
    
    // 7. Renderizar frame
    render_frame();
    
    // 8. Delay más corto para mejor responsividad
    wait_milliseconds(FRAME_DELAY_MS);
}

int game_is_over() {
    return game_over;
}
