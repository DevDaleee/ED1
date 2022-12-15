#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int **preencherMatriz(int col, int lin){

    int **mat;
    mat = (int **) calloc(lin, sizeof(int*));

    for (int i = 0; i < lin; i++){
        mat[i] = (int*)malloc(sizeof(int) * col);
    }

    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            mat[lin][col] =  rand() % 256;
        }
    }

    return mat;
    
}
int *maiorMenorMedia(int col, int lin, int **mat){
    int maior, menor, count;
    
}
void montarDados(int lin, int col, int **m){
    for (int i = 0; i < lin; i++){
        for (int j = 0; j < col; j++){
            printf("%d", m[lin][col]);
        }
        printf("\n");
    }
}

void liberarMemoria(int **m, int t ){
    for (int i = 0; i < t; i++){
        free(m[i]);
    }
    free(m);
    
}
void montarMaiorMenorMedia(int *val, int t){

}

void main(){
    srand(time(NULL));
    int **m;
    m  = preencherMatriz(10,5);
    //liberarMemoria(m, NULL);
}