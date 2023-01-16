#include <stdio.h>

int main(void){

    int x = 10;
    double y = 20.50;
    char z = 'a';

    int *pX = &x;
    double *pY = &y;
    char *pZ = &z;

    int *resultado;
    resultado = &z;

    printf("Valor x = %d \n", *resultado);

    return 0;
}