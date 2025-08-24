#include "ListaEncadeadaHospede.c"

typedef void (*OperacaoGestaoHospede)();

typedef struct
{
    int id;
    char descricao[256];
    OperacaoGestaoHospede operacao;
} Opcao;

void cliCadastrarUsuario(No *no)
{
    char nome[50];
    int pesoEmGramasAoEntrar;
    int qtdeDiasTratamento;
    
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
    int *listaQtdeCaloriasIngeridasPorDia;
    for (int i = 0; i < qtdeDiasTratamento; i++)
    {
        printf("- dia %d: ", i+1);
        scanf("%d", &valor);
        listaQtdeCaloriasIngeridasPorDia[i] = valor;
    }

    if (no == NULL)
        no = noInicializar(
            1,
            hospedeInicializar(
                nome,
                pesoEmGramasAoEntrar,
                qtdeDiasTratamento,
                listaQtdeCaloriasIngeridasPorDia
            )
        );
    else
        noAdicionarAoFinal(
            no,
            hospedeInicializar(
                nome,
                pesoEmGramasAoEntrar,
                qtdeDiasTratamento,
                listaQtdeCaloriasIngeridasPorDia
            )
        );
}

void cliMenu()
{
    printf(
        "AMBIENTE GESTAO DE HOSPEDES - SPA REI MOMO\n\n"
        "Selecione o que deseja fazer:\n");
    
}