#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "fazenda.h"
#include "criador.h"

int main(){

    Criador *listaCriador = NULL;
    criarListaEncadeadaCircularFazendas(listaCriador);
    Fazenda *listaFazenda = NULL;
    criarListaEncadeadaCircularFazendas(listaFazenda);
    Animal *listaAnimal = NULL;
    criarListaDuplaCriadores(listaAnimal);

    while(1) {    
        int op, escolha;
        printf("-------------------------\n");
        printf("Escolha uma opcao:\n");
        printf("-------------------------\n");
        printf("(1) Acessar pagina Criador.\n");
        printf("(2) Acessar pagina Fazenda.\n");
        printf("(3) Acessar pagina Animal.\n");
        printf("(4) Finzalizar o Programa\n");
        scanf("%d", &op);
        
        if (op == 4){
            break;
        }

        switch (op){
        case 1:
            printf("-------------------------\n");
            printf("Escolha uma opcao:\n");
            printf("-------------------------\n");
            printf("(1) Cadastrar criador.");
            printf("(2) Remover criador.");
            printf("(3) Buscar criador.");
            scanf("%d", &escolha);

            if(escolha == 1){
                cadastrar_criador(listaCriador);
            }
            if(escolha == 2){
                int id;
                printf("Digite o id do Criador que deseja remover:\n");
                scanf("%d", &id);
                removerCriador(listaCriador, id);
            }
            if(escolha == 3){
                int id;
                printf("Digite o id do Criador que deseja buscar:\n");
                scanf("%d", &id);
                buscar(listaCriador, id);
            }
            break;
        case 2:
                printf("-------------------------\n");
                printf("Escolha uma opcao:\n");
                printf("-------------------------\n");
                printf("(1) Cadastrar Fazenda.");
                printf("(2) Remover Fazenda.");
                printf("(3) Buscar Fazenda.");
                scanf("%d", &escolha);

                if(escolha == 1){
                    cadastrarFazenda(listaFazenda);
                }
                if(escolha == 2){
                    int id;
                    printf("Digite o id do Fazenda que deseja remover:\n");
                    scanf("%d", &id);
                    removerFazenda(listaFazenda, id);
                }
                if(escolha == 3){
                    int id;
                    printf("Digite o id do Fazenda que deseja alterar:\n");
                    scanf("%d", &id);
                    buscarFazenda(listaFazenda, id); 
                }
                break;
        case 3:
                printf("-------------------------\n");
                printf("Escolha uma opcao:\n");
                printf("-------------------------\n");
                printf("(1) Cadastrar Animal.");
                printf("(2) remover Animal.");
                scanf("%d", &escolha);

                if(escolha == 1){
                    cadastro(listaAnimal);
                }
                if(escolha == 2){
                    int id;
                    printf("Digite o id do Animal que deseja remover:\n");
                    scanf("%d", &id);
                    remover(listaAnimal, id);
                }
                break;
        default:
            printf("EScolha uma opção válida!");
            break;
        }
    }
        return 0;

}