#include "Cola.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Funcion que se encarga de crear la cola
 * 
 * @return Cola* una cola
 */

Cola* crear_cola(){
    Cola* c = (Cola*)malloc(sizeof(Cola));
    c->lon = 0;
    c->primero = c->ultimo = NULL;
    return c;
}

/**
 * @brief Funcion que se encarga de agregar datos a la cola
 * 
 * @param c Cola 
 * @param numero Dato por el usuario
 */
void encolar(Cola* c, char elemento){
    if (c->lon == 0)
    {
        CNODO *nuevo = crear_nodo(elemento);
        nuevo->sig = c->primero;
        c->primero = c->ultimo = nuevo;
        c->lon++;
    }else if(c->primero == c->ultimo){
        CNODO *nuevo = crear_nodo(elemento);
        c->primero->sig = nuevo;
        c->ultimo = nuevo;
        c->lon++;
    }else{
        CNODO *nuevo = crear_nodo(elemento);
        c->ultimo->sig = nuevo;
        c->ultimo = nuevo;
        c->lon++;
    }

}
/**
 * @brief Funcion que se encarga de sacar elementos de la Cola
 * 
 * @param c recibe una Cola
 * @return int Regresa el dato que sacó
 */
int desencolar(Cola* c){
    int value=0;

    if (c->lon != 0)
    {
        CNODO *tmp;
        tmp = c->primero;
        value = tmp->elemento;
        c->primero = c->primero->sig;
        free(tmp);
        tmp = NULL;
        c->lon--;
        return value;
    }
    return -1;
}

/**
 * @brief Funcion que imprime la cola
 * 
 * @param c Cola
 */
void imprimir_cola(Cola *c){

    for(CNODO *tmp= c->primero; tmp!=NULL; tmp =tmp->sig){
        printf("%c", tmp->elemento);
    }

}