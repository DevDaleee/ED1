#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaDupla.h"


struct conta{
	float saldo;
	char titular[100];
	int num_conta;
	struct conta *prox;
    struct conta *ant;
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

    if (lista == NULL){
        new->prox = new;
        new->ant = NULL;
    }  else {
		(lista)->ant = new;
    }
    return new;
}

Conta *inserirFim(Conta *lista){
    Conta *new = (Conta*) malloc(sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);

    if (lista == NULL){
        new->prox = new;
        new->ant = NULL;
    }  else {
		Conta *aux = lista;
		while (aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = new;
		new->prox = NULL;
		new->ant = aux;
    }
    return new;
}

void inserirMeio(Conta *lista, int ant){
	Conta *new = (Conta*) malloc(sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);

	if (lista == NULL){
		new->prox = NULL;
		new->ant = NULL;
		lista = new;
	} else {
		Conta *aux = lista;

		while (aux->prox != ant && aux->prox){
			aux = aux->prox;
		}
		new->prox = aux->prox;
		aux->prox = new;
	}
}

Conta remover(Conta *lista, int numC){
	Conta *aux = NULL; 
	Conta *remover = NULL;

	if (lista){
		if (lista->num_conta == numC){
			remover = lista;
			lista = remover->prox;
			if (lista){
				lista->ant = NULL;
			}
		} else {
			aux = lista;
			while (aux->prox && aux->prox->num_conta != numC){
				aux = aux->prox;
			}
			if (aux->prox){
				remover = aux->prox;
				aux->prox = remover->prox;
				if (aux->prox){
					aux->prox->ant = aux;
				}		
			}	
		}	
	}
	return remover;
}

void imprimirContrario(Conta *lista){
	pritnf("\n \t Lista: ");
	while (lista){
		printf("%s ", lista->titular);
		lista = lista->ant;
	}
	pritnf("\n\n");	
}

void imprimirNormal(Conta *lista){
	pritnf("\n \t Lista: ");
	while (lista){
		printf("%s ", lista->titular);
		lista = lista->prox;
	}
	pritnf("\n\n");	
}