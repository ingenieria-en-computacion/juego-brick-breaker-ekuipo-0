# --------------------------------------------------------
#  Makefile para el proyecto Breakout (versión para estudiantes)
# --------------------------------------------------------

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# ----- Archivos del proyecto principal -----
SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)

# ----- Archivos de test -----
TEST_SRC := $(wildcard test/*.c)
TEST_OBJ := $(TEST_SRC:.c=.o)

# ----- Ejecutables -----
BIN_DIR = bin
BIN = $(BIN_DIR)/game
TEST_BIN = test/run_tests

# --------------------------------------------------------
#  Objetivo por defecto: compilar el juego
# --------------------------------------------------------
all: $(BIN)

# --------------------------------------------------------
#  Compilar el ejecutable principal
# --------------------------------------------------------
$(BIN): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJ) -o $(BIN)

# --------------------------------------------------------
#  Compilar los tests (EXCLUYENDO src/main.o para evitar conflicto)
# --------------------------------------------------------
# Fuentes del juego EXCLUYENDO main.c (para tests)
GAME_SRC_NO_MAIN := $(filter-out src/main.c, $(wildcard src/*.c))
GAME_OBJ_NO_MAIN := $(GAME_SRC_NO_MAIN:.c=.o)

tests: $(TEST_OBJ) $(GAME_OBJ_NO_MAIN)
	$(CC) $(TEST_OBJ) $(GAME_OBJ_NO_MAIN) -o $(TEST_BIN)

# --------------------------------------------------------
#  Limpieza de archivos compilados
# --------------------------------------------------------
clean:
	rm -f src/*.o test/*.o $(BIN) $(TEST_BIN)

# --------------------------------------------------------
#  Limpieza total (incluye el ejecutable de juego)
# --------------------------------------------------------
clean_all: clean
	rm -rf $(BIN_DIR)

.PHONY: all tests clean clean_all
