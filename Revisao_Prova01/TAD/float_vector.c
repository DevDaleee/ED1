#include "float_vector.h"
#include <stdio.h>
#include <stdlib.h>

struct float_vector{
    int capacity;   // Número máximo de elementos 
    int size;       //  Quantidade de elementos armazenados atualmente
    int *data;      // Vetor de Floats
};
/**
 * @brief Cria (aloca) um vetor de floats com uma dada capacidade
 * 
 * @param capacity Capacidade do vetor
 * @return FloatVector* um vetor de floats alocado/criado
*/
FloatVector *create(int capacity){
    FloatVector *vec = (FloatVector*) calloc(1, sizeof(FloatVector));
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (float*) calloc(capacity, sizeof(float));

    return vec;
}

void destroy(FloatVector **vec_ref){
    FloatVector *vec = *vec_ref;

    free(vec->data);
    free(vec);
    *vec_ref = NULL;
}

void append(FloatVector *vec, float val){
    if(vec->size == vec->capacity){
        fprintf(stderr, "ERROR in 'append' \n");
        fprintf(stderr, "Vector is full \n");
        exit(EXIT_FAILURE);
    }

    vec->data[vec->size] = val;
    vec->size++;
}

void print(const FloatVector *vec){
    puts("------------------------------");
    printf("Size: %d\n", vec->size);
    printf("Capacity: %d\n", vec->capacity);

    for (int i = 0; i < vec->size; i++){
        printf("[%d] = %d\n", i, vec->data[i]);
    }
    puts("---------------------------------\n");
    
}