#include "paddle.h"

#define WIDTH 80        // Ancho total del área de juego
#define PADDLE_WIDTH 8  // Ancho de la paleta del jugador
#define PADDLE_SPEED 2  // Aumentar velocidad del paddle

static Paddle paddle;

void paddle_init() {
    // TODO: colocar el paddle centrado
    paddle.x = WIDTH / 2;
    paddle.width = PADDLE_WIDTH; 
}

void paddle_update(int direction) {
    // TODO: mover el paddle según la dirección (-1 izquierda, 1 derecha)
    if (direction == 99) {  // Código para salir
        return;
    }
    
    // Mover paddle con mayor velocidad
    paddle.x += (direction * PADDLE_SPEED);
    
    // Limitar movimiento dentro de pantalla
    int half_width = paddle.width / 2;
    if (paddle.x - half_width < 0) {
        paddle.x = half_width;
    }
    if (paddle.x + half_width >= WIDTH) {
        paddle.x = WIDTH - half_width - 1;
    }
}

//Puntero al paddle actual del juego.
Paddle* paddle_get() {
    return &paddle;
}
