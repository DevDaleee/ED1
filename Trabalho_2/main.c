#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "clientes.h"


int main(){
    Cliente *lista;

    lista = criarListaClientes();
    lista = cadastrarCliente(lista);
    lista = cadastrarCliente(lista);
    lista = cadastrarCliente(lista);
    mostrarLista(lista);
    lista = buscarCliente(lista, 2);
    lista = remover(lista, 1);
    mostrarLista(lista);
}