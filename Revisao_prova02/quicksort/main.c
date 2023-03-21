#include <stdio.h>

void troca(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int particiona(int arr[], int baixo, int alto) {
    int pivo = arr[alto];
    int i = (baixo - 1);

    for (int j = baixo; j <= alto - 1; j++) {
        if (arr[j] < pivo) {
            i++;
            troca(&arr[i], &arr[j]);
        }
    }
    troca(&arr[i + 1], &arr[alto]);
    return (i + 1);
}

void quicksort(int arr[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particiona(arr, baixo, alto);

        quicksort(arr, baixo, pi - 1);
        quicksort(arr, pi + 1, alto);
    }
}

int main() {
    int n = 10;
    int vetor[] = { 10, 7, 8, 9, 1, 5, 2, 4, 6, 3 };

    quicksort(vetor, 0, n - 1);

    printf("Vetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}