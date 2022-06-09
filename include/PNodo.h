#ifndef __PNODO_H__
#define __PNODO_H__
#include <stdbool.h>
/**
 * @brief Realizado el 17/05/2022
 * Osnaya Martinez Emmanuel
 * Palacios Barcelos Juan Antonio
 * Romero Molina David
 * Vigi Garduño Marco Alejandro
 * 
 */


typedef struct PNODO
{
    char operador;
    struct PNODO *sig;
    struct PNODO *ant;
} PNODO;

PNODO *crear_nodo_pila(char);
PNODO *borrar_nodo_pila(PNODO*);
bool actualizar_nodo_pila(PNODO*, char);

#endif