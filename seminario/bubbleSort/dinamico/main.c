#include <stdio.h>
#include <stdlib.h>

#include "bubble_sort_dynamic.h"

int main(){
	Array *lista;
    int escolha;
	lista = criarLista();
    
    printf("Quantos números deseja inserir: ");
    scanf("%d", &escolha);

    for (int i = 0; i <= escolha; i++){
        lista = inserirFim(lista);
    }

    printf("Lista original: ");
    print_lista(lista);

    bubbleSort(&lista);

    printf("\nLista ordenada: ");
    print_lista(lista);

    printf("\n");
    liberarLista(lista);

	return 0;
}