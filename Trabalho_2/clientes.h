typedef struct cliente Cliente;
typedef struct endereco Endereco;


//Criar e Cadastrar os Clientes na Lista
Cliente *criarListaClientes();
Cliente *cadastrarCliente(Cliente *lista);

//Buscar Cliente na Lista por ID
Cliente *buscarCliente(Cliente *lista, int valor);

//Liberar Alocação de Memoria
void liberarLista(Cliente **lista_ref);

//Remover Cliente
Cliente *remover(Cliente *lista, int id);


//mostar o conteúdo da lista
void mostrarLista(Cliente *lista);