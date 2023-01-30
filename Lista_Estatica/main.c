#include "listaestatica.h"
#include <stdio.h>
#include <stdlib.h>


int main(){
	int pos = 0, tam = 10;
	Conta *lista = criarListaContasEstatica(tam);
	inserirElemento(lista, pos++, tam);
	inserirElemento(lista, pos++, tam);
	mostrarElemento(lista);
	mostrarTodosElementos(lista, pos);
	return 0;
}