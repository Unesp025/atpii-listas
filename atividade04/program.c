#include <stdio.h>
#include <stdlib.h>
#include "lista-encadeada.c"

int main()
{

	int qtdeFunc;
	printf("Quantos funcionarios deseja cadastrar?: ");
	scanf("%d", &qtdeFunc);

	struct regFunc *listaRFunc = NULL;
	for (int i =0; i< qtdeFunc; i++)
	{
		char nome[30];
		printf("\nNome: ");
		scanf("%s", nome);
		if (listaRFunc == NULL)
			insere_inicio(&listaRFunc, i+1, nome);

		else insere_fim(listaRFunc, i+1, nome);
	}
	imprime_lista(listaRFunc);
	libera_lista(listaRFunc);
	return 0;
}
