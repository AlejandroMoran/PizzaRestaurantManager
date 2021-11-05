#include<time.h>
#include "listas.h"
#ifndef NODOS_H_INCLUDED
#define NODOS_H_INCLUDED
struct Orden {
    char nombre[10];
    int numeroPizzas;
    int precio;
    int numeroPedido;
    time_t hora;
    time_t horaTermino;
    struct Orden *sig;
    };   
typedef struct Orden orden;
orden *crearOrden();
void imprimeOrden(orden *p);
void leerOrden(orden *p, int num);
void freeOrden(orden *p);
#endif
