#include <stdio.h>
#include <stdlib.h>

typedef struct NOPRIMEIRO
{
	int valor;
	struct NOPRIMEIRO *proximo;
	struct NOPRIMEIRO *anterior;
}no;

typedef struct LISTAPRIMEIRO
{
	no *primeiro;
	no *ultimo;
}l;

l lista;

void inicializar(l *lista)
{
	lista->primeiro = NULL;
	lista->ultimo = NULL;
}

void inserir_zero(l *lista, int x)
{
    no *p1;
    p1 =(no *) malloc(sizeof(no));
    p1->valor = x;
    p1->anterior = NULL;
    p1->proximo = NULL;
    lista->primeiro = p1;
    lista->ultimo = p1;

}

void inserir_meio(l *lista, int x, int pos)
{
	no *p1;
	p1 = lista->primeiro;

	if(pos == 1)
    {
        printf("\n\n-----------------ERRO-----------------");
        exit(0);
        // nao sei se este comando esta com a sintaxe correta ->exit(0);
    }

	if(p1 == NULL)
    {
        printf("\n\n-----------------ERRO-----------------");
        exit(0);
    }
    else
    {
        while(--pos != 0)
        {
            if (p1->proximo != NULL)
            {
                p1 = p1->proximo;
            }
            else
            {
                printf("\n\n-----------------ERRO-----------------");
                exit(0);
            }

        }
        no *p2;
        p2 = p1->anterior;
        no *p3;
        p3 =(no *) malloc(sizeof(no));
        p3->valor = x;
        p3->proximo = p1;
        p1->anterior = p3;
        p2->proximo = p3;
        p3->anterior = p2;

    }
}

void inserir_comeco(l *lista, int x)
{
    no *p1;
    p1 = lista->primeiro;
    no *p2;
    p2 =(no *) malloc(sizeof(no));
    p2->valor = x;
    p2->proximo = p1;
    p1->anterior = p2;
    p2->anterior = NULL;
    lista->primeiro = p2;
}

void inserir_final(l *lista, int x)
{
    no *p1;
    p1 = lista->ultimo;
    no *p2;
    p2 =(no *) malloc(sizeof(no));
    p2->valor = x;
    p1->proximo = p2;
    p2->anterior = p1;
    p2->proximo = NULL;
    lista->ultimo = p2;
}

void remover_comeco (l *lista)
{
    no *r1;
    r1 = lista->primeiro;

    if(r1 == NULL)
    {
        printf("\n\n-----------------ERRO-----------------");
        exit(0);
    }
    else
    {
        no *r2;
        r2 = r1->proximo;
        r1->proximo = r2;
        lista->primeiro = r2;
        free(r1);
    }
}

void remover_meio(l *lista, int pos)
{
    no *r1;
    r1 = lista->primeiro;

    if(r1 == NULL)
    {
        printf("\n\n-----------------ERRO-----------------");
        exit(0);
    }
    else
    {
        while(--pos != 0)
        {
            if (r1->proximo != NULL)
            {
                r1 = r1->proximo;
            }
            else
            {
                printf("\n\n-----------------ERRO-----------------");
                exit(0);
            }
        }

        if (r1->proximo == NULL || r1->anterior == NULL)
        {
            "\nImpossivel realizar operacao";
            exit(0);
        }
        else
        {
            no *r2;
            r2 = r1->proximo;
            no *r3;
            r3 = r1->anterior;
            r1->anterior->proximo = r3;
            r3->proximo = r2;
            r2->anterior = r3;
            free(r1);
        }
    }
}

void remover_fim(l *lista)
{
    no *r1;
    r1 = lista->ultimo;

    if(r1 == NULL)
    {
        printf("\n\n-----------------ERRO-----------------");
        exit(0);
    }
    else
    {
        no *r2;
        r2 = r1->anterior;
        r1->anterior = r2;
        lista->ultimo = r2;
        r2->proximo = NULL;
        free(r1);
    }
}

void free_lista(l *lista)
{
    no *aux;
    no *p = lista->primeiro;

    while (p != NULL)
    {
        aux = p->proximo;
        free(p);
        p = aux;
    }
}

void limpar(void)
{
	while((getchar() != '\n') && (!EOF));
}

void mostrar(l *lista)
{
    no *p;
    p = lista->primeiro;

    while (p != NULL)
    {
        printf("\n%d", p->valor);
        p = p->proximo;
    }
}

int main(void)
{
    inicializar(&lista);
    int x, y, z, a, p, d, rp;
    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    scanf("%d", &a);
    scanf("%d", &p);
    scanf("%d", &d);
    scanf("%d", &rp);

/*  x = elemento para comecar a lista,
    y = elemento para inserir na primeira posicao,
    z = elemento para inserir na ultima posicao,
    a = elemento para inserir na posicao p,
    p = posicao que o elemento a sera inserido,
    d = elemento para inserir na ultima posicao,
    rp = posicao que sera removida.
*/

    inserir_zero(&lista, x);
    inserir_comeco(&lista, y);
    inserir_final(&lista, z);
    inserir_meio(&lista, a, p);
    inserir_final(&lista, d);
    remover_meio(&lista, rp);
    remover_comeco(&lista);
    remover_fim(&lista);

    mostrar(&lista);
    free_lista(&lista);

    return 0;
}
