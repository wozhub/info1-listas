/*
 * Info I - Ing. Martin Marino
 * TP de la clase 2013/06/24
 * David Vinazza - Curso R1041 (Lunes 14:15, Medrano)
 *
*/

#include <stdio.h>      //scanf y printf
#include <malloc.h>     //malloc y free
#include "estructuras.h" //t_elemento
#include "funciones.h" //benditos headers

t_elemento* nuevoElemento() {
    t_elemento *nuevo = malloc( sizeof(t_elemento) );
    if ( nuevo != NULL ) {  nuevo->siguiente=NULL;
                            nuevo->anterior=NULL; }
    return nuevo;
}

void verLista(t_elemento **lista) {
    printf("Lista:\t");
    t_elemento *elemento=*lista;
    while (elemento != NULL)
    {   printf("%d  ",elemento->valor);
        elemento=elemento->siguiente; }
    printf("\n");
}

void verListaReverse(t_elemento **lista) {
    printf("Lista:\t");
    t_elemento *elemento=*lista;
    while (elemento->siguiente != NULL) { elemento=elemento->siguiente; }
    while (elemento != NULL) { 
        printf("%d  ",elemento->valor);
        elemento=elemento->anterior; }
    printf("\n");
}

//recibe un puntero a la lista y un elemento y lo agrega al principio!
void agregarElemento(t_elemento **lista, t_elemento *nuevo) {
    //d printf("Agregando el elemento de valor %d a la lista\n",nuevo->valor);
    nuevo->siguiente=*lista;
    if ( *lista != NULL ) { (*lista)->anterior=nuevo;}
    *lista=nuevo;
}

//recibe la pos de un elemento a borrar en una lista
void borrarElemento(t_elemento **lista, int pos) {
    if (*lista != NULL) {
        t_elemento *elemento=*lista;

        if ( pos == 0 ) { //caso especial: borrar el primer elemento. tengo que modificar *lista
            *lista=elemento->siguiente;
            if ( *lista != NULL ) {  (*lista)->anterior=NULL; } //caso especial, la lista queda vacia
            free(elemento); }
        else { /* busco la pos del elemento a borrar*/
            unsigned int i;
            for ( i=0; i != pos; i++ ) { elemento=elemento->siguiente; /* printf("%d...",i); */ }

            //hago la magia de listas
            if (elemento->siguiente != NULL ) { elemento->siguiente->anterior=elemento->anterior; }
            elemento->anterior->siguiente=elemento->siguiente;
            free(elemento);
        }
    }
}

//recibe un puntero a la lista y la ordena borrando y agregando elementos
void SelectionSortA(struct t_elemento **lista1)
{
    t_elemento *lista2=NULL;
    
    while (*lista1 != NULL)
    {   
        t_elemento *elemento=*lista1;
        int maximo = elemento->valor;
        int pos = 0, pos_max=0;

        do
        {   if ( elemento->valor > maximo )
            {   maximo=elemento->valor;
                pos_max=pos; }

            elemento=elemento->siguiente;
            pos++;
        } while ( elemento != NULL );
        //d printf("Maximo=%d\tPos=%d\n",maximo,pos_max);
        
        t_elemento *nuevo=nuevoElemento();
        nuevo->valor=maximo;
        agregarElemento(&lista2,nuevo);

        borrarElemento(lista1,pos_max);
        //d verLista(lista1);
        //d verLista(&lista2);
    }
    *lista1=lista2;
}

//recibe un puntero a la lista y la ordena trasladando elementos a una nueva lista
void SelectionSortB(struct t_elemento **lista1)
{
    t_elemento *lista2=NULL;
    
    while (*lista1 != NULL)
    {   
        t_elemento *elemento=*lista1;
        int maximo = elemento->valor;
        int pos = 0, pos_max = 0;

        do {
            if ( elemento->valor > maximo ) {
                maximo=elemento->valor;
                pos_max=pos;
            }

            elemento=elemento->siguiente;
            pos++;
        } while ( elemento != NULL );
        //d printf("Maximo=%d\tPos=%d\n",maximo,pos_max);
        trasladarElemento(lista1,pos_max,&lista2);
        //d verLista(lista1);
        //d verLista(&lista2);
    }
    *lista1=lista2;
}

//recibe la pos de un elemento a desenlazar de una listaOrigen y agregar en una listaDestino
void trasladarElemento(t_elemento **listaOrigen, int pos, t_elemento **listaDestino) {
    if (*listaOrigen != NULL) { 
        t_elemento *elemento=*listaOrigen;

        if ( pos == 0 ) //caso especial: migrar el primer elemento. tengo que modificar *lista
        {   
            *listaOrigen=elemento->siguiente;
            if (elemento->siguiente != NULL ) { elemento->siguiente->anterior=NULL; }
            agregarElemento(listaDestino,elemento); }
        else
        {   /* busco la pos del elemento a borrar*/
            unsigned int i;
            for ( i=0; i != pos; i++ )
            { elemento=elemento->siguiente; /* printf("%d...",i); */ }

            //hago la magia de listas
            if (elemento->siguiente != NULL ) { elemento->siguiente->anterior=elemento->anterior; }
            elemento->anterior->siguiente=elemento->siguiente;

            agregarElemento(listaDestino,elemento); //no lo borro, lo agrego a la listaDestino
        }
    }
}
