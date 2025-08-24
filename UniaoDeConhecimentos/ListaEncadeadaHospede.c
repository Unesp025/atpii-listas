#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>

typedef struct 
{
    char nome[50];
    int pesoEmGramasAoEntrar;
    int pesoEmGramasAoSair;
    int qtdeDiasTratamento;
    int *listaQtdeCaloriasIngeridasPorDia;
    bool alta;
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
    novo->alta = false;
    novo->pesoEmGramasAoSair = -1;

    return novo;
}

void hospedeImprimir(Hospede *hospede)
{
    printf(
        "RECEBEU ALTA?: %s"
        "\n* Nome: %s"
        "\n* Peso ao entrar (gramas): %d"
        "\n* Peso ao sair (gramas): %d"
        "\n* Qtde dias tratamento: %d"
        "\n* Qtde de calorias ingerida por dia de tratamento:\n",
        hospede->alta ? "Sim" : "Nao",
        hospede->nome, hospede->pesoEmGramasAoEntrar, 
        hospede->pesoEmGramasAoSair, hospede->qtdeDiasTratamento
    );
    if (hospede->listaQtdeCaloriasIngeridasPorDia != NULL)
    {
        int atual;
        for (int i = 0; i < hospede->qtdeDiasTratamento; i++)
        {
            atual = hospede->listaQtdeCaloriasIngeridasPorDia[i];
            printf("- dia %d: %d\n", i+1, atual);
        }
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
    if (no != NULL)
    {
        No *atual = no;
        while (atual != NULL)
        {
            printf("\nID: %d\n", atual->id);
            hospedeImprimir(atual->hospede);
            atual = atual->proximo;
        }
    }
    else
    {
        printf("Nenhum valor para imprimir.");
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
