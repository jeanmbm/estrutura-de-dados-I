#include <stdio.h>
#include <stdlib.h>
#include "ListaDInamicaEncadeada.h"

struct elemento
{
  struct aluno dados;
  struct elemento *prox;
};

typedef struct elemento Elemento;

Lista *criaLsita()
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

int tamanhoLista(Lista *lista)
{
  if (lista == NULL)
    return 0;
  int count = 0;
  Elemento *no = *lista;
  while (no != NULL)
  {
    count++;
    no = no->prox;
  }
  return count;
}

int listaCheia(Lista *lista)
{
  return 0;
}

int listaVazia(Lista *lista)
{
  if (lista == NULL)
    return 1;
  if (*lista == NULL)
    return 1;
  return 0;
}

int inserirInicio(Lista *lista, struct aluno aluno)
{
  if (lista == NULL)
    return 0;
  Elemento *no = (Elemento *)malloc(sizeof(Elemento));
  if (no == NULL)
    return 0;
  no->dados = aluno;
  no->prox = (*lista);
  *lista = no;
  return 1;
}

int inserirFinal(Lista *lista, struct aluno aluno)
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
  }
  return 1;
}

int insereOrdenado(Lista *lista, struct aluno aluno)
{
  if (lista == NULL)
    return 0;
  Elemento *no = (Elemento *)malloc(sizeof(Elemento));
  if (no == NULL)
    return 0;
  no->dados = aluno;
  if (listaVazia(lista))
  {
    no->prox = (*lista);
    *lista = no;
    return 1;
  }
  else
  {
    Elemento *atual, *anterior = *lista;
    while (atual != NULL && atual->dados.matricula < aluno.matricula)
    {
      anterior = atual;
      atual = atual->prox;
    }
    if (atual == *lista)
    {
      no->prox = (*lista);
      *lista = no;
    }
    else
    {
      no->prox = anterior->prox;
      anterior->prox = no;
    }
    return 1;
  }
}

int removeInicio(Lista *lista)
{
  if (lista == NULL)
    return 0;
  if ((*lista) == NULL)
    return 0;
  Elemento *no = *lista;
  *lista = no->prox;
  free(no);
  return 1;
}

int removeFim(Lista *lista)
{
  if (lista == NULL)
    return 0;
  if ((*lista) == NULL)
    return 0;
  Elemento *anterior, *no = *lista;
  while (no->prox != NULL)
  {
    anterior = no;
    no = no->prox;
  }

  if (no == (*lista))
    *lista = no->prox;
  else
    anterior->prox = no->prox;
  free(no);
  return 1;
}

int remove(Lista *lista, int matricula)
{
  if (lista == NULL)
    return 0;
  Elemento *anterior, *no = *lista;
  while (no != NULL && no->dados.matricula != matricula)
  {
    anterior = no;
    no = no->prox;
  }
  if (no == NULL)
    return 0;
  if (no == *lista)
    *lista = no->prox;
  else
    anterior->prox = no->prox;
  free(no);
  return 1;
}

int cosultaPosicao(Lista *lista, int posicao, struct aluno *aluno)
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
  {
    return 0;
  }
  else
  {
    *aluno = no->dados;
    return 1;
  }
}

int cosultamatricula(Lista *lista, int matricula, struct aluno *aluno)
{
  if (lista == NULL)
    return 0;
  Elemento *no = *lista;
  while (no != NULL && no->dados.matricula != matricula)
  {
    no = no->prox;
  }
  if (no == NULL)
  {
    return 0;
  }
  else
  {
    *aluno = no->dados;
    return 1;
  }
}