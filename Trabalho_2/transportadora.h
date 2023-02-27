
#include "clientes.h"
#include "entregas.h"

typedef struct _transportadora Transportadora;

// Funções de inserção e criação
Transportadora* cria_transportadora();
void cadastrar_cliente(Transportadora *transp);
void cadastrar_entrega(Transportadora *transp);
void efetuar_entrega(Transportadora *transp);
void cadastrar_PilhaTentativaEntrega(Transportadora *transp);

// Funções de verificação
int verifica_endereco(ListaClientes *listaClientes, int id_endereco);

// Funções de exibição de dados
void mostrar_scoreTransp(Transportadora *transp);

Transportadora *libera_MemTransportadora(Transportadora *transp);
