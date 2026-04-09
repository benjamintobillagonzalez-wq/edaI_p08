#include "nodo.h"
#include <string.h> 

Noditobonito *nodo_crear(void *info, size_t tamaño) {
    Noditobonito *nuevo = (Noditobonito *)malloc(sizeof(Noditobonito));
    if (!nuevo) return NULL;

    nuevo->info = malloc(tamaño);
    if (!nuevo->info) {
        free(nuevo);
        return NULL;
    }

    memcpy(nuevo->info, info, tamaño);
    nuevo->elqsigue = NULL;
    nuevo->elqiba = NULL;

    return nuevo;
}

void nodo_eliminar(Noditobonito *nodo) {
    if (nodo == NULL) return;
    if (nodo->info != NULL) free(nodo->info);
    free(nodo);
}

bool nodo_actualizar(Noditobonito *nodo, void *info, size_t tamaño) {
   nodo->info = realloc(nodo->info, tamaño);
   if(!nodo->info, info, tamaño);
   memcpy(nodo->info, info, tamaño);
}