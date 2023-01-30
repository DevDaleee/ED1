#include <stdio.h>
#include <stdlib.h>

typedef struct contas Conta;

Conta *criarListaEstatica(int tamanho);
Conta *inserirElemento(Conta *listaContas, int posicao, int tam);
void removerElemento(Conta *listaContas, int tam);
int buscarElemento(Conta *listaContas, int tam, int numConta);
void mostraEspecifico(Conta *listaContas, int tam);
void mostrarTodos(Conta *listaContas, int tam);
void liberarMemoria(Conta *listaContas);
void mostrarSaldo (Conta *listaContas, int numConta);