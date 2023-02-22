typedef struct entrega Entrega;
typedef struct fifoE FifoE;

typedef struct newTry NewTry;

typedef struct fifoDevol FifoDevol;
typedef struct devolProd DevolProd;

FifoE *criaFila();
void addEntrega(FifoE *fifo, int id_endereco, char *produto, Cliente *cliente);
NewTry *criaPilhaNewtry();
void adiciona_PilhaNewTry(NewTry *pilha, int id_entrega, int id_endereco, char *prod, Cliente *cliente);
FifoDevol* cria_FilaDevolucaoProd();
void adiciona_FilaDevolucaoProd(FifoDevol *FilaDevolucaoProd, int id_entrega, int id_endereco, char *prod, Cliente *cliente);

int gera_id_entrega(FifoE *fifo); 
int TentativaEntrega(NewTry *pilha);

int verifica_filaEntrega(FifoE *fifo);
int verifica_pilhaNewTry(NewTry *pilha);
int verifica_filaDevolucaoProd(FifoDevol *FilaDevolucaoProd);
int verifica_EntregasIguais(FifoE *fifo);
int verifica_NewTryIguais(NewTry *pilha);

void remove_FilaEntrega(FifoE *fifo);
void remova_Fila_AddPilha(FifoE *fifo, NewTry *pilha);
void remove_PilhaNewTry(NewTry *pilha);
void remove_Pilha_AddFilaDevol(NewTry *pilha, FifoDevol *FilaDevolucaoProd);

void imprimirEntregas(FifoE *fifo);
void ImprimirTentativas(NewTry *pilha);

void liberar_FilaEntregas(FifoE *fifo);
void liberar_PilhaEntregasNot(NewTry *pilha);
void liberar_FilaDevolucao(FifoDevol *FilaDevolucaoProd);