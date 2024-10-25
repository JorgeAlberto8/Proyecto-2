#include <stdio.h>
#include <stdlib.h>

// Estructura de la casilla, se representa la posición en el tablero
typedef struct Casilla {
    char pieza; // tipo de pieza en la casilla
    struct Casilla *arriba;
    struct Casilla *abajo;
    struct Casilla *izquierda;
    struct Casilla *derecha;
} Casilla;

// Crear casilla en memoria dinámica
Casilla* crearCasilla(char pieza) {
    Casilla* nueva = (Casilla*)malloc(sizeof(Casilla)); // Reserva memoria para la casilla
    nueva->pieza = pieza; // asigna pieza
    nueva->arriba = nueva->abajo = nueva->izquierda = nueva->derecha = NULL;
    return nueva; 
}

// Creación del tablero 8x8
Casilla*** crearTablero() {
    Casilla*** tablero = (Casilla***)malloc(8 * sizeof(Casilla**)); // Memoria con 8 filas
    for (int i = 0; i < 8; i++) {
        tablero[i] = (Casilla**)malloc(8 * sizeof(Casilla*)); // Memoria con 8 columnas
        for (int j = 0; j < 8; j++) {
            tablero[i][j] = crearCasilla('.'); // Inicializa cada casilla vacía con '.'
        }
    }
    return tablero; 
}

// Función para conectar las casillas 
void conectarTablero(Casilla*** tablero) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) { // Cambié `i++` a `j++` en el incremento
            if (i > 0) tablero[i][j]->arriba = tablero[i-1][j];
            if (i < 7) tablero[i][j]->abajo = tablero[i+1][j];
            if (j > 0) tablero[i][j]->izquierda = tablero[i][j-1];
            if (j < 7) tablero[i][j]->derecha = tablero[i][j+1];
        }
    }    
}

// Función para leer el archivo y llenar el tablero
void cargarTablero(Casilla*** tablero, const char* ArchivosdeEntrada) {
    FILE *archivo = fopen("/Users/jorgeelvira/Desktop/Archivos de Entrada", "r");
    if (archivo == NULL) {
        printf("No se puede abrir el archivo.\n");
        return;
    }
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fscanf(archivo, " %c", &(tablero[i][j]->pieza)); // Lee y asigna las piezas al tablero
        }
    }
    fclose(archivo);
}
// Función para imprimir el tablero
void imprimirTablero(Casilla*** tablero) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", tablero[i][j]->pieza); // Imprime el tipo de pieza en cada casilla
        }
        printf("\n"); // Nueva línea después de cada fila
    }
}

int main() {
    Casilla*** tablero = crearTablero();
    conectarTablero(tablero);
    cargarTablero(tablero, "T1.txt");
    imprimirTablero(tablero);
    
    // Libera memoria (opcional, pero recomendado para evitar fugas de memoria)
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            free(tablero[i][j]);
        }
        free(tablero[i]);
    }
    free(tablero);
    
    return 0;
}