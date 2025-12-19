# 🔗 Data Structures & Algorithms (C Implementation)

Este repositório contém implementações manuais das principais **Estruturas de Dados** e **Algoritmos de Ordenação** fundamentais da Ciência da Computação, desenvolvidas puramente em **C**.

O objetivo deste projeto é demonstrar domínio sobre gerenciamento de memória, ponteiros e análise de complexidade, sem depender de bibliotecas de alto nível.

---

## 🛠️ Estruturas de Dados Implementadas

### 1. Estruturas Lineares
* **Listas Encadeadas (Linked Lists):** Manipulação dinâmica de nós e ponteiros.
* **Pilhas (Stacks):** Lógica LIFO (Last In, First Out).
* **Filas (Queues):** Lógica FIFO (First In, First Out).
* **Deques:** Fila de duas pontas.

### 2. Estruturas Não-Lineares
* **Árvores Binárias (Binary Trees):** Implementação recursiva e iterativa.
* **Árvores Binárias de Busca (BST):** Inserção ordenada e busca eficiente ($O(\log n)$).

---

## ⚡ Algoritmos de Ordenação (Sorting)

Implementação e análise comparativa dos principais métodos de ordenação:

* **Bubble Sort:**
    * Algoritmo elementar de troca ($O(n^2)$). Útil para fins didáticos e pequenos conjuntos de dados.
* **Quick Sort:**
    * Estratégia "Dividir para Conquistar" ($O(n \log n)$).
    * Implementação eficiente utilizando particionamento e escolha de pivô.
* **Merge Sort:**
    * Ordenação estável baseada em recursão ($O(n \log n)$).
    * Foco na manipulação de índices e fusão (merge) de subvetores.

---

## 💻 Conceitos Técnicos Abordados

* **Gerenciamento de Memória:** Uso extensivo de `malloc`, `free` e aritmética de ponteiros.
* **Complexidade Assintótica (Big O):** Análise de desempenho de tempo e espaço.
* **Recursividade:** Aplicada em árvores e algoritmos de ordenação eficientes.
* **Tipos Abstratos de Dados (TAD):** Modularização do código com arquivos de cabeçalho (`.h`).

---

## ⚙️ Como Compilar e Executar

Utilize o compilador `gcc`.

### Exemplo: Compilando o Quick Sort
```bash
gcc -o quicksort sorting/quicksort.c
./quicksort
