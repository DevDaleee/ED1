#include "entregas.h"
#include "transportadora.h"
#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _fifoE {
    Entrega *inicio;
    Entrega *fim;
}FifoE;

typedef struct _entrega {
    int id_entrega;
    int id_endereco;
    Cliente *cliente;
    char produto[50];
    Entrega *prox;
}Entrega;

typedef struct _NewTry{
    int id_entrega;
    int tentativa;
    int id_endereco;
    Cliente *cliente;
    char produto[50];
    NewTry *prox;
}NewTry;
typedef struct _FifoDevol {
    DevolProd *inicio;
    DevolProd *fim;
}FifoDevol;

typedef struct _DevolProd{
    int id_entrega;
    int id_endereco;
    Cliente *cliente;
    char produto[50];
    DevolProd *prox;
}DevolProd;

// Funções de inserção e criação
FifoE *criaFila() {
    FifoE *novo = (FifoE *) calloc(sizeof(FifoE), 1);

    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;    
}

void addEntrega(FifoE *fifo, int id_endereco, char *produto, Cliente *cliente){    Entrega *novo = (Entrega *) calloc(sizeof(Entrega), 1);

    novo->id_entrega = gera_id_entrega(fifo);
    novo->id_endereco = id_endereco;
    novo->cliente = cliente;
    strcpy(novo->produto, produto);

    if (verifica_filaEntrega(fifo)) {
        novo->prox = NULL;
        fifo->inicio = novo;
        fifo->fim = novo;
    }
    else {
        fifo->fim->prox = novo;
        novo->prox = NULL;
        fifo->fim = novo;
    }

}

NewTry *criaPilhaNewtry(){
    return NULL;
}

void adiciona_PilhaNewTry(NewTry *PilhaEntregasNot, int id_entrega, int id_endereco, char *prod, Cliente *cliente) {
    NewTry *novo = (NewTry *) calloc(sizeof(NewTry), 1);
    novo->tentativa = 2;
    novo->id_entrega = id_entrega;
    novo->id_endereco = id_endereco;
    novo->cliente = cliente;
    strcpy(novo->produto, prod);

    if (verifica_pilhaEntregaNewTry(PilhaEntregasNot)) {
        novo->prox = NULL;
        PilhaEntregasNot = novo;
    }
    else {
        novo->prox = PilhaEntregasNot;
        PilhaEntregasNot = novo;
    }
}

FifoDevol* cria_FilaDevolucaoProd() {
    FifoDevol *novo = (FifoDevol *) calloc(sizeof(FifoDevol), 1);

    novo->inicio = NULL;
    novo->fim = NULL;
    return novo;
}

void adiciona_FilaDevolucaoProd(FifoDevol *FilaDevolucaoProd, int id_entrega, int id_endereco, char *prod, Cliente *cliente){
    DevolProd *novo = (DevolProd *) calloc(sizeof(DevolProd), 1);

    novo->id_entrega = id_entrega;
    novo->id_endereco = id_endereco;
    novo->cliente = cliente;
    strcpy(novo->produto, prod);

    if (verifica_FifoDevol(FilaDevolucaoProd)) {
        novo->prox = NULL;
        FilaDevolucaoProd->inicio = novo;
        FilaDevolucaoProd->fim = novo;
    }
    else {
        FilaDevolucaoProd->fim->prox = novo;
        novo->prox = NULL;
        FilaDevolucaoProd->fim = novo;
    }
}

// Funções acessórias
int gera_id_entrega(Entrega *fifo) {
    int id_entrega;

    // gera ID unico para entrega
    do
    {
        id_entrega = rand() % 10000;
    } while (busca_cliente(fifo, id_entrega) == 1);
    
    return id_entrega;
}

int TentativaEntrega(NewTry *pilha) {
    NewTry *aux = pilha;

    if (verifica_NewTryIguais(aux)) {
        // Se ainda houve uma tentativa de entrega nao sucedida, eu incremento
        if (aux->tentativa == 2 || aux->tentativa == 3 ) {
            aux->tentativa += 1;
            aux->prox->tentativa += 1;
        }   
    }
    else {
        if (aux->tentativa == 2 || aux->tentativa == 3 ) {
            aux->tentativa += 1;
            aux->prox->tentativa += 1;
        }   
    }
    // Se a tentativa ja for superior a 3,  eu terei que remover minha entrega da pilha e adicionar na fila de devolucao
    return aux->tentativa;
}

// Funções de verificação
int verifica_filaEntrega(FifoE *fifo) {
    if (fifo->inicio == NULL) {
        return 1;
    } else {
        return 0;
    }
}

int verifica_pilhaNewTry(NewTry *pilhaNewTry) {
    if (pilhaNewTry == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int verifica_filaDevolucaoProd(FifoDevol *FilaDevolucaoProd){
    if (FilaDevolucaoProd->inicio == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int verifica_EntregasIguais(FifoE *fifo) {
    Entrega *aux = fifo->inicio;

    if (aux->prox->id_endereco == aux->id_endereco) {
        return 1;
    }
    else {
        return 0;
    }
}

int verifica_NewTryIguais(NewTry *pilha) {
    NewTry *aux = pilha;

    if (aux->id_endereco == aux->prox->id_endereco) {
        return 1;
    }
    else {
        return 0;
    }
}

// Funções de remoção
void remove_FilaEntrega(FifoE *fifo) {
    if (verifica_filaEntrega(fifo)) {
        puts("Nao possui entregas a serem efetuadas!");
    }
    else {
        Entrega *aux = fifo->inicio;
        fifo->inicio = aux->prox;
        free(aux);
        aux = NULL;
        puts("Entrega finalizada!");
    }
}

void remova_Fila_AddPilha(FifoE *fifo, NewTry *pilha) {
    if (verifica_filaEntrega(fifo)) {
        puts("Nao possui entregas a serem efetuadas!");
    }
    else {
        Entrega *aux = fifo->inicio;
        adiciona_PilhaNewTry(pilha, aux->id_entrega, aux->id_endereco, aux->produto, aux->cliente);
        fifo->inicio = aux->prox;
        free(aux);
        aux = NULL;
        puts("Entrega nao efetuada! Adicionada a pilha de entregas!");
    }
}

void remove_PilhaNewTry(NewTry *pilha) {
    if (verifica_pilhaNewTry(pilha)) {
        puts("Pilha de entrega esta vazia");
    }
    else {
        NewTry *aux = pilha;

        pilha = aux->prox;
        free(aux);
        aux = NULL;
        puts("Entrega finalizada!");
    }
}

void remove_Pilha_AddFilaDevol(NewTry *PilhaNewTry, FifoDevol *fila) {
    if (verifica_pilhaNewTry(PilhaNewTry)) {
        puts("Nao possui entregas!");
    }
    else {
        NewTry *aux = PilhaNewTry;
        PilhaNewTry = aux->prox;
        adiciona_FifoDevol(fila, aux->id_entrega, aux->id_endereco, aux->produto, aux->cliente);
        free(aux);
        aux = NULL;
        puts("Entrega adicionada a fila de devolucao!");
    }
}

// Funções de exibição de dados
void imprimirEntregas(FifoE *fifo) {
    if (verifica_filaEntrega(fifo)) {
        puts("Nao possui entregas a serem efetuadas!");
    }
    else {
        Entrega *aux = fifo->inicio;

        if (verifica_EntregasIguais(fifo)) {
            puts("Possui 2 entregas a serem efetuadas no mesmo endereco!");
            
            puts("Entrega");
            printf("ID Entrega: %d\n", aux->id_entrega);
            printf("ID Endereco: %d\n", aux->id_endereco);
            printf("Produto: %s\n", aux->produto);
            puts("Cliente");
            mostra_cliente(aux->cliente);

            puts("Entrega");
            printf("ID Entrega: %d\n", aux->prox->id_entrega);
            printf("ID Endereco: %d\n", aux->prox->id_endereco);
            printf("Produto: %s\n", aux->prox->produto);
            puts("Cliente");
            mostra_cliente(aux->prox->cliente);
        }
        else {
            puts("Entrega");
            printf("ID Entrega: %d\n", aux->id_entrega);
            printf("ID Endereco: %d\n", aux->id_endereco);
            printf("Produto: %s\n", aux->produto);
            puts("Cliente");
            mostra_cliente(aux->cliente);     
        }
    }
}

void ImprimirTentativas(NewTry *pilha) {
    if (verifica_pilhaNewTry(pilha)) {
        puts("Nao possui entregas nao efetuadas!");
    }
    else {
        NewTry *aux = pilha;
        
        if (verifica_NewTryIguais(pilha)) {
           puts("Possui 2 entregas no mesmo endereco");
           
            puts("Entrega");
            printf("ID Entrega: %d\n", aux->id_entrega);
            printf("ID Endereco: %d\n", aux->id_endereco);
            printf("Produto: %s\n", aux->produto);
            printf("Tentativa de entrega de numero: %d\n", aux->tentativa);
            puts("Cliente");
            mostra_cliente(aux->cliente);

            puts("Entrega");
            printf("ID Entrega: %d\n", aux->prox->id_entrega);
            printf("ID Endereco: %d\n", aux->prox->id_endereco);
            printf("Produto: %s\n", aux->prox->produto);
            printf("Tentativa de entrega de numero: %d\n", aux->prox->tentativa);
            puts("Cliente");
            mostra_cliente(aux->prox->cliente);     
        }
        else {
            puts("Entrega");
            printf("ID Entrega: %d\n", aux->id_entrega);
            printf("ID Endereco: %d\n", aux->id_endereco);
            printf("Produto: %s\n", aux->produto);
            printf("Tentativa de entrega de numero: %d\n", aux->tentativa);
            puts("Cliente");
            mostra_cliente(aux->cliente);
        }
    }
}