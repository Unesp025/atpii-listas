#include<stdio.h>
#include<stdlib.h>
#include "estruturas.c"

void exibirMensagem(char *mensagem)
{
  printf("\e[1;1H\e[2J");
  printf("\n%s", mensagem);
  printf("\n\nPressione [ENTER] para continuar...\n");
  getchar();
  getchar();
  printf("\e[1;1H\e[2J");
}

void cadastrarNovoHospede(No *lista)
{
  char nome[30];
  int pesoEntrada, qtdDiasTratamento = -1;
  char altaBinario = -1;
  bool alta;
  printf("\n= Cadastro de hospede =\n");
  printf("\nNome: ");
  scanf("%s", &nome);

  printf("\nPeso entrada: ");
  scanf("%d", &pesoEntrada);

  while (altaBinario >1 || altaBinario < 0)
  {
    printf("\nRecebeu alta? (1 - sim / 0 - nao): ");
    scanf("%d", &altaBinario);
  }
  if (altaBinario == 1)
    alta = true;
  else
    alta = false;

  while (qtdDiasTratamento>20 || qtdDiasTratamento < 1)
  {
    printf("\nQuantos dias de tratamento?: ");
    scanf("%d", &qtdDiasTratamento);
  }

  Hospede *hospede = inicializarHospede(nome, alta, pesoEntrada, qtdDiasTratamento);
  if (obterTamanhoLista(lista) == 0)
  {
    lista = inicializarNo(hospede);
  }
  else
  {
    adicionarNo(lista, hospede);
  }
  exibirMensagem("Hospede adicionado com sucesso!");
}

void removerHospede(No *lista)
{
  int id;
  printf("\nId da remocao: ");
  scanf("%d", id);
  No *atual = lista;
  No *temp = atual;
  while (atual != NULL)
  {
    if (atual->hospede->id == id)
    {
    }
  }
}

void exibirHospede(No *lista)
{
  printf("\n= Lista de hospedes =\n\n");
  imprimirNo(lista);
  exibirMensagem("");
}

void menu(No *lista)
{
  printf("\e[1;1H\e[2J");
  int opcao;
  printf("\n= Escolha uma acao = ");
  printf(
      "\n0 - Concluir"
      "\n1 - Adicionar"
      "\n2 - Dar baixa"
      "\n3 - Exibir\n\n");
  scanf("%d", &opcao);
  printf("\e[1;1H\e[2J");
  if (opcao == 0)
  {
    printf("\n\tEncerrando operacao..");
    return;
  }
  else if (opcao == 1)
  {
    cadastrarNovoHospede(lista);
  }
  else if (opcao == 2)
  {
    removerHospede(lista);
  }
  else if (opcao == 3)
  {
    exibirHospede(lista);
  }

  menu(lista);
}
