#include "CNODO.h"
#include <stdlib.h>
/**
 * @brief Realizado el 17/05/2022
 * Osnaya Martinez Emmanuel
 * Palacios Barcelos Juan Antonio
 * Romero Molina David
 * Vigi Garduño Marco Alejandro
 * 
 */


/**
 * @brief Funcion que crea el nodo para la cola
 * 
 * @param numero recibe un entero
 * @return CNODO* regresa un nodo con el dato
 */

CNODO *crear_nodo(char elemento){
    CNODO *nuevo = (CNODO*)malloc(sizeof(CNODO));
    nuevo->sig = NULL;
    nuevo->elemento = elemento;
    return nuevo;
}

/**
 * @brief Funcion que borra el nodo 
 * 
 * @param n recibe un nodo
 * @return CNODO* retorna un nodo 
 */

CNODO *borrar_nodo(CNODO *n){
    if(n!=NULL){
        if(n->sig == NULL){
            free(n);
            return NULL;
        }
        return n;
    }
    return NULL;
}

/**
 * @brief Funcion que actualiza el nodo
 * 
 * @param n recibe un nodo
 * @param numero recibe un numero
 * @return true si pudo actualizar
 * @return false si no pudo actualizar
 */

bool actualizar_nodo(CNODO *n, char elemento){
    if(n!=NULL){
        n->elemento = elemento;
        return true;
    }
    return false;
}