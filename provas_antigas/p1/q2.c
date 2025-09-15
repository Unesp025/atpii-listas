#include <stdio.h>
#include <stdlib.h>

void questao2(char origem[], char destino[])
{
	FILE *f_origem, *f_destino;
	f_origem = fopen(origem, "r");
	f_destino = fopen(destino, "w");
	if (f_origem == NULL || f_destino == NULL)
	{
		printf("erro ao abrir arquivo");
		return;
	}
	char linha[100];
	while (fgets(linha, 100, f_origem) != NULL)
	{
		fputs(linha, f_destino);
	}
}

int main()
{
	char origem[100] = "D:/unesp/atpii-listas/provas_antigas/p1/arquivos/origem.txt";
	char destino[100] = "D:/unesp/atpii-listas/provas_antigas/p1/arquivos/destino.txt";

	questao2(origem, destino);
	printf("\noperacao concluida\n");
	return 0;
}
