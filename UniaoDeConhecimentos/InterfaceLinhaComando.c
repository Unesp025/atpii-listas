#include "ListaEncadeadaHospede.c"

No *cadastrarHospede(No *no)
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
    while(qtdeDiasTratamento > 20)
    {
        printf("O tempo maximo de hospedagem e 20 dias: ");
        scanf("%d", &qtdeDiasTratamento);
    }

    printf(
        "Informe abaixo a qtde de calorias que deve ser \ningerida para cada dia do tratamento (%d dias):\n", 
        qtdeDiasTratamento
    );
    int valor;
    int *listaQtdeCaloriasIngeridasPorDia = (int*) malloc(sizeof(int) * qtdeDiasTratamento);
    for (int i = 0; i < qtdeDiasTratamento; i++)
    {
        printf("- dia %d: ", i+1);
        scanf("%d", &valor);
        listaQtdeCaloriasIngeridasPorDia[i] = valor;
    }

    No *noRetorno;
    if (no == NULL)
    {
        noRetorno = noInicializar(
            1,
            hospedeInicializar(
                nome,
                pesoEmGramasAoEntrar,
                qtdeDiasTratamento,
                listaQtdeCaloriasIngeridasPorDia
            )
        );
        return noRetorno;
    }
    else
    {
        noAdicionarAoFinal(
            no,
            hospedeInicializar(
                nome,
                pesoEmGramasAoEntrar,
                qtdeDiasTratamento,
                listaQtdeCaloriasIngeridasPorDia
            )
        );
        return no;
    }
}

void darAltaEmHospedePorId(No *no)
{
    int id;
    printf("Informe o ID do hospede que deseja dar alta (0 para cancelar): ");
    scanf("%d", id);
    if (id != 0)
    {
        No *atual = no;
        while (atual->proximo != NULL)
        {
            if (atual->id == id)
            {
                int pesoEmGramasAoSair;
                atual->hospede->alta = true;
                printf("Informe o peso de saida (gramas): ");
                scanf("%d", pesoEmGramasAoSair);
                atual->hospede->pesoEmGramasAoSair = pesoEmGramasAoSair;
                // return no;
            }
            atual = atual->proximo;
        }
    }
}

void menu(No *no)
{
    system("cls");
    int opcao;
    printf(
        "AMBIENTE GESTAO DE HOSPEDES - SPA REI MOMO\n\n"
        "Selecione o que deseja fazer:\n");
    printf(
        "1. Cadastrar\n"
        "2. Dar alta\n"
        "3. Exibir todos\n"
    );
    scanf("%d", &opcao);
    getchar();

    system("cls");
    if (opcao == 1)
        no = cadastrarHospede(no);
    if (opcao == 2)
        darAltaEmHospedePorId(no);
    else if (opcao == 3)
        noImprimir(no);
    printf("\n\nPressione [ENTER] para prosseguir");
    getchar();

    menu(no);
}