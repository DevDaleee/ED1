#include <stdio.h>
#include <stdlib.h>
#define TAM 5

struct balde {
    int qtd;
    int valores[TAM];
};

void insertionSort(int *lista, int tamanho) {
    int chave;
    int j, i;

    for (i = 1; i < tamanho; i++) {
        chave = lista[i];
        j = i - 1;

        while (j >= 0 && lista[j] > chave) {
            lista[j + 1] = lista[j];
            j--;
        }
        lista[j + 1] = chave;
    }
}

void bucketSort(int *V, int N) {
    int i, j, maior, menor, nroBaldes, pos;
    struct balde *bd;

    // Acha o menor e maior valor
    maior = menor = V[0];
    for (i = 0; i < N; i++) {
        if (V[i] > maior)
            maior = V[i];
        if (V[i] < menor)
            menor = V[i];
    }

    // Inicializa Baldes
    nroBaldes = (maior - menor) / TAM + 1;
    bd = (struct balde *)malloc(nroBaldes * sizeof(struct balde));
    for (i = 0; i < nroBaldes; i++) {
        bd[i].qtd = 0;
    }

    // Distribui os valores nos baldes
    for (i = 0; i < N; i++) {
        pos = (V[i] - menor) / TAM;
        bd[pos].valores[bd[pos].qtd] = V[i];
        bd[pos].qtd++;
    }

    // Ordena baldes e coloca no array
    pos = 0;
    for (i = 0; i < nroBaldes; i++) {
        insertionSort(bd[i].valores, bd[i].qtd);
        for (j = 0; j < bd[i].qtd; j++) {
            V[pos] = bd[i].valores[j];
            pos++;
        }
    }

    free(bd);
}

int main() {
    int v[TAM] = { 23, 4, 17, 8, 29 };

    printf("Lista Desordenada:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    bucketSort(v, TAM);

    printf("Lista Ordenada:\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    return 0;
}
