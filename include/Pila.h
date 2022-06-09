#ifndef __PILA_H__
#define __PILA_H__
#include "PNodo.h"
/**
 * @brief Realizado el 19/05/2022
 * Osnaya Martinez Emmanuel
 * Palacios Barcelos Juan Antonio
 * Romero Molina David
 * Vigi Garduño Marco Alejandro
 * 
 */

typedef struct Pila
{
    PNODO *fondo;
    int log;
}Pila;

Pila* pila_vacia();
void push(Pila*, char);
char pop(Pila*);
void imprimir_pila(Pila *);
void destruir(Pila *);

#endif
