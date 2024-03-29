typedef struct pixel Pixel;
typedef struct imagem Imagem;

Imagem *criarImagem(int largura, int altura);
void preencherImagem(Imagem *img);
void imprimirImagem(Imagem *img);
void liberarImagem(Imagem *img);
void setPixelValue(Imagem *img, int y, int x, int valor);
void getPixelValue(Imagem *img, int x, int y);