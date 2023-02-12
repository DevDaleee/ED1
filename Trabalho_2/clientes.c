#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clientes.h"

typedef struct _listaClientes {
    Cliente *inicio;
    Cliente *fim;
}ListaClientes;

typedef struct _enderecoCli{
    int id_endereco;
    char rua[50];
    char bairro[50];
    int num_casa;
}EnderecoCli;

typedef struct _cliente {
    int id_cli;
    char nome_cli[50];
    EnderecoCli enderecoCli;
    Cliente *prox;
}Cliente;

// Funções de criaçãoe e inserção
ListaClientes* cria_lista_Clientes() {
    ListaClientes *listaClientes = (ListaClientes *) calloc(sizeof(ListaClientes), 1);

    listaClientes->inicio = NULL;
    listaClientes->fim = NULL;
    
    return listaClientes;
}

void adiciona_cliente(ListaClientes *listaClientes) {
    Cliente *novo = (Cliente *) calloc(sizeof(Cliente), 1);

    // Leitura e atribuição dos dados do clien

    novo->id_cli = gera_id_cliente(listaClientes);
    printf("%d\n", novo->id_cli);
    printf("Nome: ");
    setbuf(stdin, NULL);
    scanf("%s", novo->nome_cli);
    
    puts("--Endereco--");
    novo->enderecoCli.id_endereco = novo->id_cli;
    printf("Rua: ");
    setbuf(stdin, NULL);
    scanf("%s", novo->enderecoCli.rua);
    printf("Bairro: ");
    setbuf(stdin, NULL);
    scanf("%s", novo->enderecoCli.bairro);
    printf("Numero da casa: ");
    scanf("%d", &novo->enderecoCli.num_casa);


    if (verifica_listaClientes(listaClientes)) {
        novo->prox = NULL;
        listaClientes->inicio = novo;
        listaClientes->fim = novo;
    }
    else {
        novo->prox = NULL;
        listaClientes->fim->prox = novo;
        listaClientes->fim = novo;
    }

    puts("Cliente adicionado com sucesso!");
}

// Funções de impressão
void mostra_clientes(ListaClientes *listaClientes) {
    if (verifica_listaClientes(listaClientes)) {
        puts("Lista de clientes esta vazia!");
    }
    else {
        Cliente *aux = listaClientes->inicio;

        while (aux != NULL) {
            puts("  LISTA DE CLIENTES  ");

            printf("ID Cliente: %d\n", aux->id_cli);
            printf("Nome: %s\n", aux->nome_cli);
            puts("--Endereco--");
            printf("Rua: %s\n", aux->enderecoCli.rua);
            printf("Bairro: %s\n", aux->enderecoCli.bairro);
            printf("Numero: %d\n", aux->enderecoCli.num_casa);

            aux = aux->prox;
        }
    }
}

void mostra_cliente(Cliente *cliente) {
    printf("Nome: %s\n", cliente->nome_cli);
    printf("Rua: %s\n", cliente->enderecoCli.rua);
    printf("Bairro: %s\n", cliente->enderecoCli.bairro);
    printf("Num da casa: %d\n", cliente->enderecoCli.num_casa);
}

// Funções de verificação
int verifica_listaClientes(ListaClientes *listaClientes) {  
    // verifica se lista de clientes está vazia
    if (listaClientes->inicio == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int busca_cliente(ListaClientes *listaClientes, int id_cli) {
    if (verifica_listaClientes(listaClientes)) {
        return 0;
    }
    else {
        Cliente *aux = listaClientes->inicio;

        while (aux != NULL) {
            if (id_cli == aux->id_cli) {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

int verifica_endereco_cliente(ListaClientes *listaClientes, int id_endereco) {
    if (verifica_listaClientes(listaClientes)) {
        return 0;
    }
    else {
        Cliente *aux = listaClientes->inicio;

        while (aux != NULL) {
            if (aux->enderecoCli.id_endereco == id_endereco) {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}

// Funções para remoção e liberação
void remove_cliente(ListaClientes *listaClientes) {
    if (verifica_listaClientes(listaClientes)) {
        puts("Lista de clientes esta vazia!");
    }
    else {
        int id_cli;
        printf("ID do cliente a ser removido: ");
        scanf("%d", &id_cli);

        // Se o ID existir na lista de clientes, eu removo
        if (busca_cliente(listaClientes, id_cli)) {
            Cliente *aux = listaClientes->inicio;
            Cliente *aux2 = NULL;

            while (aux->id_cli != id_cli) {
                aux2 = aux;
                aux = aux->prox;
            }

            // Ultimo elemento da lista
            if (aux == listaClientes->fim) {
                aux2->prox = aux->prox;
                listaClientes->fim = aux2;
                free(aux);
                aux = NULL;
            }
            // Primeiro elemento da lista
            else if (listaClientes->inicio == aux) {
                listaClientes->inicio = aux->prox;
                free(aux);
                aux = NULL;
            }
            // Qualquer outro elemento da lista
            else {
                aux2->prox = aux->prox;
                free(aux);
                aux = NULL;
            }
            puts("Removido com sucesso!!!");
        }
        // Se não existir mostro que não existe o cliente
        else {
            puts("Cliente não existe!");
        }
    }
}

ListaClientes* libera_listaClientes(ListaClientes *listaClientes) {
    if (verifica_listaClientes(listaClientes)) {
        puts("Lista vazia!");
    }
    else {
        Cliente *aux = listaClientes->inicio;
        Cliente *aux2 = NULL;

        while (aux != NULL) {
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
            aux2 = NULL;
        }
        listaClientes->inicio = NULL;
        listaClientes->fim = NULL;
        free(listaClientes);
        listaClientes = NULL;
        return listaClientes;
    }
}

// Funções acessórias
int gera_id_cliente(ListaClientes *listaClientes) {
    int id_cli;

    // Gero ID do cliente enquanto existir um igual na lista de clientes, até que gere
    // um que não exista
    do
    {
        id_cli = rand() % 10000;
    } while (busca_cliente(listaClientes, id_cli) == 1);
    
    return id_cli;
}

Cliente* retorna_Cliente(ListaClientes *listaClientes, int id_cli) {
    Cliente *aux = listaClientes->inicio;

    while (aux != NULL) {
        if (aux->id_cli == id_cli) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}