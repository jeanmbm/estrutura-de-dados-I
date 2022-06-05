#include <stdio.h>
#include <stdlib.h>
#include "FilaDinamica.c"

int main()
{
  int saida = 1;
  int escolha, aux;
  Fila *fila = NULL;
  struct aluno alunoConsulta;

  while (saida == 1)
  {
    printf("\n\n============== MENU ==============");
    printf("\n\nInforme uma das opcoes:");
    printf("\n1 - Criar fila");
    printf("\n2 - Enfileirar elemento (Enqueue)");
    printf("\n3 - Desenfileirar elemento (Dequeue)");
    printf("\n4 - Consultar primeiro elemento da fila");
    printf("\n5 - Verificar tamanho");
    printf("\n6 - Verificar se esta cheia");
    printf("\n7 - Verificar se esta vazia");
    printf("\n8 - Imprimir fila");
    printf("\n0 - Sair");
    printf("\n\nEscolha: ");
    scanf("%d", &escolha);

    switch (escolha)
    {
    case 1:
      fila = cria_Fila();
      printf("\n!! Fila criada !!");
      break;

    case 2:
      if (fila == NULL)
      {
        printf("\nA fila e nula");
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

        aux = insere_Fila(fila, alunoAdd);

        if (aux != 1)
          printf("\n!! Nao foi possivel enfileirar !!");
        else
          printf("\n!! Elemento inserido com sucesso !!");
      }
      break;

    case 3:
      aux = remove_Fila(fila);

      if (aux == -1)
        printf("\nA fila e nula");
      else if (aux == 0)
        printf("\nA fila esta vazia");
      else
        printf("\n!! Elemento retirado com sucesso !!");
      break;

    case 4:
      aux = consulta_Fila(fila, &alunoConsulta);

      if (aux == -1)
      {
        printf("\nA fila e nula");
      }
      else if (aux == 0)
      {
        printf("\nA fila esta vazia");
      }
      else
      {
        printf("\nPrimeiro da fila:");
        printf("\n\nNome: %s\n", alunoConsulta.nome);
        printf("Matricula: %d\n", alunoConsulta.matricula);
        printf("Notas:\n");
        printf("\tN1: %.2f\n", alunoConsulta.n1);
        printf("\tN2: %.2f\n", alunoConsulta.n2);
        printf("\tN3: %.2f\n", alunoConsulta.n3);
      }
      break;

    case 5:
      aux = tamanho_Fila(fila);
      if (aux == 0)
        printf("\nA fila e nula");
      else
        printf("\nTamanho: %d", aux);
      break;

    case 6:
      aux = Fila_cheia();
      if (aux == 0)
        printf("\nA fila nao esta cheia");
      break;

    case 7:
      aux = Fila_vazia(fila);
      if (aux == -1)
        printf("\nA fila e nula");
      else if (aux == 0)
        printf("\nA fila nao esta vazia");
      else
        printf("\nA fila esta vazia");
      break;

    case 8:
      imprime_Fila(fila);
      break;

    case 0:
      saida = 0;
      libera_Fila(fila);
      break;

    default:
      printf("\n\n!!! Opcao invalida !!!\n");
      break;
    }
  }

  libera_Fila(fila);
  return 0;
}
