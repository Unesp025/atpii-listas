#include<stdio.h>
#include<string.h>

int main(int argc, char **argv)
{
    if (argc < 3) 
    {
        printf("\nWARN: Forneca o arquivo de entrada e a palavra buscada\n");
        return 1;
    }
    char *entradaNome = argv[1];
    char *palavraBuscada = argv[2];
    FILE *entrada = fopen(entradaNome, "r");
    char linha[100];
    int linhaAtualIndex = 0;
    while (fgets(linha, 100, entrada) != NULL)
    {
        if (strstr(linha, palavraBuscada))
            printf("\nPalavra encontrada na linha %d: ", linhaAtualIndex+1);
        linhaAtualIndex++;
    } 
    fclose(entrada);
    return 0;
}