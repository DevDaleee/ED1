#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clientes.h"

struct endereco{
    char estado[100], cidade[100], logradouro[100];
};


struct cliente{
    int id;
    char nome[100];
    Endereco endereco;
    struct cliente *prox;
};

Cliente *criarListaClientes(){
    return NULL;
}

Cliente *cadastrarCliente(Cliente *lista){

    Cliente *new = (Cliente*) malloc(sizeof(Cliente));
    new->id = rand() % 1000 + 10;
    printf("Nome: \n");
	setbuf(stdin, NULL);
    fgets(new->nome, 100, stdin);
    printf("Endereço: Estado \n");
	setbuf(stdin, NULL);
    fgets(new->endereco.estado, 100, stdin);
    printf("Endereço: Cidade \n");
	setbuf(stdin, NULL);
    fgets(new->endereco.cidade, 100, stdin);
    printf("Endereço: Logradouro \n");
	setbuf(stdin, NULL);
    fgets(new->endereco.logradouro, 100, stdin);
	setbuf(stdin, NULL);

	new->prox = NULL;

	if(lista = NULL){
		return new;
	} else { 
		Cliente *aux = lista;
		while( aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = new;
		return lista; 	
	}
}

Cliente *buscarCliente(Cliente *lista, int valor){
	Cliente *aux = lista;

	if (lista != NULL){
		while (aux != NULL && aux->id != valor){
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

Cliente *remover(Cliente *lista, int id){
	Cliente *aux = lista;
	Cliente *ant = lista;

	if (lista != NULL){
		while (aux != NULL  && aux->id != id){
			ant = aux;
			aux = ant->prox;
			if (aux == NULL){
				return lista;
			}else if (ant == NULL){
				lista = aux->prox;
			} else{
				ant->prox = aux->prox;
			}
			free(aux);
			return lista;
		}	
	}else{
		return NULL;
	}
}

void mostrarLista(Cliente *lista){
	Cliente *aux = lista;
	printf("\nPrint values \n");
	while(aux != NULL){
		printf("Nome: %s\n Estado: %s\n Cidade: %s\nLogradouro: %s\n", aux->nome, aux->endereco.estado, aux->endereco.cidade, aux->endereco.logradouro);
		aux = aux->prox;
	}
}


void liberarLista(Cliente **lista_ref){
	Cliente *list = *lista_ref;
	Cliente *aux = NULL; 
	while (list != NULL){
		aux = list->prox;
		free(list);
		list = aux;
	}
	free(list);
	*lista_ref = NULL;
}