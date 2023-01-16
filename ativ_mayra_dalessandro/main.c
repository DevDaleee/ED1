#include <stdio.h>
#include <stdlib.h>

#include "imagem.h"

int main(){
    Imagem *img;
    int x, y, z;

    img = criarImagem(5,5);
    preencherImagem(img);
    setPixelValue(img, 2, 2, 255);
    imprimirImagem(img);
    liberarImagem(img);

/** 1 - Comente -o que aconte com aslinhas 15 e 16
    img->pixels[10].valor = 255;
    printf("%d ", img->pixels[10].valor);

    Resposta: Como a estrutura não está definida no cabeçalho, 
    não temos acesso a ela da função main, por que ela está em imagem.c
    e quando executamos o main ele irá ler só a definição, e não
    conseguimos acessar o atributo apenas pela atribuição.


    2 - Comente o que acontece com as linhas 20 e 21
    setPixelValue(img,3,2,255);
    printf("valor da posicao 3,2 %d\n", getPixelValue(img,3,2))

    Resposta: Nesse caso deu certo pois ele está acessando os 
    atributos a partir de uma função que foi definida no mesmo 
    arquivo em foram definidas as structs.
**/
    return 0;
}