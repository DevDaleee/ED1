#include <stdio.h>
#include <string.h>
#define string "O EXERCICIO E FACIL"

void main()
{
    char vetor[] = string;
    char ocorrencias[] = string;
    int i = 0, j = 0, k = 0;
    int tam = strlen(vetor);

    for (i = 0; i < tam; i++)
    {
        for (j = i + 1; j < tam;)
        {
            if (ocorrencias[j] == ocorrencias[i])
            {
                for (k = j; k < tam; k++)
                    ocorrencias[k] = ocorrencias[k + 1];
                
                tam--;
            }
            else
            {
                j++;
            }
        }
    }

    int soma_ocor = 0;
    for (i = 0; i < tam; i++)
    {
        soma_ocor = 0;

        j = 0;
        while (vetor[j] != '\0')
        {
            if (ocorrencias[i] == vetor[j])
            {
                soma_ocor++;
            }
            j++;
        }
        printf("'%c' = %d\n", ocorrencias[i], soma_ocor);
    }
    
}