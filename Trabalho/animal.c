#include "animal.h"
#include "fazenda.h"
#include "criador.h"
#include <stdio.h>
#include <stdlib.h>

struct animal{
	int id_animal, id_fazenda;
	char sexo; // M ou F
	float peso; //em KG
	int status; // 1 - Nascimento na propria fazenda | 2 - venda | 3 - troca | 4 - Permuta
	struct animal *prox;
};

Animal *criaListaEncadeadaSimplesAnimais(){
	return NULL;
}

Animal *cadastro(Animal *rebanho){
	Animal *new = (Animal*) malloc(sizeof(Animal));
	new->id_animal = rand() % 100 + 10;
	printf("Sexo - ");
	scanf("%s", new->sexo);
	printf("Peso - ");
	scanf("%f", new->peso);
	printf("Status - ");
	scanf("%d", &new->status);
	new->prox = rebanho;
	return new;
}

void adicionarAnimal(Animal *rebanho, Animal *novo) {
	if (rebanho == NULL) {
		novo->prox = NULL;
	}
	else {
		novo->prox = rebanho;
	}
}

Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal){
	Animal *aux = origem->rebanho;
	Animal *aux2 = destino->rebanho;
	if (buscarAnimal(aux, id_animal) == 1){
		Animal *rem = remover(origem, id_animal);
		rem->id_fazenda = destino->id_fazenda;
		rem->status = 3;
		adicionarAnimal(aux2, rem);
		
	}else{
		printf("Erro! Ação não pode ser completada! \n");
	}
}

float calcArroba(Animal *rebanho) {
	if (rebanho != NULL) {
		Animal *aux = rebanho;
		float arroba;

		while (aux != NULL) {
			arroba += (aux->peso / 15);

			aux = aux->prox;
		}
		return arroba; 
	}
}

void quantCSexo(Animal *rebanho) {
	int masc, fem;

	Animal *aux = rebanho;

	while (aux != NULL) {
		if (aux->sexo == "M") {
			masc++;
		}
		else if (aux->sexo == "F") {
			fem++;
		}
		printf("Sexo M: %d \n",masc);
		printf("Sexo F: %d \n", fem);
		masc = 0; 
		fem = 0;

		aux = aux->prox;
	}
}

int buscarAnimal(Animal *rebanho, int id_animal) {
	if (rebanho != NULL) {
		Animal *aux = rebanho;

		while (aux != NULL) {
			if (id_animal == aux->id_animal) {
				return 1;
			}
		}
		return 0;
	}
	else {
		return 0;
	}
}

Animal *remove(Fazenda *fazenda, int id_animal) {
	Animal *aux = fazenda->rebanho;
	Animal *rem = NULL;

	if (buscar_animal(aux, id_animal) == 1) {
		if (aux->id_animal == id_animal) {
			rem = aux;
			fazenda->rebanho = aux->prox;
		}
		else {
			while (aux->prox->id_animal != id_animal) {
				aux = aux->prox;
			}
			rem = aux->prox;
			aux->prox = aux->prox->prox;
		}
	}
	else {
		fprintf(stderr, "ERRO\n");
	}
	return rem;		
}

void liberarMem(Animal *rebanho){
    Animal *aux = rebanho;
	Animal *aux2 = NULL;

	while (aux != NULL) {
		aux2 = aux;
		aux = aux->prox;
		free(aux2);
		aux2 = NULL;
	}
	free(aux);
}