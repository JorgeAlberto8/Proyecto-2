#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tablero{
    char dato;
    struct tablero *up;
    struct tablero *down;
    struct tablero *der;
    struct tablero *izq;
} tablero;


tablero *a1, *a2, *a3, *a4, *a5, *a6, *a7, *a8;
tablero *b1, *b2, *b3, *b4, *b5, *b6, *b7, *b8;
tablero *c1, *c2, *c3, *c4, *c5, *c6, *c7, *c8;
tablero *d1, *d2, *d3, *d4, *d5, *d6, *d7, *d8;
tablero *e1, *e2, *e3, *e4, *e5, *e6, *e7, *e8;
tablero *f1, *f2, *f3, *f4, *f5, *f6, *f7, *f8;
tablero *g1, *g2, *g3, *g4, *g5, *g6, *g7, *g8;
tablero *h1, *h2, *h3, *h4, *h5, *h6, *h7, *h8;
tablero **heada1, **heada2, **heada3, **heada4, **heada5, **heada6, **heada7, **heada8;

void memoria_dinamica(){
    a1 = (tablero*)malloc(sizeof(tablero));
    a2 = (tablero*)malloc(sizeof(tablero));
    a3 = (tablero*)malloc(sizeof(tablero));
    a4 = (tablero*)malloc(sizeof(tablero));
    a5 = (tablero*)malloc(sizeof(tablero));
    a6 = (tablero*)malloc(sizeof(tablero));
    a7 = (tablero*)malloc(sizeof(tablero));
    a8 = (tablero*)malloc(sizeof(tablero));

    b1 = (tablero*)malloc(sizeof(tablero));
    b2 = (tablero*)malloc(sizeof(tablero));
    b3 = (tablero*)malloc(sizeof(tablero));
    b4 = (tablero*)malloc(sizeof(tablero));
    b5 = (tablero*)malloc(sizeof(tablero));
    b6 = (tablero*)malloc(sizeof(tablero));
    b7 = (tablero*)malloc(sizeof(tablero));
    b8 = (tablero*)malloc(sizeof(tablero));

    c1 = (tablero*)malloc(sizeof(tablero));
    c2 = (tablero*)malloc(sizeof(tablero));
    c3 = (tablero*)malloc(sizeof(tablero));
    c4 = (tablero*)malloc(sizeof(tablero));
    c5 = (tablero*)malloc(sizeof(tablero));
    c6 = (tablero*)malloc(sizeof(tablero));
    c7 = (tablero*)malloc(sizeof(tablero));
    c8 = (tablero*)malloc(sizeof(tablero));

    d1 = (tablero*)malloc(sizeof(tablero));
    d2 = (tablero*)malloc(sizeof(tablero));
    d3 = (tablero*)malloc(sizeof(tablero));
    d4 = (tablero*)malloc(sizeof(tablero));
    d5 = (tablero*)malloc(sizeof(tablero));
    d6 = (tablero*)malloc(sizeof(tablero));
    d7 = (tablero*)malloc(sizeof(tablero));
    d8 = (tablero*)malloc(sizeof(tablero));

    e1 = (tablero*)malloc(sizeof(tablero));
    e2 = (tablero*)malloc(sizeof(tablero));
    e3 = (tablero*)malloc(sizeof(tablero));
    e4 = (tablero*)malloc(sizeof(tablero));
    e5 = (tablero*)malloc(sizeof(tablero));
    e6 = (tablero*)malloc(sizeof(tablero));
    e7 = (tablero*)malloc(sizeof(tablero));
    e8 = (tablero*)malloc(sizeof(tablero));

    f1 = (tablero*)malloc(sizeof(tablero));
    f2 = (tablero*)malloc(sizeof(tablero));
    f3 = (tablero*)malloc(sizeof(tablero));
    f4 = (tablero*)malloc(sizeof(tablero));
    f5 = (tablero*)malloc(sizeof(tablero));
    f6 = (tablero*)malloc(sizeof(tablero));
    f7 = (tablero*)malloc(sizeof(tablero));
    f8 = (tablero*)malloc(sizeof(tablero));

    g1 = (tablero*)malloc(sizeof(tablero));
    g2 = (tablero*)malloc(sizeof(tablero));
    g3 = (tablero*)malloc(sizeof(tablero));
    g4 = (tablero*)malloc(sizeof(tablero));
    g5 = (tablero*)malloc(sizeof(tablero));
    g6 = (tablero*)malloc(sizeof(tablero));
    g7 = (tablero*)malloc(sizeof(tablero));
    g8 = (tablero*)malloc(sizeof(tablero));

    h1 = (tablero*)malloc(sizeof(tablero));
    h2 = (tablero*)malloc(sizeof(tablero));
    h3 = (tablero*)malloc(sizeof(tablero));
    h4 = (tablero*)malloc(sizeof(tablero));
    h5 = (tablero*)malloc(sizeof(tablero));
    h6 = (tablero*)malloc(sizeof(tablero));
    h7 = (tablero*)malloc(sizeof(tablero));
    h8 = (tablero*)malloc(sizeof(tablero));
}

void creacion_tablero(){
    a1->dato = '.'; a1->izq = NULL; a1->down = NULL; a1->up = a2; a1->der = b1;
    a2->dato = '.'; a2->izq = NULL; a2->down = a1; a2->up = a3; a2->der = b2;
    a3->dato = '.'; a3->izq = NULL; a3->down = a2; a3->up = a4; a3->der = b3;
    a4->dato = '.'; a4->izq = NULL; a4->down = a3; a4->up = a5; a4->der = b4;
    a5->dato = '.'; a5->izq = NULL; a5->down = a4; a5->up = a6; a5->der = b5;
    a6->dato = '.'; a6->izq = NULL; a6->down = a5; a6->up = a7; a6->der = b6;
    a7->dato = '.'; a7->izq = NULL; a7->down = a6; a7->up = a8; a7->der = b7;
    a8->dato = '.'; a8->izq = NULL; a8->down = a7; a8->up = NULL; a8->der = b8;
    
    b1->dato = '.'; b1->izq = a1; b1->down = NULL;b1->up = b2; b1->der = c1;
    b2->dato = '.'; b2->izq = a2; b2->down = b1; b2->up = b3; b2->der = c2;
    b3->dato = '.'; b3->izq = a3; b3->down = b2; b3->up = b4; b3->der = c3;
    b4->dato = '.'; b4->izq = a4; b4->down = b3; b4->up = b5; b4->der = c4;
    b5->dato = '.'; b5->izq = a5; b5->down = b4; b5->up = b6; b5->der = c5;
    b6->dato = '.'; b6->izq = a6; b6->down = b5; b6->up = b7; b6->der = c6;
    b7->dato = '.'; b7->izq = a7; b7->down = b6; b7->up = b8; b7->der = c7;
    b8->dato = '.'; b8->izq = a8; b8->down = b7; b8->up = NULL;b8->der = c8;

    c1->dato = '.'; c1->izq = b1; c1->down = NULL; c1->up = c2; c1->der = d1;
    c2->dato = '.'; c2->izq = b2; c2->down = c1;  c2->up = c3; c2->der = d2;
    c3->dato = '.'; c3->izq = b3; c3->down = c2;  c3->up = c4; c3->der = d3;
    c4->dato = '.'; c4->izq = b4; c4->down = c3;  c4->up = c5; c4->der = d4;
    c5->dato = '.'; c5->izq = b5; c5->down = c4;  c5->up = c6; c5->der = d5;
    c6->dato = '.'; c6->izq = b6; c6->down = c5;  c6->up = c7; c6->der = d6;
    c7->dato = '.'; c7->izq = b7; c7->down = c6;  c7->up = c8; c7->der = d7;
    c8->dato = '.'; c8->izq = b8; c8->down = c7;  c8->up = NULL;c8->der = d8;

    d1->dato = '.'; d1->izq = c1; d1->down = NULL; d1->up =d2; d1->der = e1;
    d2->dato = '.'; d2->izq = c2; d2->down = d1;  d2->up = d3; d2->der = e2;
    d3->dato = '.'; d3->izq = c3; d3->down = d2;  d3->up = d4; d3->der = e3;
    d4->dato = '.'; d4->izq = c4; d4->down = d3;  d4->up = d5; d4->der = e4;
    d5->dato = '.'; d5->izq = c5; d5->down = d4;  d5->up = d6; d5->der = e5;
    d6->dato = '.'; d6->izq = c6; d6->down = d5;  d6->up = d7; d6->der = e6;
    d7->dato = '.'; d7->izq = c7; d7->down = d6;  d7->up = d8; d7->der = e7;
    d8->dato = '.'; d8->izq = c8; d8->down = d7;  d8->up = NULL;d8->der = e8;

    e1->dato = '.'; e1->izq = d1; e1->down = NULL; e1->up = e2; e1->der = f1;
    e2->dato = '.'; e2->izq = d2; e2->down = e1;  e2->up = e3; e2->der = f2;
    e3->dato = '.'; e3->izq = d3; e3->down = e2;  e3->up = e4; e3->der = f3;
    e4->dato = '.'; e4->izq = d4; e4->down = e3;  e4->up = e5; e4->der = f4;
    e5->dato = '.'; e5->izq = d5; e5->down = e4;  e5->up = e6; e5->der = f5;
    e6->dato = '.'; e6->izq = d6; e6->down = e5;  e6->up = e7; e6->der = f6;
    e7->dato = '.'; e7->izq = d7; e7->down = e6;  e7->up = e8; e7->der = f7;
    e8->dato = '.'; e8->izq = d8; e8->down = e7;  e8->up = NULL; e8->der =f8;

    f1->dato = '.'; f1->izq = e1; f1->down = NULL; f1->up =f2; f1->der = g1;
    f2->dato = '.'; f2->izq = e2; f2->down = f1;  f2->up = f3; f2->der = g2;
    f3->dato = '.'; f3->izq = e3; f3->down = f2;  f3->up = f4; f3->der = g3;
    f4->dato = '.'; f4->izq = e4; f4->down = f3;  f4->up = f5; f4->der = g4;
    f5->dato = '.'; f5->izq = e5; f5->down = f4;  f5->up = f6; f5->der = g5;
    f6->dato = '.'; f6->izq = e6; f6->down = f5;  f6->up = f7; f6->der = g6;
    f7->dato = '.'; f7->izq = e7; f7->down = f6;  f7->up = f8; f7->der = g7;
    f8->dato = '.'; f8->izq = e8; f8->down = f7;  f8->up = NULL;f8->der = g8;

    g1->dato = '.'; g1->izq = f1; g1->down = NULL; g1->up =g2; g1->der = h1;
    g2->dato = '.'; g2->izq = f2; g2->down = g1;  g2->up = g3; g2->der = h2;
    g3->dato = '.'; g3->izq = f3; g3->down = g2;  g3->up = g4; g3->der = h3;
    g4->dato = '.'; g4->izq = f4; g4->down = g3;  g4->up = g5; g4->der = h4;
    g5->dato = '.'; g5->izq = f5; g5->down = g4;  g5->up = g6; g5->der = h5;
    g6->dato = '.'; g6->izq = f6; g6->down = g5;  g6->up = g7; g6->der = h6;
    g7->dato = '.'; g7->izq = f7; g7->down = g6;  g7->up = g8; g7->der = h7;
    g8->dato = '.'; g8->izq = f8; g8->down = g7;  g8->up = NULL; g8->der = h8;
    
    h1->dato = '.'; h1->izq = g1; h1->down = NULL; h1->up =h2; h1->der = NULL;
    h2->dato = '.'; h2->izq = g2; h2->down = h1;  h2->up = h3; h2->der = NULL;
    h3->dato = '.'; h3->izq = g3; h3->down = h2;  h3->up = h4; h3->der = NULL;
    h4->dato = '.'; h4->izq = g4; h4->down = h3;  h4->up = h5; h4->der = NULL;
    h5->dato = '.'; h5->izq = g5; h5->down = h4;  h5->up = h6; h5->der = NULL;
    h6->dato = '.'; h6->izq = g6; h6->down = h5;  h6->up = h7; h6->der = NULL;
    h7->dato = '.'; h7->izq = g7; h7->down = h6;  h7->up = h8; h7->der = NULL;
    h8->dato = '.'; h8->izq = g8; h8->down = h7;  h8->up = NULL; h8->der = NULL;
}

void print_tablero(tablero *a8, tablero *b8, tablero *c8, tablero *d8, 
tablero *e8, tablero *f8, tablero *g8, tablero *h8){
    FILE *fptr;
    char name_file[100];
    printf("Que nombre le pondras a tu archivo? Recuerda poner .txt al final \n");
    fgets(name_file, sizeof(name_file), stdin);
    name_file[strcspn(name_file,"\n")] = 0;
    fptr = fopen(name_file, "w");
    if (fptr != NULL){
        printf("Acceso al archivo\n");
        fprintf(fptr, "\n");
    } else {
        printf("No se abre");
        return;
    }
    
    tablero *tmp1 = a8;
    tablero *tmp2 = b8;
    tablero *tmp3 = c8;
    tablero *tmp4 = d8;
    tablero *tmp5 = e8;
    tablero *tmp6 = f8;
    tablero *tmp7 = g8;
    tablero *tmp8 = h8;
    

    for(int i = 0; i < 8; i++){
        printf("entra %d \n", i+1);
        fprintf(fptr, "%d | %c |", 8-i, tmp1->dato);
        fprintf(fptr, "| %c |", tmp2->dato);
        fprintf(fptr, "| %c |", tmp3->dato);
        fprintf(fptr, "| %c |", tmp4->dato);
        fprintf(fptr, "| %c |", tmp5->dato);
        fprintf(fptr, "| %c |", tmp6->dato);
        fprintf(fptr, "| %c |", tmp7->dato);
        fprintf(fptr, "| %c | \n", tmp8->dato);

        tmp1 = tmp1->down;
        tmp2 = tmp2->down;
        tmp3 = tmp3->down;
        tmp4 = tmp4->down;
        tmp5 = tmp5->down;
        tmp6 = tmp6->down;
        tmp7 = tmp7->down;
        tmp8 = tmp8->down;
    }
    fprintf(fptr, "    a    b    c    d    e    f    g    h\n");
    fclose(fptr);
}
int main(){
    memoria_dinamica();
    creacion_tablero();
    print_tablero(a8, b8, c8, d8, e8, f8, g8, h8);
}