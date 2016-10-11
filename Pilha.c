#include <stdio.h>
#include <stdbool.h>

typedef struct pilha
{
    int v[5];
    int topo;
}pilha;

pilha p;
int n = 5;
int aux;

bool cheio(void)
{

    bool N = true;

    if (p.topo == 4)
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

int push (int x)
{

    if (cheio() == true)
    {
        p.topo++;
        p.v[p.topo] = x;
    }
    else
    {
        printf("\n\nPilha cheia");
    }

}

int pop(void)
{

    if (vazio() == true)
    {
        aux = p.v[p.topo];
        p.topo--;
        return aux;
    }
    else
    {
        printf("\nPilha vazia");
    }

}

void menu(void)
{

    int entrada, e1, i;

    printf("\n1: Entrada: ");
    printf("\n\n2: Retirar: ");
    printf("\n\n3: Mostrar: \n\n");
    scanf("%d", &entrada);

    switch(entrada)
    {

    case 1:
        printf("\nDigite um valor para a pilha: ");
        scanf("%d", &e1);
        while ((getchar() != '\n') && (!EOF));
        push(e1);
        menu();
    break;

    case 2:
        if (vazio() == true)
        {
            printf("\nO numero retirado e: %d\n", pop());
            menu();
        }
        else
        {
            printf("\n\nPilha vazia\n\n");
            menu();
        }

    break;

    case 3:
        for (i = p.topo; i  > -1; i--)
            printf("\nPosicao %d -> Valor %d ", i + 1, p.v[i]);
        menu();
    break;

    }

}


int main(void)
{
    p.topo =  -1;
    menu();
}

