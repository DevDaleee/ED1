#include <stdio.h>
#include <stdlib.h>

#include "criador.h"
#include "fazenda.h"
#include "animal.h"

struct endereco{
	char cidade[50], estado[2], logradouro[200];
};

struct fazenda{
	int id_criador, id_fazenda;
	char nome[100];
	Endereco localizacao;
	float valor_fazenda;
	Animal *rebanho;
	struct fazenda *prox;
};

Fazenda *criarListaEncadeadaCircularFazendas(){
	return NULL;
}

Fazenda *cadastrarFazenda(Fazenda *fazendas){
	Fazenda *new = (Fazenda *) malloc(sizeof(Fazenda));

	new->id_fazenda = rand() % 1000;
	printf("Nome: ");
	fgets(new->nome, 100, stdin); 
	scanf("%s", new->localizacao.cidade);
	scanf("%s", new->localizacao.estado);
	scanf("%s", new->localizacao.logradouro);
	new->valor_fazenda = 0;
	new->rebanho = criaListaEncadeadaSimplesAnimais();

	return new;
}

void addFazenda(Fazenda *fazendas, Fazenda *nova) {
	Fazenda *aux = fazendas;

	if (fazendas == NULL) {
		nova->prox = nova;
	}
	else {
		nova->prox = aux;	
		while (aux->prox != fazendas) {
			aux = aux->prox;
		}
		aux->prox = nova;
	}
}


Fazenda *removerFazenda(Fazenda *fazendas, int id){
	Fazenda *aux = fazendas;
	Fazenda *ant = NULL; 

	if (fazendas == NULL){
		return NULL;
	}else if(fazendas->rebanho != NULL){
		while (aux != NULL && aux->id_criador != id){
			ant = aux;
			aux = ant->prox;
			if (aux == NULL){
				return fazendas;
			}
			if (ant == NULL) {
				fazendas = aux->prox;
			}else{
				ant->prox = aux->prox;
			}
			free(aux);
			return fazendas;
		}

	}else{
		printf("Não é possivel remover Fazendas que contém animais!");
	}
}//nao permitir remover fazenda se houver animais cadastrados

Fazenda *alterar_fazenda(Fazenda *fazendas, int id) {

	if (fazendas != NULL) {
		if(buscarFazenda(fazendas, id) == 1) {
			Fazenda *aux = fazendas;

			while (aux->prox != fazendas) {
				if (aux->id_fazenda == id) {
					printf("Novo nome: ");
					scanf("%s", aux->nome);
					printf("Nova cidade: ");
					scanf("%s", aux->localizacao.cidade);
					printf("Novo estado: ");
					scanf("%s", aux->localizacao.estado);
					printf("Novo logradouro: ");
					scanf("%s", aux->localizacao.logradouro);
				}
			}
		}
		else {
			return NULL;
		}
	}
	else {
		return NULL;
	}
}
// alterar dados cadastrais da fazenda. exemplo: nome e endereco;
int buscarFazenda(Fazenda *fazendas, int id) {
	if (fazendas != NULL) {
		Fazenda *aux = fazendas;

		while (aux->prox != fazendas) {
			aux = aux->prox;

			if (aux->id_fazenda == id) {
				return 1;
			}
		}
		return 0;
	}
	else {
		return 0;
	}
}

float totalArroba(Fazenda *fazendas) {
	fazendas->valor_fazenda = 267.5 * calcArroba(fazendas->rebanho);
}

void quantSexo(Fazenda *fazendas){

	if (fazendas != NULL) {
		Fazenda *aux = fazendas;

		while (aux->prox != fazendas) {
			printf("Fazenda: %s\n", aux->nome);
			quantSexo(aux->rebanho);
			aux = aux->prox;
		}
	}
	else {
		fprintf(stderr, "ERRO\n");
	}
}

void liberarMemoriaF(Fazenda *fazendas) {
	if (fazendas != NULL) {
		Fazenda *aux = fazendas;
		Fazenda *aux2 = NULL;

		while (aux->prox != fazendas) {
			aux2 = aux;
			aux = aux->prox;
			free(aux2);
			aux2 = NULL;	
		}
		free(aux);
		aux = NULL;
	}
}