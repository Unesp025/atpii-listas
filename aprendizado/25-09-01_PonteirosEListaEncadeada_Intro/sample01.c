#include<stdlib.h>

struct no
{
	int info;
	struct no *prox;
};

void insere_inicio(struct no **atual, int v)
{
	struct no *aux; // nesse momento é lixo.
	aux = (struct no *) malloc(sizeof(struct no)); // aux ganha uma posição de memória válida.

	aux->info = v; // atrbuto info do no para o qual o ponteiro aux aponta recebe uma cópia do valor de v.
	aux->prox = *atual; // atributo prox do no para o qual o ponteiro aux aponta recebe o conteúdo de *atual, que é o endereço do ponteiro p da main.
	// ou seja, agora: aux->prox aponta para onde *atual aponta.
	*atual = aux; // o conteúdo de **atual, que é o endereço do ponteiro p na main, recebe uma copia do conteúdo de aux, que é o endereço do no alocado no começo da função.

	// quando a funcao acaba, atual, v e aux deixam de existir.
}

int main()
{
	struct no *p = NULL;
	return 0;
}

