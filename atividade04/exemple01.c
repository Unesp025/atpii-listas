#include<stdio.h>
#include<stdlib.h>

struct no
{
	int valor;
	struct no *proximo;
};

void insere_inic(struct no *atual, int valor)
{
	struct no *aux = (struct no *)malloc(sizeof(struct no));
	aux->valor = valor;
	aux->proximo = atual;
	atual=aux;
}

int main()
{
	struct no *p = NULL;
	int valor = 10;

	insere_inic(p, valor);

	if (p==NULL) printf("p eh NULL");
	else printf("valor em p: %d", p->valor);

	free(p);

	return 0;
}
