typedef struct animal Animal;
#include "fazenda.h"

Animal *criaListaEncadeadaSimplesAnimais();
Animal *cadastro(Animal *rebanho);
Animal *permutasAnimais(Fazenda *origem, Fazenda *destino, int id_animal);//obervar para atualizar o status do animal na fazenda de destino
Animal *remover(Animal *animais, int id_animal);


//Funções Desenvolvidadas pela Dupla
void adicionarAnimal(Animal *rebanho, Animal *novo);
float calcArroba(Animal *rebanho);
void QuantCSexo(Animal *rebanho);
void liberarMem(Animal *rebanho);
int buscarAnimal(Animal *rebanho, int id_animal);


/*
Desenvolva funcoes que:

Done - Funcao para liberar a memoria
*/