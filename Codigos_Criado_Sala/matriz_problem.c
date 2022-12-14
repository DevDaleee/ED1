#include <stdio.h>

void  main(){
    int vet[] = {10, 20, 30, 40} ;

    for (int i = 0; i < 4; i++){
        printf("%d\n", vet[(i / 2) + i % 2]);
    }
}
