#include <stdio.h>
#include <stdlib.h>
#include "str.h"

void lerStr(){

}

int mystrlen(char *str){
    int countador = 0;

    while(*str != '\0'){
        countador++;
        *str++;
    }
    return countador;
}

int mystrcmp(char *str1, char *str2){
    if (mystrlen(str1) != mystrlen(str2)){
        if(mystrlen(str1) < mystrlen(str2)){
            return "A maior string é", str2;
        }
        if(mystrlen(str1) > mystrlen(str2)){
            return "A mairo string é", str1;
        }
    }else{
        return "Elas tem o mesmo tamanho";
    }
}

char *mystrcat(char *str1, char *str2){
    if ((str1 == NULL) && (str2 == NULL)){
        return NULL;
    }
    char *start = str1;
    while (*start != '\0'){
        start++;
    }
    while(str2 != '\0'){
        *start++ = str2++;
    }
    *start = '\0';

    return start;
}

int tamanhoStr(char *str){
    return mystrlen(str);
}
int comparar(char *str1, char *str2){
    return mystrcmp(str1, str2);
}
int concatenar(char *str1, char *str2){
    return mystrcat(str1, str2);
}

//void liberar(char *str);
