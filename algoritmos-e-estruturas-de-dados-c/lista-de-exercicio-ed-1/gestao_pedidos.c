#include <stdio.h>
#include <string.h>
#include "gestao_pedidos.h"

void inicializarPedido(Pedido *p)
{
    p->numItens = 0;
    p->total = 0.0;
    strcpy(p->status, "pendente");
    strcpy(p->endereco, "");
}

void adicionarItem(Pedido *p, Item item)
{
    if (p->numItens < MAX_ITENS)
    {
        p->itens[p->numItens++] = item;
        calcularTotal(p);
    }
}

void removerItem(Pedido *p, const char *nome)
{
    int encontrado = 0;
    for (int i = 0; i < p->numItens; i++)
    {
        if (strcmp(p->itens[i].nome, nome) == 0)
        {
            encontrado = 1;
        }
        if (encontrado && i < p->numItens - 1)
        {
            p->itens[i] = p->itens[i + 1];
        }
    }
    if (encontrado)
    {
        p->numItens--;
        calcularTotal(p);
    }
}

void calcularTotal(Pedido *p)
{
    p->total = 0.0;
    for (int i = 0; i < p->numItens; i++)
    {
        p->total += p->itens[i].preco * p->itens[i].quantidade;
    }
}

void definirEndereco(Pedido *p, const char *endereco)
{
    strncpy(p->endereco, endereco, MAX_ENDERECO - 1);
    p->endereco[MAX_ENDERECO - 1] = '\0';
}

void alterarStatus(Pedido *p, const char *novoStatus)
{
    strncpy(p->status, novoStatus, MAX_STATUS - 1);
    p->status[MAX_STATUS - 1] = '\0';
}

void finalizarPedido(Pedido *p)
{
    printf("\nPedido Finalizado\n");
    printf("Endereço: %s\n", p->endereco);
    printf("Status: %s\n", p->status);
    printf("Itens:\n");
    for (int i = 0; i < p->numItens; i++)
    {
        printf("- %s x%d (R$ %.2f cada)\n", p->itens[i].nome, p->itens[i].quantidade, p->itens[i].preco);
    }
    printf("Total: R$ %.2f\n", p->total);
    
}
int main()
{
    Pedido p;
    inicializarPedido(&p);

    Item i1 = {"Pizza Margherita", 40.00, 1};
    Item i2 = {"Refrigerante", 8.00, 2};

    adicionarItem(&p, i1);
    adicionarItem(&p, i2);

    definirEndereco(&p, "Rua das Flores, 123 - Centro");
    alterarStatus(&p, "preparando");

    removerItem(&p, "Refrigerante");

    adicionarItem(&p, (Item){"Suco Natural", 10.00, 1});
    alterarStatus(&p, "entregue");

    finalizarPedido(&p);

    return 0;
}