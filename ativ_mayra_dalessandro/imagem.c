#include <stdio.h>
#include <stdlib.h>

#include "imagem.h"


struct pixel{
    int valor, x, y;

};
struct imagem{
    Pixel *pixels;
    int largura, altura;
};
Imagem *criarImagem(int largura, int altura){
    int tam;
    tam = largura * altura;
    Imagem *img;
    img = (Imagem*) malloc(sizeof(Imagem));
    img->altura = altura;
    img->largura = largura;
    img->pixels = (Pixel*)malloc(altura * largura * sizeof(Pixel));

    return img;
}
void preencherImagem(Imagem *img){
    int i, j, k;   

    for(i = 0; i < img->altura; i++){  
        for(j = 0; j < img->largura; j++){
            k = i + img->largura + j;
            img->pixels[i * img->largura + j].valor = rand() % 256; 
            img->pixels[i * img->largura + j].x = j;
            img->pixels[i * img->largura + j].y = i;
        }
    }
}
void imprimirImagem(Imagem *img){
    int i, j;
    for(i=0;i < img->altura;i++){ 
        for(j = 0;j < img->largura;j++){
            printf("%d ", img->pixels[i * img->largura + j].valor);
        }
        printf("\n"); 
    }
}
void liberarImagem(Imagem *img){
    free(img->pixels); 
    free(img);
}
void setPixelValue(Imagem *img, int y, int x, int valor){
    img->pixels[y * img->largura + x].valor = valor;

}
void getPixelValue(Imagem *img, int x, int y){
    printf("%d", img->pixels[y * img->largura + x].valor); // vai retornar os valores preenchidos em setPixelValue
}
