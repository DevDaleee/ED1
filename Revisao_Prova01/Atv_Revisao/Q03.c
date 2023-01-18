/*
3) Construa um programa (main) que aloque em tempo de execução (dinamicamente)
uma matriz de ordem m x n (linha por coluna), usando 1+m chamadas a função
malloc. 
Agora, aproveite este programa para construir uma função que recebendo os
parametros m e n aloque uma matriz de ordem m x n e retorne um ponteiro para esta
matriz alocada. Crie ainda uma função para liberar a área de memória alocada pela
matriz. Finalmente, crie um novo programa (main) que teste/use as duas funções
criadas acima. 
*/

#include <stdio.h>
#include <stdlib.h>


int **preencherMatriz(int lin, int col){
	int **mat;
	mat = (int **) calloc(lin, sizeof(int*));
	for (int i = 0; i < lin; ++i){
			mat[i] = (int *) malloc(sizeof(int) * col);
	}	
	return mat;
}

void mostrarDados(int lin, int col, int **m){
	for (int i = 0; i < lin; ++i){
		for (int j = 0; j < col; ++j){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}

void liberarMemoria(int **m, int t){
	for (int i = 0; i < t; ++i){
		free(m[i]);
	}
	free(m);
}

int main(){
    int **m;
    m = preencherMatriz(5, 5);
    mostrarDados(5, 5, m);
    liberarMemoria(m, 5);
}