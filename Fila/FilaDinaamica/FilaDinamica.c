#include <stdio.h>
#include <stdlib.h>
#include "FilaDinamica.h"

struct elemento
{
  struct aluno dados;
  struct elemento *prox;
};

typedef struct elemento Elem;

struct fila
{
  struct elemento *inicio;
  struct elemento *final;
  int qtd;
};

Fila *cria_Fila()
{
  Fila *fi = (Fila *)malloc(sizeof(struct fila));
  if (fi != NULL)
  {
    fi->final = NULL;
    fi->inicio = NULL;
    fi->qtd = 0;
  }
  return fi;
}

void libera_Fila(Fila *fi)
{
  if (fi != NULL)
  {
    Elem *no;
    while (fi->inicio != NULL)
    {
      no = fi->inicio;
      fi->inicio = fi->inicio->prox;
      free(no);
    }
    free(fi);
  }
}

int tamanho_Fila(Fila *fi)
{
  if (fi == NULL)
    return 0;
  return fi->qtd;
}

int Fila_cheia()
{
  return 0;
}

int Fila_vazia(Fila *fi)
{
  if (fi == NULL)
    return -1;
  if (fi->inicio == NULL)
    return 1;
  return 0;
}

int insere_Fila(Fila *fi, struct aluno al)
{
  if (fi == NULL)
    return 0;
  Elem *no = (Elem *)malloc(sizeof(Elem));
  if (no == NULL)
    return 0;
  no->dados = al;
  no->prox = NULL;
  if (fi->final == NULL) // fila vazia
    fi->inicio = no;
  else
    fi->final->prox = no;
  fi->final = no;
  fi->qtd++;
  return 1;
}

int remove_Fila(Fila *fi)
{
  if (fi == NULL)
    return 0;
  if (fi->inicio == NULL) // fila vazia
    return 0;
  Elem *no = fi->inicio;
  fi->inicio = fi->inicio->prox;
  free(no);
  if (fi->inicio == NULL) // fila ficou vazia.
    fi->final = NULL;
  fi->qtd--;
  return 1;
}

int consulta_Fila(Fila *fi, struct aluno *al)
{
  if (fi == NULL)
    return -1;
  if (fi->inicio == NULL)
    return 0;

  *al = fi->inicio->dados;
  return 1;
}

void imprime_Fila(Fila *fi)
{
  if (fi == NULL)
    return;
  Elem *no = fi->inicio;

  printf("======== FILA ========\n");
  while (no != NULL)
  {
    printf("\nNome: %s\n", no->dados.nome);
    printf("Matricula: %d\n", no->dados.matricula);
    printf("Notas:\n");
    printf("\tN1: %.2f\n", no->dados.n1);
    printf("\tN2: %.2f\n", no->dados.n2);
    printf("\tN3: %.2f\n", no->dados.n3);
    printf("---------------------------------------------------------\n");

    no = no->prox;
  }
}