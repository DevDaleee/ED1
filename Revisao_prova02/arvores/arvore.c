#include <stdio.h>
#include <stdlib.h>

typedef struct _no {
    int conteudo;
    struct _no *esquerdo, *direito;
} No;

typedef struct _ArvB {
    No *raiz;
}ArvB;

void inserirEsquerda(No *no, int valor);
void inserirDireita(No *no, int valor);
void inserir(ArvB *arv, int valor);
int buscar(No *raiz, int chave);
void imprimir(No *raiz);
No* remover(No* raiz, int chave);

int main() {
    int op, valor;
    ArvB arv;
    arv.raiz = NULL;

    do
    {
        printf("\n0 - sair\n1 - inserir\n2 - imprimir\n3 - Buscar\n4 - Remover\n");
        scanf("%d", &op);

        switch (op)
        {
        case 0:
            printf("\nsaindo...\n");
            break;
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir(&arv, valor);
            break;
        case 2:
            puts("Impressao da arvore binaria:");
            imprimir(arv.raiz);
            break;
        case 3:
            printf("Qual valor deseja buscar  ?");
            scanf("%d", &valor);
            printf("Resultado da busca: %d\n", buscar(arv.raiz, valor));
            break;
        case 4:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            arv.raiz = remover(arv.raiz, valor);
            break;
        default:
            puts("Opcao invalida...");
        }
    } while (op != 0);
        

    return 0;
}

void inserirEsquerda(No *no, int valor) {
    if (no->esquerdo == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        no->esquerdo = novo;   
    }
    else {
        if (valor < no->esquerdo->conteudo) {
            inserirEsquerda(no->esquerdo, valor);
        }
        if (valor > no->esquerdo->conteudo) {
            inserirDireita(no->esquerdo, valor);
        }
    }
}

void inserirDireita(No *no, int valor) {
    if (no->direito == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        no->direito = novo;
    }    
    else {
        if (valor > no->direito->conteudo) {
            inserirDireita(no->direito, valor);
        }
        if (valor < no->direito->conteudo) {
            inserirEsquerda(no->direito, valor);
        }
    }
}

void inserir(ArvB *arv, int valor) {
    if (arv->raiz == NULL) {
        No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerdo = NULL;
        novo->direito = NULL;
        arv->raiz = novo;
    }
    else {
        if (valor < arv->raiz->conteudo) {
            inserirEsquerda(arv->raiz, valor);
        }
        if (valor > arv->raiz->conteudo) {
            inserirDireita(arv->raiz, valor);
        }
    }
}

int buscar(No *raiz, int chave) {
    if (raiz == NULL) {
        return 0;
    }
    else {
        if (raiz->conteudo == chave) {
            return raiz->conteudo;
        }
        else {
            if (chave < raiz->conteudo) {
                return buscar(raiz->esquerdo, chave);
            }
            else {
                return buscar(raiz->direito, chave);
            }
        }
    }
}

void imprimir(No *raiz) {
    if (raiz != NULL) {
       imprimir(raiz->esquerdo);
       printf("%d ", raiz->conteudo);
       imprimir(raiz->direito); 
    }
}

No* remover(No* raiz, int chave) {
    if (raiz == NULL) {
        puts("Valor nao encontrado!!!");
        return NULL;
    }
    else {
        if (raiz->conteudo == chave) {
            //Nó folha
            if (raiz->esquerdo == NULL && raiz->direito == NULL) {
                free(raiz);
                return NULL;
            }
            else {
                // Nó com 1 filho
                if (raiz->esquerdo == NULL || raiz->direito == NULL) {
                    No *aux;
                    if (raiz->esquerdo != NULL) {
                        aux = raiz->esquerdo;
                    }
                    else {
                        aux = raiz->direito;
                    }
                    free(raiz);
                    return aux;
                }
                // Nó com 2 filhos
                else {
                    No *aux = raiz->esquerdo;
                    while (aux->direito != NULL) {
                        aux = aux->direito;
                    }
                    raiz->conteudo = aux->conteudo;
                    aux->conteudo = chave;
                    raiz->esquerdo = remover(raiz->esquerdo, chave);
                    return raiz;
                }
            }
        }
        else {
            if (chave < raiz->conteudo) {
                raiz->esquerdo = remover(raiz->esquerdo, chave);
            }
            else {
                raiz->direito = remover(raiz->direito, chave);
            }
            return raiz;
        }
    }
}