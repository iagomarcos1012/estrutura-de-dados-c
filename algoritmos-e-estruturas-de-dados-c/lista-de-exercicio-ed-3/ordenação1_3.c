#include <stdio.h>
#include <stdlib.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int medianaDeTres(int v[], int ini, int fim) {
    int meio = (ini + fim) / 2;

    if (v[ini] > v[meio])
        troca(&v[ini], &v[meio]);
    if (v[ini] > v[fim])
        troca(&v[ini], &v[fim]);
    if (v[meio] > v[fim])
        troca(&v[meio], &v[fim]);

    return meio;
}

int particao(int v[], int ini, int fim) {
    int i = ini, j = fim;
    int m = medianaDeTres(v, ini, fim);
    int pivo = v[m];

    while (1) {
        while (v[i] < pivo) i++;
        while (v[j] > pivo) j--;

        if (i < j) {
            troca(&v[i], &v[j]);
            i++;
            j--;
        } else {
            return j;
        }
    }
}

void QuickSort(int v[], int ini, int fim) {
    if (ini < fim) {
        int q = particao(v, ini, fim);
        QuickSort(v, ini, q);
        QuickSort(v, q + 1, fim);
    }
}

void imprime(int v[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main() {
    int v[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor original:\n");
    imprime(v, n);

    QuickSort(v, 0, n - 1);

    printf("Vetor ordenado:\n");
    imprime(v, n);

    return 0;
}
