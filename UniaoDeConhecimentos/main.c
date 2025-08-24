#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct 
{
    char nome[50];
    int pesoEmGramasAoEntrar;
    int qtdeDiasTratamento;
    int *listaQtdeCaloriasIngeridasPorDia;
} Hospede;

Hospede *hospedeInicializar(
    char *nome, 
    int pesoEmGramasAoEntrar, 
    int qtdeDiasTratamento,
    int *listaQtdeCaloriasIngeridasPorDia
)
{
    Hospede *novo = (Hospede *) malloc(sizeof(Hospede));
    if (novo == NULL) return NULL;
    strcpy(novo->nome, nome);
    novo->pesoEmGramasAoEntrar = pesoEmGramasAoEntrar;
    novo->qtdeDiasTratamento = qtdeDiasTratamento;
    novo->listaQtdeCaloriasIngeridasPorDia = listaQtdeCaloriasIngeridasPorDia;

    return novo;
}

void hospedeImprimir(Hospede *hospede)
{
    printf(
        "Nome: %s"
        "\nPeso ao entrar (gramas): %d"
        "\nQtde dias tratamento: %d"
        "\nQtde de calorias ingerida por dia de tratamento:\n",
        hospede->nome, hospede->pesoEmGramasAoEntrar, hospede->qtdeDiasTratamento
    );
    int atual;
    for (int i = 0; i < hospede->qtdeDiasTratamento; i++)
    {
        atual = hospede->listaQtdeCaloriasIngeridasPorDia[i];
        printf("- dia %d: %d\n", i+1, atual);
    }
}

void hospedeLiberarEspacoMemoria(Hospede *hospede)
{
    free(hospede->listaQtdeCaloriasIngeridasPorDia);
    free(hospede);
}

typedef struct no 
{
    int id;
    Hospede *hospede;
    struct no *proximo;
} No;

No *noInicializar(int id, Hospede *hospede)
{
    No *novo = (No *) malloc(sizeof(No));
    if (novo == NULL) return NULL;
    novo->id = id;
    novo->hospede = hospede;
    novo->proximo = NULL;

    return novo;
}

No *noAdicionarAoFinal(No *no, Hospede *hospede)
{
    if (no->proximo==NULL)
    {
        No *novo = noInicializar(no->id + 1, hospede);
        no->proximo = novo;
        return novo;
    }
    return noAdicionarAoFinal(no->proximo, hospede);
}

void noImprimir(No *no)
{
    No *atual = no;
    while (atual != NULL)
    {
        printf("ID: %d\n", atual->id);
        hospedeImprimir(atual->hospede);
        atual = atual->proximo;
    }
}

void noLiberarEspacoMemoria(No* no)
{
    while (no != NULL)
    {
        No *temp = no->proximo;
        hospedeLiberarEspacoMemoria(no->hospede);
        free(no);
        no = temp;
    }
}

void cliCadastrarUsuario(No *no)
{
    char nome[50];
    int pesoEmGramasAoEntrar;
    int qtdeDiasTratamento;
    int *listaQtdeCaloriasIngeridasPorDia;
    printf("\n== CADASTRO DE HOSPEDE ==\n");
    printf("Nome: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0;
    printf("Peso ao entrar (gramas): ");
    scanf("%d", &pesoEmGramasAoEntrar);
    printf("Qtde dias tratamento: ");
    scanf("%d", &qtdeDiasTratamento);

    printf(
        "Informe abaixo a qtde de calorias que deve ser \ningerida para cada dia do tratamento (%d dias):\n", 
        qtdeDiasTratamento
    );
    int valor;
    for (int i = 0; i < qtdeDiasTratamento; i++)
    {
        printf("- dia %d: ", i+1);
        scanf("%d", &valor);
        listaQtdeCaloriasIngeridasPorDia[i] = valor;
    }
    noAdicionarAoFinal(
        no, 
        hospedeInicializar(nome, pesoEmGramasAoEntrar, qtdeDiasTratamento, listaQtdeCaloriasIngeridasPorDia));
}

int main()
{
    char h1Nome[] = "rulio";
    int h1ListaCalorias[5] = {1000, 1000, 1200, 1200, 1300};
    Hospede *h1 = hospedeInicializar(h1Nome, 50000, 5, h1ListaCalorias);
    
    char h2Nome[] = "camidjo";
    int h2ListaCalorias[7] = {2000, 2000, 2200, 2200, 2300, 2300, 2300};
    Hospede *h2 = hospedeInicializar(h2Nome, 75000, 7, h2ListaCalorias);
    
    No *listaCadastros = noInicializar(1, h1);
    noAdicionarAoFinal(listaCadastros, h2);

    noImprimir(listaCadastros);
    noLiberarEspacoMemoria(listaCadastros);
    
    return 0;
}