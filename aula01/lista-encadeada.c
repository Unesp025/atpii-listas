#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
  int num;
  struct no *proximo;
} No;

No *inicializarNo(int num)
{
  No *no = (No *)malloc(sizeof(No));
  if (no == NULL)
    return NULL;
  no->num = num;
  no->proximo = NULL;

  return no;
}

No *adicionarNo(No *no, int num)
{
  if (no->proximo == NULL)
  {
    No *novo = inicializarNo(num);
    no->proximo = novo;
    return novo;
  }
  return adicionarNo(no->proximo, num);
}

void removerNoByValor(No *no, int num)
{
  No *atual = no;
  No *temp = no;
  while (atual != NULL)
  {
    if (atual->num == num)
    {
      temp = atual->proximo;
      free(atual);
      return;
    }
    temp = atual;
    atual = atual->proximo;
  }
  printf("\nValor nao encontrado.\n");
}

void imprimirNo(No *no)
{
  No *atual = no;
  while (atual != NULL)
  {
    printf("\n%d", atual->num);
    atual = atual->proximo;
  }
}

void liberarNo(No *no)
{
  while (no != NULL)
  {
    No *temp = no->proximo;
    free(no);
    no = temp;
  }
}