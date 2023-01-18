/*
1) Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos
e passe esse vetor para uma função que vai ler os elementos desse vetor. Depois, no
programa principal, o vetor preenchido deve ser impresso. Além disso, antes de
finalizar o programa, deve-se liberar a área de memória alocada. 
*/

#include <stdio.h>
#include <stdlib.h>


int main(){
    int tam;
    int *vetor;
    scanf("%d", &tam);
    vetor = (int *) malloc(tam * sizeof(int));
    preenche(vetor, tam);
    print(vetor, tam);
    
    free(vetor);
    
    return 0;
}

void preenche(int *vetor, int tam){
    int valor;
    for (int i = 0; i < tam; i++){
        scanf("%d", &valor);
        vetor[i] = valor;
    }
}

void print(int *vetor, int tam){
    for (int i = 0; i < tam; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}