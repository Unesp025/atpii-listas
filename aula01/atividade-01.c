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
    int pesoEntrada)
{
  Hospede *hospede = (Hospede *)malloc(sizeof(Hospede));
  hospede->id = 0;
  strcpy(hospede->nome, nome);
  hospede->pesoEntrada = pesoEntrada;
  hospede->alta = false;
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

int main()
{
  Hospede *h1 = inicializarHospede("brunello", 70000);
  Hospede *h2 = inicializarHospede("bruno concli", 75000);
  Hospede *h3 = inicializarHospede("maveco", 4);

  No *lista = inicializarNo(h1);
  adicionarNo(lista, h2);
  adicionarNo(lista, h3);

  imprimirNo(lista);
  liberarNo(lista);
  return 0;
}
