#ifndef __COLA_H_
#define __COLA_H_
#include "CNODO.h"

/**
 * @brief Realizado el 18/05/2022
 * Osnaya Martinez Emmanuel
 * Palacios Barcelos Juan Antonio
 * Romero Molina David
 * Vigi Garduño Marco Alejandro
 * 
 */

typedef struct Cola
{
    int lon;
    CNODO* primero;
    CNODO* ultimo;
} Cola;

Cola* crear_cola();
void encolar(Cola*, char);
int desencolar(Cola*);
void imprimir_cola(Cola*);







#endif