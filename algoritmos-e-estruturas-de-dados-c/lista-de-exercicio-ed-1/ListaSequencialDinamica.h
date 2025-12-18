#ifndef LISTA_SEQUENCIAL_DINAMICA_H
#define LISTA_SEQUENCIAL_DINAMICA_H

#define INCREMENTO 100

typedef struct
{
    int *dados;
    int tamanho;
    int max;
} Lista;

Lista *criaLista();
void destroiLista(Lista *li);
int inserirFim(Lista *li, int valor);
void imprimirLista(Lista *li);

#endif
