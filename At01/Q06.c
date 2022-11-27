#include <stdio.h>
#include <string.h>
#define STR_HISTOGRAM_MAX_TAM   (256)

void strhist( const char * str, int hist[ STR_HISTOGRAM_MAX_TAM ] ){
    memset( hist, 0, sizeof(int) * STR_HISTOGRAM_MAX_TAM );
    while( *str )
        hist[ *str++ ]++;
}

void exibir_histograma( int hist[STR_HISTOGRAM_MAX_TAM], int min ){
    int i = 0;
    int j = 0;
    for( i = 0; i < STR_HISTOGRAM_MAX_TAM; i++ ){
        if( (isprint(i)) && (hist[i] >= min) ){
            printf("[%c]: %d ", i, hist[i] );
            for( j = 0; j < hist[i]; j++ )
                printf("*");
            printf("\n");
        }
    }
}

int main(int arg, char ** argv){
    char string[] = "o exercicio e facil";
    int h[ STR_HISTOGRAM_MAX_TAM ];
    strhist( string, h );
    exibir_histograma( h, 2 );
    return 0;
}