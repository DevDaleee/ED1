#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clientes.h"
#include "entregas.h"
#include "transportadora.h"
    
typedef struct _listaClientes {
    Cliente *start;
    Cliente *end;
}ListaClientes;

typedef struct _endCliente{
    int id_endereco;
    char rua[60];
    char bairro[60];
    int num; 
}EndCliente;

typedef struct _cliente {
    int id_cliente;
    char nome_cliente[50];
    EndCliente endCliente;
    Cliente *prox;
}Cliente;

ListaClientes* criarListaClientes() {
    ListaClientes *listaClientes = (ListaClientes *) calloc(sizeof(ListaClientes), 1);

    listaClientes->start = NULL;
    listaClientes->end = NULL;
    
    return listaClientes;
}

void adicionar_cliente(ListaClientes *listaClientes) {
    Cliente *new = (Cliente *) calloc(sizeof(Cliente), 1);

    new->id_cliente = gerar_id_cliente(listaClientes);

    printf("%d\n", new->id_cliente);
    printf("Nome: ");
    setbuf(stdin, NULL);
    scanf("%s", new->nome_cliente);
    
    puts("____ENDERECO____");
    new->endCliente.id_endereco = new->id_cliente;

    printf("RUA: ");
    setbuf(stdin, NULL);
    scanf("%s", new->endCliente.rua);
    printf("BAIRRO: ");
    setbuf(stdin, NULL);
    scanf("%s", new->endCliente.bairro);
    printf("Num da casa: ");
    scanf("%d", &new->endCliente.num);

    if(verificar_clientes(listaClientes)) {
        new->prox = NULL;
        listaClientes->start = new;
        listaClientes->end = new;
    }
    else{
        new->prox = NULL;
        listaClientes->end->prox = new;
        listaClientes->end = new;
    }
    puts("O cliente foi adicionado!");
}
void exibir_clientes(ListaClientes *listaClientes){

    if(verificar_clientes(listaClientes)) {
        puts("Nao ha clientes cadastrados!");
    }
    else{
        Cliente *aux = listaClientes->start;

        while (aux != NULL) {
            puts("____LISTA DE CLIENTES____");

            printf("id do cliente: %d\n", aux->id_cliente);
            printf("Nome: %s\n", aux->nome_cliente);
            puts("____Endereco____");
            printf("RUA: %s\n", aux->endCliente.rua);
            printf("BAIRRO: %s\n", aux->endCliente.bairro);
            printf("NUMERO: %d\n", aux->endCliente.num);

            aux = aux->prox;
        }
    }
}
void exibir_cliente(Cliente *cliente) {
    printf("NOME: %s\n", cliente->nome_cliente);
    printf("RUA: %s\n", cliente->endCliente.rua);
    printf("BAIRRO: %s\n", cliente->endCliente.bairro);
    printf("Num da Casa: %d\n", cliente->endCliente.num);
}
int verificar_clientes(ListaClientes *listaClientes){  

    if (listaClientes->start == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}
int buscar_cliente(ListaClientes *listaClientes, int id_cliente) {
    if (verificar_clientes(listaClientes)){
        return 0;
    }
    else{
        Cliente *aux = listaClientes->start;

        while (aux != NULL) {
            if (id_cliente == aux->id_cliente) {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}
int verificar_endereco(ListaClientes *listaClientes, int id_endereco) {
    if (verificar_clientes(listaClientes)) {
        return 0;
    }
    else {
        Cliente *aux = listaClientes->start;

        while (aux != NULL) {
            if (aux->endCliente.id_endereco == id_endereco) {
                return 1;
            }
            aux = aux->prox;
        }
        return 0;
    }
}
void remover_cliente(ListaClientes *listaClientes){
    if(verificar_clientes(listaClientes)) {
        puts("A lista de clientes esta vazia!");
    }
    else{
        int id_cliente;
        printf("id do cliente que deseja remover: ");
        scanf("%d", &id_cliente);

        if(buscar_cliente(listaClientes, id_cliente)){
            Cliente *aux = listaClientes->start;
            Cliente *aux2 = NULL;

            while(aux->id_cliente != id_cliente) {
                aux2 = aux;
                aux = aux->prox;
            }
            if(aux == listaClientes->end) {
                aux2->prox = aux->prox;
                listaClientes->end = aux2;
                free(aux);
                aux = NULL;
            }
            else if(listaClientes->start == aux) {
                listaClientes->start = aux->prox;
                free(aux);
                aux = NULL;
            }
            else{
                aux2->prox = aux->prox;
                free(aux);
                aux = NULL;
            }
            puts("Cliente removido!");
        }
        else {
            puts("Este cliente nao existe!");
        }
    }
}
ListaClientes* liberar_clientes(ListaClientes *listaClientes) {
    if (verificar_clientes(listaClientes)){
        puts("A lista esta vazia!");
    }
    else {
        Cliente *aux = listaClientes->start;
        Cliente *aux2 = NULL;

        while (aux != NULL) {
            aux2 = aux;
            aux = aux->prox;
            free(aux2);
            aux2 = NULL;
        }
        listaClientes->start = NULL;
        listaClientes->end = NULL;
        free(listaClientes);
        listaClientes = NULL;
    }
}
int gerar_id_cliente(ListaClientes *listaClientes) {
    int id_cliente;

    do{
        id_cliente = rand() % 10000;
    } while (buscar_cliente(listaClientes, id_cliente) == 1);
    
    return id_cliente;
}
Cliente* retornar_Cliente(ListaClientes *listaClientes, int id_cliente) {
    Cliente *aux = listaClientes->start;

    while (aux != NULL) {
        if (aux->id_cliente == id_cliente) {
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}