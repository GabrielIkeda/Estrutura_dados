#include <stdio.h>
#define MAX 5

typedef struct LETRAS
{

    int inicio, fim;
    char vetor[MAX];

}fila;

fila f;
char aux;

char inserir(char x)
{
    if (f.fim == MAX - 1)
    {
        printf("\n\nFila cheia");
    }
    else
    {
        f.fim++;
        f.vetor[f.fim] = x;
       // printf("%c", f.vetor[f.fim]);

    }
}

void remover(void)
{
    if (f.inicio > f.fim)
    {
        printf("\n\nFila vazia");
    }
    else
    {
        aux = f.vetor[f.inicio];
        f.inicio++;
    }
}


int main(void)
{
    f.inicio =  0;
    f.fim = -1;

    int entrada = 1, i;
    char e1;

    for (i = 1; i <= MAX; i++)
    {

      printf("\nDigite um valor para a fila: ");
      scanf("%c", &e1);

      while ((getchar() != '\n') && (!EOF));

      inserir(e1);

      printf("%c", f.vetor[f.fim]);
    }

    remover();

    printf("\n\n\n-----------------Posicao %d -> Letra %c", i , aux);


    for (i = f.inicio; i  <= f.fim; i++)
    printf("\n\nPosicao %d -> Valor %c ", i - 1, f.vetor[i]);

}
