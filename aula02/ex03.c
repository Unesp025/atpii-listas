#include<stdio.h>
#include<string.h>

int contarOcorrencias(char *palavra, char *vetorComparacao)
{
	int contador = 0;	
	
	for (int i = 0; i < strlen(palavra); i++)
	{
		for (int j =0; j < strlen(vetorComparacao); j++)
		{
			if (vetorComparacao[j] == palavra[i])
			{
				contador++;
				break;
			}
		}
	}
	return contador;
}

int main()
{
	int tamanho;
	char vogais[6] = {'a','e','i','o','u','\0'};
	char entrada[100];
	printf("Digite uma UNICA palavra (NAO MAIS DE UMA): ");
	scanf("%s", entrada);
	tamanho = contarOcorrencias(entrada, vogais);
	printf("Ha %d vogais na palara %s", tamanho, entrada);
	
	return 0;
}