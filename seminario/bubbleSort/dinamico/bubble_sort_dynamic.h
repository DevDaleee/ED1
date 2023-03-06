typedef struct array Array;

//Função para criar a lista
Array *criarLista();

//Função para inserir um valor na lista
Array *inserirFim(Array *lista); 

//Função liberar a memoria alocada
void liberarLista(Array *lista_ref);

/* Função que ordena uma lista de inteiros em ordem crescente usando bubble sort */
void bubbleSort(Array **lista);

/* Função que imprime uma lista de inteiros */
void print_lista(Array *lista );