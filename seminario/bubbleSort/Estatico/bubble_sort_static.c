#include <stdio.h>

/* Função que ordena uma lista de inteiros em ordem crescente usando bubble sort */
void bubble_sort(int *lista, int tamanho);

/* Função que imprime uma lista de inteiros */
void print_lista(int *lista, int tamanho);

int main() {
    int lista[] = {4, 7, 2, 5, 4, 0};
    int tamanho = 6;

    printf("Lista original: ");
    print_lista(lista, tamanho);

    bubble_sort(lista, tamanho);

    printf("\nLista ordenada: ");
    print_lista(lista, tamanho);

    printf("\n");
    
    return 0;
}

void print_lista(int *lista, int tamanho) {
    //Apenas percorro a lista mostrando todos os valores que estão presentes no Array
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
}

void bubble_sort(int *lista, int tamanho) {
    //Declaro as váriaveis que vão me ajudar na hora de executar a ordenação
    int i, j, temp;

    //Percorro a lista no valor i
    for (i = 0; i < tamanho - 1; i++) {
        //Percorro o array uma posição antes da posição i, neste caso com o j
        for (j = 0; j < tamanho - i - 1; j++) {
            //Se o valor atual for maior que o valor seguinte
            if (lista[j] > lista[j + 1]) {
                //Guardo esse valor maior em uma váriavel temporaria
                temp = lista[j];
                //Salvo o valor menor na posição correta durante essa repetição
                lista[j] = lista[j + 1];
                //Passo o valor maior para a posição da frente
                lista[j + 1] = temp;
            }
        }
    }
}