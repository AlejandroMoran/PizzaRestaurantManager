#ifndef LISTAS_H_INCLUDED
#define LISTAS_H_INCLUDED
#include "nodos.h"
struct Lista {
    orden *inicio;
    orden *fin;
    };
typedef struct Lista lista;
struct Lista *crearLista();
void agregarOrdenFinal(lista *unaLista, orden *unaOrden);
int recorrerLista(lista *unaLista);
void GuardarArchivo(lista *unaLista);
struct Orden *buscar(lista *unaLista, int clave);
struct Orden *borrar(lista *unaLista);
#endif 
