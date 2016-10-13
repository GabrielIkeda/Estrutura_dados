#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define LIM 1000

typedef char tipo;

tipo frase[LIM];


typedef struct pilha
{
    int palindromo_numero_inverso;
    char palindromo_normal[LIM];
    char palindromo_inverso[LIM];
    int topo;
}pilha;

pilha p;

struct pilha topo = {-1,-1};

bool cheio(void)
{

    bool N = true;

    if (p.topo == LIM)
    {
        N = false;// nao esta cheio
    }

    return N;

}

bool vazio(void)
{

    bool N = true;

    if (p.topo == - 1)
    {
        N = false; // nao esta cheio
    }


    return N;

}

void push (tipo x)
{

    if (cheio() == true)
    {
        p.topo++;
        frase[p.topo] = x;
    }
    else
    {
        printf("\n\nPilha cheia");
    }

}

void pop(tipo *y)
{

    if (vazio() == true)
    {
        *y = frase[p.topo];
        p.topo--;
    }
    else
    {
        printf("\nPilha vazia");
    }

}

void processamento (void)
{

    int i, tamanho;

    printf("Entre um numero para descobrir se e palindromo:  ");
    scanf("%s", &p.palindromo_normal);

    tamanho = strlen( p.palindromo_normal );

    for (i = 0; i < tamanho; i++)
    {
        push(p.palindromo_normal[i]);
    }

    for (i = 0; i < tamanho; i++)
    {
        pop(&p.palindromo_inverso[i]);
    }

    p.palindromo_numero_inverso = atoi(p.palindromo_inverso);

    if (!strcasecmp (p.palindromo_normal, p.palindromo_inverso))
    {
        printf("\n\n%s e um palindromo", p.palindromo_normal);
    }
    else
    {
        printf("\n\n%s nao e um palindromo", p.palindromo_normal);
    }

}

int main(void)
{
    processamento();

}


