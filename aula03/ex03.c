#include<stdio.h>

int main()
{
    char arquivoNome[50] = "input\\nomes.txt";
    FILE *arquivo = fopen(arquivoNome, "r");
    int contador = 0;
    char linha[100];
    while (fgets(linha, 100, arquivo) != NULL)
    {
        contador++;
    }
    printf("\nO arquivo informado tem %d linhas", contador);
    fclose(arquivo);
    return 0;
}