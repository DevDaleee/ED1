#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct _linkLista {
    struct _node *inicio;
    struct _node *fim;
    int tamanho;
}LinkLista;

typedef struct _node {
    int valor;
    struct _node *prox;
    struct _node *ant;
}Node;

LinkLista* CriaLinkLista();
void InsereInicio(LinkLista* Link_Lista);
void InsereSort(LinkLista *link_lista);
void InsertionSort(LinkLista* Link_Lista);
void PrintLista(LinkLista* Link_Lista);


int main () {
    LinkLista *cabeca = CriaLinkLista();

    for (int i = 0; i < 10; i++) {
        InsereInicio(cabeca);
    }

    puts("Lista gerada!");
    PrintLista(cabeca);

    InsertionSort(cabeca);
    puts("Lista Ordenada!");
    PrintLista(cabeca);

    return 0;
}

LinkLista *CriaLinkLista() {
    LinkLista *link_lista = (LinkLista *) calloc(sizeof(LinkLista), 1);

    link_lista->inicio = NULL;
    link_lista->fim = NULL;
    int tamanho = 0;

    return link_lista;
}

void InsereInicio(LinkLista* Link_Lista) {

    Node *novo = (Node *) calloc(sizeof(Node), 1);
    novo->valor = rand() % 100;

    if (Link_Lista->inicio == NULL) {
        novo->prox = NULL;
        novo->ant = NULL;
        Link_Lista->inicio = novo;
        Link_Lista->fim = novo;
        Link_Lista->tamanho++;
    }
    else {
        novo->prox = Link_Lista->inicio;
        novo->ant = NULL;
        Link_Lista->inicio->ant = novo;
        Link_Lista->inicio = novo;
        Link_Lista->tamanho++;
    }
}

void InsereSort(LinkLista *link_lista) {
    Node *novo = (Node *) calloc(sizeof(Node), 1);
    novo->valor = rand() % 100;

    if (link_lista->inicio == NULL) {
        link_lista->inicio = novo;
        link_lista->fim = novo;
        link_lista->tamanho ++;
        novo->prox = NULL;
        novo->ant = NULL;
        return;
    }

    if (link_lista->inicio->valor >= novo->valor) {
        novo->prox = link_lista->inicio;
        link_lista->inicio->ant = novo;
        link_lista->inicio = novo;
        novo->ant = NULL;
        link_lista->tamanho++;
        return; 
    }

    Node* atual = link_lista->inicio;

    while (atual->prox != NULL && atual->prox->valor < novo->valor) {
        atual = atual->prox;
    }

    novo->prox = atual->prox;

    if (atual->prox != NULL) {
        atual->prox->ant = novo;
    }
    else {
        link_lista->fim = novo;
    }

    atual->prox = novo;
    novo->ant = atual;
    link_lista->tamanho++;
}

void InsertionSort(LinkLista* Link_Lista) {
    Node* atual = Link_Lista->inicio->prox;

    while (atual != NULL) {
        Node* chave = atual;
        int valor_chave = chave->valor;

        Node *anterior = chave->ant;

        while (anterior != NULL && anterior->valor > valor_chave) {
            anterior->prox->valor = anterior->valor;
            anterior = anterior->ant;
        }

        if (anterior == NULL) {
            Link_Lista->inicio->valor = valor_chave;
        }
        else {
            anterior->prox->valor = valor_chave;
        }

        atual = atual->prox;
    }
}

void PrintLista(LinkLista* Link_Lista) {
    Node *temp = Link_Lista->inicio;

    while (temp != NULL) {
        printf("%d ", temp->valor);
        temp = temp->prox;
    }
    puts("");
}