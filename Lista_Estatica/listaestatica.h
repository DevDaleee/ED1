#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct conta Conta;

Conta *criarListaContasEstatica(int tam);
void inserirElemento(Conta *lista, int p, int t);
void removerElemento(Conta *lista, int num_conta, int tamanho);
int buscarElemento(Conta *lista, int tam, int num_conta);
void mostrarElemento(Conta *elemento);
void mostrarTodosElementos(Conta *lista, int t);
void liberarMemoria(Conta *lista);
void mostrarSaldo(Conta *lista, int num_conta, int);
