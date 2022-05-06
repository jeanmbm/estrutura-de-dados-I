// JEAN MOREIRA BORGES DE MORAIS

#include <stdio.h>
#include <stdlib.h>
#include "ListaDuplamenteEncadeada.c"

int main()
{
  struct Aluno a[7] = {
      {1004, "Larisse", 5.1, 7.4, 8.2},
      {1001, "Zenaide", 5.7, 6.1, 7.4},
      {1003, "Arthur", 6.9, 4.1, 4.3},
      {1000, "Allan", 9.5, 7.8, 8.5},
      {1002, "Gabriel", 6.8, 5.7, 7.0}};

  // Criando lista
  Lista *lista = criaLista();

  // Inserindo lista de forma ordenada
  int i;
  for (i = 0; i < 5; i++)
  {
    insereListaOrdenada(lista, a[i]);
  }

  // imprimindo lista
  imprimeLista(lista);

  // Inserindo aluno no inicio da lista
  struct Aluno alunoNovo1 = {1005, "Cirilo Marcos", 6.8, 4.9, 7.3};
  insereInicioLista(lista, alunoNovo1);
  printf("\n\n\n________________ Inserindo aluno no inicio ________________\n");
  imprimeLista(lista);

  // Inserindo aluno no final da lista
  struct Aluno alunoNovo2 = {1006, "Pereira", 2.5, 5.6, 8.7};
  insereFinalLista(lista, alunoNovo2);
  printf("\n\n\n________________ Inserindo aluno no final ________________\n");
  imprimeLista(lista);

  // Removendo aluno no inicio da lista
  removeInicioLista(lista);
  printf("\n\n\n________________ Removendo aluno no inicio ________________\n");
  imprimeLista(lista);

  // Removendo aluno no final da lista
  removeFinalLista(lista);
  printf("\n\n\n________________ Removendo aluno no final ________________\n");
  imprimeLista(lista);

  // Removendo aluno da lista pela matrícula
  removeLista(lista, 1003);
  printf("\n\n\n________________ Removendo aluno pela matrícula ________________\n");
  imprimeLista(lista);

  // Consultando aluno pela posição na lista
  printf("\n\n\n________________ Consultando aluno pela posição na lista ________________\n");
  int posicao = 2;
  int existeAlunoPosicao = consultaListaPosicao(lista, posicao, a);
  if (existeAlunoPosicao == 1)
  {
    printf("\nAluno da posicao %d existe\n", posicao);
  }
  else
  {
    printf("\nAluno da posicao %d não existe\n", posicao);
  }

  // segunda consulta
  posicao = 15;
  int existeAlunoPosicao2 = consultaListaPosicao(lista, 14, a);
  if (existeAlunoPosicao2 == 1)
  {
    printf("\nAluno da posicao %d existe\n", posicao);
  }
  else
  {
    printf("\nAluno da posicao %d não existe\n", posicao);
  }

  // Consultando aluno pela matrícula
  printf("\n\n\n________________ Consultando aluno pela matrícula ________________\n");
  int matricula = 1002;
  int existeMatricula = consultaListaMatricula(lista, matricula, a);
  if (existeMatricula == 1)
  {
    printf("\nAluno da matricula %d existe\n", matricula);
  }
  else
  {
    printf("\nAluno da matricula %d não existe\n", matricula);
  }

  // segunda consulta
  matricula = 1010;
  int existeMatricula2 = consultaListaMatricula(lista, matricula, a);
  if (existeMatricula2 == 1)
  {
    printf("\nAluno da matricula %d existe\n", matricula);
  }
  else
  {
    printf("\nAluno da matricula %d não existe\n", matricula);
  }

  liberaLista(lista);
  system("pause");
  return 0;
}
