typedef struct _listaClientes ListaClientes;
typedef struct _endCliente EndCliente;
typedef struct _cliente Cliente;

ListaClientes* criarListaClientes();
void adicionar_cliente(ListaClientes *listaClientes);

void exibir_clientes(ListaClientes *listaClientes);
void exibir_cliente(Cliente *cliente);

int verificar_clientes(ListaClientes *listaClientes);
int buscar_cliente(ListaClientes *listaClientes, int id_cliente);
int verificar_endereco(ListaClientes *listaClientes, int id_endereco);

void remover_cliente(ListaClientes *listaClientes);
ListaClientes* liberar_clientes(ListaClientes *listaClientes);

int gerar_id_cliente(ListaClientes *listaClientes);
Cliente* retornar_Cliente(ListaClientes *listaClientes, int id_cliente);