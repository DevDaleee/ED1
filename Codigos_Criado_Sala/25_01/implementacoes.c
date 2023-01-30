#include "tad.h"
#include <stdio.h>
#include <stdlib.h>

struct Conta{
    float saldo;
    int numConta;
    char titular(100);
};

Conta *criarListaEstatica(int tamanho){
    Conta *vec = (Conta*) calloc(tamanho, sizeof(Conta));
    return vec;
}
Conta *inserirElemento(Conta *listaContas, int tam, int tamA){
    if (tamA == tam){
        printf("Erro");
        printf("Tamanho Excedido!!");
    }else{
        listaContas->numConta = tamA;
        listaContas->saldo = 0;
        listaContas->titular = gets();
    }
    return listaContas;
}
void removerElemento(Conta *listaContas, int tam){
    listaContas->numConta = NULL;
    listaContas->saldo = NULL;
    listaContas->titular = NULL;
}
int buscarElemento(Conta *listaContas, int tam, int numConta){    
    for (int i = 0; i < tam; i++){
        if (tam[i] == listaContas->numConta){
            return 1;
        }
    }
    
}
void mostraEspecifico(Conta *listaContas, int tam);
void mostrarTodos(Conta *listaContas, int tam){
    for (int i = 0; i < tam; i++){
        printf("%d", listaContas->numconta[i]);
    printf("%s", listaContas->titular[i]);
        printf("%.2f", listaContas->saldo[i]);
    }
    
}
void liberarMemoria(Conta *listaContas){
    free(listaContas);
}