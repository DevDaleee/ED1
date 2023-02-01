#include "listaestatica.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct conta{
	float saldo;
	int num_conta;
	char nome[100];
};

Conta *criarListaContasEstatica(int tam){
	Conta *listaContas = (Conta*) calloc(sizeof(Conta), tam);
	return listaContas;
}

void inserirElemento(Conta *lista, int p, int t){
	srand(time(NULL));
	if (p < t){
		scanf("%f", &lista[p].saldo);
		scanf("%s", lista[p].nome);
		lista[p].num_conta = rand() % 100 + 10;
	}
}

void removerElemento(Conta *lista, int num_conta, int tamanho){
	for (int i = 0; i < tamanho; i++){
		if (lista[i].num_conta == num_conta){
			for (int j = i; j < tamanho; j++){
				lista[j] = lista[j++];
			}
			break;
		}	
	}
}

void mostrarElemento(Conta *elemento){
	printf("\nSaldo: %.2f\nNome: %s\nNumero da Conta: %d\n", elemento->saldo, elemento->nome, elemento->num_conta);
}

void mostrarTodosElementos(Conta *lista, int t){
	for (int i = 0; i < t; ++i){
		mostrarElemento(&lista[i]);
	}
}

void liberarMemoria(Conta *lista){
    free(lista);
}

void mostrarSaldo(Conta *lista, int num_conta, int tamanho){
	for (int i = 0; i < tamanho; i++){
		printf("Saldo %.2f: ", lista[num_conta].saldo);
	}
	
}
