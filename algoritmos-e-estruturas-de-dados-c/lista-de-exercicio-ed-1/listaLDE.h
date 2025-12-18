#ifndef LISTA_LDE_H
#define LISTA_LDE_H

typedef struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} No;

No* inserirFim(No* inicio, int valor);
void imprimirReverso(No* inicio);
void liberarLista(No* inicio);

#endif
