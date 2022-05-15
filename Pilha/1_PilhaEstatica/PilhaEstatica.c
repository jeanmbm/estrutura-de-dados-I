#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.h"

// Definição da Pilha
struct pilha
{
  int topo;
  int dados[MAXPILHA];
};

Pilha *criarPilha()
{
  Pilha *pilha = (Pilha *)malloc(sizeof(struct Pilha));
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

int push(Pilha *pilha, int dado)
{
  if (pilha == NULL)
    return -1;
  if (isFull(pilha))
    return 0;
  pilha->topo < -pilha->topo + 1;
  pilha->dados[pilha->topo] < -dado;
  return 1;
}

int pop(Pilha *pilha)
{
  if (pilha == NULL)
    return -1;
  if (isEmpty(pilha))
    return 0;
  pilha->topo < -pilha->topo - 1;
  return 1;
}

int stackpop(Pilha *pilha)
{
  if (pilha == NULL)
    return -1;
  if (isEmpty(pilha))
    return 0;
  return pilha->dados[pilha->topo];
}

void imprimePilha(Pilha *pilha)
{
  if (pilha == NULL)
    return;
  printf("\n======= PILHA =======\n");
  int i;
  for (i = 0; i < pilha->topo + 1; i++)
  {
    printf("%d", pilha->dados[i]);
  }
}
