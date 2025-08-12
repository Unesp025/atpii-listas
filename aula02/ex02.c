#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char entrada[100];
	int tamanho;
	printf("Digite uma palavra: ");
	scanf("%s", entrada);
	tamanho = strlen(entrada);
	for (int i = tamanho; i >= 0; i--)
	{
		printf("%c", entrada[i]);
	}

	return 0;
}