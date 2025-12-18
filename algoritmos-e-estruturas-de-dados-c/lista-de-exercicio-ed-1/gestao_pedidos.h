#ifndef PEDIDO_H
#define PEDIDO_H

#define MAX_ITENS 100
#define MAX_NOME 100
#define MAX_ENDERECO 200
#define MAX_STATUS 50

typedef struct {
    char nome[MAX_NOME];
    float preco;
    int quantidade;
} Item;

typedef struct {
    Item itens[MAX_ITENS];
    int numItens;
    char endereco[MAX_ENDERECO];
    float total;
    char status[MAX_STATUS];
} Pedido;

void inicializarPedido(Pedido *p);
void adicionarItem(Pedido *p, Item item);
void removerItem(Pedido *p, const char *nome);
void calcularTotal(Pedido *p);
void definirEndereco(Pedido *p, const char *endereco);
void alterarStatus(Pedido *p, const char *novoStatus);
void finalizarPedido(Pedido *p);

#endif

