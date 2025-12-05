#include "ball.h"
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24

static Ball ball;

void ball_init() {
    // Posicionar la pelota al centro
    ball.x = WIDTH / 2;
    ball.y = HEIGHT / 2;
    
    // Dar velocidad inicial (aleatoria)
    ball.dx = (rand() % 2) ? 1 : -1;
    ball.dy = -1;  // Hacia arriba
}

void ball_update() {
    // Mover la pelota
    ball.x += ball.dx;
    ball.y += ball.dy;
    
    // Rebote en paredes laterales
    if (ball.x <= 0) {
        ball.x = 0;
        ball.dx = 1;
    } else if (ball.x >= WIDTH - 1) {
        ball.x = WIDTH - 1;
        ball.dx = -1;
    }
    
    // Rebote en techo
    if (ball.y <= 0) {
        ball.y = 0;
        ball.dy = 1;
    }
}

Ball* ball_get() {
    return &ball;
}
