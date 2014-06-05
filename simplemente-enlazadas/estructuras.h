/*
 * Info I - Ing. Martin Marino
 * TP de la clase 2013/06/17
 * David Vinazza - Curso R1041 (Lunes 14:15, Medrano)
*/

typedef struct t_persona {
    char nombre[20];
    unsigned int edad;
} t_persona;

typedef struct t_elemento {
    t_persona *persona; //un puntero al struct con datos a ordenar
    struct t_elemento *siguiente;
} t_elemento;

typedef struct t_manipulador {
    t_elemento *primero; //un puntero al primer elemento de la lista
    t_elemento *ultimo; //un puntero al último elemento
    unsigned int cantidad; //un contador de elementos
} t_manipulador;
