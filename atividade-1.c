#include<stdio.h>
#include<stdbool.h>
#include<string.h>

typedef struct {
	int idFicha;
	char nome[30];
	int pesoEntrada;
	int pesoSaida;
	int qtdDiasTratamento;
	int *qtdCaloriasPorDia;
	bool alta;
} Hospede;

typedef struct no
{
	Hospede hospede;
	struct no *proximo;
} No;

int *preencherCaloriasPorDia(Hospede *hospede, int pesoSaida)

Hospede *inicializarHospede(
	char nome[30],
	int pesoEntrada)
{
	Hospede *hospede = (Hospede *) malloc(sizeof(Hospede));
	strcpy(hospede->nome, nome);
	hospede->pesoEntrada = pesoEntrada;
	hospede->alta = false;
}

void definirIdFicha(Hospede *hospede, int idFicha)
{
	hospede->idFicha = idFicha;
}

No *inicializarNo(Hospede *hospede)
{
	No *no = (No *) malloc(sizeof(No));
	if (no == NULL) return NULL;
	no->hospede=hospede;
	definirIdFicha(hospede, 1);
	no->proximo=null;

	return no;
}

No *adicionarNo(No *no, Hospede *hospede)
{
	if (no->proximo==NULL)
	{
		No *novo = inicializarNo(hospede);
		definirIdFicha(novo->hospede, (no->id+1));
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
	while(atual!=NULL)
	{
		printf("\nPaciente: %s\nPeso Entrada: %d", no->hospede->nome, no->hospede->pesoEntrada);
		atual = atual->proximo;
	}
}

void liberarNo(No *no)
{
	while(no->proximo!=NULL)
	{
		No *temp = no->proximo;
		free(no->hospede);
		free(no);
		no = temp;
	}

}

int main ()
{
	Hospede *h1 = inicializarHospede("brunello", 70000);
	Hospede *h2 = inicializarHospede("bruno concli", 75000);

	No *lista = inicializarNo(h1);
	adicionarNo(lista, h2);

	imprimirNo(lista);
	liberarNo(lista);
	return 0;
}
