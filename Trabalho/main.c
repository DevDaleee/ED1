#include <stdio.h>
#include <stdlib.h>
#include "animal.h"
#include "fazenda.h"
#include "criador.h"

int main(){
    int op, escolha;
    printf("-*20");
    printf("Escolha uma opcao:\n");
    printf("-*20");
    printf("(1) Acessar pagina Criador.\n");
    printf("(2) Acessar pagina Fazenda.\n");
    printf("(3) Acessar pagina Animal.\n");
    scanf("%d", &op);

    Criador *listaCriador = NULL;
    criarListaDuplaCriadores(listaCriador);
    Fazenda *listaFazenda = NULL;
    criarListaDuplaCriadores(listaFazenda);
    Animal *listaAnimal = NULL;
    criarListaDuplaCriadores(listaAnimal);

    switch (op){
    case 1:
        printf("-*20");
        printf("Escolha uma opcao:\n");
        printf("-*20");
        printf("(1) Cadastrar criador.");
        printf("(2) Remover criador.");
        printf("(3) Buscar criador.");
        scanf("%d", &escolha);

        if(escolha == 1){
            cadastrar(listaCriador);
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
            printf("-*20");
            printf("Escolha uma opcao:\n");
            printf("-*20");
            printf("(1) Cadastrar Fazenda.");
            printf("(2) Remover Fazenda.");
            printf("(3) Buscar Fazenda.");
            scanf("%d", &escolha);

            if(escolha == 1){
                cadastrar(listaFazenda);
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
                buscar(listaFazenda, id); 
            }
            break;
    case 3:
            printf("-*20");
            printf("Escolha uma opcao:\n");
            printf("-*20");
            printf("(1) Cadastrar Animal.");
            printf("(2) Permutar Animal.");
            printf("(3) remover Animal.");
            scanf("%d", &escolha);

            if(escolha == 1){
                cadastrar(listaAnimal);
            }
            if(escolha == 2){
                int id;
                char origem, destino;
                printf("Digite o id do Animal que deseja remover:\n");
                scanf("%d", &id);
                printf("Qual o local de origem do animal? \n");
                scanf("%s", &origem);
                printf("Qual o local de destino do animal? \n");
                scanf("%s", &destino);
            
                permutasAnimais(origem, destino, id);
            }
            if(escolha == 3){
                int id;
                printf("Digite o id do Animal que deseja remover:\n");
                scanf("%d", &id);
                remove(listaAnimal, id);
            }
            break;
    default:
        printf("EScolha uma opção válida!");
        break;
    }
    return 0;

}
