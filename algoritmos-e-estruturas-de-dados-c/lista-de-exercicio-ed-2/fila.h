#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

typedef struct {
    int prioridade;
    int valor;
} Item;

typedef struct {
    Item *elementos;
    int capacidade;
    int tamanho;
} FilaPrioridade;

FilaPrioridade* criarFilaPrioridade(int capacidade);
void destruirFilaPrioridade(FilaPrioridade *fp);
void inserirFilaPrioridade(FilaPrioridade *fp, int prioridade, int valor);
Item* verInicioFilaPrioridade(FilaPrioridade *fp);
Item* removerFilaPrioridade(FilaPrioridade *fp);
void imprimirFilaPrioridade(FilaPrioridade *fp);
int obterTamanhoFilaPrioridade(FilaPrioridade *fp);
int estaVaziaFilaPrioridade(FilaPrioridade *fp);
int estaCheiaFilaPrioridade(FilaPrioridade *fp);

#endif