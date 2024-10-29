#include <stdio.h>
#include <stdlib.h>

typedef struct Casilla {
    char pieza;
    struct Casilla *arriba, *abajo, *izquierda, *derecha;
} Casilla;

typedef struct Movimiento {
    int fila;
    int columna;
    char pieza;
    struct Movimiento* siguiente; // Apuntador al siguiente movimiento para la estructura de pila
} Movimiento;

// Función para crear una nueva casilla
Casilla* crearCasilla(char pieza) {
    Casilla* nueva = (Casilla*)malloc(sizeof(Casilla));
    nueva->pieza = pieza;
    nueva->arriba = nueva->abajo = nueva->izquierda = nueva->derecha = NULL;
    return nueva;
}

// Función para crear un tablero de ajedrez
Casilla*** crearTablero() {
    Casilla*** tablero = (Casilla***)malloc(8 * sizeof(Casilla**));
    for (int i = 0; i < 8; i++) {
        tablero[i] = (Casilla**)malloc(8 * sizeof(Casilla*));
        for (int j = 0; j < 8; j++) {
            tablero[i][j] = crearCasilla('.');
        }
    }
    return tablero;
}

// Conectar las casillas del tablero
void conectarTablero(Casilla*** tablero) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (i > 0) tablero[i][j]->arriba = tablero[i-1][j];
            if (i < 7) tablero[i][j]->abajo = tablero[i+1][j];
            if (j > 0) tablero[i][j]->izquierda = tablero[i][j-1];
            if (j < 7) tablero[i][j]->derecha = tablero[i][j+1];
        }
    }    
}

// Leer el tablero y detectar la posición de la pieza protagonista
void cargarTablero(Casilla*** tablero, char* piezaProtagonista, int* filaProtagonista, int* columnaProtagonista) {
    FILE* archivo = fopen("/Users/jorgeelvira/Desktop/Archivos de Entrada/T1.txt", "r");
    if (archivo == NULL) {
        printf("No se puede abrir el archivo en la ruta especificada.\n");
        return;
    }

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fscanf(archivo, " %c", &(tablero[i][j]->pieza));
        }
    }

    char coordCol;
    int coordFil;
    fscanf(archivo, " %c%d", &coordCol, &coordFil);
    *filaProtagonista = 8 - coordFil;
    *columnaProtagonista = coordCol - 'A';
    *piezaProtagonista = tablero[*filaProtagonista][*columnaProtagonista]->pieza;

    fclose(archivo);
}

// Función para crear un nuevo nodo de movimiento
Movimiento* crearMovimiento(int fila, int columna, char pieza) {
    Movimiento* nuevoMovimiento = (Movimiento*)malloc(sizeof(Movimiento));
    nuevoMovimiento->fila = fila;
    nuevoMovimiento->columna = columna;
    nuevoMovimiento->pieza = pieza;
    nuevoMovimiento->siguiente = NULL;
    return nuevoMovimiento;
}

// Función para agregar un movimiento a la pila (push)
void push(Movimiento** tope, int fila, int columna, char pieza) {
    Movimiento* nuevoMovimiento = crearMovimiento(fila, columna, pieza);
    nuevoMovimiento->siguiente = *tope;
    *tope = nuevoMovimiento;
}

// Función para mostrar y vaciar la pila de movimientos
void mostrarMovimientos(Movimiento* tope) {
    printf("Movimientos válidos:\n");
    while (tope != NULL) {
        printf("Movimiento a: Fila: %d, Columna: %d -> Pieza: %c\n",
               tope->fila, tope->columna, tope->pieza);
        Movimiento* temp = tope;
        tope = tope->siguiente;
        free(temp); // Liberar cada nodo después de imprimir
    }
}

void imprimirTablero(Casilla*** tablero) {
    printf("Tablero:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", tablero[i][j]->pieza);
        }
        printf("\n");
    }
}

// Función para buscar movimientos válidos de la Torre y almacenarlos en la pila
void movimientosValidos(Casilla* torre, int filaInicial, int columnaInicial, Movimiento** pilaMovimientos) {
    Casilla* temp = torre;
    int fila = filaInicial, columna = columnaInicial;

    // Arriba
    while (temp->arriba != NULL) {
        temp = temp->arriba;
        fila--;
        if (temp->pieza != '.') break;
        push(pilaMovimientos, fila, columna, temp->pieza);
    }

    // Abajo
    temp = torre;
    fila = filaInicial;
    while (temp->abajo != NULL) {
        temp = temp->abajo;
        fila++;
        if (temp->pieza != '.') break;
        push(pilaMovimientos, fila, columna, temp->pieza);
    }

    // Izquierda
    temp = torre;
    columna = columnaInicial;
    while (temp->izquierda != NULL) {
        temp = temp->izquierda;
        columna--;
        if (temp->pieza != '.') break;
        push(pilaMovimientos, filaInicial, columna, temp->pieza);
    }

    // Derecha
    temp = torre;
    columna = columnaInicial;
    while (temp->derecha != NULL) {
        temp = temp->derecha;
        columna++;
        if (temp->pieza != '.') break;
        push(pilaMovimientos, filaInicial, columna, temp->pieza);
    }
}

void liberarTablero(Casilla*** tablero) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            free(tablero[i][j]);
        }
        free(tablero[i]);
    }
    free(tablero);
}

int main() {
    Casilla*** tablero = crearTablero();
    conectarTablero(tablero);

    char piezaProtagonista;
    int filaProtagonista, columnaProtagonista;
    
    cargarTablero(tablero, &piezaProtagonista, &filaProtagonista, &columnaProtagonista);

    if (tablero[filaProtagonista][columnaProtagonista] != NULL) {
        Movimiento* pilaMovimientos = NULL; // Inicializa la pila de movimientos
        movimientosValidos(tablero[filaProtagonista][columnaProtagonista], filaProtagonista, columnaProtagonista, &pilaMovimientos);

        // Mostrar y vaciar la pila de movimientos
        mostrarMovimientos(pilaMovimientos);
    } else {
        printf("Error: La casilla protagonista es NULL.\n");
    }

    liberarTablero(tablero);
    return 0;
}
