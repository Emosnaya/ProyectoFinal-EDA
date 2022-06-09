#ifndef __NODO_H__
#define __NODO_H__


typedef struct Nodo
{
    char palabra;
    struct Nodo *sig;
} Nodo;

Nodo* crear_nodo_lista(char);




#endif