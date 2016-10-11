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
    if (Fila->ultimo == NULL)
    {
        p->prox = p;
        Fila->primeiro = p;

    }
    else
    {
        Fila->ultimo->prox = p;
        p->prox = Fila->primeiro;

    }
    Fila->ultimo = p;
}

void remover (F *Fila)
{
    if (Fila->primeiro != NULL)
    {
        no *p = Fila->primeiro;
        Fila->primeiro = p->prox;
        Fila->ultimo->prox = p->prox;


        free(p);
    }

}

void free_fila(F *Fila)
{
    no *aux;
    no *p = Fila->primeiro;

    do
    {
        aux = p->prox;
        free(p);
        p = aux;
    }while (p != Fila->primeiro);
}

void limpar(void)
{
    while((getchar() != '\n') && (!EOF));
}

void mostrar(F *Fila)
{
    no *p = Fila->primeiro;
    do
    {
        printf("\n%d", p->valor);
        p = p->prox;
    }while(p != Fila->primeiro);
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

    scanf("%d", &x);
    limpar();
    inserir(&Fila, x);

    scanf("%d", &x);
    limpar();
    inserir(&Fila, x);

    mostrar(&Fila);

    remover(&Fila);

    mostrar(&Fila);


    free_fila(&Fila);

    return 0;

}

