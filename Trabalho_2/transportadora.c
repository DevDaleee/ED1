#include <stdio.h>
#include <stdlib.h>
#include "transportadora.h"

typedef struct _transportadora {
    ListaClientes *listaClientes;
    Entrega *FilaEntregas;
    NewTry *PilhaEntregasNot;
    FifoDevol *FilaDevolucaoProd;
    float score1;
    float score2;
    float score3;
    float score4;
    float scoreTot; 
} Transportadora;

    Transportadora* cria_transportadora() {
    Transportadora *transp = (Transportadora *) calloc(sizeof(Transportadora), 1);

    transp->listaClientes = cria_lista_Clientes();
    transp->FilaEntregas = cria_FilaEntregas();
    transp->PilhaEntregasNot = cria_PilhaEntregaNot();
    transp->FilaDevolucaoProd = cria_FilaDevolucaoProd();

    return transp;
}

void cadastrar_cliente(Transportadora *transp) {
    adiciona_cliente(transp->listaClientes);
}

void cadastrar_entrega(Transportadora *transp) {
    int id_endereco;
    char produto[20];
    puts("--Entrega--");
    printf("Produto: ");
    setbuf(stdin, NULL);
    scanf("%s", produto);

    printf("ID do endereco de entrega: ");
    scanf("%d", &id_endereco);

    if (verifica_endereco(transp->listaClientes, id_endereco)) {
        Cliente *cliente = retorna_Cliente(transp->listaClientes, id_endereco);
        adiciona_entrega(transp->FilaEntregas, id_endereco, &produto, cliente);
        puts("Entrega cadastrada!");
    }
    else {
        puts("Endereco invalido, nao consta na lista de clientes!");
    }
}

void efetuar_entrega(Transportadora *transp) {
    int StatusPresenca = -1;

    mostrar_entrega(transp->FilaEntregas);
    
    do
    {
        printf("Digite o status da entrega [1] - Efetuada [0] - Cliente ausente");
        scanf("%d", &StatusPresenca);
    } while (StatusPresenca > 1 || StatusPresenca < 0);

    if (StatusPresenca == 1){
        if (verifica_EntregasIguais(transp->FilaEntregas)) {
            remove_FilaEntrega(transp->FilaEntregas);
            remove_FilaEntrega(transp->FilaEntregas);
        }
        else {
            remove_FilaEntrega(transp->FilaEntregas);
        }
        transp->score1 += 5;
        transp->scoreTot += transp->score1;
    }
    else if(StatusPresenca == 0) {
        if (verifica_EntregasIguais(transp->FilaEntregas)) {
            remova_Fila_AddPilha(transp->FilaEntregas, transp->PilhaEntregasNot);
            remova_Fila_AddPilha(transp->FilaEntregas, transp->PilhaEntregasNot);      
        }
        else {
            remova_Fila_AddPilha(transp->FilaEntregas, transp->PilhaEntregasNot);
        }
    }

}

void cadastrar_PilhaEntregasNot(Transportadora *transp) {
    int StatusPresenca = -1;
    puts("Nova tentativa de entrega do produto");

    mostraEntregaNot(transp->PilhaEntregasNot);

    do
    {
        printf("Digite o status da entrega [1] - Efetuada [0] - Cliente ausente");
        scanf("%d", &StatusPresenca);
    } while (StatusPresenca > 1 || StatusPresenca < 0);

    if (StatusPresenca == 1) {
        if (verifica_pilhaEntregaNot(transp->PilhaEntregasNot)) {
            remove_PilhaEntregaNot(transp->PilhaEntregasNot);
            remove_PilhaEntregaNot(transp->PilhaEntregasNot);
        } else {
            remove_PilhaEntregaNot(transp->PilhaEntregasNot);
        } if (TentativaEntrega(transp->PilhaEntregasNot) == 4) {
            transp->score3 += 2;
            transp->scoreTot += transp->score3;
        } else {
            transp->score2 += 3;
            transp->scoreTot += transp->score2;
        }
    } else {
        int tentativa = TentativaEntrega(transp->PilhaEntregasNot);

        if (tentativa == 3) {
            puts("Entrega nao sucedida! Ainda continuara a tentativa de entrega!");
        }
        else {
            puts("Limite de tentativas de entrega excedido! O produto sera adicionado a fila de devolucao.");
            remove_Pilha_AddFilaDevol(transp->PilhaEntregasNot, transp->FilaDevolucaoProd);
            transp->score4 += 0.8;
            transp->scoreTot += transp->score4;
        }
    }
}
int verifica_endereco(ListaClientes *listaClientes, int id_endereco) {
    return verifica_endereco_cliente(listaClientes, id_endereco);
}
void mostrar_scoreTransp(Transportadora *transp) {
    puts("--- SCORE TRANSPORTADORA ---");
    printf("N° de pontos - Entregas na 1° tentativa: %d\n", transp->score1);
    printf("N° de pontos - Entregas na 2° tentativa: %d\n", transp->score2);
    printf("N° de pontos - Entregas na 3° tentativa: %d\n", transp->score3);
    printf("N° de pontos - Entregas para fila de devolucao: %d\n", transp->score4);
    printf("Score total: %d\n", transp->scoreTot);
}