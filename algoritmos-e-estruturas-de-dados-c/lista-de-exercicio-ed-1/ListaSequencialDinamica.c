#include <stdio.h>
#include <stdlib.h>
#include "ListaSequencialDinamica.h"

Lista *criaLista()
{
    Lista *li = (Lista *)malloc(sizeof(Lista));
    if (li == NULL)
        return NULL;

    li->dados = (int *)malloc(INCREMENTO * sizeof(int));
    if (li->dados == NULL)
    {
        free(li);
        return NULL;
    }

    li->tamanho = 0;
    li->max = INCREMENTO;
    return li;
}

void destroiLista(Lista *li)
{
    if (li != NULL)
    {
        free(li->dados);
        free(li);
    }
}

int inserirFim(Lista *li, int valor)
{
    if (li == NULL)
        return 0;

    if (li->tamanho == li->max)
    {
        int *novo = (int *)realloc(li->dados, (li->max + INCREMENTO) * sizeof(int));
        if (novo == NULL)
            return 0;

        li->dados = novo;
        li->max += INCREMENTO;
    }

    li->dados[li->tamanho++] = valor;
    return 1;
}

void imprimirLista(Lista *li)
{
    if (li == NULL)
        return;

    printf("Lista (%d/%d): ", li->tamanho, li->max);
    for (int i = 0; i < li->tamanho; i++)
    {
        printf("%d ", li->dados[i]);
    }
    printf("\n");
}
int main()
{
    Lista *li = criaLista();
    if (li == NULL)
    {
        printf("Erro ao criar lista.\n");
        return 1;
    }

    for (int i = 1; i <= 250; i++)
    {
        inserirFim(li, i);
    }

    imprimirLista(li);
    destroiLista(li);
    return 0;
}