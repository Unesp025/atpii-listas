#include<stdio.h>
#include<stdlib.h>

struct no
{
	int info;
	struct no *prox;
};

int tamanho(struct no *atual)
{
	int contador = 0;
	while(atual!=NULL)
	{
		contador++;
		atual = atual->prox;
	}
	return contador;
}

int tamanho_rec(struct no *atual)
{
	if (atual == NULL) return 0;
	return tamanho_rec(atual->prox) + 1;
}

void insere_inicio(struct no **atual, int valor)
{
	struct no *aux = (struct no *)malloc(sizeof(struct no));
	aux->info = valor;
	aux->prox = NULL;
	*atual = aux;
}

void insere_fim(struct no *atual, int valor)
{
	while(atual->prox!=NULL)
		atual = atual->prox;

	struct no *aux = (struct no *)malloc(sizeof(struct no));
	aux->info = valor;
	aux->prox = NULL;
	atual->prox = aux;
}

void imprime_lista(struct no *atual)
{
	while (atual!=NULL)
	{
		printf("\nvalor: %d", atual->info);
		atual = atual->prox;
	}
}

void libera_lista(struct no *atual)
{
	struct no *temp;
	while(atual->prox =NULL)
	{
		temp = atual;
		atual = atual->prox;
		free(temp);
	}
}

int main()
{
	struct no *lista = NULL;
	insere_inicio(&lista, 1);
	for (int i = 2; i < 18; i++)
	{
		insere_fim(lista, i);
	}
	imprime_lista(lista);
	printf("\ntamanho: %d\ntamanho recursivo: %d", tamanho(lista), tamanho_rec(lista));
	libera_lista(lista);
	return 0;
}

