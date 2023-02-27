#include <stdio.h>
#include <stdlib.h>

#include "animal.h"
#include "fazenda.h"
#include "criador.h"

struct criador
{
	int id_criador;
	char nome[100];
	Fazenda *fazendas;//Esse ponteiro e uma lista circular (atentem-se)
	float patrimonio; //esse valor deve ser constantemente modificado para que o valor esteja atualizado	
	struct criador *prox, *ant; //lista dupla encadeada, nao é necessário ser circular
};

Criador *criarListaDuplaCriadores(){
	return NULL;
}

Criador *cadastrar_criador(Criador *criadores) {
	Criador *new = (Criador *) calloc(sizeof(Criador), 1);

	new->id_criador = rand() % 1000000;

	printf("%d\n", new->id_criador);
	printf("Nome: ");
	fgets(new->nome, 100, stdin); 
	new->fazendas = criarListaEncadeadaCircularFazendas();
	printf("Patrimonio: ");
	scanf("%f", &new->patrimonio);

	if (criadores == NULL){
        new->prox = new;
        new->ant = NULL;
    }  else {
		(criadores)->ant = new;
    }
    return new;
}

Criador *removerCriador(Criador *criadores, int id) {

	if (buscar(criadores, id) == 1) {
		Criador *aux = criadores;
		while (aux != NULL) {

			if (aux->id_criador == id) {
				if (aux->fazendas == NULL) {
					if (aux->ant == NULL) {
						aux->prox->ant = NULL;
						Criador *aux2 = aux->prox;
						free(aux);
						aux = NULL;
						return aux2;
					}
					else if(aux->ant != NULL && aux->prox != NULL) {
						aux->ant->prox = aux->prox;
						aux->prox->ant = aux->ant;
						free(aux);
						aux = NULL;
						return criadores;
					}
					else if (aux->prox == NULL) {
						aux->ant->prox = NULL;
						aux->ant = NULL;
						free(aux);
						aux = NULL;
						return criadores;
					}
				}
				else {
					fprintf(stderr, "ERRO AO REMOVER\n");
					return criadores;
				}
			}
		}
	}
	else {
		return criadores;
	}
}//nao é permitido remover criador com fazendas cadastradas

int buscar(Criador *criadores, int id){
	Criador *aux = criadores;

	if (criadores == NULL){
		return NULL;
	}else{
		while (aux != NULL && aux->id_criador != id){
			aux = aux->prox;
			if (aux->id_criador == id){
				return 1;
			}
			
			if (aux == NULL){
				return 0;
			}else{
				return 0;
			}
		}
	}
}

float calcPatrimonio(Criador *criadores, int id){
	Criador *aux = criadores;
	
	if (criadores == NULL){
		printf("Erro! Lista de Criadores vazia!");
	}else{
		do{
			aux = aux->prox;
		}while (aux->prox->id_criador != id);
		if(aux->prox == NULL){
			printf("Criador não encontado!");
		}else{
			printf("Patrimonio total do Cirador: %s\n", aux->nome);
			printf("R$ %2.f\n", aux->patrimonio);
			return aux->patrimonio;
		}
	}
	
}
void printCriadores(Criador *criadores){
	printf("\n \t Lista de Criadores: ");
	while (criadores){
		printf("ID: %d \n", criadores->id_criador);
		printf("Nome: %s \n", criadores->nome);
		printf("Patrimonio: %.2f \n", criadores->patrimonio);
		criadores = criadores->prox;
	}
	printf("\n\n");	
}

void liberarMemCriador(Criador *criadores) {
	if (criadores != NULL) {
		Criador *aux = criadores;
		while (aux->prox != NULL){
			aux = aux->prox;
			free(aux->ant);
		}

		free(aux);
	}else{
		printf("Erro, não foi possivel liberar memoria!");
	}
}