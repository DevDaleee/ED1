
#include <stdio.h>
#include <stdlib.h>



int **preencherMatriz(int lin, int col){
	int **mat;
	mat = (int **) calloc(lin, sizeof(int*));
	for (int i = 0; i < lin; ++i)
		{
			mat[i] = (int *) malloc(sizeof(int) * col);
		}	

	for (int i = 0; i < lin; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			mat[i][j] = rand() % 256;
			//scanf("%d", &mat[i][j]);
		}
	}
	return mat;
}

void mostrarDados(int lin, int col, int **m){
	for (int i = 0; i < lin; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
}
void liberarMemoria(int **m, int t){
	for (int i = 0; i < t; ++i)
	{
		free(m[i]);
	}
	free(m);
}

int *menorMaiorMedia(int l, int c, int **mat){
	int *vet;
	vet = (int *) malloc(sizeof(int) * 3);
	vet[0] = mat[0][0];
	vet[1] = mat[0][0];
	vet[2] = 0;
	for (int i = 0; i < l; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (mat[i][j] < vet[0])
			{
				vet[0] = mat[i][j];
			}
			if (mat[i][j] > vet[1])
			{
				vet[1] = mat[i][j];
			}
			vet[2] += mat[i][j];
		}
	}
	vet[2] /= (l * c);
	return vet;
}
void exibirVetor(int *vet){
	printf("Menor: %d\n", vet[0]);
	printf("Maior: %d\n", vet[1]);
	printf("Media: %d\n", vet[2]);
}

int main(){
	int **m;
	m = preencherMatriz(10, 5);
	mostrarDados(10, 5, m);
	exibirVetor(menorMaiorMedia(10, 5, m));
	liberarMemoria(m, 10);
	return 0;
}