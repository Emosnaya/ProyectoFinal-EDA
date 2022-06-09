#include "Pila.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Funcion que crea una pila vacia
 * 
 * @return Pila* 
 */

Pila* pila_vacia(){
    Pila* p = (Pila*)malloc(sizeof(Pila));
    p->fondo = NULL;
    p->log = 0;
    return p;
}

/**
 * @brief Funcion que agrega datos a la pila
 * 
 * @param p Pila
 * @param operador Dato dado por el usuario 
 */
void push(Pila* p, char operador){
    PNODO *nuevo = crear_nodo_pila(operador);
    nuevo->sig = p->fondo;
    p->fondo = nuevo;
    p->log++;
}
/**
 * @brief Funcion que imprime la Pila
 * 
 * @param p Recibe una Pila
 */
void imprimir_pila(Pila *p){
    printf("[ ");
    for(PNODO *tmp= p->fondo; tmp != NULL; tmp =tmp->sig){
        printf("%c ", tmp->operador);
    }
    printf("]\n");
}

/**
 * @brief Funcion que se encarga de sacar elementos de la Pila
 * 
 * @param p recibe una pila
 * @return char regresa el dato que sacó de la pila
 */

char pop(Pila *p){
    char returnValue;
    PNODO *aux = p->fondo;
    returnValue = aux->operador;
    p->fondo = p->fondo->sig;
    p->log--;
    free(aux);
    return returnValue;
}

void destruir(Pila *p){
    Pila *aux;

    if(p != NULL){
        while (p != NULL)
        {
            aux = p;
            p = p->fondo->sig;
            free(aux);
        }
        
    }
}
