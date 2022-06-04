// FilaEstatica.h
#define MAX 50

struct aluno
{
  int matricula;
  char nome[30];
  float n1, n2, n3;
};

typedef struct fila Queue;

Queue cria_Queue();
void libera_Queue(Queue *que);
int tamanho_Queue(Queue *que);
int isFull(Queue *que);
int isEmpty(Queue *que);
int enqueue(Queue *que, struct aluno al);
int dequeue(Queue *que);
int consulta_Queue(Queue *que, struct aluno *al);
void imprimirFila(Queue *que);
