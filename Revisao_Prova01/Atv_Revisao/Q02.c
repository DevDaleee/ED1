/*
2) Faça uma função que receba um valor n e crie dinamicamente um vetor de n elementos e retorne um ponteiro. 
Crie uma função que receba um ponteiro para um vetor e um valor n e imprima os n elementos desse vetor. 
Construa também uma função que receba um ponteiro para um vetor e libere esta área de memória. 
Ao final, crie uma função principal que leia um valor n e chame a função criada acima. Depois,
a função principal deve ler os n elementos desse vetor. Então, a função principal deve
chamar a função de impressão dos n elementos do vetor criado e, finalmente, liberar a
memória alocada através da função criada para liberação.
*/

int *alocar(int n){
    int *vetor;
    vetor = (int *) malloc(n * sizeof(int));
    return vetor;
}
void preencher(int n, int *vetor){
    for (int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
}

void imprimir(int n, int *vetor){
    for (int i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

void liberarMemoria(int *vetor){
    free(vetor);
}

int main(){
    int n, *vetor;
    scanf("%d", &n);

    vetor = alocar(n);
    preencher(n, vetor);
    imprimir(n, vetor);
    liberarMemoria(vetor);

    return 0;
}
