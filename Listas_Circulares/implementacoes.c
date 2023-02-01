#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "listaCircular.h"


struct conta{
	float saldo;
	char titular[100];
	int num_conta;
	struct conta *prox;
};  

Conta *criarLista(){
	return NULL;
}

Conta *inserir(Conta *lista){
    Conta *new = (Conta*) malloc(sizeof(Conta));
	new->num_conta = rand() % 100 + 10;
	printf("Nome - ");
	scanf("%s", new->titular);
	printf("Saldo - ");
	scanf("%f", &new->saldo);
    if (lista == NULL){
        new->prox = new;
    }else{
        Conta *aux;
        aux = lista;
        new->prox = aux;
        while(aux->prox != lista){
            aux = aux->prox;
        }
        aux->prox = new;
    }
	return new;
}

void imprimir(Conta *lista){
    Conta *p = lista;
    if (p){
        do{
            printf("%.2f\n", p->saldo);
            printf("%d\n", p->num_conta);
            printf("%s\n", p->titular);
            p = p->prox; //Avançar para o próximo nó
        } while (p != lista);
        
    }
    
}