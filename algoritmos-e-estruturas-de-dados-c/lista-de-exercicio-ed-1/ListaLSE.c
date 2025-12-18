#include <stdio.h>
#include <stdlib.h>
#include "ListaLSE.h"

ListaLSE *criaLista()
{
    ListaLSE *lista = (ListaLSE *)malloc(sizeof(ListaLSE));
    if (lista != NULL)
        lista->inicio = NULL;
    return lista;
}

void insereInicio(ListaLSE *lista, int valor)
{
    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return;

    novo->valor = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
}

void imprimeLista(ListaLSE *lista)
{
    No *aux = lista->inicio;
    printf("Lista: ");
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void imprimeReversoIterativo(ListaLSE *lista)
{
    int tamanho = 0;
    No *aux = lista->inicio;

    while (aux != NULL)
    {
        tamanho++;
        aux = aux->prox;
    }

    int *pilha = (int *)malloc(tamanho * sizeof(int));
    if (pilha == NULL)
        return;

    aux = lista->inicio;
    for (int i = 0; i < tamanho; i++)
    {
        pilha[i] = aux->valor;
        aux = aux->prox;
    }

    printf("Reverso (iterativo): ");
    for (int i = tamanho - 1; i >= 0; i--)
    {
        printf("%d ", pilha[i]);
    }
    printf("\n");

    free(pilha);
}

void imprimeReversoRecursivaAux(No *no)
{
    if (no == NULL)
        return;
    imprimeReversoRecursivaAux(no->prox);
    printf("%d ", no->valor);
}

void imprimeReversoRecursivo(ListaLSE *lista)
{
    printf("Reverso (recursivo): ");
    imprimeReversoRecursivaAux(lista->inicio);
    printf("\n");
}

void liberaLista(ListaLSE *lista)
{
    No *aux = lista->inicio;
    while (aux != NULL)
    {
        No *temp = aux;
        aux = aux->prox;
        free(temp);
    }
    free(lista);
}
int main()
{
    ListaLSE *lista = criaLista();

    for (int i = 1; i <= 5; i++)
    {
        insereInicio(lista, i);
    }

    imprimeLista(lista);
    imprimeReversoIterativo(lista);
    imprimeReversoRecursivo(lista);

    liberaLista(lista);
    return 0;
}