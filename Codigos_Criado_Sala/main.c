/*
Um usuário vai informar um série de número ele não sabe quantos serão. -1 será o criterio de parada. Ao final, devera informar todos os números 
que o usuário informou e métricas estatisticas como:
- média
- Desvio Padrão
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
float media(int *v, int count){
    float soma = 0, res;
    for (int i = 0; i < count; i++){
        soma += v[i];
    }
    res = soma/count;
    return res;
}

int variancia(int *v, int count){
    float soma = 0.0;
    float dev = 0.0;
    float med = media(count, v);
    int i = 0;

    for( i = 0; i < count; i++ ){
        dev = v[i] - med;
        soma += (dev * dev);
    }

    return soma / count;
}

int desvio_padrao (int *v, int count){
    float res = variancia(v, count);
    return sqrt(res);
}
*/
int main(){
    int *v, num = 0, total = 0, count = 0;
    
    v = (int *) malloc(1* sizeof(int));

    for (int i = 0; num != -1; i++){
        scanf("%d", &num);
        count++;
        if(num == -1){
            break;
        }else{
            v = (int *) realloc(v, sizeof(int) * count);
            v[i] = num;
        }
    }
    for (int i = 0; i < count; i++){
        printf(v[i]);
    }
    
    //printf("Media  = %.2f \n",media(v, count));
    //printf("Variancia = %f \n", variancia(v, count));
    //printf("Desvio Padrão = %lf\n", desvio_padrao(v, count));
    free(v);
}