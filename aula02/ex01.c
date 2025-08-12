#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	char entrada[100];
	printf("Tapez un mot: ");
	scanf("%s", entrada);
	printf("La taille du mot tape est: %d", strlen(entrada)); 
	return 0;
}