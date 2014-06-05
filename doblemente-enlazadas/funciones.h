/*
 * Info I - Ing. Martin Marino
 * TP de la clase 2013/06/24
 * David Vinazza - Curso R1041 (Lunes 14:15, Medrano)
 *
*/

t_elemento* nuevoElemento();
void verLista(t_elemento **lista);
void agregarElemento(t_elemento **lista, t_elemento *nuevo);

//recibe la pos de un elemento a borrar en una lista
void borrarElemento(t_elemento **lista, int pos);

//recibe un puntero a la lista y la ordena borrando y agregando elementos
void selectionSortA(struct t_elemento **lista1);

//recibe un puntero a la lista y la ordena trasladando elementos a una nueva lista
void selectionSortB(struct t_elemento **lista1);

//recibe la pos de un elemento a desenlazar de una listaOrigen y agregar en una listaDestino
void trasladarElemento(t_elemento **listaOrigen, int pos, t_elemento **listaDestino);
