#include<stdio.h>
#include<time.h>
#include "nodos.h"
#include "listas.h"
int main() {
    int k,l,x,y;
    int numerodepedido;
    struct Orden *o;
    struct Lista *listaPendientes, *listaProduccion, *listaHistoricas;
    FILE *fp = fopen("Ordenes.dat","a+");
    if(fp == NULL) {
        printf("error leyendo");
        return -1;
        }
    fseek(fp,0,SEEK_SET);
    x=fread(&numerodepedido, sizeof(int), 1, fp);
    if(x==0)
        numerodepedido=0;
    listaPendientes = crearLista();
    listaProduccion = crearLista();
    listaHistoricas = crearLista();
    if(numerodepedido!=0){
        for(y=0;y<numerodepedido;y++){
            o = crearOrden();
            fread(o, sizeof(*o), 1, fp);
            imprimeOrden(o);
            agregarOrdenFinal(listaHistoricas,o);
            }
        }
        fclose(fp);
    while(1){
        printf("\e[1;1H\e[2J");
        printf(" Levantar una orden(1)\n Ver ordenes pendientes(2)\n Comenzar produccion(3)\n Ver ordenes en produccion(4)\n Terminar produccion(5)\n Buscar una orden en el sistema(6)\n Ver ordenes Terminadas(7)\n Salir(0)\n\n");
        scanf("%d", &k);
        if(k==1){
            o = crearOrden();
            leerOrden(o, numerodepedido);
            numerodepedido++;
            agregarOrdenFinal(listaPendientes,o);
        }
        else if(k==2){
            getchar();
            printf("\e[1;1H\e[2J");
            printf("                ORDENES PENDIENTES\n");
            recorrerLista(listaPendientes);
            printf("Presione cualquier tecla para continuar");
            getchar();
        }
        else if(k==3){
            getchar();
            printf("\e[1;1H\e[2J");
            o = listaPendientes->inicio;
            if(o==NULL){
                printf("No hay ordenes pendientes\n");
                printf("Presione cualquier tecla para continuar");
                getchar();
            }
            else{
                printf("SE COMENZO LA PRODUCCION DE LA SIGUIENTE ORDEN\n");
                imprimeOrden(listaPendientes->inicio);
                borrar(listaPendientes);
                agregarOrdenFinal(listaProduccion,o);
                printf("Presione cualquier tecla para continuar");
                getchar();
            }
        }
        else if(k==4){
            printf("\e[1;1H\e[2J");
            getchar();
            printf("                ORDENES EN PRODUCCION\n");
            recorrerLista(listaProduccion);
            printf("Presione cualquier tecla para continuar");
            getchar();
        }
        else if(k==5){
            getchar();
            printf("\e[1;1H\e[2J");
            if(listaProduccion->inicio==NULL){
                printf("No hay ordenes en produccion\n");
                printf("Presione cualquier tecla para continuar");
                getchar();
            }
            else{
                printf("SE TERIMINO LA PRUDUCCION DE LA SIGUIENTE ORDEN\n");
                imprimeOrden(listaProduccion->inicio);
                o = listaProduccion->inicio;
                borrar(listaProduccion);
                o->horaTermino=time(NULL);
                agregarOrdenFinal(listaHistoricas,o);
                printf("Presione cualquier tecla para continuar");
                getchar();
            }
        }
        else if(k==6){
            getchar();
            printf("\e[1;1H\e[2J");
            printf("Ingrese el numero de la orden que desea buscar\n");
            scanf("%d", &l);
            o = buscar(listaPendientes,l);
            if(o!=NULL){
                printf("La orden:\n");
                imprimeOrden(o);
                printf("aun no comienza su produccion\n");
            }
            else if(o==NULL){
                o = buscar(listaProduccion,l);
                if(o==NULL) {
                    o = buscar(listaHistoricas,l);
                    if(o==NULL)
                        printf("No se encontro una orden con ese numero\n\n");
                    else{
                        printf("La orden:\n");
                        imprimeOrden(o);
                    }
                }
                else{
                    printf("La orden:\n");
                    imprimeOrden(o);
                    printf("Esta en produccion\n");
                }
            }
            printf("Presione cualquier tecla para continuar");
            getchar();
            getchar();
        }
        else if(k==7){
            printf("\e[1;1H\e[2J");
            getchar();
            printf("                ORDENES TERMINADAS\n");
            recorrerLista(listaHistoricas);
            printf("Presione cualquier tecla para continuar");
            getchar();
        }
        else if(k==0){
            fp = fopen("Ordenes.dat","w");
            if(fp == NULL) {
                printf("error abriendo el archivo");
                return -1;
                }
            numerodepedido=recorrerLista(listaHistoricas);
            fwrite(&numerodepedido, sizeof(int), 1, fp);
            fclose(fp);
            break;
        }
        else {
            getchar();
            printf("\e[1;1H\e[2J");
            printf("Esa opcion no existe\n\n");  
            printf("Presione cualquier tecla para continuar");
            getchar();
        }
    }
    printf("\e[1;1H\e[2J");
    GuardarArchivo(listaHistoricas);
    return 0;
}
