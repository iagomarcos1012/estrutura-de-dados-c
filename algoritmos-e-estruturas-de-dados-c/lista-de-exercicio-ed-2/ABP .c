#include "ABP.h"
#include <stdio.h>
#include <stdlib.h>

int encontrar_maior(No* raiz) {
    if (raiz == NULL) return '\0';
    No* atual = raiz;
    while (atual->direita != NULL) {
        atual = atual->direita;
    }
    return atual->valor;
}

int encontrar_menor(No* raiz) {
    if (raiz == NULL) return '\0';
    No* atual = raiz;
    while (atual->esquerda != NULL) {
        atual = atual->esquerda;
    }
    return atual->valor;
}
No* inserir(No* raiz, char valor) {
    if (raiz == NULL) return criar_no(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}
No* remover(No* raiz, char valor) {
    if (raiz == NULL) return NULL;

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
       
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No* atual = raiz->direita;
        while (atual->esquerda != NULL) {
            atual = atual->esquerda;
        }
        raiz->valor = atual->valor;
        raiz->direita = remover(raiz->direita, atual->valor);
    }
    return raiz;
}
void caminhar_decrescente(No* raiz) {
    if (raiz != NULL) {
        caminhar_decrescente(raiz->direita);
        printf("%c ", raiz->valor);
        caminhar_decrescente(raiz->esquerda);
    }
}

