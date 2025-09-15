#include<stdio.h>
#include<stdlib.h>

void ordena_vet(int *vet, int tam)
{
	int cont;
	do
	{
		cont = 0;
		for (int i = 0; i < tam-1; i++)
		{
			if (vet[i] > vet[i+1])
			{
				int temp = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = temp;
				cont++;
			}
		}
	}
	while (cont != 0);
}

int main()
{
	int vet[6] = {3, 7, 2, 5, 1, 6};
	ordena_vet(vet, 6);
	for (int i = 0; i< 6; i++)
		printf("%d\n", vet[i]);

	return 0;
}
