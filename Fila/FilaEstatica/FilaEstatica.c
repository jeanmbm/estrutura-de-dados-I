// FilaEstatica.c
#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

struct fila
{
  int inicio, final, qtd;
  struct aluno dados[MAX];
};

Queue *cria_Queue()
{
  Queue *que = (Queue *)malloc(sizeof(struct fila));
  if (que != NULL)
  {
    que->inicio = 0;
    que->final = 0;
    que->qtd = 0;
  }
  return que;
}

void libera_Queue(Queue *que)
{
  free(que);
}

int tamanho_Queue(Queue *que)
{
  if (que == NULL)
    return -1;
  return que->qtd;
}

int isFull(Queue *que)
{
  if (que == NULL)
    return -1;
  if (que->qtd == MAX)
    return 1;
  else
    return 0;
}

int isEmpty(Queue *que)
{
  if (que == NULL)
    return -1;
  if (que->qtd == 0)
    return 1;
  else
    return 0;
}

int enqueue(Queue *que, struct aluno al)
{
  if (que == NULL)
    return 0;
  if (isFull(que))
    return 0;
  que->dados[que->final] = al;
  que->final = (que->final + 1) % MAX;
  que->qtd++;
  return 1;
}
int dequeue(Queue *que)
{
  if (que = NULL || isEmpty(que))
    return 0;
  que->inicio = (que->inicio + 1) % MAX;
  que->qtd--;
  return 1;
}

int consulta_Queue(Queue *que, struct aluno *al)
{
  if (que == NULL || isEmpty(que))
    return 0;
  *al = que->dados[que->inicio];
  return 1;
}

void imprimirFila(Queue *que)
{
  if (que == NULL)
    return;
  printf("\n======= PILHA =======\n");
  int i;
  for (i = 0; i < que->qtd; i++)
  {
    printf("Nome: %s\n", que->dados[i].nome);
    printf("Matricula: %d\n", que->dados[i].matricula);
    printf("Notas:\n");
    printf("\tN1: %.2f\n", que->dados[i].n1);
    printf("\tN2: %.2f\n", que->dados[i].n2);
    printf("\tN3: %.2f\n", que->dados[i].n3);
    printf("---------------------------------------------------------\n");
  }
}