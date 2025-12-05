#include "brick.h"

static Brick bricks[BRICK_ROWS][BRICK_COLS];

void bricks_init() {
    for (int i = 0; i < BRICK_ROWS; i++) {
        for (int j = 0; j < BRICK_COLS; j++) {
            bricks[i][j].active = 1;  // Todos los ladrillos activos inicialmente
        }
    }
}

Brick (*bricks_get())[BRICK_COLS] {
    return bricks;
}

void brick_destroy(int row, int col) {
    if (row >= 0 && row < BRICK_ROWS && col >= 0 && col < BRICK_COLS) {
        bricks[row][col].active = 0;  // Marcar como destruido
    }
}
