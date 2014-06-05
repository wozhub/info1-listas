/*
 * Info I - Ing. Martin Marino
 * TP de la clase 2013/06/24
 * David Vinazza - Curso R1041 (Lunes 14:15, Medrano)
 *
*/

typedef struct t_elemento {
    int valor;
    struct t_elemento *siguiente;
    struct t_elemento *anterior;
} t_elemento;
