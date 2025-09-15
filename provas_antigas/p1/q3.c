#include <stdio.h>
#include <stdlib.h>

struct no
{
	int info;
	struct no *prox;
};

struct no *questao3 (struct no *L1, struct no *L2)
{
	struct no *L3 = (struct no *) malloc(sizeof(struct no));
	struct no *aux;
	aux = L3;
	aux->info = L1->info;
	L1 = L1->prox;
	while (L1 != NULL || L2 != NULL)
	{

	if (L2!= NULL)
	{
		aux->prox = (struct no *) malloc(sizeof(struct no));
		aux = aux->prox;
		aux->info = L2->info;
		L2 = L2->prox;
	}

	if (L1 != NULL)
	{
		aux->prox = (struct no *) malloc(sizeof(struct no));
		aux = aux->prox;
		aux->info = L1->info;
		L1 = L1->prox;
	}
	}
	aux->prox = NULL;
	return L3;
}

void insere_inicio(struct no **atual, int valor)
{
	struct no *novo = (struct no *)malloc(sizeof(struct no));
	novo-> info = valor;
	novo->prox = NULL;
	*atual = novo;
}

void insere_fim(struct no *atual, int valor)
{
	while (atual->prox != NULL)
		atual = atual->prox;

	struct no *novo = (struct no*) malloc(sizeof(struct no));
	novo-> info = valor;
	novo->prox = NULL;
	atual->prox = novo;
}

void imprime_lista(struct no *atual)
{
	while(atual!=NULL)
	{
		printf("\nvalor: %d", atual->info);
		atual = atual->prox;
	}
}

void libera_lista(struct no *atual)
{
	struct no *temp;
	while(atual != NULL)
	{
		temp = atual;
		atual = atual->prox;
		free(temp);
	}
}

int main()
{
	struct no *L1 = NULL;
	insere_inicio(&L1, 1);
	for (int i = 3; i <= 5; i+=2)
	{
		insere_fim(L1, i);
	}

	struct no *L2 = NULL;
	insere_inicio(&L2, 2);
	for (int i = 4; i<=8; i+=2)
	{
		insere_fim(L2, i);
	}
	imprime_lista(L1);
	printf("\n");
	imprime_lista(L2);
	printf("\n");

	struct no *L3;
	L3 = questao3(L1, L2);
	imprime_lista(L3);

	libera_lista(L1);
	libera_lista(L2);
	libera_lista(L3);
	return 0;
}
