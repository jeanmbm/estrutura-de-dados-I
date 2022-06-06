// JEAN MOREIRA BORGES DE MORAIS - 20201043021

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
    printf("\nNome: %s\n", pilha->dados[i].nome);
    printf("Matricula: %d\n", pilha->dados[i].matricula);
    printf("Notas:\n");
    printf("\tN1: %.2f\n", pilha->dados[i].n1);
    printf("\tN2: %.2f\n", pilha->dados[i].n2);
    printf("\tN3: %.2f\n", pilha->dados[i].n3);
    printf("Index: %d\n", i);
    printf("\n---------------------------------------------------------\n");
  }
}

int concatenaPilha(Pilha *pilha1, Pilha *pilha2)
{
  if (pilha1 == NULL || pilha2 == NULL)
  {
    printf("!!!  Nao foi possivel concatenar as pilhas  !!!");
    return 0;
  }
  else
  {
    Pilha *aux = criarPilha();

    while (pilha2->topo != -1)
    {
      struct aluno aluno;
      stackpop(pilha2, &aluno);
      push(aux, aluno);
      pop(pilha2);
    }

    while (aux->topo != -1)
    {
      struct aluno aluno;
      stackpop(aux, &aluno);
      push(pilha1, aluno);
      pop(aux);
    }

    return 1;
  }
}

int copiaPilha(Pilha *pilha, Pilha *copia)
{
  if (pilha == NULL)
    return -1;
  if (isEmpty(pilha))
    return 0;

  Pilha *aux = criarPilha();

  while (pilha->topo != -1)
  {
    printf("\naqui 1");
    struct aluno aluno;
    stackpop(pilha, &aluno);
    push(aux, aluno);
    pop(pilha);
  }

  while (aux->topo != -1)
  {
    printf("\n%d", aux->topo);
    printf("\naqui 2");
    struct aluno aluno;
    stackpop(aux, &aluno);
    printf("\naqui 3");
    push(pilha, aluno);
    printf("\naqui 4");
    push(copia, aluno);
    printf("\naqui 5");
    pop(aux);
    printf("\naqui 6");
  }
  liberaPilha(aux);
  return 1;
}
