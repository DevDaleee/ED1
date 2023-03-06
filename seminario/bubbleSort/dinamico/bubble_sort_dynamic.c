#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort_dynamic.h"

//Declaração da Estrutura Array
struct array{
    int valor;
	struct array *prox;
};

//Criação da estrutura dinamica Array
Array *criarLista(){
	return NULL;
}

//Função para inserção dos valores 
Array *inserirFim(Array *lista){
	Array *new = (Array*)malloc(sizeof(Array));
	new->valor = rand() % 100 + 10;
	new->prox = NULL;

	if (lista == NULL){
		return new;
	} else { 
		Array *aux = lista;
		while( aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = new;

		return lista; 	
	}
}

//Função para mostar a lista
void print_lista(Array* lista) {
    Array* current = lista;

    while (current != NULL) {
        printf("%d ", current->valor);
        current = current->prox;
    }
    printf("\n");
}



void bubbleSort(Array **lista) {
    int swapped, i;
    Array * ptr1;
    Array * lptr = NULL;

    // Verifica se a lista está vazia ou tem apenas um elemento
    if (*lista == NULL || (*lista)->prox == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = *lista;

        while (ptr1->prox != lptr) {
            if (ptr1->valor > ptr1->prox->valor) {
                // Troca os valores dos nós
                int temp = ptr1->valor;
                ptr1->valor = ptr1->prox->valor;
                ptr1->prox->valor = temp;
                swapped = 1;
            }
            ptr1 = ptr1->prox;
        }
        lptr = ptr1;
    } while (swapped);
}
//Função simples para liberar memoria
void liberarLista(Array *lista_ref){
	Array *list = lista_ref;
	Array *aux = NULL; 
	while (list != NULL){
		aux = list->prox;
		free(list);
		list = aux;
	}
	free(list);
	lista_ref = NULL;
}