#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int valor;
    struct NO *prox;
}no;

typedef struct fila
{
    no *primeiro;
    no *ultimo;
}F;

F Fila;

void inicializar(F *Fila)
{
    Fila->primeiro = NULL;
    Fila->ultimo = NULL;
}

void inserir (F *Fila, int x)
{
    no *p;


    p =(no *) malloc(sizeof(no));
    p->valor = x;
    p->prox = NULL;
    if (Fila->ultimo == NULL)
    {
        Fila->primeiro = p;
    }
    else
    {
        Fila->ultimo->prox = p;
    }

    Fila->ultimo = p;
}

void remover (F *Fila)
{
    no *p;
    if (Fila->primeiro != NULL)
    {
        p = Fila->primeiro;
        Fila->primeiro = p->prox;
        if(Fila->primeiro == NULL)
        {
            Fila->ultimo = NULL;
        }
    }
    free(p);
}

void free_fila(F *Fila)
{
    no *aux;
    no *p = Fila->primeiro;

    while (p != NULL)
    {
        aux = p->prox;
        free(p);
        p = aux;
    }
}

void limpar(void)
{
    while((getchar() != '\n') && (!EOF));
}


int main(void)
{
    inicializar(&Fila);
    int x, i;

    scanf("%d", &x);
    limpar();
    inserir(&Fila, x);

    scanf("%d", &x);
    limpar();
    inserir(&Fila, x);

    scanf("%d", &x);
    limpar();
    inserir(&Fila, x);

    remover(&Fila);

    no *p = Fila.primeiro;
    while(p != NULL)
    {
        printf("\n%d", p->valor);
        p = p->prox;
    }

    free_fila(&Fila);

    return 0;

}

