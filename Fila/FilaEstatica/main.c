#include <stdio.h>
#include <stdlib.h>
#include "FilaEstatica.h"

int main()
{
  int saida = 1;
  int escolha, aux;
  Queue *fila = NULL;

  while (saida = 1)
  {
    printf("\n\n============== MENU ==============");
    printf("\n\nInforme uma das opcoes:");
    printf("\n1 - Criar fila"); //
    printf("\n2 - Enfileirar elemento (Enqueue)");
    printf("\n3 - Desenfileirar elemento (Dequeue)");
    printf("\n4 - Consultar primeiro elemento da fila");
    printf("\n5 - Verificar tamanho");       //
    printf("\n6 - Verificar se esta cheia"); //
    printf("\n7 - Verificar se esta vazia"); //
    printf("\n8 - Imprimir fila");           //
    printf("\n0 - Sair");                    //
    printf("\n\nEscolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
      fila = cria_Queue();
      printf("\n!! Fila criada !!");
      break;

    case 2:
      if (fila == NULL)
      {
        printf("\nA fila e nula");
      }
      else if (isFull(fila) == 1)
      {
        printf("\nA fila esta cheia");
      }
      else
      {
        struct aluno alunoAdd;
        printf("\nDigite o nome do aluno: ");
        scanf("%s", alunoAdd.nome);
        printf("Digite o numero de matricula do aluno: ");
        scanf("%d", &alunoAdd.matricula);
        printf("Digite o valor da N1: ");
        scanf("%f", &alunoAdd.n1);
        printf("Digite o valor da N2: ");
        scanf("%f", &alunoAdd.n2);
        printf("Digite o valor da N3: ");
        scanf("%f", &alunoAdd.n3);

        aux = enqueue(fila, alunoAdd);

        if (aux != 1)
          printf("\n!! Nao foi possivel enfileirar !!");
        else
          printf("\n!! Elemento inserido com sucesso !!");
      }
      break;

    case 3:
      aux = enqueue(fila);
      if (aux == -1)
        printf("\nA fila e nula");
      else if (aux == 0)
        printf("\nA fila esta vazia");
      else
        printf("\n!! Elemento retirado com sucesso !!");
      break;

    case 4:
      /* code */
      break;

    case 5:
      aux = tamanho_Queue(pilha);
      if (aux == -1)
        printf("A fila e nula");
      else
        printf("\nTamanho: %d", aux);
      break;

    case 6:
      aux = isFull(fila);
      if (aux == -1)
        printf("A fila e nula");
      else if (aux == 0)
        printf("A fila nao esta cheia");
      else
        printf("A fila esta cheia");
      break;

    case 7:
      aux = isEmpty(fila);
      if (aux == -1)
        printf("A fila e nula");
      else if (aux == 0)
        printf("A fila nao esta vazia");
      else
        printf("A fila esta vazia");
      break;

    case 8:
      imprimirFila(fila);
      break;

    case 0:
      saida = 0;
      libera_Queue(fila);
      break;

    default:
      printf("!!! Opcao invalida !!!");
      break;
    }
  }

  return 0;
}