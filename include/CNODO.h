#ifndef __CNODO_H__
#define __CNODO_H__
#include <stdbool.h>
/**
 * @brief Realizado el 17/05/2022
 * Osnaya Martinez Emmanuel
 * Palacios Barcelos Juan Antonio
 * Romero Molina David
 * Vigi Garduño Marco Alejandro
 * 
 */

typedef struct CNODO
{
    char elemento;
    struct CNODO *sig;
} CNODO;


CNODO *crear_nodo(char);
CNODO *borrar_nodo(CNODO*);
bool actualizar_nodo(CNODO*, char);

#endif


