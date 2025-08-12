#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
  int id;
  char nome[30];
  int pesoEntrada;
  int pesoSaida;
  int qtdDiasTratamento;
  int *qtdCaloriasPorDia;
  bool alta;
} Hospede;

typedef struct no
{
  Hospede *hospede;
  struct no *proximo;
} No;

Hospede *inicializarHospede(
    char nome[30],
    bool alta,
    int pesoEntrada,
    int qtdDiasTratamento)
{
  Hospede *hospede = (Hospede *)malloc(sizeof(Hospede));
  hospede->id = 0;
  strcpy(hospede->nome, nome);
  hospede->pesoEntrada = pesoEntrada;
  hospede->alta = alta;
  hospede->qtdDiasTratamento = qtdDiasTratamento;
  return hospede;
}

void definirId(Hospede *hospede, int id)
{
  hospede->id = id;
}

No *inicializarNo(Hospede *hospede)
{
  No *no = (No *)malloc(sizeof(No));
  if (no == NULL)
    return NULL;
  no->hospede = hospede;
  definirId(hospede, 1);
  no->proximo = NULL;

  return no;
}

No *adicionarNo(No *no, Hospede *hospede)
{
  if (no->proximo == NULL)
  {
    No *novo = inicializarNo(hospede);
    definirId(novo->hospede, (no->hospede->id + 1));
    no->proximo = novo;
    return novo;
  }
  else
  {
    return adicionarNo(no->proximo, hospede);
  }
}

void imprimirNo(No *no)
{
  No *atual = no;
  while (atual != NULL)
  {
    printf("\nId: %d\nPaciente: %s\nPeso Entrada: %d", atual->hospede->id, atual->hospede->nome, atual->hospede->pesoEntrada);
    atual = atual->proximo;
  }
}

int obterTamanhoLista(No *lista)
{
  if (lista == NULL)
    return 0;
  int tamanho = 1;
  No *atual = lista;
  while (atual->proximo != NULL)
  {
    tamanho++;
  }
  return tamanho;
}

void liberarNo(No *no)
{
  while (no->proximo != NULL)
  {
    No *temp = no->proximo;
    free(no->hospede);
    free(no);
    no = temp;
  }
}
