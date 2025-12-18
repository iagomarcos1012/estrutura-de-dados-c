#include <stdio.h>
#include <stdlib.h>
#include "ABPpai.h"

No *criar_no(char valor, No *pai)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = novo->direita = NULL;
    novo->pai = pai;
    return novo;
}

No *inserir(No *raiz, char valor)
{
    if (raiz == NULL)
        return criar_no(valor, NULL);

    if (valor < raiz->valor)
    {
        if (raiz->esquerda == NULL)
        {
            raiz->esquerda = criar_no(valor, raiz);
        }
        else
        {
            inserir(raiz->esquerda, valor);
        }
    }
    else if (valor > raiz->valor)
    {
        if (raiz->direita == NULL)
        {
            raiz->direita = criar_no(valor, raiz);
        }
        else
        {
            inserir(raiz->direita, valor);
        }
    }
    return raiz;
}

No *buscar(No *raiz, char valor)
{
    if (raiz == NULL || raiz->valor == valor)
        return raiz;
    if (valor < raiz->valor)
        return buscar(raiz->esquerda, valor);
    return buscar(raiz->direita, valor);
}

No *encontrar_menor(No *raiz)
{
    while (raiz->esquerda != NULL)
        raiz = raiz->esquerda;
    return raiz;
}

No *remover(No *raiz, char valor)
{
    if (raiz == NULL)
        return NULL;

    if (valor < raiz->valor)
    {
        raiz->esquerda = remover(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = remover(raiz->direita, valor);
    }
    else
    {
        if (raiz->esquerda == NULL || raiz->direita == NULL)
        {
            No *temp = raiz->esquerda ? raiz->esquerda : raiz->direita;
            if (temp != NULL)
                temp->pai = raiz->pai;
            free(raiz);
            return temp;
        }
        else
        {
            No *sucessor = encontrar_menor(raiz->direita);
            raiz->valor = sucessor->valor;
            raiz->direita = remover(raiz->direita, sucessor->valor);
        }
    }
    return raiz;
}

void em_ordem(No *raiz)
{
    if (raiz != NULL)
    {
        em_ordem(raiz->esquerda);
        printf("%c ", raiz->valor);
        em_ordem(raiz->direita);
    }
}

void pre_ordem(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%c ", raiz->valor);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void pos_ordem(No *raiz)
{
    if (raiz != NULL)
    {
        pos_ordem(raiz->esquerda);
        pos_ordem(raiz->direita);
        printf("%c ", raiz->valor);
    }
}

int contar_nos(No *raiz)
{
    if (raiz == NULL)
        return 0;
    return 1 + contar_nos(raiz->esquerda) + contar_nos(raiz->direita);
}

void imprimir_caminho_para_raiz(No *folha)
{
    while (folha != NULL)
    {
        printf("%c ", folha->valor);
        folha = folha->pai;
    }
    printf("\n");
}

void imprimir_caminhos_folha_para_raiz(No *raiz)
{
    if (raiz == NULL)
        return;
    if (raiz->esquerda == NULL && raiz->direita == NULL)
    {
        imprimir_caminho_para_raiz(raiz);
    }
    imprimir_caminhos_folha_para_raiz(raiz->esquerda);
    imprimir_caminhos_folha_para_raiz(raiz->direita);
}

void destruir_abp(No *raiz)
{
    if (raiz != NULL)
    {
        destruir_abp(raiz->esquerda);
        destruir_abp(raiz->direita);
        free(raiz);
    }
}
int main()
{
    No *raiz = NULL;
    int opcao;
    char valor;

    do
    {
        printf("\nMenu:\n");
        printf("1 - Criar ABP\n");
        printf("2 - Inserir um elemento\n");
        printf("3 - Buscar um elemento\n");
        printf("4 - Remover um elemento\n");
        printf("5 - Imprimir em ordem\n");
        printf("6 - Imprimir em pre-ordem\n");
        printf("7 - Imprimir em pos-ordem\n");
        printf("8 - Mostrar quantidade de nos\n");
        printf("9 - Mostrar caminhos de folhas ate a raiz\n");
        printf("10 - Destruir ABP\n");
        printf("11 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            raiz = NULL;
            printf("ABP criada.\n");
            break;
        case 2:
            printf("Digite o valor a ser inserido: ");
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
            break;
        case 3:
            printf("Digite o valor a ser buscado: ");
            scanf(" %c", &valor);
            if (buscar(raiz, valor))
                printf("Valor encontrado.\n");
            else
                printf("Valor nao encontrado.\n");
            break;
        case 4:
            printf("Digite o valor a ser removido: ");
            scanf(" %c", &valor);
            raiz = remover(raiz, valor);
            break;
        case 5:
            printf("Em ordem: ");
            em_ordem(raiz);
            printf("\n");
            break;
        case 6:
            printf("Pre-ordem: ");
            pre_ordem(raiz);
            printf("\n");
            break;
        case 7:
            printf("Pos-ordem: ");
            pos_ordem(raiz);
            printf("\n");
            break;
        case 8:
            printf("Quantidade de nos: %d\n", contar_nos(raiz));
            break;
        case 9:
            printf("Caminhos de folhas ate a raiz:\n");
            imprimir_caminhos_folha_para_raiz(raiz);
            break;
        case 10:
            destruir_abp(raiz);
            raiz = NULL;
            printf("ABP destruida.\n");
            break;
        case 11:
            destruir_abp(raiz);
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
        }

    } while (opcao != 11);

    return 0;
}