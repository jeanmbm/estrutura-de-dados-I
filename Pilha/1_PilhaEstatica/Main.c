#include <stdio.h>
#include <stdlib.h>
#include "PilhaEstatica.c"

int main()
{
  int saida = 1;
  int escolha, aux;
  Pilha *pilha = NULL;
  while (saida == 1)
  {
    printf("\n\n============== MENU ==============");
    printf("\n\nInforme uma das opcoes:");
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
      struct aluno alunoAdd;
      printf("\nDigite o nome do aluno: ");
      scanf("%s", alunoAdd.nome);
      printf("\nDigite o numero de matricula do aluno: ");
      scanf("%d", &alunoAdd.matricula);
      printf("\nDigite o valor da N1: ");
      scanf("%f", &alunoAdd.n1);
      printf("\nDigite o valor da N2: ");
      scanf("%f", &alunoAdd.n2);
      printf("\nDigite o valor da N3: ");
      scanf("%f", &alunoAdd.n3);

      aux = push(pilha, alunoAdd);
      if (aux == -1)
        printf("\nA pilha é nula");
      else if (aux == 0)
        printf("\nA pilha está cheia");
      else
        printf("\n!! Elemento inserido com sucesso !!");
      break;

    case 3:
      aux = pop(pilha);
      if (aux == -1)
        printf("\nA pilha é nula");
      else if (aux == 0)
        printf("\nA pilha está vazia");
      else
        printf("\n!! Elemento retirado com sucesso !!");
      break;

    case 4:
      printf("\nToDo !!");
      //      struct aluno alunoStackpop;
      //    aux = stackpop(pilha, alunoStackpop);
      //      if (aux == -1)
      //        printf("\nA pilha é nula");
      //      else if (aux == 0)
      //        printf("\nA pilha está vazia");
      //      else
      //        printf("\nValor do topo: %d", aux);
      break;

    case 5:
      aux = size(pilha);
      if (aux == -1)
        printf("A pilha é nula");
      else
        printf("\nTamanho: %d", aux);
      break;

    case 6:
      aux = isFull(pilha);
      if (aux == -1)
        printf("\nA pilha é nula");
      else if (aux == 0)
        printf("\nA pilha não está cheia");
      else
        printf("\nA pilha está cheia");
      break;

    case 7:
      aux = isEmpty(pilha);
      if (aux == -1)
        printf("A pilha é nula");
      else if (aux == 0)
        printf("A pilha não está vazia");
      else
        printf("A pilha está vazia");
      break;

    case 8:
      imprimePilha(pilha);
      break;

    case 0:
      saida = 0;
      liberaPilha(pilha);
      break;

    default:
      printf("!!! Opção invalida !!!");
    }
  }
}