#ifndef __NODO_H__
#define __NODO_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

typedef struct Nodo {
    void *info;            
    struct Nodo *elqsigue;  
    struct Nodo *elqiba;    
} Noditobonito;

Noditobonito *nodo_crear(void *info, size_t size);
void nodo_eliminar(Noditobonito *nodo);
bool nodo_actualizar(Noditobonito *nodo, void *info, size_t size);

#endif