#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void trocar(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapifyUp(FilaPrioridade *fp, int indice) {
    int pai = (indice - 1) / 2;
    while (indice > 0 && fp->elementos[indice].prioridade < fp->elementos[pai].prioridade) {
        trocar(&fp->elementos[indice], &fp->elementos[pai]);
        indice = pai;
        pai = (indice - 1) / 2;
    }
}

void minHeapifyDown(FilaPrioridade *fp, int indice) {
    int menor = indice;
    int esquerda = 2 * indice + 1;
    int direita = 2 * indice + 2;

    if (esquerda < fp->tamanho && fp->elementos[esquerda].prioridade < fp->elementos[menor].prioridade) {
        menor = esquerda;
    }
    if (direita < fp->tamanho && fp->elementos[direita].prioridade < fp->elementos[menor].prioridade) {
        menor = direita;
    }

    if (menor != indice) {
        trocar(&fp->elementos[indice], &fp->elementos[menor]);
        minHeapifyDown(fp, menor);
    }
}

FilaPrioridade* criarFilaPrioridade(int capacidade) {
    FilaPrioridade *fp = (FilaPrioridade*) malloc(sizeof(FilaPrioridade));
    if (fp == NULL) {
        perror("Erro ao alocar FilaPrioridade");
        return NULL;
    }
    fp->elementos = (Item*) malloc(sizeof(Item) * capacidade);
    if (fp->elementos == NULL) {
        perror("Erro ao alocar elementos da FilaPrioridade");
        free(fp);
        return NULL;
    }
    fp->capacidade = capacidade;
    fp->tamanho = 0;
    return fp;
}

void destruirFilaPrioridade(FilaPrioridade *fp) {
    if (fp != NULL) {
        free(fp->elementos);
        free(fp);
    }
}

void inserirFilaPrioridade(FilaPrioridade *fp, int prioridade, int valor) {
    if (fp == NULL || estaCheiaFilaPrioridade(fp)) {
        printf("Erro: Fila de prioridade cheia ou nao inicializada.\n");
        return;
    }

    Item novoItem = {prioridade, valor};
    fp->elementos[fp->tamanho] = novoItem;
    fp->tamanho++;
    minHeapifyUp(fp, fp->tamanho - 1);
    printf("Item (prioridade: %d, valor: %d) inserido com sucesso.\n", prioridade, valor);
}

Item* verInicioFilaPrioridade(FilaPrioridade *fp) {
    if (fp == NULL || estaVaziaFilaPrioridade(fp)) {
        printf("Erro: Fila de prioridade vazia ou nao inicializada.\n");
        return NULL;
    }
    return &fp->elementos[0];
}

Item* removerFilaPrioridade(FilaPrioridade *fp) {
    if (fp == NULL || estaVaziaFilaPrioridade(fp)) {
        printf("Erro: Fila de prioridade vazia ou nao inicializada.\n");
        return NULL;
    }

    Item *removido = (Item*) malloc(sizeof(Item));
    if (removido == NULL) {
        perror("Erro ao alocar item removido");
        return NULL;
    }

    *removido = fp->elementos[0];
    fp->elementos[0] = fp->elementos[fp->tamanho - 1];
    fp->tamanho--;
    minHeapifyDown(fp, 0);

    printf("Item (prioridade: %d, valor: %d) removido com sucesso.\n", removido->prioridade, removido->valor);
    return removido;
}

void imprimirFilaPrioridade(FilaPrioridade *fp) {
    if (fp == NULL || estaVaziaFilaPrioridade(fp)) {
        printf("A fila de prioridade esta vazia ou nao inicializada.\n");
        return;
    }
    printf("Elementos da Fila de Prioridade (Heap): \n");
    for (int i = 0; i < fp->tamanho; i++) {
        printf("  [P: %d, V: %d] ", fp->elementos[i].prioridade, fp->elementos[i].valor);
    }
    printf("\n");
}

int obterTamanhoFilaPrioridade(FilaPrioridade *fp) {
    if (fp == NULL) {
        return 0;
    }
    return fp->tamanho;
}

int estaVaziaFilaPrioridade(FilaPrioridade *fp) {
    return fp->tamanho == 0;
}

int estaCheiaFilaPrioridade(FilaPrioridade *fp) {
    return fp->tamanho == fp->capacidade;
}

void exibirMenu() {
    printf("\n--- MENU FILA DE PRIORIDADES (HEAP DE MINIMO) ---\n");
    printf("1 - Criar Fila\n");
    printf("2 - Inserir um item pela prioridade\n");
    printf("3 - Ver o inicio da Fila\n");
    printf("4 - Remover um item\n");
    printf("5 - Imprimir a Fila\n");
    printf("6 - Mostrar o tamanho da Fila\n");
    printf("7 - Destruir a Fila\n");
    printf("8 - Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    FilaPrioridade *minHeap = NULL; 
    int opcao;
    int prioridade, valor, capacidade;
    Item *itemTemp;
    do {
        exibirMenu();
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Por favor, digite um numero.\n");
            while (getchar() != '\n');
            continue; 
        }

        switch (opcao) {
            case 1:
                if (minHeap != NULL) {
                    printf("Uma fila ja existe. Destrua-a primeiro para criar uma nova.\n");
                    break;
                }
                printf("Digite a capacidade da fila: ");
                if (scanf("%d", &capacidade) != 1 || capacidade <= 0) {
                    printf("Capacidade invalida");
                    break;
                }
                minHeap = criarFilaPrioridade(capacidade);
                if (minHeap != NULL) {
                    printf("Fila de prioridade criada com capacidade %d.\n", capacidade);
                } else {
                    printf("Falha ao criar a fila de prioridade.\n");
                }
                break;
            case 2:
                if (minHeap == NULL) {
                    printf("Por favor, crie a fila de prioridade primeiro (Opcao 1).\n");
                    break;
                }
                printf("Digite a prioridade do item (menor valor = maior prioridade): ");
                if (scanf("%d", &prioridade) != 1) {
                    printf("Prioridade invalida. Digite um numero inteiro.\n");
                    while (getchar() != '\n');
                    break;
                }
                printf("Digite o valor do item: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Valor invalido. Digite um numero inteiro.\n");
                    while (getchar() != '\n');
                    break;
                }
                inserirFilaPrioridade(minHeap, prioridade, valor);
                break;
            case 3:
                if (minHeap == NULL) {
                    printf("Por favor, crie a fila de prioridade primeiro (Opcao 1).\n");
                    break;
                }
                itemTemp = verInicioFilaPrioridade(minHeap);
                if (itemTemp != NULL) {
                    printf("Inicio da Fila (Menor Prioridade): Prioridade = %d, Valor = %d\n", itemTemp->prioridade, itemTemp->valor);
                }
                break;
            case 4:
                if (minHeap == NULL) {
                    printf("Por favor, crie a fila de prioridade primeiro (Opcao 1).\n");
                    break;
                }
                itemTemp = removerFilaPrioridade(minHeap);
                if (itemTemp != NULL) {
                    free(itemTemp);
                }
                break;
            case 5:
                if (minHeap == NULL) {
                    printf("Por favor, crie a fila de prioridade primeiro (Opcao 1).\n");
                    break;
                }
                imprimirFilaPrioridade(minHeap);
                break;
            case 6:
                if (minHeap == NULL) {
                    printf("Por favor, crie a fila de prioridade primeiro (Opcao 1).\n");
                    break;
                }
                printf("Tamanho da Fila: %d\n", obterTamanhoFilaPrioridade(minHeap));
                break;
            case 7:
                if (minHeap != NULL) {
                    destruirFilaPrioridade(minHeap);
                    minHeap = NULL; 
                    printf("Fila de prioridade destruida.\n");
                } else {
                    printf("Nenhuma fila de prioridade para destruir.\n");
                }
                break;
            case 8:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
        if (opcao != 8) {
            while (getchar() != '\n');
        }

    } while (opcao != 8);

   
    if (minHeap != NULL) {
        destruirFilaPrioridade(minHeap);
    }

    return 0;
}

void unirFilasPrioridade(FilaPrioridade *F1, FilaPrioridade *F2) {
    if (F1 == NULL || F2 == NULL) {
        printf("Erro: Uma das filas de prioridade nao foi inicializada.\n");
        return;
    }

    printf("Iniciando uniao das filas de prioridade...\n");

    while (!estaVaziaFilaPrioridade(F2)) {
        Item *itemParaMover = removerFilaPrioridade(F2); 
        if (itemParaMover != NULL) {
            
            if (!estaCheiaFilaPrioridade(F1)) {
                inserirFilaPrioridade(F1, itemParaMover->prioridade, itemParaMover->valor);
            } else {
                printf("Aviso: F1 esta cheia, nao foi possivel inserir todos os itens de F2.\n");
               
            }
            free(itemParaMover);
        }
    }
}