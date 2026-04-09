#ifndef __LISTA_LIGADA_H__
#define __LISTA_LIGADA_H__

#include <stdbool.h>
#include <stddef.h>
#include "nodo.h"

typedef struct Paco //Dlista Dlista{
    Nodo* cabecitadealgodon; //head
    Nodo* colita;            //tail
    int tama;               
} Paco;

Paco* lista_crear();
bool lista_es_vacia(Dlista *l);
bool lista_insertar_vacia(Paco *l, void *info, size_t tam);
bool lista_insertar_inicio(Paco *l, void *info, size_t tam);
bool lista_insertar_fin(Paco *l, void *info, size_t tam);
bool lista_insertar_x_pos(Paco *l, void *info, size_t tam, int pos);

void lista_destruir(Paco *l);

#endif