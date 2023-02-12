typedef struct _listaClientes ListaClientes;
typedef struct _enderecoCli EnderecoCli;
typedef struct _cliente Cliente;

// Funções de criaçãoe e inserção
ListaClientes* cria_lista_Clientes();
void adiciona_cliente(ListaClientes *listaClientes);

// Funções de impressão
void mostra_clientes(ListaClientes *listaClientes);
void mostra_cliente(Cliente *cliente);

// Funções de verificação
int verifica_listaClientes(ListaClientes *listaClientes);
int busca_cliente(ListaClientes *listaClientes, int id_cli);
int verifica_endereco_clientes(ListaClientes *listaClientes, int id_endereco);

// Funções para remoção e liberação
void remove_cliente(ListaClientes *listaClientes);
ListaClientes* libera_listaClientes(ListaClientes *listaClientes);

// Funções acessórias
int gera_id_cliente(ListaClientes *listaClientes);
Cliente* retorna_Cliente(ListaClientes *listaClientes, int id_cli);