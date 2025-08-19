#include<stdio.h>

int main()
{
    char arquivoCaminho[50] = "input\\nomes.txt";
    FILE *arquivo = fopen(arquivoCaminho, "r");
    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL)
    {
        printf("%s", linha);
    }
    printf("\nConcluida leitura do arquivo.");
    fclose(arquivo);
    return 0;
}