// JEAN MOREIRA BORGES DE MORAIS

struct Aluno
{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};

typedef struct elemento *Lista;

Lista *criaLista();
void liberaLista(Lista *lista);
int consultaListaPosicao(Lista *lista, int posicao, struct Aluno *auluno);
int consultaListaMatricula(Lista *lista, int matricula, struct Aluno *aluno);
int insereInicioLista(Lista *lista, struct Aluno al);
int insereFinalLista(Lista *lista, struct Aluno al);
int insereListaOrdenada(Lista *lista, struct Aluno al);
int removeLista(Lista *lista, int matricula);
int removeInicioLista(Lista *lista);
int removeFinalLista(Lista *lista);
void imprimeLista(Lista *lista);
