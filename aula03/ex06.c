#include<stdio.h>

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        printf("Forneca os dois arquivos de entrada e um de saida.");
        return 1;
    }
    char *entrada1Caminho = argv[1], *entrada2Caminho = argv[2], *saidaCaminho = argv[3];
    FILE *entrada1 = fopen(entrada1Caminho,  "r");
    FILE *entrada2 = fopen(entrada2Caminho,  "r");
    FILE *saida = fopen(saidaCaminho,  "a");

    char linha1[100];
    char linha2[100];
    while (fgets(linha1, 100, entrada1) != NULL)
    {
        fputs(linha1, saida);
    }
    while (fgets(linha2, 100, entrada2) != NULL)
    {
        fputs(linha2, saida);
    }

    fclose(entrada1);
    fclose(entrada2);
    fclose(saida);
    return 0;
}