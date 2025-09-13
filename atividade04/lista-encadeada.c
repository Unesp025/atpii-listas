#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct regFunc
{
	int numeroMatricula;
	char nome[50];
	struct regFunc *proximo;
};

void insere_inicio(struct regFunc **atual, int numeroMatricula, char *nome)
{
	struct regFunc *aux = (struct regFunc *)malloc(sizeof(struct regFunc));
	aux->numeroMatricula = numeroMatricula;
	strcpy(aux->nome, nome);
	aux->proximo = *atual;
	*atual = aux;
}

void insere_fim(struct regFunc *atual, int numeroMatricula, char *nome)
{
	while (atual->proximo != NULL)
	{
		atual = atual->proximo;
	}
	struct regFunc *aux = (struct regFunc *) malloc(sizeof(struct regFunc));
	strcpy(aux->nome, nome);
	aux->numeroMatricula = numeroMatricula;
	aux->proximo = NULL;
	atual->proximo = aux;
}

void imprime_lista(struct regFunc *atual)
{
	while(atual != NULL)
	{
		printf("\nMatricula: %d\nNome: %s", atual->numeroMatricula, atual->nome);
		atual = atual->proximo;
	}
	printf("\nFim da lista...\n");
}

void libera_lista(struct regFunc *head)
{
	struct regFunc *temp;
	while (head != NULL)
	{
		temp = head;
		head = head->proximo;
		free(temp);
	}
}

int main()
{
	struct regFunc *listaRFunc = NULL;
	int nMat01 = 1;
	char nome01[] = "guapo";

	int nMat02 = 2;
	char nome02[] = "giorgita";

	int nMat03 = 3;
	char nome03[] = "jerardio";

	insere_inicio(&listaRFunc, nMat01, nome01);

	insere_fim(listaRFunc, nMat02, nome02);
	insere_fim(listaRFunc, nMat03, nome03);

	imprime_lista(listaRFunc);
	libera_lista(listaRFunc);

	return 0;
}
