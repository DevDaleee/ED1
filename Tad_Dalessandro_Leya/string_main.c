#include <stdio.h>
#include <stdlib.h>
#include "string.h"


int main (){
    char *str1, *str2;
  
    str1 = ler();
    str2 = ler();

    printf("frase 1: %s\n", str1);
    printf("frase 2: %s\n", str2);

    printf("frase concatenada: %s\n", concatenar(str1, str2));

    printf("tamanho string 1: %d\n", tamanho(str1));
    printf("tamanho string 2: %d\n", tamanho(str2));

    printf("Se for 0 = diferente e 1 = igual: %d\n", iguais(str1, str2));
    return 0;
}