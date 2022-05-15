#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.c"

int main
{

  int saida = 1;
  int escolha;
  Pilha *pilha;
  while (saida == 1)
  {
    printf("\n\n============== MENU ==============");
    printf("\n\nInforme uma das opções:");
    printf("\n1 - Criar uma pilha"); //
    printf("\n2 - Empilhar elemento (PUSH)");
    printf("\n3 - Desempilhar (POP)");
    printf("\n4 - Pegar elemento do topo (STACKPOP)");
    printf("\n5 - Verificar tamanho");       //
    printf("\n6 - Verificar se esta cheia"); //
    printf("\n7 - Verificar se esta vazia"); //
    printf("\n8 - Imprimir pilha");          //
    printf("\n0 - Sair");                    //
    printf("\n\nEscolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
      pilha = criarPilha();
      printf("\nPilha criada!");
      break;

    case 2:
      int valor;
      printf("\nDigite um valor inteiro para ser empilhado: ");
      scanf("%d", &valor);
      int aux = push(pilha, valor);
      break;

    case 3:

      break;

    case 4:

      break;

    case 5:
      int aux = size(pilha);
      if (aux == -1)
        printf("A pilha informada é nula");
      else
        printf("\nTamanho: %d", % aux);
      break;

    case 6:
      int aux = isFull(pilha);
      if (aux == -1)
        printf("\nA pilha informada é nula");
      else if (aux == 0)
        printf("\nA pilha não está cheia");
      else
        printf("\nA pilha está cheia");
      break;

    case 7:
      int aux = isEmpty(pilha);
      if (aux == -1)
        printf("A pilha informada é nula");
      else if (aux == 0)
        printf("A pilha não está vazia");
      else
        printf("A pilha está vazia");
      break;

    case 8:
      imprimePilha(pilha);
      break;

    default:
      saida = 0;
      liberaPilha(pilha);
      break;
    }
  }
}