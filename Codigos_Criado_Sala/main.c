/*
Um usuário vai informar um série de número ele não sabe quantos serão. -1 será o criterio de parada. Ao final, devera informar todos os números 
que o usuário informou e métricas estatisticas como:
- média
- Desvio Padrão
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int media(int count, int *v){
    float soma = 0;
    for (int i = 0; i < count; i++){
        soma += v[i];
    }
    return soma/count;
}
/*
double variancia(double s[], int n){
    double soma = 0.0;
    double dev = 0.0;
    double med = media(n, s);
    int i = 0;

    for( i = 0; i < n; i++ ){
        dev = s[i] - med;
        soma += (dev * dev);
    }

    return soma / n;
}

double desvio_padrao (double s, int n){
    double v = variancia(s, n);
    return sqrt(v);
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
        printf(media(count, v));
    }
}