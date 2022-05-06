// ALUNO: JEAN MOREIRA, 20201043021

#include <stdio.h>
#include <stdlib.h>
#include "./ListaSequencial.c"

void mostraTamanhoLista(Lista *li)
{
    int tamanho = tamanho_lista(li);
    if (tamanho != -1)
        printf("A lista possui %d\n alunos", tamanho);
    else
        printf("A lista não existe");
}

int main()
{
    struct aluno a[15] = {
        {1011, "Carla", 5.6, 1.5, 6.8},
        {1005, "Larisse", 5.1, 7.4, 8.2},
        {1007, "Michael", 6.3, 5.8, 2.5},
        {1001, "Zenaide", 5.7, 6.1, 7.4},
        {1009, "Bernardo", 5.9, 6.1, 8.4},
        {1012, "Kellen", 7.8, 5.0, 5.7},
        {1003, "Arthur", 6.9, 4.1, 4.3},
        {1000, "Alexandre", 9.5, 7.8, 8.5},
        {1006, "Leandro", 9.2, 8.4, 7.9},
        {1008, "Allan", 6.1, 7.8, 8.5},
        {1004, "Laura", 8.1, 6.8, 9.8},
        {1002, "Gabriel", 6.8, 5.7, 7.0},
        {1010, "Miguel", 9.6, 8.3, 8.0},
    };

    // Criando lista
    Lista *lista = cria_lista();

    // lista vazia
    printf("\n________________ Verificando se a lista está vazia ________________\n");
    int vazia1 = lista_vazia(lista);
    if (vazia1 == 1)
        printf("\nA lista está vazia\n");
    else
        printf("\nA lista não está vazia\n");

    // Inserindo lista de forma ordenada
    for (int i = 0; i < 13; i++)
    {
        insere_lista_ordenada(lista, a[i]);
    }

    // imprimindo lista
    imprime_lista(lista);

    // Mostrando o tamanho da lista
    mostraTamanhoLista(lista);

    // Inserindo aluno no inicio da lsita
    struct aluno alunoNovo1 = {1013, "Cirilo Marcos", 6.8, 4.9, 7.3};
    insere_lista_inicio(lista, alunoNovo1);
    printf("\n\n\n________________ Inserindo aluno no inicio ________________\n");
    imprime_lista(lista);
    mostraTamanhoLista(lista);

    // Inserindo aluno no final da lsita
    struct aluno alunoNovo2 = {1014, "Pereira", 2.5, 5.6, 8.7};
    insere_lista_final(lista, alunoNovo2);
    printf("\n\n\n________________ Inserindo aluno no final ________________\n");
    imprime_lista(lista);
    mostraTamanhoLista(lista);

    // Removendo aluno no inicio da lista
    int removidoInicio = remove_lista_inicio(lista);
    if (removidoInicio != 0)
    {
        printf("\n\n\n________________ Removendo aluno no inicio ________________\n");
        printf("\n!! Aluno removido com sucesso  !!\n");
        imprime_lista(lista);
        mostraTamanhoLista(lista);
    }
    else
    {
        printf("\nA lista não existe\n");
    }

    // Removendo aluno no final da lista
    int removidoFinal = remove_lista_final(lista);
    if (removidoFinal != 0)
    {
        printf("\n________________ Removendo aluno no final ________________\n");
        printf("\n!! Aluno removido com sucesso !!\n");
        imprime_lista(lista);
        mostraTamanhoLista(lista);
    }
    else
    {
        printf("\nA lista não existe\n");
    }

    // Removendo aluno da lista pela matrícula
    int removido = remove_lista(lista, 1004);
    if (removidoFinal != 0)
    {
        printf("\n________________ Removendo aluno pela matrícula ________________\n");
        printf("\n!! Aluno removido com sucesso !!\n");
        imprime_lista(lista);
        mostraTamanhoLista(lista);
    }
    else
    {
        printf("\nA lista não existe\n");
    }

    // Consultando aluno pela posição na lista
    printf("\n________________ Consultando aluno pela posição na lista ________________\n");
    int existeAlunoPosicao = consulta_lista_pos(lista, 5, a);
    if (existeAlunoPosicao == 1)
    {
        printf("\nAluno Existe\n");
    }
    else
    {
        printf("\nAluno não existe\n");
    }

    // segunda consulta
    int existeAlunoPosicao2 = consulta_lista_pos(lista, 14, a);
    if (existeAlunoPosicao2 == 1)
    {
        printf("\nAluno Existe\n");
    }
    else
    {
        printf("\nAluno não existe\n");
    }

    // Consultando aluno pela matrícula
    printf("\n________________ Consultando aluno pela matrícula ________________\n");
    int existeMatricula = consulta_lista_mat(lista, 1007, a);
    if (existeMatricula == 1)
    {
        printf("\nAluno Existe\n");
    }
    else
    {
        printf("\nAluno nao existe\n");
    }

    // segunda consulta
    int existeMatricula2 = consulta_lista_mat(lista, 1005, a);
    if (existeMatricula2 == 1)
    {
        printf("\nAluno Existe\n");
    }
    else
    {
        printf("\nAluno nao existe\n");
    }

    // lista cheia
    printf("\n________________ Verificando se a lista está cheia ________________\n");
    int cheia = lista_cheia(lista);
    if (cheia == 1)
        printf("\nA lista está cheia\n");
    else
        printf("\nA lista não está cheia\n");

    // lista vazia
    printf("\n________________ Verificando se a lista está vazia ________________\n");
    int vazia = lista_vazia(lista);
    if (vazia == 1)
        printf("\nA lista está vazia\n");
    else
        printf("\nA lista não está vazia\n");

    printf("\n\n\n\n\n");

    // Liberando espaço da lista
    libera_lista(lista);

    system("pause");

    return 0;
}
