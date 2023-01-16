#include <stdio.h>

int main(){

    void testeVariavel(int x);
    void testePonteiro(int *pX);
    int teste = 1;
    int *pTeste = &teste;
    
    testeVariavel(teste);
    testePonteiro(pTeste);

    printf("%i \n", *pTeste);

    return 0;
}

void testeVariavel(int x){
    ++x;
    printf("%i \n", x);
}

void testePonteiro (int *pX){
    ++*pX;
}