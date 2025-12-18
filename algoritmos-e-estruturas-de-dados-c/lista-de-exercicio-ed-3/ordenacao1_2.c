#include <stdio.h>
#include <stdlib.h>

void merge(int v[], int aux[], int ini, int meio, int fim)
{
    for (int i = ini; i <= fim; i++)
    {
        aux[i] = v[i];
    }

    int i = ini;
    int j = meio + 1;
    int k = ini;

    while (i <= meio && j <= fim)
    {
        if (aux[i] <= aux[j])
        {
            v[k++] = aux[i++];
        }
        else
        {
            v[k++] = aux[j++];
        }
    }

    while (i <= meio)
    {
        v[k++] = aux[i++];
    }
}

void mergeSort(int v[], int aux[], int ini, int fim)
{
    if (ini >= fim)
        return;

    int meio = (ini + fim) / 2;
    mergeSort(v, aux, ini, meio);
    mergeSort(v, aux, meio + 1, fim);
    merge(v, aux, ini, meio, fim);
}

void mergeSortUnicoAux(int v[], int n)
{
    int *aux = malloc(n * sizeof(int));
    if (!aux)
    {
        printf("Erro ao alocar memória auxiliar.\n");
        return;
    }
    mergeSort(v, aux, 0, n - 1);
    free(aux);
}

void imprimeVetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main()
{
    int v[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor original:\n");
    imprimeVetor(v, n);

    mergeSortUnicoAux(v, n);

    printf("Vetor ordenado:\n");
    imprimeVetor(v, n);

    return 0;
}
