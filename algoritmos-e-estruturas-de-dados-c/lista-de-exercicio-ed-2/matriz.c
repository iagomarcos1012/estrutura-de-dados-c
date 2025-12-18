#include "matriz.h"
#include <stdio.h>
#include <stdlib.h> 

Matriz* criarMatriz(int linhas, int colunas) {
    if (linhas <= 0 || colunas <= 0) {
        printf("Erro: Dimensoes da matriz devem ser positivas.\n");
        return NULL;
    }

    Matriz *mat = (Matriz*) malloc(sizeof(Matriz));
    if (mat == NULL) {
        perror("Erro ao alocar Matriz");
        return NULL;
    }

    mat->linhas = linhas;
    mat->colunas = colunas;
    mat->dados = (int*) malloc(sizeof(int) * linhas * colunas);
    if (mat->dados == NULL) {
        perror("Erro ao alocar dados da Matriz");
        free(mat);
        return NULL;
    }

    for (int i = 0; i < linhas * colunas; i++) {
        mat->dados[i] = 0;
    }

    return mat;
}

void destruirMatriz(Matriz *mat) {
    if (mat != NULL) {
        free(mat->dados);
        free(mat);       
    }
}

void preencherMatriz(Matriz *mat) {
    if (mat == NULL || mat->dados == NULL) {
        printf("Erro: Matriz nao inicializada para preenchimento.\n");
        return;
    }
    printf("Preenchendo matriz (%d x %d):\n", mat->linhas, mat->colunas);
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            printf("Digite o elemento [%d][%d]: ", i, j);
            
            if (scanf("%d", &mat->dados[i * mat->colunas + j]) != 1) {
                printf("Entrada invalida. Por favor, digite um numero inteiro.\n");
               
                while (getchar() != '\n');
                j--; 
            }
        }
    }
}

void imprimirMatriz(Matriz *mat) {
    if (mat == NULL || mat->dados == NULL) {
        printf("Matriz vazia ou nao inicializada.\n");
        return;
    }
    printf("\nMatriz (%d x %d):\n", mat->linhas, mat->colunas);
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            printf("%4d ", mat->dados[i * mat->colunas + j]);
        }
        printf("\n");
    }
}

int obterElemento(Matriz *mat, int i, int j) {
    if (mat == NULL || mat->dados == NULL || i < 0 || i >= mat->linhas || j < 0 || j >= mat->colunas) {
        printf("Erro: Acesso invalido a elemento da matriz.\n");
        return -1; 
    }
    return mat->dados[i * mat->colunas + j];
}

void definirElemento(Matriz *mat, int i, int j, int valor) {
    if (mat == NULL || mat->dados == NULL || i < 0 || i >= mat->linhas || j < 0 || j >= mat->colunas) {
        printf("Erro: Acesso invalido a elemento da matriz para definicao.\n");
        return;
    }
    mat->dados[i * mat->colunas + j] = valor;
}

Matriz* somarMatrizes(Matriz *mat1, Matriz *mat2) {
    if (mat1 == NULL || mat2 == NULL || mat1->dados == NULL || mat2->dados == NULL) {
        printf("Erro: Uma ou ambas as matrizes de entrada nao estao inicializadas para a soma.\n");
        return NULL;
    }
    if (mat1->linhas != mat2->linhas || mat1->colunas != mat2->colunas) {
        printf("Erro: As dimensoes das matrizes devem ser iguais para a soma.\n");
        printf("Matriz 1: %dx%d, Matriz 2: %dx%d\n", mat1->linhas, mat1->colunas, mat2->linhas, mat2->colunas);
        return NULL;
    }

    Matriz *resultado = criarMatriz(mat1->linhas, mat1->colunas);
    if (resultado == NULL) {
        printf("Erro: Nao foi possivel criar a matriz resultado da soma.\n");
        return NULL;
    }

    for (int i = 0; i < mat1->linhas * mat1->colunas; i++) {
        resultado->dados[i] = mat1->dados[i] + mat2->dados[i];
    }
    return resultado;
}

Matriz* subtrairMatrizes(Matriz *mat1, Matriz *mat2) {
    if (mat1 == NULL || mat2 == NULL || mat1->dados == NULL || mat2->dados == NULL) {
        printf("Erro: Uma ou ambas as matrizes de entrada nao estao inicializadas para a subtracao.\n");
        return NULL;
    }
    if (mat1->linhas != mat2->linhas || mat1->colunas != mat2->colunas) {
        printf("Erro: As dimensoes das matrizes devem ser iguais para a subtracao.\n");
        printf("Matriz 1: %dx%d, Matriz 2: %dx%d\n", mat1->linhas, mat1->colunas, mat2->linhas, mat2->colunas);
        return NULL;
    }

    Matriz *resultado = criarMatriz(mat1->linhas, mat1->colunas);
    if (resultado == NULL) {
        printf("Erro: Nao foi possivel criar a matriz resultado da subtracao.\n");
        return NULL;
    }

    for (int i = 0; i < mat1->linhas * mat1->colunas; i++) {
        resultado->dados[i] = mat1->dados[i] - mat2->dados[i];
    }
    return resultado;
}

Matriz* multiplicarMatrizes(Matriz *mat1, Matriz *mat2) {
    if (mat1 == NULL || mat2 == NULL || mat1->dados == NULL || mat2->dados == NULL) {
        printf("Erro: Uma ou ambas as matrizes de entrada nao estao inicializadas para a multiplicacao.\n");
        return NULL;
    }

    if (mat1->colunas != mat2->linhas) {
        printf("Erro: As dimensoes das matrizes sao incompativeis para a multiplicacao.\n");
        printf("Colunas da Matriz 1 (%d) devem ser iguais as Linhas da Matriz 2 (%d).\n", mat1->colunas, mat2->linhas);
        return NULL;
    }

    Matriz *resultado = criarMatriz(mat1->linhas, mat2->colunas);
    if (resultado == NULL) {
        printf("Erro: Nao foi possivel criar a matriz resultado da multiplicacao.\n");
        return NULL;
    }

    for (int i = 0; i < mat1->linhas; i++) { 
        for (int j = 0; j < mat2->colunas; j++) { 
            int soma_produto = 0;
            for (int k = 0; k < mat1->colunas; k++) { 
                soma_produto += mat1->dados[i * mat1->colunas + k] * mat2->dados[k * mat2->colunas + j];
            }
            resultado->dados[i * resultado->colunas + j] = soma_produto;
        }
    }
    return resultado;
}

int main() {
    Matriz *matA = NULL;
    Matriz *matB = NULL;
    Matriz *matC = NULL; 

    printf("--- Testando TAD Matriz Sequencial com Operacoes Matematicas ---\n\n");

    printf("1. Criacao e Preenchimento de Matrizes:\n");
    matA = criarMatriz(2, 3);
    if (matA == NULL) {
        printf("Falha ao criar Matriz A.\n");
        return EXIT_FAILURE;
    }
    printf("Preencha a Matriz A (2x3):\n");
    preencherMatriz(matA);
    imprimirMatriz(matA);

    matB = criarMatriz(2, 3);
    if (matB == NULL) {
        printf("Falha ao criar Matriz B.\n");
        destruirMatriz(matA);
        return EXIT_FAILURE;
    }
    printf("\nPreencha a Matriz B (2x3):\n");
    preencherMatriz(matB);
    imprimirMatriz(matB);

    printf("\n--- 2. Teste de Soma de Matrizes (A + B) ---\n");
    matC = somarMatrizes(matA, matB);
    if (matC != NULL) {
        printf("Resultado da Soma (A + B):\n");
        imprimirMatriz(matC);
        destruirMatriz(matC); 
        matC = NULL;
    } else {
        printf("Nao foi possivel realizar a soma. (Verifique as dimensoes)\n");
    }

    printf("\n--- 3. Teste de Subtracao de Matrizes (A - B) ---\n");
    matC = subtrairMatrizes(matA, matB);
    if (matC != NULL) {
        printf("Resultado da Subtracao (A - B):\n");
        imprimirMatriz(matC);
        destruirMatriz(matC); 
        matC = NULL;
    } else {
        printf("Nao foi possivel realizar a subtracao. (Verifique as dimensoes)\n");
    }

    printf("\n--- 4. Teste de Multiplicacao de Matrizes (Compativeis) ---\n");
    Matriz *matD = criarMatriz(3, 2); 
    if (matD == NULL) {
        printf("Falha ao criar Matriz D.\n");
        destruirMatriz(matA);
        destruirMatriz(matB);
        return EXIT_FAILURE;
    }
    printf("\nPreencha a Matriz D (3x2) para multiplicacao:\n");
    preencherMatriz(matD);
    imprimirMatriz(matD);

    printf("\nMatriz A (2x3):\n");
    imprimirMatriz(matA);
    printf("\nMatriz D (3x2):\n");
    imprimirMatriz(matD);

    matC = multiplicarMatrizes(matA, matD); 
    if (matC != NULL) {
        printf("Resultado da Multiplicacao (A * D):\n");
        imprimirMatriz(matC);
        destruirMatriz(matC); 
        matC = NULL;
    } else {
        printf("Nao foi possivel realizar a multiplicacao. (Verifique as dimensoes)\n");
    }
    destruirMatriz(matD);
    matD = NULL;

  
    printf("\n--- 5. Teste de Multiplicacao de Matrizes (Incompativeis) ---\n");
    printf("\nTentando multiplicar Matriz A (2x3) por Matriz B (2x3):\n");
    imprimirMatriz(matA);
    imprimirMatriz(matB);
    matC = multiplicarMatrizes(matA, matB); 
    if (matC != NULL) {
        printf("Isso nao deveria acontecer se as dimensoes fossem incompativeis!\n");
        destruirMatriz(matC);
    } else {
        printf("Multiplicacao falhou conforme esperado devido a dimensoes incompativeis.\n");
    }

    printf("\n--- 6. Liberando a memoria das matrizes originais ---\n");
    destruirMatriz(matA);
    destruirMatriz(matB);
    printf("Matrizes A e B destruidas.\n");

    printf("\n--- Fim dos Testes ---\n");

    return 0;
}