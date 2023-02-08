typedef struct criador Criador;

Criador *criarListaDuplaCriadores();
Criador *cadastrar(Criador *criadores);
Criador *removerCriador(Criador *criadores, int id);//nao é permitido remover criador com fazendas cadastradas
int buscar(Criador *criadores, int id);

//Funções Ciradas pela Dupla
void mostrarCriadores(Criador *criadores);
void liberarMemCriador(Criador *criadores);
float calcPatrimonio(Criador *criadores, int id);
void printCriadores(Criador *criadores);
/*
Desenvolva funçoes para:
- Retornar o patrimonio do criador (esse valor deve sempre estar atualizado)
Done - Funcao para mostrar cada criador e todos os seus respectivos atributos
Done - Funcao para liberar a memoria
*/