#include <stdio.h>
#include <stdlib.h>
#include "transportadora.h"
#include "clientes.h"
#include "entregas.h"

int main(){
    Transportadora *transport = cria_transportadora();
    Cliente *client = criarListaClientes();
    Entrega *filaEntrega = criaFila();
   

    NewTry *pilhaTentativas = criaPilhaNewtry();
    FifoDevol *filaDevolucao = cria_FilaDevolucaoProd();

    

    while(1) {    
        int op, escolha;
        printf("-------------------------\n");
        printf("Escolha uma opcao:\n");
        printf("-------------------------\n");
        printf("(1) Acessar pagina Cliente.\n");
        printf("(2) Acessar pagina Transportadora.\n");
        printf("(3) Acessar pagina Entrega.\n");
        printf("(4) Finzalizar o Programa\n");
        scanf("%d", &op);
        
        if (op == 4){
            libera_MemTransportadora(transport);
            break;
        }

        switch (op){
        case 1:
            printf("-------------------------\n");
            printf("Escolha uma opcao:\n");
            printf("-------------------------\n");
            printf("(1) Cadastrar Cliente.");
            printf("(2) Remover Cliente.");
            printf("(3) Buscar Cliente.");
            printf("(4) exibir Clientes.");
            scanf("%d", &escolha);

            if(escolha == 1){
                adicionar_cliente(client);
            }
            if(escolha == 2){
                remover_cliente(client);
            }
            if(escolha == 3){
                int id;
                printf("Digite o id do cliente que deseja buscar:\n");
                scanf("%d", &id);
                buscar_cliente(client, id);
            }
            if(escolha == 4){
                
                exibir_clientes(client);
            }
            break;
        case 2:
            printf("-------------------------\n");
            printf("Escolha uma opcao:\n");
            printf("-------------------------\n");
            printf("(1) Cadastrar Cliente.\n");
            printf("(2) Cadastrar Entrega.\n");
            printf("(3) Efetuar Entrega.\n");
            printf("(4) Mostrar Score.\n");
            scanf("%d", &escolha);

            if(escolha == 1){
                cadastrar_cliente(transport);
            }
            if(escolha == 2){
                cadastrar_entrega(transport);
            }
            if(escolha == 3){
                efetuar_entrega(transport);
            }
            if(escolha == 4){
                mostrar_scoreTransp(transport);
            }
            break;
        case 3:
                printf("-------------------------\n");
                printf("Escolha uma opcao:\n");
                printf("-------------------------\n");
                printf("(1) Ver Todas as Entregas.\n");
                printf("(2) Ver as Tentativas de Entregas.\n");
                scanf("%d", &escolha);

                if(escolha == 1){
                    imprimirEntregas(filaEntrega);
                }
                if(escolha == 2){
                    ImprimirTentativas(pilhaTentativas);
                }
                break;
        default:
            printf("EScolha uma opção válida!");
            libera_MemTransportadora(transport);
            break;
        }
    }
        return 0;

}