// JEAN MOREIRA BORGES DE MORAIS - 20201043021

#define MAXPILHA 50

struct aluno
{
  int matricula;
  char nome[30];
  float n1, n2, n3;
};

typedef struct pilha Pilha;

Pilha *criarPilha();
void liberaPilha(Pilha *pilha);
int push(Pilha *pilha, struct aluno dado);
int pop(Pilha *pilha);
int size(Pilha *pilha);
int stackpop(Pilha *pilha, struct aluno *aluno);
int isEmpty(Pilha *pilha);
int isFull(Pilha *pilha);
void imprimePilha(Pilha *pilha);
int concatenaPilha(Pilha *pilha1, Pilha *pilha2);
int copiaPilha(Pilha *pilha, Pilha *copia);
