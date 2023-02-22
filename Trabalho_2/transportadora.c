#include <stdio.h>
#include <stdlib.h>
#include "transportadora.h"
#include "clientes.h"
#include "entregas.h"

typedef struct _transportadora {
    ListaClientes *listaClientes;
    Entrega *FilaEntregas;
    NewTry *PilhaTentativas;
    FifoDevol *FilaDevolucao;
    float score1;
    float score2;
    float score3;
    float score4;
    float scoreTot; 
} Transportadora;

Transportadora* cria_transportadora() {
    Transportadora *transp = (Transportadora *) calloc(sizeof(Transportadora), 1);

    transp->listaClientes = criarListaClientes();
    transp->FilaEntregas = criaFila();
    transp->PilhaTentativas = criaPilhaNewtry();
    transp->FilaDevolucao = cria_FilaDevolucaoProd();

    return transp;
}

void cadastrar_cliente(Transportadora *transp) {
    adicionar_cliente(transp->listaClientes);
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
        Cliente *cliente = retornar_Cliente(transp->listaClientes, id_endereco);
        addEntrega(transp->FilaEntregas, id_endereco, produto, cliente);
        puts("Entrega cadastrada!");
    }
    else {
        puts("Endereco invalido, nao consta na lista de clientes!");
    }
}

void efetuar_entrega(Transportadora *transp) {
    int StatusPresenca = -1;

    imprimirEntregas(transp->FilaEntregas);
    
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
            remova_Fila_AddPilha(transp->FilaEntregas, transp->PilhaTentativas);
            remova_Fila_AddPilha(transp->FilaEntregas, transp->PilhaTentativas);      
        }
        else {
            remova_Fila_AddPilha(transp->FilaEntregas, transp->PilhaTentativas);
        }
    }

}

void cadastrar_PilhaTentativasEntrega(Transportadora *transp) {
    int StatusPresenca = -1;
    puts("Nova tentativa de entrega do produto");

    ImprimirTentativas(transp->PilhaTentativas);

    do
    {
        printf("Digite o status da entrega [1] - Efetuada [0] - Cliente ausente");
        scanf("%d", &StatusPresenca);
    } while (StatusPresenca > 1 || StatusPresenca < 0);

    if (StatusPresenca == 1) {
        if (verifica_pilhaNewTry(transp->PilhaTentativas)) {
            remove_PilhaNewTry(transp->PilhaTentativas);
            remove_PilhaNewTry(transp->PilhaTentativas);
        } else {
            remove_PilhaNewTry(transp->PilhaTentativas);
        } if (TentativaEntrega(transp->PilhaTentativas) == 4) {
            transp->score3 += 2;
            transp->scoreTot += transp->score3;
        } else {
            transp->score2 += 3;
            transp->scoreTot += transp->score2;
        }
    } else {
        int tentativa = TentativaEntrega(transp->PilhaTentativas);

        if (tentativa == 3) {
            puts("Entrega nao sucedida! Ainda continuara a tentativa de entrega!");
        }
        else {
            puts("Limite de tentativas de entrega excedido! O produto sera adicionado a fila de devolucao.");
            remove_Pilha_AddFilaDevol(transp->PilhaTentativas, transp->FilaDevolucao);
            transp->score4 += 0.8;
            transp->scoreTot += transp->score4;
        }
    }
}
int verifica_endereco(ListaClientes *listaClientes, int id_endereco) {
    return verificar_endereco(listaClientes, id_endereco);
}
void mostrar_scoreTransp(Transportadora *transp) {
    puts("Pontuação Da Transportadora");
    printf("N° de pontos - Entregas na 1° tentativa: %.1f\n", transp->score1);
    printf("N° de pontos - Entregas na 2° tentativa: %.1f\n", transp->score2);
    printf("N° de pontos - Entregas na 3° tentativa: %.1f\n", transp->score3);
    printf("N° de pontos - Entregas para fila de devolucao: %.1f\n", transp->score4);
    printf("Score total: %.1f\n", transp->scoreTot);
}

Transportadora *libera_MemTransportadora(Transportadora *transp) { // Libera memória da struct transportadora e seus correspondentes
    liberar_clientes(transp->listaClientes);
    liberar_FilaEntregas(transp->FilaEntregas);
    liberar_PilhaEntregasNot(transp->PilhaTentativas);
    liberar_FilaDevolucao(transp->FilaDevolucao);
    free(transp);
    transp = NULL;
    return transp;
}