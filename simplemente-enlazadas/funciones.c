/*
 * Info I - Ing. Martin Marino
 * TP de la clase 2013/06/17
 * David Vinazza - Curso R1041 (Lunes 14:15, Medrano)
*/

#include <stdio.h>      //scanf y printf
#include <malloc.h>     //malloc y free
#include "estructuras.h" //los structs
#include "funciones.h"  //los headers

//FUNCIONES CON PERSONAS

t_persona* nuevaPersona()
{
    t_persona *persona = malloc( sizeof(t_persona) );
    if ( persona != NULL )
    {
        printf("Nombre: ");
        scanf("%s",persona->nombre);
        printf("Edad: ");
        scanf("%d",&persona->edad);
    }
    return persona;
};

void verPersona(t_persona* persona)
{
    printf("Nombre: %s\tEdad: %d\n",persona->nombre,persona->edad);
}

// FUNCIONES CON ELEMENTOS

t_elemento* nuevoElemento()
{
    t_elemento *elemento = malloc( sizeof(t_elemento) );
    if ( (elemento) != NULL )
    {
        elemento->persona=nuevaPersona();
        elemento->siguiente=NULL;
    }
    return elemento;
};

void verElemento(t_elemento* elemento)
{
    printf("pos de memoria: %d\n",elemento);
    verPersona(elemento->persona);
}

void borrarElemento(t_manipulador *lista, int pos)
{
    if ( pos == -1 ) { pos=lista->cantidad-1; } 
    if ( lista->cantidad == 0 || pos >= lista->cantidad  ) { return; } //caso especial: la pos no existe
    else if ( pos == 0 ) //caso especial: borrar el primer elemento. no tiene anterior
    {   
        t_elemento *elemento=lista->primero;
        free(elemento->persona);
        lista->primero=elemento->siguiente;
        free(elemento);
    }
    else
    {   

        /* busco la pos anterior al elemento a borrar*/
        t_elemento *elemento=lista->primero;
        unsigned int i;
        for ( i=0; i != pos-1; i++ )
        { elemento=elemento->siguiente; /* printf("%d...",i); */ }

        //hago la magia de listas
        t_elemento *aborrar=elemento->siguiente;
        free(aborrar->persona);
        elemento->siguiente=aborrar->siguiente;
        free(aborrar);
    }
    printf("\nSe borro el elemento #%d\n",pos);
    lista->cantidad--;
}

//FUNCIONES CON EL MANIPULADOR DE LISTAS

t_manipulador* nuevoManipulador()
{
    t_manipulador *lista = (t_manipulador *) malloc( sizeof(t_manipulador) );
    if ( lista != NULL )
    {
        lista->primero=NULL;
        lista->ultimo=NULL;
        lista->cantidad=0;
    }
    return lista;
};

void verLista(t_manipulador *lista)
{
    printf("\n\n");
    printf("La lista tiene %d elementos\n",lista->cantidad);
    t_elemento *elemento=lista->primero;

    unsigned int i;
    for (i=0; elemento != NULL; i++)
    {
      printf("elemento #%d\n",i);
      verElemento(elemento);
      elemento=elemento->siguiente;  
    } 
}

void borrarLista(t_manipulador *lista)
{
    printf("Borrando LISTA!");

    while (lista->cantidad != 0)
    { borrarElemento(lista,0); }

    free(lista);
}

void cargarLista(t_manipulador *lista, unsigned int cantidad)
{
   unsigned int i;
   for (i=0;i<cantidad;i++)
   {
        t_elemento *elemento=nuevoElemento();
        agregarElemento(lista,elemento,-1); //agrego en la primera pos
   }
}

void agregarElemento(t_manipulador *lista, t_elemento *elemento, int pos)
{
    //d printf("Agregando elemento a la pos %d/%d\n",pos,lista->cantidad);

    if ( pos == 0 || lista->cantidad == 0 )
    {   //d printf("Adelante!\n");
        elemento->siguiente=lista->primero;
        lista->primero=elemento;
    }
    else if ( pos == -1 || pos > lista->cantidad )
    {   //d printf("Al fondo!\n");
        lista->ultimo->siguiente=elemento;
        lista->ultimo=elemento;
    }

    if ( lista->cantidad == 0 ) //si es el primer elemento agregado a la lista
    { lista->ultimo=elemento; } //es tambien el ultimo

    lista->cantidad++; 
}
