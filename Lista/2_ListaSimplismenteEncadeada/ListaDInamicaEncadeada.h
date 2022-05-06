struct aluno
{
  int matricula;
  char nome[30];
  float n1, n2, n3;
};

typedef struct elemento *Lista;

Lista *criaLista();
void liberaLista(Lista *lista);
int tamanhoLista(Lista *lista);
int ListaCheia(Lista *lista);
int listaVazia(Lista *lista);
int inserirInicio(Lista *lista, struct aluno aluno);
int inserirFinal(Lista *lista, struct aluno aluno);
int insereOrdenado(Lista *lista, struct aluno aluno);
int removeInicio(Lista *lista);
int removeFim(Lista *lista);
int remove(Lista *lista, int matricula);
int cosultaPosicao(Lista *lista, int posicao, struct aluno *aluno);
int cosultamatricula(Lista *lista, int matricula, struct aluno *aluno);
