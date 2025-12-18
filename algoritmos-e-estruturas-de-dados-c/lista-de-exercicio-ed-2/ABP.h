#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    char valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criar_no(char valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}
