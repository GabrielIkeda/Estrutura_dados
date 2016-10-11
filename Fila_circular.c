#include <stdio.h>

#define MAX 5

typedef struct LETRA
{
    int inicio, fim;
    char vetor[MAX];
}FILA;

int incremento(char k)
{
    return (k + 1) % MAX;
}

void entrada(char x, FILA *f)
{
    if (incremento(f->fim) == f->inicio)
    {
        printf("\nFila cheia");
    }
    else
    {
        f->vetor[f->fim] = x;
        f->fim = incremento(f->fim);
    }
}

void saida(FILA *f)
{
    if (f->fim == f->inicio)
    {
        printf("\nFila vazia");
    }
    else
    {
        int aux = f->vetor[f->inicio];
        f->inicio = incremento(f->inicio);
    }
}

int main(void)
{
    FILA fila;
    fila.inicio = 0;
    fila.fim = 0;

    char e1;
    int i, resp1 = 1, resp2 = 1, m;

    while (resp1 != 4)
    {
        printf("1 - Inserir\n2 - Remover\n3 - Mostrar\n4 - Sair\n");
        scanf("%d", &resp1);
        while ((getchar() != '\n') && (!EOF));

        if (resp1 == 1)
        {
            resp2 = 1;
            while (resp2 == 1)
            {
                printf("\nEntre com um valor para a fila: ");
                scanf("%c", &e1);

                while ((getchar() != '\n') && (!EOF));

                entrada(e1, &fila);



                printf("\nTecle 1 para continuar ...");
                scanf("%d", &resp2);
                while ((getchar() != '\n') && (!EOF));
            }
        }

        if (resp1 == 2)
        {
            resp2 = 1;
            while (resp2 == 1)
            {
                saida(&fila);
                printf("\nTecle 1 para continuar ...");
                scanf("%d", &resp2);
                while ((getchar() != '\n') && (!EOF));
            }
        }

        if (resp1 == 3)
        {
            resp2 = 1;

            while (resp2 == 1)
            {
                m = fila.inicio;
                while (m != fila.fim)
                {
                    printf("\nPosicao %d -> Letra %c\n", i + 1, fila.vetor[m]);
                    m = incremento(m);

                }
                resp2 = 0;
            }
        }
    }
    return 0;
}
