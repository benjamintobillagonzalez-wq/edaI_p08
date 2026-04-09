#include <stdlib.h>
#include "lista_ligada.h"

Paco* lista_crear() {
    Paco* nueva_lista = (Paco*)malloc(sizeof(Paco));
    if (nueva_lista != NULL) {
        nueva_lista->cabecitadealgodon = NULL;
        nueva_lista->colita = NULL;
    }
    return nueva_lista;
}

bool lista_insertar_vacia(Paco *l, void *info, size_t tam) {
    if (l == NULL || l->cabecitadealgodon != NULL) return false;

    Noditobonito* nuevo = nodo_crear(info, tam);
    if (nuevo == NULL) return false;

    l->cabecitadealgodon = nuevo;
    l->colita = nuevo;
    nuevo->elqsigue = NULL;
    nuevo->elqiba = NULL;
    
    return true;
}

bool lista_insertar_inicio(Paco *l, void *info, size_t tam) {
    if (l == NULL) return false;
    if (l->cabecitadealgodon == NULL) return lista_insertar_vacia(l, info, tam);

    Noditobonito* nuevo = nodo_crear(info, tam);
    if (nuevo == NULL) return false;

    nuevo->elqsigue = l->cabecitadealgodon;
    nuevo->elqiba = NULL;
    
    l->cabecitadealgodon->elqiba = nuevo;
    l->cabecitadealgodon = nuevo;
    
    return true;
}

bool lista_insertar_fin(Paco *l, void *info, size_t tam) {
    if (l == NULL) return false;
    if (l->colita == NULL) return lista_insertar_vacia(l, info, tam);

    Noditobonito* nuevo = nodo_crear(info, tam);
    if (nuevo == NULL) return false;

    nuevo->elqiba = l->colita;
    nuevo->elqsigue = NULL;
    
    l->colita->elqsigue = nuevo;
    l->colita = nuevo;
    
    return true;
}

bool lista_insertar_x_pos(Paco *l, void *info, size_t tam, int pos) {
    if (l == NULL || pos < 0) return false;
    
    if (pos == 0) return lista_insertar_inicio(l, info, tam);

    Noditobonito* tmp = l->cabecitadealgodon;
    int i = 0;

    while (tmp != NULL && i < pos) {
        tmp = tmp->elqsigue;
        i++;
    }

    if (tmp == NULL) {
        if (i == pos) return lista_insertar_fin(l, info, tam);
        return false; 
    }

    Noditobonito* nuevo = nodo_crear(info, tam);
    if (nuevo == NULL) return false;

    nuevo->elqsigue = tmp;
    nuevo->elqiba = tmp->elqiba;
    
    if (tmp->elqiba != NULL) {
        tmp->elqiba->elqsigue = nuevo;
    }
    tmp->elqiba = nuevo;

    return true;
}