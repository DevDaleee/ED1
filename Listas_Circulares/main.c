#include <stdlib.h>
#include <stdio.h>
#include "listaCircular.h"

int main(){
	Conta *lista;

	lista = criarLista();
	lista = inserir(lista);
    lista = inserir(lista);
	lista = inserir(lista);
	imprimir(lista);
	return 0;
}