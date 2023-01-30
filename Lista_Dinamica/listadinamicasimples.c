#include <stdio.h>
#include <stdlib.h>

#include "listadinamicasimples.h"


struct conta{
	float saldo;
	char titular[100];
	int num_conta;
	struct conta *prox;
};

Conta *criarLista(){
	return NULL;
}

Conta *inserirInicio(Conta *lista){
	Conta *new = (Conta*) malloc(sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->prox = lista;
	return new;
}

Conta *inserirFim(Conta *lista){
	Conta *new = (Conta*) malloc(sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
	new->prox = NULL;

	if (lista = NULL){
		return new;
	} else { 
		Conta *aux = lista;

		while( aux->prox != NULL){
			aux = aux->prox;
		}

		aux->prox = new;

		return lista; 	
	}
}

Conta *inserirOrdenado(Conta *lista){
	Conta *new = (Conta*) malloc(sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);

	if (lista = NULL){
		new->prox = NULL;
		return new;
	} else {
		Conta *aux = lista;
		Conta *ant = NULL;

		while (aux != NULL && aux->saldo < new->saldo){
			ant = aux;
			ant = aux->prox;
		}
		if (ant == NULL){
			new->prox = lista;
			return new;
			
		}else{
			new->prox = aux;
			ant->prox = new;
			return lista;
		}		
	}
}

Conta *remover(Conta *lista, int valor){
	Conta *aux = lista;
	Conta *ant = NULL; 

	if (listaVazia(lista) == 0){
		while (aux != NULL && aux->num_conta != valor){
			ant = aux;
			aux = ant->prox;
			if (aux == NULL){
				return lista;
			}
			if (ant == NULL) {
				lista = aux->prox;
			}else{
				ant->prox = aux->prox;
			}
			free(aux);
			return lista;
		}

	}else{
		return NULL;
	}
}

Conta *buscar(Conta *lista, int valor){
	Conta *aux = lista;

	if (listaVazia(lista) == 0){
		while (aux != NULL && aux->num_conta != valor){
			aux = aux->prox;
			if (aux == NULL){
				return NULL;
			}else{
				return lista;
			}
		}
	}else{
		return NULL;
	}
	
}

Conta *alterar(Conta *lista, int oldValue, int newValue){
	Conta *aux = lista;

	if (listaVazia(lista) == 0){
		while (aux != NULL && aux->num_conta != oldValue){
			aux = aux->prox;
		}
		if (aux == NULL){
			return NULL;
		}else{
			aux->num_conta = newValue;
			return lista;
		}
	}else{
		return NULL;
	}
}

int listaVazia(Conta *lista) {
	if (lista == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void mostrarLista(Conta *lista){
	Conta *aux = lista;
	printf("\nPrint values \n");
	while(aux != NULL){
		printf("Nome: %s\nSaldo: %.2f\nNum conta %d\n ", aux->titular, aux->saldo, aux->num_conta);
		aux = aux->prox;
	}
}

void liberarLista(Conta **lista_ref){
	Conta *list = *lista_ref;
	Conta *aux = NULL; 
	while (list != NULL){
		aux = list->prox;
		free(list);
		list = aux;
	}
	free(list);
	*lista_ref = NULL;
}