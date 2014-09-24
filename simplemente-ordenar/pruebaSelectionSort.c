/*
 * Info I - Ing. Martin Marino
 * TP de la clase 2013/06/24
 * David Vinazza - Curso R1041 (Lunes 14:15, Medrano)
 *
*/

#include <stdio.h>      //scanf y printf
#include <malloc.h>     //malloc y free
#include "estructuras.h" //t_elemento
#include "funciones.h" //

#define CANTIDAD 20 //numero de elementos en la lista

void main() {
    t_elemento *lista=NULL;

    srand (time(NULL));
    unsigned int i,valor;
    for (i=0;i<CANTIDAD;i++) {
        valor=rand() % 100;
        t_elemento *nuevo=nuevoElemento();
        nuevo->valor=valor;
        agregarElemento(&lista,nuevo);
    }

    printf("Lista Original\n");
    verLista(&lista);
    SelectionSortA(&lista);
    
    printf("Ordenada mediante ordenarListaA\n");
    verLista(&lista);

}
