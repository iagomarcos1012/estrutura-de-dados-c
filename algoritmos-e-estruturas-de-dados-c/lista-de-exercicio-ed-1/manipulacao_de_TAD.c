#include <stdio.h>
#include <stdlib.h>

#define NULL 0
#define MAX 100



// inverter fila estatica


typedef struct {
    int dados[MAX];
    int ini;
    int fim;
} FilaEstatica;

void inverterFilaEstatica(FilaEstatica *f) {
    int i = f->ini;
    int j = (f->fim - 1 + MAX) % MAX;

    while (i != j && (i + 1) % MAX != j) {
        int temp = f->dados[i];
        f->dados[i] = f->dados[j];
        f->dados[j] = temp;

        i = (i + 1) % MAX;
        j = (j - 1 + MAX) % MAX;
    }
}

// inverter fila dinamica

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *ini;
    No *fim;
} FilaDinamica;

void inverterFilaDinamica(FilaDinamica *fila) {
    No *anterior = NULL;
    No *atual = fila->ini;
    No *proximo;

    fila->fim = fila->ini; 

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    fila->ini = anterior;
}

//inverter pilha estatica


typedef struct {
    int dados[MAX];
    int topo; 
} PilhaEstatica;

void inverterPilhaEstatica(PilhaEstatica *p) {
    int i = 0;
    int j = p->topo;

    while (i < j) {
        int temp = p->dados[i];
        p->dados[i] = p->dados[j];
        p->dados[j] = temp;
        i++;
        j--;
    }
}

// inverter pilha dinamica

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *topo;
} PilhaDinamica;

void inverterPilhaDinamica(PilhaDinamica *p) {
    No *anterior = NULL;
    No *atual = p->topo;
    No *proximo;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }

    p->topo = anterior;
}

// concatena fila estatica

#define MAX 100

typedef struct {
    int dados[MAX];
    int ini;
    int fim;
} FilaEstatica;

void concatenarFilaEstatica(FilaEstatica *f1, FilaEstatica *f2) {
    int i = f2->ini;
    while (i < f2->fim) {
        if (f1->fim < MAX) {
            f1->dados[f1->fim++] = f2->dados[i++];
        } else {
            printf("Erro: F1 sem espaço para concatenar.\n");
            break;
        }
    }

    f2->ini = f2->fim = 0;
}

// concatena fila dinamica

typedef struct No {
    int valor;
    struct No *prox;
} No;

typedef struct {
    No *ini;
    No *fim;
} FilaDinamica;

void concatenarFilaDinamica(FilaDinamica *f1, FilaDinamica *f2) {
    if (f2->ini == NULL) return; 

    if (f1->ini == NULL) {
        f1->ini = f2->ini;
        f1->fim = f2->fim;
    } else {
        f1->fim->prox = f2->ini;
        f1->fim = f2->fim;
    }

    f2->ini = NULL;
    f2->fim = NULL;
}