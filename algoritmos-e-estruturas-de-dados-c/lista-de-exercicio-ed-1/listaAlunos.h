#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

#define TAM_NOME 100

typedef struct {
    char nome[TAM_NOME];
    int matricula;
    float nota;
} Aluno;

typedef struct No {
    Aluno dados;
    struct No *prox;
} No;

typedef struct {
    No *inicio;
} ListaAlunos;

ListaAlunos* criaLista();
void liberaLista(ListaAlunos *lista);
int insereOrdenado(ListaAlunos *lista, Aluno a);
int removePorMatricula(ListaAlunos *lista, int matricula);
void imprimeLista(ListaAlunos *lista);

#endif
