#include "PNodo.h"
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
 * @brief Funcion que crea el nodo
 * 
 * @param operador recibe un caracter
 * @return PNODO* regresa un nodod
 */

PNODO* crear_nodo_pila(char operador){
    PNODO *nuevo = (PNODO*)malloc(sizeof(PNODO));
    nuevo->ant = NULL;
    nuevo->sig = NULL;
    nuevo->operador = operador;
    return nuevo;
}

/**
 * @brief Funcion que borra un nodod
 * 
 * @param n Recibe un nodo
 * @return PNODO* regresa un nodo
 */

PNODO* borrar_nodo_pila(PNODO *n){
    if(n!=NULL){
        if(n->sig == NULL && n->ant == NULL){
            free(n);
            return NULL;
        }
        return n;
    }
    return NULL;
}

/**
 * @brief Funcion que actualiza el nodo de la pila
 * 
 * @param n Nodo de la pila
 * @param operador el dato
 * @return true si pudo actualizar
 * @return false si no pudo actualizar
 */

bool actualizar_nodo_pila(PNODO *n,  char operador){
    if(n!=NULL){
        n->operador = operador;
        return true;
    }
    return false;
}