#include<stdio.h>
#include<stdlib.h>

struct no
{
	int info;
	struct no *prox;
};

void inserirInicio(struct no **atual, int v)
{
	struct no *aux;
	aux = (struct no *) malloc(sizeof(struct no));
	// *aux.info = v;
	aux->info = v;
	aux->prox = *atual;
	*atual = aux;
}

void imprimirLista(struct no **atual)
{
	while (atual !=NULL)
	{
		printf(
		atual = atual->prox;
	}
}

int main()
{
	struct no *p = NULL;
	int valor = 10;
	inserirInicio(&p, valor);

	return 0;
}

