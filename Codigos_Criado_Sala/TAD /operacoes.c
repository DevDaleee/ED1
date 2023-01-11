#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

int main(){
    float x = 87, y = 65;
    printf("Soma %.2f \n", soma(x,y));
    printf("Subtrair %.2f\n", subtrair(x,y));
    printf("Multiplicar %.2f\n", multiplicar(x,y));
    printf("Dividir %.2f\n", dividir(x,y));
    return 0;
}