#include <stdio.h>
#include <stdlib.h>


int main(){
    // Abre um espaco na memoria de 4 bytes cheios com lixo de memoria;
    int *p = (int *) malloc(sizeof(int));
    // Abre um espaco na memoria de 4 bytes vazios;
    int *q = (int *) calloc(5, sizeof(int));
    // Realoca um espaco na memoria, pode aumentar ou diminuir;
    int *p = (int *) realloc(p, 8); 
    
    free(p);
    free(q);

    return 0;
}