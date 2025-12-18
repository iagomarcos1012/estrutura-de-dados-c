#ifndef LISTA_LSE_H
#define LISTA_LSE_H

typedef struct No
{
    int valor;
    struct No *prox;
} No;

typedef struct
{
    No *inicio;
} ListaLSE;

ListaLSE *criaLista();
void insereInicio(ListaLSE *lista, int valor);
void imprimeLista(ListaLSE *lista);
void imprimeReversoIterativo(ListaLSE *lista);
void imprimeReversoRecursivo(ListaLSE *lista);
void liberaLista(ListaLSE *lista);

#endif
