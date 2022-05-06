// JEAN MOREIRA BORGES DE MORAIS

#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplamenteEncadeada.h"

struct elemento
{
    struct elemento *ant;
    struct Aluno dados;
    struct elemento *prox;
};

typedef struct elemento Elemento;

Lista *criaLista()
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    if (lista != NULL)
        *lista = NULL;
    return lista;
}

void liberaLista(Lista *lista)
{
    if (lista != NULL)
    {
        Elemento *no;
        while ((*lista) != NULL)
        {
            no = *lista;
            *lista = (*lista)->prox;
            free(no);
        }
        free(lista);
    }
}

int insereInicioLista(Lista *lista, struct Aluno aluno)
{
    if (lista == NULL)
        return 0;
    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    if (no == NULL)
        return 0;
    no->dados = aluno;
    no->prox = (*lista);
    no->ant = NULL;
    if (*lista != NULL)
        (*lista)->ant = no;
    *lista = no;
    return 1;
}

int insereFinalLista(Lista *lista, struct Aluno aluno)
{
    if (lista == NULL)
        return 0;
    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    if (no == NULL)
        return 0;
    no->dados = aluno;
    no->prox = NULL;
    if ((*lista) == NULL)
    {
        no->ant = NULL;
        *lista = no;
    }
    else
    {
        Elemento *aux = *lista;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }
        aux->prox = no;
        no->ant = aux;
    }
    return 1;
}

int insereListaOrdenada(Lista *lista, struct Aluno aluno)
{
    if (lista == NULL)
        return 0;
    Elemento *no = (Elemento *)malloc(sizeof(Elemento));
    if (no == NULL)
        return 0;
    no->dados = aluno;
    if ((*lista) == NULL)
    {
        no->prox = NULL;
        no->ant = NULL;
        *lista = no;
        return 1;
    }
    else
    {
        Elemento *anterior, *atual = *lista;
        while (atual != NULL && atual->dados.matricula < aluno.matricula)
        {
            anterior = atual;
            atual = atual->prox;
        }
        if (atual == *lista)
        {
            no->ant = NULL;
            (*lista)->ant = no;
            no->prox = (*lista);
            *lista = no;
        }
        else
        {
            no->prox = anterior->prox;
            no->ant = anterior;
            anterior->prox = no;
            if (atual != NULL)
                atual->ant = no;
        }
        return 1;
    }
}

int removeLista(Lista *lista, int matricula)
{
    if (lista == NULL || (*lista) == NULL)
        return 0;
    Elemento *no = *lista;
    while (no != NULL && no->dados.matricula != matricula)
    {
        no = no->prox;
    }
    if (no == NULL)
        return 0;

    if (no->ant == NULL)
        *lista = no->prox;
    else
        no->ant->prox = no->prox;

    if (no->prox != NULL)
        no->prox->ant = no->ant;

    free(no);
    return 1;
}

int removeInicioLista(Lista *lista)
{
    if (lista == NULL || (*lista) == NULL)
        return 0;
    Elemento *no = *lista;
    *lista = no->prox;
    if (no->prox != NULL)
        no->prox->ant = NULL;
    free(no);
    return 1;
}

int removeFinalLista(Lista *lista)
{
    if (lista == NULL || (*lista) == NULL)
        return 0;
    Elemento *no = *lista;
    while (no->prox != NULL)
    {
        no = no->prox;
    }
    if (no->ant == NULL)
        *lista = no->prox;
    else
        no->ant->prox = NULL;
    free(no);
    return 1;
}

int consultaListaPosicao(Lista *lista, int posicao, struct Aluno *aluno)
{
    if (lista == NULL || posicao <= 0)
        return 0;
    Elemento *no = *lista;
    int i = 1;
    while (no != NULL && i < posicao)
    {
        no = no->prox;
        i++;
    }
    if (no == NULL)
        return 0;
    else
    {
        *aluno = no->dados;
        return 1;
    }
}

int consultaListaMatricula(Lista *lista, int matricula, struct Aluno *aluno)
{
    if (lista == NULL)
        return 0;
    Elemento *no = *lista;
    while (no != NULL && no->dados.matricula != matricula)
    {
        no = no->prox;
    }
    if (no == NULL)
        return 0;
    else
    {
        *aluno = no->dados;
        return 1;
    }
}

void imprimeLista(Lista *lista)
{
    if (lista == NULL)
        return;
    Elemento *no = *lista;
    while (no != NULL)
    {
        printf("Matricula: %d\n", no->dados.matricula);
        printf("Nome: %s\n", no->dados.nome);
        printf("Notas:\n");
        printf("\tN1: %.2f\n", no->dados.n1);
        printf("\tN2: %.2f\n", no->dados.n2);
        printf("\tN3: %.2f\n", no->dados.n3);
        printf("---------------------------------------------------------\n");

        no = no->prox;
    }
}
