#include <stdio.h>
#include <stdlib.h>
#include "ListaDInamicaEncadeada.c"

int main()
{
  Lista *lista;

  lista = criaLista();
  int x;
  x = tamanhoLista(lista);
  printf("Tamanho da lista: %d", x);

  x = listaCheia(lista);
  if (listaCheia(lista))
    printf("Lista está cheia");

  x = listaVazia(lista);
  if (listaVazia(lista))
    printf("Lista está vazia");

  struct aluno aluno = {20201, "Fulano de tal", 7.8, 6.9, 6.1};
  x = inserirInicio(lista, aluno);

  struct aluno aluno2 = {20202, "Ciclano", 5.8, 7.9, 6.6};
  x = inserirFinal(lista, aluno2);

  liberaLista(lista);

  return 0;
};