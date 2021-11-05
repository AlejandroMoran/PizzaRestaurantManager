#include<stdlib.h>
#include<stdio.h>
#include "nodos.h"
#include "listas.h"
#include<time.h>
orden *crearOrden() {
    orden *p;
    p=malloc(sizeof(orden));
    p->sig =NULL;
    return p;
}
void imprimeOrden(orden *p) {
    struct tm * timeinfo;
    struct tm * timeinfo1;
    timeinfo = localtime (&p->hora);
    timeinfo1 = localtime (&p->horaTermino);
    printf("[%d]   ", p->numeroPedido);
    if(p->hora==p->horaTermino)
        printf("%s   %s ",p->nombre, asctime(timeinfo));
    else
        printf("%s   %s      fue termiada el %s ",p->nombre, asctime(timeinfo),asctime(timeinfo1));
    printf("     El pedido contiene %d pizza(s)",p->numeroPizzas);
    printf(" y debe pagar %d pesos\n\n",p->precio);
    
    }
void leerOrden(orden *p, int num){
    printf("\e[1;1H\e[2J");
    getchar();
    printf("Dame el nombre del cliente\n");
    scanf("%s",(p->nombre));
    getchar();
    printf("Cuantas pizzas quiere?\n");
    scanf("%d",&(p->numeroPizzas));
    if(p->numeroPizzas>4) {
        printf("lo siento,solo se pueden ordenar 4 pizzas por cliente si quiere mas debera de hacer otra orden\n");
        p->numeroPizzas=4;
        p->precio=p->numeroPizzas*100;
        printf("El cliente debe de pagar %d\n",(p->precio));
        p->numeroPedido=num;
        p->hora=time(NULL);
        p->horaTermino=time(NULL);
        printf("Presione cualquier tecla para continuar");
        getchar();
        getchar();
    }
    else {
        p->precio=p->numeroPizzas*100;
        printf("El cliente debe de pagar %d\n",(p->precio));
        p->numeroPedido=num;
        p->hora=time(NULL);
        p->horaTermino=time(NULL);
        printf("Presione cualquier tecla para continuar");
        getchar();
        getchar();
        }
    }
void freeOrden(orden *p){
    free(p);
    }
    
