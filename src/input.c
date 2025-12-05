#include "input.h"
#include <stdio.h>
#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/time.h>
    #include <sys/types.h>
#endif

// Variable global para mantener el estado de las teclas
static int left_pressed = 0;
static int right_pressed = 0;
static int quit_pressed = 0;

#ifdef _WIN32
int input_update() {
    // En Windows, usar _kbhit para entrada no bloqueante
    while (_kbhit()) {
        char c = _getch();
        if (c == 'a' || c == 'A') {
            left_pressed = 1;
        } else if (c == 'd' || c == 'D') {
            right_pressed = 1;
        } else if (c == 'q' || c == 'Q') {
            quit_pressed = 1;
        }
    }
    
    // Determinar dirección basada en estado de teclas
    if (quit_pressed) {
        quit_pressed = 0;
        return 99;
    }
    if (left_pressed) {
        left_pressed = 0;
        return -1;
    }
    if (right_pressed) {
        right_pressed = 0;
        return 1;
    }
    return 0;
}
#else
// Para Linux/Mac - versión mejorada
static void enable_raw_mode() {
    static struct termios oldt, newt;
    static int initialized = 0;
    
    if (!initialized) {
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        initialized = 1;
    }
}

static void disable_raw_mode() {
    static struct termios oldt;
    static int saved = 0;
    
    if (!saved) {
        tcgetattr(STDIN_FILENO, &oldt);
        saved = 1;
    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

int input_update() {
    enable_raw_mode();
    
    fd_set readfds;
    struct timeval timeout;
    
    // Configurar para lectura no bloqueante
    FD_ZERO(&readfds);
    FD_SET(STDIN_FILENO, &readfds);
    timeout.tv_sec = 0;
    timeout.tv_usec = 0;  // No esperar
    
    // Verificar si hay entrada disponible
    if (select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout) > 0) {
        char c;
        if (read(STDIN_FILENO, &c, 1) > 0) {
            if (c == 'a' || c == 'A') {
                return -1;
            } else if (c == 'd' || c == 'D') {
                return 1;
            } else if (c == 'q' || c == 'Q') {
                return 99;
            }
        }
    }
    
    return 0;
}
#endif
