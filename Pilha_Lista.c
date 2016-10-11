#include <stdio.h>
#include <stdlib.h>

typedef struct NO
{
    int valor;
    struct NO *prox;
}no;

typedef struct pilha
{
    no *topo;
}P;

P Pilha;

void inicializar(P *Pilha)
{
    Pilha->topo = NULL;
}

void inserir (P *Pilha, int x)
{
    no *aux;

    aux =(no *) malloc(sizeof(no));
    aux->valor = x;
    aux->prox = Pilha->topo;
    Pilha->topo = aux;

}

void remover (P *Pilha)
{
    no *aux;
    if (Pilha->topo != NULL)
    {
        aux = Pilha->topo;
        Pilha->topo = aux->prox;
    }
    free(aux);
}

void free_fila(P *Pilha)
{
    no *aux;
    no *pp = Pilha->topo;

    while (pp != NULL)
    {
        aux = pp->prox;
        free(pp);
        pp = aux;
    }
}

void limpar(void)
{
    while((getchar() != '\n') && (!EOF));
}


int main(void)
{
    inicializar(&Pilha);
    int x, i;

    scanf("%d", &x);
    limpar();
    inserir(&Pilha, x);

    scanf("%d", &x);
    limpar();
    inserir(&Pilha, x);

    scanf("%d", &x);
    limpar();
    inserir(&Pilha, x);

    remover(&Pilha);
    remover(&Pilha);

    no *p = Pilha.topo;

    while(p != NULL)
    {
        printf("\n%d", p->valor);
        p = p->prox;
    }

    free_fila(&Pilha);

    return 0;

}

