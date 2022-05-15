#define MAXPILHA = 40;

typedef struct pilha Pilha;

Pilha *criarPilha();
void liberaPilha(Pilha *pilha);
int push(Pilha *pilha, int dado);
int pop(Pilha *pilha);
int size(Pilha *pilha);
int stackpop(Pilha *pilha);
int empty(Pilha *pilha);
int full(Pilha *pilha);
void imprimePilha(Pilha *pilha);