#include "render.h"
#include "ball.h"
#include "paddle.h"
#include "brick.h"
#include <stdio.h>
#include "score.h"
#include <stdlib.h>

#ifdef _WIN32
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#define WIDTH 80
#define HEIGHT 24

void render_frame() {
    // 1. limpiar pantalla
    printf("\033[2J\033[H");

    Ball* ball = ball_get();
    Paddle* paddle = paddle_get();
    Brick (*bricks)[BRICK_COLS] = bricks_get();

    
    // Dibujar el marco superior
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");

     for (int y = 0; y < HEIGHT; y++) {
        printf("#");  // Pared izquierda
        
        for (int x = 0; x < WIDTH; x++) {
            int drawn = 0;
            

    // 2. dibujar ladrillos
    if (y < BRICK_ROWS) {
                int brick_x = x / 2;  
                if (brick_x < BRICK_COLS) {
                    if (bricks[y][brick_x].active) {
                        if (x % 2 == 0) {
                            printf("\033[33m[\033[0m");  // Color amarillo
                        } else {
                            printf("\033[33m]\033[0m");
                        }
                        drawn = 1;
                    }
                }
            }
    // 3. dibujar pelota
     if (!drawn && x == ball->x && y == ball->y) {
                printf("\033[31mO\033[0m");  // Color rojo
                drawn = 1;
            }
    // 4. dibujar paddle
    if (!drawn && y == HEIGHT - 1) {
                int paddle_start = paddle->x - paddle->width/2;
                int paddle_end = paddle->x + paddle->width/2;
                
                if (x >= paddle_start && x <= paddle_end) {
                    if (x == paddle_start) {
                        printf("\033[34m[\033[0m");  // Color azul
                    } else if (x == paddle_end) {
                        printf("\033[34m]\033[0m");
                    } else {
                        printf("\033[34m=\033[0m");
                    }
                    drawn = 1;
                }
            }

     // Espacio vacío
            if (!drawn) {
                printf(" ");
            }
        }
       
          printf("#\n");  // Pared derecha
    }
    
    // Dibujar marco inferior
    for (int i = 0; i < WIDTH + 2; i++) {
        printf("#");
    }
    printf("\n");
    // 5. mostrar puntaje y vidas
     printf("Vidas iniciales: ***  |  Puntaje: %d | Controles: A(izq) D(der) Q(Salir)\n", score_get());
}

