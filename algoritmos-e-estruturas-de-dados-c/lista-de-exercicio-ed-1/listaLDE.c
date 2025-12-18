#include <stdio.h>
#include <stdlib.h>
#include "listaLDE.h"

No* inserirFim(No* inicio, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    if (novo == NULL) return inicio;

    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (inicio == NULL) return novo;

    No* atual = inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    atual->prox = novo;
    novo->ant = atual;

    return inicio;
}

void imprimirReverso(No* inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    No* atual = inicio;
    while (atual->prox != NULL) {
        atual = atual->prox;
    }

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->ant;
    }
    printf("\n");
}

void liberarLista(No* inicio) {
    No* atual = inicio;
    while (atual != NULL) {
        No* temp = atual;
        atual = atual->prox;
        free(temp);
    }
}
