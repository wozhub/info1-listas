/*
 * Info I - Ing. Martin Marino
 * TP de la clase 2013/06/17
 * David Vinazza - Curso R1041 (Lunes 14:15, Medrano)
*/

#include <stdio.h>          //scanf y printf
#include "estructuras.h"    //los structs
#include "funciones.h"      //para manejar la lista, sus elementos y los structs ordenados

int main()
{
    t_manipulador *lista;
    lista = nuevoManipulador();

    if ( lista != NULL )
    { cargarLista(lista,5); }
    verLista(lista);

    borrarElemento(lista,2);
    borrarElemento(lista,-1);
    verLista(lista);

    borrarLista(lista);
};
