#ifndef ABP_H
#define ABP_H

typedef struct No {
    char valor;
    struct No* esquerda;
    struct No* direita;
    struct No* pai;
} No;

No* criar_no(char valor, No* pai);
No* inserir(No* raiz, char valor);
No* buscar(No* raiz, char valor);
No* remover(No* raiz, char valor);
void em_ordem(No* raiz);
void pre_ordem(No* raiz);
void pos_ordem(No* raiz);
int contar_nos(No* raiz);
void imprimir_caminhos_folha_para_raiz(No* raiz);
void destruir_abp(No* raiz);

#endif