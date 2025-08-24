#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char nome[50];
    int pesoEmGramasAoEntrar;
    int qtdeDiasTratamento;
    int *listaQtdeCaloriasIngeridasPorDia;
} Hospede;

Hospede *hospedeInicializar(
    char *nome, 
    int pesoEmGramasAoEntrar, 
    int qtdeDiasTratamento,
    int *listaQtdeCaloriasIngeridasPorDia
)
{
    Hospede *novo = (Hospede *) malloc(sizeof(Hospede));
    if (novo == NULL) return NULL;
    strcpy(novo->nome, nome);
    novo->pesoEmGramasAoEntrar = pesoEmGramasAoEntrar;
    novo->qtdeDiasTratamento = qtdeDiasTratamento;
    novo->listaQtdeCaloriasIngeridasPorDia = listaQtdeCaloriasIngeridasPorDia;

    return novo;
}

void hospedeImprimir(Hospede *hospede)
{
    printf(
        "Nome: %s"
        "\nPeso ao entrar (gramas): %d"
        "\nQtde dias tratamento: %d"
        "\nQtde de calorias ingerida por dia de tratamento:\n",
        hospede->nome, hospede->pesoEmGramasAoEntrar, hospede->qtdeDiasTratamento
    );
    int atual;
    for (int i = 0; i < hospede->qtdeDiasTratamento; i++)
    {
        atual = hospede->listaQtdeCaloriasIngeridasPorDia[i];
        printf("- dia %d: %d\n", i+1, atual);
    }
}

void hospedeLiberarEspacoMemoria(Hospede *hospede)
{
    free(hospede->listaQtdeCaloriasIngeridasPorDia);
    free(hospede);
}

typedef struct no 
{
    int id;
    Hospede *hospede;
    struct no *proximo;
} No;

No *noInicializar(int id, Hospede *hospede)
{
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) return NULL;
    novo->id = id;
    novo->hospede = hospede;
    novo->proximo = NULL;

    return novo;
}

No *noAdicionarAoFinal(No *no, Hospede *hospede)
{
    if (no->proximo==NULL)
    {
        No *novo = noInicializar(no->id + 1, hospede);
        no->proximo = novo;
        return novo;
    }
    return noAdicionarAoFinal(no->proximo, hospede);
}

void noImprimir(No *no)
{
    No *atual = no;
    while (atual != NULL)
    {
        printf("ID: %d\n", atual->id);
        hospedeImprimir(atual->hospede);
        atual = atual->proximo;
    }
}

void noLiberarEspacoMemoria(No* no)
{
    while (no != NULL)
    {
        No *temp = no->proximo;
        hospedeLiberarEspacoMemoria(no->hospede);
        free(no);
        no = temp;
    }
}
