#include<stdio.h>
#include<string.h>

bool ehPalindromo(char *palavra)
{
	int tamanho = strlen(palavra);
	for (int i = 0; i < tamanho/2; i++)
	{
		if (palavra[i] != palavra[tamanho-(1+i)]) return false;
	}
	return true;
}

int main()
{
	char entrada[100];
	printf("Digite uma palavra: ");
	scanf("%s", entrada);	
	bool palindromo = ehPalindromo(entrada);
	if (palindromo) printf("Sim,'%s' eh palindromo.", entrada);
	else printf("Nao, '%s' nao eh palindromo.", entrada);

	return 0;
}