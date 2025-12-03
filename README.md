[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/1Rxr4Cf6)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=21938437&assignment_repo_type=AssignmentRepo)
# 🎮 Proyecto: Brick Breaker en Consola (C)

Este repositorio contiene la plantilla base para el proyecto de programación donde deberás implementar una versión simplificada del juego **Brick Breaker** usando únicamente la consola y la función `printf`.

## 📝 Instrucciones Generales

1. Solo puedes usar:
   - `printf`
   - `scanf`
   - Arreglos, estructuras y funciones básicas de C
   - ANSI colors (opcional)
2. No puedes usar:
   - Bibliotecas gráficas
   - Bibliotecas de posicionamiento de cursor como ncurses u otras
3. La pantalla debe simular un tablero usando solo texto ASCII.

---

## 🚀 Objetivo del Proyecto

Implementar un juego funcional donde:

- La pelota rebota en paredes, plataforma y bloques.
- El jugador controla la plataforma con teclas.
- El juego termina cuando:
  - Se destruyen todos los bloques (ganar)
  - La pelota cae al fondo (perder)

---

## 📂 Estructura del Repositorio

```
/
├── src/
│   └── main.c
│   └── game.c
│   └── ball.c
│   └── brick.c
│   └── paddle.c
│   └── score.c
│   └── render.c
│   └── input.c
├── inclue/
│   └── library_compat.c
│   └── game.c
│   └── ball.c
│   └── brick.c
│   └── paddle.c
│   └── score.c
│   └── render.c
│   └── input.c
├── docs/
│   └── BrickBreaker.pdf (especificaciones del programa)
│   └── ColisionesPelota.psc (Algoritmos para la detección de las colilsiones y movimiento de la pelota)
│
├── tests/
│   ├── test_compile.sh
│   ├── test_files.sh
│   ├── test_menu.sh
│   └── run_tests.sh
│
├── .github/
│   └── workflows/
│       └── autograde.yml
│
└── README.md
```


---

## 🧪 ¿Qué debes entregar?

- Código funcional en `src/main.c`
- Documento de diseño en `docs/`
  - Descripción del problema
  - Análisis del problema
  - Diseño del juego
  - Pseudocódigo
- Captura o video corto donde se vea funcionando (opcional si tu profesor lo pide)

---

## ▶️ ¿Cómo compilar?

Se debe compilar desde la carpeta principal, es decir; en la carpeta superior a src e include

```bash
gcc src/*.c -Iinclude -o juego
./juego
```
---

## 🧱 Caracteres sugeridos

Paredes: #

Plataforma: ====

Pelota: O

Bloque: []


## 👍 Evaluación

La rúbrica completa está en docs/especificacion.pdf.

## 📬 Dudas

En caso de dudas, consulta a tu profesora o revisa nuevamente la especificación.


---

## **📄 docs/especificacion.md**

Entregar un PDF, conviértelo, pero aquí está el contenido:

```markdown
# Especificación del Proyecto: Brick Breaker en Consola

## 1. Descripción del Problema
El estudiante debe implementar una versión del juego Brick Breaker con texto ASCII en consola, usando únicamente `printf`. El jugador controla una plataforma horizontal que rebota una pelota para destruir bloques ubicados en la parte alta de la pantalla.

## 2. Requerimientos
- Menú inicial con:
  - Iniciar juego
  - Instrucciones
  - Salir
- Movimiento automático de la pelota
- Rebotes contra:
  - Paredes
  - Parte superior
  - Plataforma
  - Bloques
- Final del juego:
  - Victoria: todos los bloques destruidos
  - Derrota: pelota cae al fondo
- Uso opcional de colores ANSI
- Código claro y organizado

## 3. Análisis del Problema
Igual al documento que tenemos en el pdf

## 4. Diseño
(… secciones de análisis y diagramas)

## 5. Implementación
- Estructura del bucle principal
- Manejo de entrada del usuario
- Impresión de pantalla
- Lógica de rebote
- Lógica de colisión

```



