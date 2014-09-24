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
    if ( nuevo != NULL ) {   
        nuevo->siguiente=NULL;
        return nuevo;
    }
}

void verLista(t_elemento **lista) {
    printf("Lista:\t");
    t_elemento *elemento=*lista;
    while (elemento != NULL) {
        printf("%d  ",elemento->valor);
        elemento=elemento->siguiente; }
    printf("\n");
}

//recibe un puntero a la lista y un elemento y lo agrega al principio!
void agregarElemento(t_elemento **lista, t_elemento *nuevo) {
    //d printf("Agregando el elemento de valor %d a la lista\n",nuevo->valor);
    nuevo->siguiente=*lista;
    *lista=nuevo;
}

//recibe la pos de un elemento a borrar en una lista
void borrarElemento(t_elemento **lista, int pos) {
    if (*lista != NULL) {
        t_elemento *elemento=*lista;

        if ( pos == 0 ) //caso especial: borrar el primer elemento. tengo que modificar *lista
        {   *lista=elemento->siguiente;
            free(elemento); }
        else {
            /* busco la pos anterior al elemento a borrar*/
            unsigned int i;
            for ( i=0; i != pos-1; i++ )
            { elemento=elemento->siguiente; /* printf("%d...",i); */ }

            //hago la magia de listas
            t_elemento *aborrar=elemento->siguiente;
            elemento->siguiente=aborrar->siguiente;
            free(aborrar);
        }
    }
}

//recibe un puntero a la lista y la ordena borrando y agregando elementos
void SelectionSortA(struct t_elemento **lista1) {
    t_elemento *lista2=NULL;
    
    while (*lista1 != NULL) {   
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
void SelectionSortB(struct t_elemento **lista1) {
    t_elemento *lista2=NULL;
    while (*lista1 != NULL) {   
        t_elemento *elemento=*lista1;
        int maximo = elemento->valor;
        int pos = 0, pos_max = 0;

        do {
            if ( elemento->valor > maximo ) {
                maximo=elemento->valor;
                pos_max=pos; }
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

        if ( pos == 0 ) //caso especial: borrar el primer elemento. tengo que modificar *lista
        {   *listaOrigen=elemento->siguiente;
            agregarElemento(listaDestino,elemento); }
        else
        {   /* busco la pos anterior al elemento a borrar*/
            unsigned int i;
            for ( i=0; i != pos-1; i++ )
            { elemento=elemento->siguiente; /* printf("%d...",i); */ }

            //hago la magia de listas
            t_elemento *asaltear=elemento->siguiente; //lo salteo o desenlazo de la listaOrigen
            elemento->siguiente=asaltear->siguiente;
            agregarElemento(listaDestino,asaltear); //no lo borro, lo agrego a la listaDestino
        }
    }
}
