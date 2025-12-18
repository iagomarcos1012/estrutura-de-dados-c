#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaAlunos.h"

ListaAlunos *criaLista()
{
    ListaAlunos *lista = (ListaAlunos *)malloc(sizeof(ListaAlunos));
    if (lista != NULL)
        lista->inicio = NULL;
    return lista;
}

void liberaLista(ListaAlunos *lista)
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

int insereOrdenado(ListaAlunos *lista, Aluno a)
{
    if (lista == NULL)
        return 0;

    No *novo = (No *)malloc(sizeof(No));
    if (novo == NULL)
        return 0;

    novo->dados = a;
    novo->prox = NULL;

    if (lista->inicio == NULL || strcmp(a.nome, lista->inicio->dados.nome) < 0)
    {
        novo->prox = lista->inicio;
        lista->inicio = novo;
        return 1;
    }

    No *ant = lista->inicio;
    while (ant->prox != NULL && strcmp(ant->prox->dados.nome, a.nome) < 0)
    {
        ant = ant->prox;
    }

    novo->prox = ant->prox;
    ant->prox = novo;
    return 1;
}

int removePorMatricula(ListaAlunos *lista, int matricula)
{
    if (lista == NULL || lista->inicio == NULL)
        return 0;

    No *ant = NULL;
    No *atual = lista->inicio;

    while (atual != NULL && atual->dados.matricula != matricula)
    {
        ant = atual;
        atual = atual->prox;
    }

    if (atual == NULL)
        return 0;

    if (ant == NULL)
        lista->inicio = atual->prox;
    else
        ant->prox = atual->prox;

    free(atual);
    return 1;
}

void imprimeLista(ListaAlunos *lista)
{
    if (lista == NULL)
        return;

    No *aux = lista->inicio;
    printf("Lista de Alunos:\n");
    while (aux != NULL)
    {
        printf("Nome: %s | Matrícula: %d | Nota: %.2f\n",
               aux->dados.nome,
               aux->dados.matricula,
               aux->dados.nota);
        aux = aux->prox;
    }
}
int main()
{
    ListaAlunos *lista = criaLista();

    Aluno a1 = {"Carlos", 101, 8.5};
    Aluno a2 = {"Ana", 103, 9.0};
    Aluno a3 = {"Beatriz", 102, 7.8};

    insereOrdenado(lista, a1);
    insereOrdenado(lista, a2);
    insereOrdenado(lista, a3);

    imprimeLista(lista);

    printf("\nRemovendo aluno com matrícula 102...\n");
    removePorMatricula(lista, 102);

    imprimeLista(lista);

    liberaLista(lista);
    return 0;
}