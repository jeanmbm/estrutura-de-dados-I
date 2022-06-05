#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.h"

// Definição da Pilha
struct pilha
{
  int topo;
  struct aluno dados[MAXPILHA];
};

Pilha *criarPilha()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(struct pilha));
  if (pilha != NULL)
    pilha->topo = -1;
  return pilha;
}

void liberaPilha(Pilha *pilha)
{
  free(pilha);
}

int isEmpty(Pilha *pilha)
{
  if (pilha == NULL)
    return -1;
  if (pilha->topo == -1)
    return 1;
  return 0;
}

int isFull(Pilha *pilha)
{
  if (pilha == NULL)
    return -1;
  if (pilha->topo == MAXPILHA - 1)
    return 1;
  return 0;
}

int size(Pilha *pilha)
{
  if (pilha == NULL)
    return -1;
  return pilha->topo + 1;
}

int push(Pilha *pilha, struct aluno dado)
{
  if (pilha == NULL)
    return -1;
  if (isFull(pilha))
    return 0;
  pilha->topo++;
  pilha->dados[pilha->topo] = dado;
  return 1;
}

int pop(Pilha *pilha)
{
  if (pilha == NULL)
    return -1;
  if (isEmpty(pilha))
    return 0;
  pilha->topo = pilha->topo - 1;
  return 1;
}

int stackpop(Pilha *pilha, struct aluno *aluno)
{
  if (pilha == NULL)
    return -1;
  if (isEmpty(pilha))
    return 0;
  *aluno = pilha->dados[pilha->topo];
  return 1;
}

void imprimePilha(Pilha *pilha)
{
  if (pilha == NULL)
    return;
  printf("\n======= PILHA =======\n");
  int i;
  for (i = pilha->topo; i >= 0; i--)
  {
    printf("Nome: %s\n", pilha->dados[i].nome);
    printf("Matricula: %d\n", pilha->dados[i].matricula);
    printf("Notas:\n");
    printf("\tN1: %.2f\n", pilha->dados[i].n1);
    printf("\tN2: %.2f\n", pilha->dados[i].n2);
    printf("\tN3: %.2f\n", pilha->dados[i].n3);
    printf("Index: %d\n", i);
    printf("---------------------------------------------------------\n");
  }
}

Pilha *concatenaPilha(Pilha *pilha1, Pilha *pilha2)
{
  if (pilha1 == NULL || pilha2 == NULL)
  {
    printf("!!!  Nao foi possovel concatenar as pilhas  !!!");
    return;
  }
  else
  {
    Pilha *p = criarPilha();

    int i;
    for (i = 0; i <= pilha1->topo; i++)
    {
      p->dados[i] = pilha1->dados[i];
      p->topo++;
    }

    for (i = (p->topo + 1); i <= (pilha2->topo + (p->topo + 1)); i++)
    {
      p->dados[i] = pilha2->dados[i - (p->topo + 1)];
      p->topo++;
    }
    return p;
  }
}
