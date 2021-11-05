#include <stdlib.h>
#include<stdio.h>
#include "nodos.h"
#include "listas.h"
struct Lista *crearLista() {
    struct Lista *p;
    p = malloc(sizeof(lista));
    p->inicio = p->fin = NULL;
    return p;
    }
void agregarOrdenFinal(lista *unaLista, orden *unaOrden) {
 if(unaLista->inicio==NULL){
    unaLista->inicio = unaLista->fin = unaOrden;
    return;
    }
    unaLista->fin->sig = unaOrden;
    unaLista->fin = unaOrden;
    }
int recorrerLista(lista *unaLista) {
    orden *p;
    int num=0;
    p = unaLista->inicio;
    while(p!=NULL){
        imprimeOrden(p);
        num++;
        p=p->sig;
        }
    return num;
    }
struct Orden *buscar(lista *unaLista, int clave){
    orden *p;
    p = unaLista->inicio;
    while(p!=NULL){
        if(p->numeroPedido==clave)
            return p;
        p=p->sig;
        }
    return NULL;
}
struct Orden *borrar(lista *unaLista){
    orden *p;
    p=unaLista->inicio;
    if(unaLista->inicio == unaLista->fin) {
        unaLista->inicio = unaLista->fin = NULL;
        return p;
    }
    else {
        unaLista->inicio = unaLista->inicio->sig;
        p->sig = NULL;
        return p;
        }
}
void GuardarArchivo(lista *unaLista){
    orden *p;
    p = unaLista->inicio;
    FILE *fp = fopen("Ordenes.dat","a");
    if(fp == NULL) {
        printf("error abriendo el archivo");
        return;
        }
    while(p!=NULL){
        fwrite(p, sizeof(orden), 1, fp);
        freeOrden(p);
        p=p->sig;
        }
    fclose(fp);
}
    
        
