#include<stdio.h>

int main()
{
    char nomeInputAtual[50];
    char arquivoCaminho[50] = "output/nomes.txt";
    FILE *arquivo = fopen(arquivoCaminho, "w");
    for (int i = 0; i < 5; i++)
    {
        printf("\nDigite o %d° nome: ", (i+1));
        scanf("%s", nomeInputAtual);
        fputs(nomeInputAtual, arquivo);
        fputs("\n", arquivo);
    }

    printf("\nEscrita de nomes concluída.");
    fclose(arquivo);
    return 0;
}