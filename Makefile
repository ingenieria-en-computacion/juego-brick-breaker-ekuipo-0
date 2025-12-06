# --------------------------------------------------------
#  Makefile para el proyecto Breakout (versión para estudiantes)
# --------------------------------------------------------

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# ----- Archivos del proyecto principal -----
SRC := $(wildcard src/*.c)
OBJ := $(SRC:.c=.o)

# ----- Archivos de test -----
TEST_SRC := $(wildcard test/*.c)    # CAMBIO: de 'tests/*.c' a 'test/*.c'
TEST_OBJ := $(TEST_SRC:.c=.o)

# ----- Ejecutables -----
BIN_DIR = bin
BIN = $(BIN_DIR)/game
TEST_BIN = test/run_tests            # CAMBIO: de 'tests/run_tests' a 'test/run_tests'

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
#  Compilar los tests
# --------------------------------------------------------
tests: $(TEST_OBJ) $(OBJ)
	$(CC) $(TEST_OBJ) $(OBJ) -o $(TEST_BIN)

# --------------------------------------------------------
#  Limpieza de archivos compilados
# --------------------------------------------------------
clean:
	rm -f src/*.o test/*.o $(BIN) $(TEST_BIN)  # CAMBIO: de 'tests/*.o' a 'test/*.o'

# --------------------------------------------------------
#  Limpieza total (incluye el ejecutable de juego)
# --------------------------------------------------------
clean_all: clean
	rm -rf $(BIN_DIR)

.PHONY: all tests clean clean_all
