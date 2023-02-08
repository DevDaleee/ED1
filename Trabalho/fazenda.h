typedef struct fazenda Fazenda;
typedef struct endereco Endereco;

Fazenda *criarListaEncadeadaCircularFazendas();
Fazenda *cadastrarFazenda(Fazenda *fazendas);
Fazenda *removerFazenda(Fazenda *fazendas, int id);//nao permitir remover fazenda se houver animais cadastrados
Fazenda *alterarFazenda(Fazenda *fazendas, int id);//alterar dados cadastrais da fazenda. exemplo: nome e endereco; 
int buscarFazenda(Fazenda *fazendas, int id);

//Criadas pela dupla
void addFazenda(Fazenda *fazendas, Fazenda *nova);
void liberarMemoriaF(Fazenda *fazendas);
void quantSexo(Fazenda *fazendas);
void calculaPeso(Fazenda *fazendas, int id);
float totalArroba(Fazenda *fazendas);
void listaAnimais(Fazenda *fazendas);
