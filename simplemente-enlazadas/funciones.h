/*
 * Info I - Ing. Martin Marino
 * TP de la clase 2013/06/17
 * David Vinazza - Curso R1041 (Lunes 14:15, Medrano)
*/

t_persona* nuevaPersona();
void verPersona(t_persona* persona); //imprime los campos del struct persona

t_elemento* nuevoElemento();
void verElemento(t_elemento* elemento); //imprime la pos de memoria del elemento y su struct referido

t_manipulador* nuevoManipulador(); //devuelve un puntero a un nuevo manejador de listas
void verLista(t_manipulador *lista); //itera por la lista mostrando su elemento
void cargarLista(t_manipulador *lista, unsigned int cantidad); //crea [cantidad] nuevos elementos y los agrega al final de la lista
void borrarLista(t_manipulador *lista); //borra elemento por elemento, luego la lista
void agregarElemento(t_manipulador *lista, t_elemento *elemento, int pos); //agrega el elemento a la pos de la lista
void borrarElemento(t_manipulador *lista, int pos); //borra el struct referido y luego el elemento
