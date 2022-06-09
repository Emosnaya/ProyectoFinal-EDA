#include <stdio.h>
#include <stdlib.h>
#include "Cola.h"
#include "Pila.h"
#include <string.h>

/**
 * @brief Realizado el 24/05/2022
 * 
 * Osnaya Martinez Emmanuel
 * Palacios Barcelos Juan Antonio
 * Romero Molina David
 * Vigi Garduño Marco Alejandro
 * 
 */

//Prototipo de funciones
int prioridad_infija(char);
void balanceo_simbolos(Pila*, char []);
int prioridad_pila(char);

int main()
{
	//Declarar variables
	int  tamano=0;
	char cadena[100],x;
	Cola *c;
	Pila *p;

	p = pila_vacia();
	c = crear_cola();

	printf("Ingrese la expresion infija: ");
	fgets(cadena,100, stdin);
	tamano = strlen(cadena);
	
	for (int i = 0; i < tamano; i++)
	{
		if ((cadena[i]>=49&&cadena[i]<=57) || (cadena[i]>=97&&cadena[i]<=122))
		{
			encolar(c,cadena[i]);
		}else if(cadena[i]== '+' || cadena[i]== '-' || cadena[i] == '*' || cadena[i]=='/' || cadena[i]== '(' || cadena[i] == '^'){
			if (p->log == 0)
			{
				push(p,cadena[i]);
			}
			else{
				if (prioridad_infija(cadena[i]) > prioridad_pila(p->fondo->operador))
				{
					push(p, cadena[i]);
				}else {
					if(prioridad_infija(cadena[i]) == prioridad_pila(p->fondo->operador)){
						x =pop(p);
						encolar(c, x);
						push(p, cadena[i]);
					}else{
						x= pop(p);
						encolar(c,x);
					}
				}
			}
		}

		if (cadena[i] == ')'){
			while (p->fondo->operador != '(' && p != NULL)
			{
				x = pop(p);
				encolar(c,x);
			}
			if (p->fondo->operador == '(')
			{
				x=pop(p);
			}
			
			
		}
	}

	while (p->log != 0)
	{
		x=pop(p);
		encolar(c, x);
	}

	printf("Su notacion postfija es: ");imprimir_cola(c);
	printf("\n");


	return (0);
}


int prioridad_infija(char c){
	switch (c)
	{
	case '+':
		return 1;
		break;
	case '-':
		return 1;
	case '(':
		return 5;
	case '^':
		return 4;
	case '/':
		return 2;
	case '*':
		return 2;
	default:
		break;
	}
	return -1;
	
}

void balanceo_simbolos(Pila*p2, char cadena[]){
	Pila *aux;
	int i = 0;

	while (cadena[i] != '\0')
	{
		if (cadena[i] == '(' || cadena[i]== '[' || cadena[i] == '{')
		{
			push(p2, cadena[i]);
		}else if (cadena[i] == ')' || cadena[i]== ']' || cadena[i] == '}')
		{
			aux = p2;
			if (aux != NULL)
			{
				if (cadena[i]== ')')
				{
					if ( aux->fondo->operador == '(')
					{
						pop(p2);
					}
				} else if (cadena[i]==']')
				{
					if (aux->fondo->operador == '[')
					{
						pop(p2);
					}
				}else if (cadena[i]== '}')
				{
					if (aux->fondo->operador == '{')
					{
						pop(p2);
					}
				}
			} else {
				push(p2, cadena[i]);
			}
		}
		i++;
	}
	if(p2==NULL){
		printf("BALANCEO CORRECTO");
	}
	
}

int prioridad_pila(char c){

	switch (c)
	{
	case '^':
		return 3;
		break;
	case '*':
		return 2;
		break;
	case '/':
		return 2;
		break;
	case '+':
		return 1;
		break;
	case '-':
		return 1;
		break;
	case '(':
		return 0;
		break;
	default:
		break;
	}
	return -1;
}