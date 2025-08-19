#include<stdio.h>
#include<string.h>

int main (int argc, char *argv[])
{
    char *arquivoOrigem, *arquivoSaida;
    if (argc < 3) 
    {
        printf("\nInforme os aruqivos, seu bucha");
        return 1;
    }
    arquivoOrigem = argv[1];
    arquivoSaida = argv[2];
    FILE *entrada = fopen(arquivoOrigem, "r");
    FILE *saida = fopen(arquivoSaida, "a");
    char linha[100];
    while (fgets(linha, 100, entrada) != NULL)
    {
        fputs(linha, saida);
    }
    return 0;
}
