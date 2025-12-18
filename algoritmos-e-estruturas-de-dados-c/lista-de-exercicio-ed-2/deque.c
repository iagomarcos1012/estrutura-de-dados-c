#include<stdio.h>
#include<stdlib.h>
#include"deque.h"
#include"dequeS.h"

void imprimirInversoSeq(DequeS* d) {
    for (int i = d->fim - 1; i >= d->inicio; i--) {
        printf("%c ", d->dados[i]);
    }
}
void imprimirInversoDDE(Deque* d) {
    No* atual = d->fim;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->ant;
    }
}
int metadesSaoSimetricas(Deque* d) {
    int tam = tamanhoDeque(d);
    for (int i = 0; i < tam / 2; i++) {
        char ini = acessarPosicao(d, i);
        char fim = acessarPosicao(d, tam - 1 - i);
        if (ini != fim) return 0;
    }
    return 1;
}
