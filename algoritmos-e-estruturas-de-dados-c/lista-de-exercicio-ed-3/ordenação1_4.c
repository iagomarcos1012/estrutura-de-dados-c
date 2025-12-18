#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int aux[], int ini, int meio, int fim) {
    for (int i = ini; i <= fim; i++) aux[i] = v[i];

    int i = ini, j = meio + 1, k = ini;
    while (i <= meio && j <= fim) {
        if (aux[i] <= aux[j]) v[k++] = aux[i++];
        else v[k++] = aux[j++];
    }
    while (i <= meio) v[k++] = aux[i++];
}

void mergeSort(int v[], int aux[], int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        mergeSort(v, aux, ini, meio);
        mergeSort(v, aux, meio + 1, fim);
        merge(v, aux, ini, meio, fim);
    }
}

void ordenar(int v[], int n) {
    int* aux = malloc(n * sizeof(int));
    if (!aux) exit(1);
    mergeSort(v, aux, 0, n - 1);
    free(aux);
}

void encontrarComuns(int v1[], int v2[], int n) {
    ordenar(v1, n);
    ordenar(v2, n);

    int i = 0, j = 0;
    printf("Elementos comuns: ");
    while (i < n && j < n) {
        if (v1[i] == v2[j]) {
            printf("%d ", v1[i]);
            i++;
            j++;
        } else if (v1[i] < v2[j]) {
            i++;
        } else {
            j++;
        }
    }
    printf("\n");
}

int main() {
    int v1[] = {4, 9, 5, 1, 3};
    int v2[] = {9, 7, 3, 1, 6};
    int n = sizeof(v1) / sizeof(v1[0]);

    encontrarComuns(v1, v2, n);

    return 0;
}
