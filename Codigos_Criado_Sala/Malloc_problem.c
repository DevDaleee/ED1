#include <stdlib.h>
#include <stdio.h>

int *obterdados() {
	int vet[10];
	for (int i = 0; i < 10; i++) 
		vet[i] = i*i;
	return vet;
}

int *obterdados2(){
	int *vet;
	vet = (int *) malloc(sizeof(int)*10);
	for (int i = 0; i < 10; i++)
		vet[i] = i * i;
	return vet;
}

int main() {
	int *v, *v1;
	//v = obterdados();  Não funcionará pois os dados serão perdidos por falta de alocação dinamica, logo os dados só existem na função
	v1 = obterdados2();
	for(int i = 0; i < 10; i++)
		printf("%d - %d", v[i], v1[i]);
	free(v1);
	return 0;
}