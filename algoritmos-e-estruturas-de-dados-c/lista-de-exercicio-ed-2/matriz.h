#ifndef MATRIZ_SEQUENCIAL_H
#define MATRIZ_SEQUENCIAL_H

typedef struct {
    int linhas;
    int colunas;
    int *dados; 
} Matriz;

Matriz* criarMatriz(int linhas, int colunas);
void destruirMatriz(Matriz *mat);
void preencherMatriz(Matriz *mat);
void imprimirMatriz(Matriz *mat);
int obterElemento(Matriz *mat, int i, int j);
void definirElemento(Matriz *mat, int i, int j, int valor);

Matriz* somarMatrizes(Matriz *mat1, Matriz *mat2);
Matriz* subtrairMatrizes(Matriz *mat1, Matriz *mat2);
Matriz* multiplicarMatrizes(Matriz *mat1, Matriz *mat2);

#endif 