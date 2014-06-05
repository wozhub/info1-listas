/*
 * Info I - Ing. Martin Marino
 * TP de la clase 2013/06/24
 * David Vinazza - Curso R1041 (Lunes 14:15, Medrano)
 *
*/

#include <stdio.h>      //scanf y printf
#include <stdio.h>      //scanf y printf
#include <malloc.h>     //malloc y free
#include "estructuras.h" //t_elemento
#include "funciones.h" //

#include <time.h>

void prueba( int CANTIDAD );

void main()
{
    prueba(25000);
    prueba(50000);
    prueba(75000);
    prueba(100000);
}

void prueba( int CANTIDAD )
{
    int start, end;
    int dif;

    t_elemento *listaA=NULL;
    t_elemento *listaB=NULL;

    srand (time(NULL));
    unsigned int i,valor;
    printf("Creando la lista de %d elementos...\n",CANTIDAD);
    for (i=0;i<CANTIDAD;i++)
    {
        valor=rand() % 100;
        t_elemento *nuevoA=nuevoElemento();
        t_elemento *nuevoB=nuevoElemento();
        nuevoA->valor=valor;
        nuevoB->valor=valor;
        agregarElemento(&listaA,nuevoA);
        agregarElemento(&listaB,nuevoB);
    }

    printf("Ordenando mediante eliminacion y creacion de elementos...\n");
    start=time(NULL);
    SelectionSortA(&listaA);
    end=time(NULL);
    dif=end-start;
    printf("Listo! Ordenar %d elementos mediante eliminacion y creacion de elementos tomo %d segundos\n",CANTIDAD,dif);

    printf("Ordenando mediante intercambio de punteros...\n");
    start=time(NULL);
    SelectionSortB(&listaB);
    end=time(NULL);
    dif=end-start;
    printf("Listo! Ordenar %d elementos mediante intercambio de punteros tomo %d segundos\n",CANTIDAD,dif);
}
