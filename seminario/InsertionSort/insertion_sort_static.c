#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int *lista, int tamanho);
void MostraLista(int *lista, int tamanho);

int main () {

    int lista[6] = {4, 7, 2, 5, 4, 0};
    int tamanho = 6;

    MostraLista(lista, tamanho);
    InsertionSort(lista, tamanho);
    puts("-----------------");
    MostraLista(lista, tamanho);

    return 0;
}

void InsertionSort(int *lista, int tamanho) {
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

void MostraLista(int *lista, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }

    puts("");
}