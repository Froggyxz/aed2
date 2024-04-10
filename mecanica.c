#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_PECAS 10
#define MAX_FUNCIONARIOS 10
#define MAX_REMOVIDAS 10

typedef struct FUNCIONARIO
{
    char nome_funcionario[50];
    int id_funcionario;
    char carro_consertando[50];
    float total_recebido;
    float vai_receber;
} FUNCIONARIO;

typedef struct Peca
{
    char nome[50];
    int id;
    char data_comprada[10];
    char tipo_carro[50];
    int estoque;
} Peca;

typedef struct Removidas
{
    char nome_peca[50];
    int id_peca;
    char data_comprada[10];
    int qtd;
    int id_funcionario;
    char data_retirada[10];
} Removidas;

typedef struct Mecanica
{
    FUNCIONARIO funcionarios[MAX_FUNCIONARIOS];
    int count_funcionarios;
    Peca pecas[MAX_PECAS];
    int count_pecas;
    Removidas removidas[MAX_REMOVIDAS];
    int count_removidas;
} Mecanica;




Mecanica inicializarMecanica()
{
    Mecanica mecanica;
    mecanica.count_funcionarios = 0;
    mecanica.count_pecas = 0;
    mecanica.count_removidas = 0;
    return mecanica;
}

void cadastrar_peca(Mecanica *mecanica)
{
    if (mecanica->count_pecas < MAX_PECAS)
    {
        Peca novaPeca;

        printf("Digite o nome da peça: ");
        fgets(novaPeca.nome, sizeof(novaPeca.nome), stdin);

        printf("Digite o ID da peça: ");
        scanf("%d", &novaPeca.id);
        getchar();

        printf("Digite a data que a peça foi comprada (ddmmaaaa): ");
        fgets(novaPeca.data_comprada, sizeof(novaPeca.data_comprada), stdin);

        printf("Digite o tipo de carro para a peça: ");
        fgets(novaPeca.tipo_carro, sizeof(novaPeca.tipo_carro), stdin);

        printf("Digite a quantidade em estoque: ");
        scanf("%d", &novaPeca.estoque);
        getchar();

        mecanica->pecas[mecanica->count_pecas] = novaPeca;
        mecanica->count_pecas++;
        printf("Peça cadastrada com sucesso!\n");
    }
    else
    {
        printf("Nao e possivel cadastrar mais pecas. O limite e de %d pecas.\n", MAX_PECAS);
    }
}

void atualizar_peca(Mecanica *mecanica)
{
    int id, i;
    printf("Digite o id da peca que deseja atualizar: ");
    scanf("%d", &id);
    getchar();

    for (i = 0; i < mecanica->count_pecas; i++)
    {
        if (mecanica->pecas[i].id == id)
        {
            printf("Digite o novo nome da peca: ");
            fgets(mecanica->pecas[i].nome, sizeof(mecanica->pecas->nome), stdin);
            getchar();
            printf("Digite a nova data que a peca foi comprada (ddmmaaaa): ");
            fgets(mecanica->pecas[i].data_comprada, sizeof(mecanica->pecas->data_comprada), stdin);
            getchar();
            printf("Digite o novo tipo de carro para a peca: ");
            fgets(mecanica->pecas[i].tipo_carro, sizeof(mecanica->pecas->tipo_carro), stdin);
            getchar();
            printf("Digite a nova quantidade em estoque: ");
            scanf("%d", &mecanica->pecas[i].estoque);
            getchar();
            printf("Peca atualizada com sucesso!\n");
            return;
        }
    }
    printf("Peca com id %d nao encontrada.\n", id);
}

void retirar_peca(Mecanica *mecanica)
{
    int idpeca;
    Removidas RETIRAR;
    printf("Digite o id da peça que deseja retirar: ");
    scanf("%d", &idpeca);
    getchar();

    for (int i = 0; i < mecanica->count_pecas; i++)
    {
        if (mecanica->pecas[i].id == idpeca)
        {
            printf("Digite a data da retirada da peça (ddmmaaaa): ");
            fgets(RETIRAR.data_retirada, sizeof(RETIRAR.data_retirada), stdin);

            printf("Digite o id do funcionário que retirou a peça: ");
            scanf("%d", &RETIRAR.id_funcionario);
            getchar();

            printf("Digite a quantidade retirada: ");
            scanf("%d", &RETIRAR.qtd);
            getchar();

            if (mecanica->pecas[i].estoque < RETIRAR.qtd)
            {
                printf("Quantidade em estoque insuficiente.\n");
                return;
            }
            if (mecanica->count_removidas < MAX_REMOVIDAS)
            {
            mecanica->pecas[i].estoque -= RETIRAR.qtd;
            mecanica->removidas[mecanica->count_removidas].id_peca = mecanica->pecas[i].id;
            strncpy(mecanica->removidas[mecanica->count_removidas].nome_peca, mecanica->pecas[i].nome, sizeof(mecanica->pecas[i].nome));
            mecanica->removidas[mecanica->count_removidas].id_funcionario = RETIRAR.id_funcionario;
            strncpy(mecanica->removidas[mecanica->count_removidas].data_comprada, mecanica->pecas[i].data_comprada, sizeof(mecanica->pecas[i].data_comprada));
            mecanica->removidas[mecanica->count_removidas].qtd = RETIRAR.qtd;
            }
            else
            {
                printf("Limite de registro de peças retiradas atingido.\n");
                return;
            }
            printf("Peça com id %d retirada com sucesso!\n", idpeca);
            
        }
        FILE *fp;
        fp = fopen("retiradas.txt", "wb");
        if (fp == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
        }

    fwrite(mecanica->removidas, sizeof(Removidas), mecanica->count_removidas, fp);

    fclose(fp);
    }

    printf("Peça com id %d não encontrada.\n", idpeca);
}

void buscar_peca(Mecanica *mecanica)
{
    int id, i;
    printf("Digite o id da peca que deseja buscar: ");
    scanf("%d", &id);
    getchar();

    for (i = 0; i < mecanica->count_pecas; i++)
    {
        if (mecanica->pecas[i].id == id)
        {
            printf("Peca encontrada:\n");
            printf("Nome: %s\n", mecanica->pecas[i].nome);
            printf("ID: %d\n", mecanica->pecas[i].id);
            printf("Data Comprada: %s\n", mecanica->pecas[i].data_comprada);
            printf("Tipo de Carro: %s\n", mecanica->pecas[i].tipo_carro);
            printf("Estoque: %d\n", mecanica->pecas[i].estoque);
            return;
        }
    }
    printf("Peca com id %d nao encontrada.\n", id);
}

void listar_pecas(Mecanica *mecanica)
{
    if (mecanica->count_pecas == 0)
    {
        printf("Nao ha pecas cadastradas.\n");
        return;
    }

    for (int i = 0; i < mecanica->count_pecas; i++)
    {
        printf("\nPeca: %d", i + 1);
        printf("\nNome: %s", mecanica->pecas[i].nome);
        printf("ID: %d", mecanica->pecas[i].id);
        printf("\nData Comprada: %s", mecanica->pecas[i].data_comprada);
        printf("Tipo de Carro: %s", mecanica->pecas[i].tipo_carro);
        printf("Estoque: %d\n", mecanica->pecas[i].estoque);
    }
}

void escrever_dados_arquivo(Mecanica *mecanica)
{
    FILE *fp;
    fp = fopen("pecas.txt", "wb");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fwrite(mecanica->pecas, sizeof(Peca), mecanica->count_pecas, fp);

    fclose(fp);
    printf("Dados escritos no arquivo com sucesso!\n");
}

void receber_dados_arquivo(Mecanica *mecanica)
{
    FILE *fp;
    fp = fopen("pecas.txt", "rb");
    if (fp == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    int num_pecas_lidas = fread(mecanica->pecas, sizeof(Peca), MAX_PECAS, fp);
    if (num_pecas_lidas == 0)
    {
        printf("Nenhuma peça encontrada no arquivo.\n");
    }
    else
    {
        mecanica->count_pecas = num_pecas_lidas;
        printf("Dados lidos do arquivo binário com sucesso!\n");
    }

    fclose(fp);
}

// funcoes de ordenacao


int compara_strings(const void *a, const void *b) {
    return strcmp(((const Peca *)a)->nome, ((const Peca *)b)->nome);
}

void troca(void *a, void *b) {
    Peca temp;
    memcpy(&temp, a, sizeof(Peca));
    memcpy(a, b, sizeof(Peca));
    memcpy(b, &temp, sizeof(Peca));
}

int particiona(void *arr, int esq, int dir, int (*compara)(const void *, const void *)) {
    void *pivo = ((char *)arr + dir * sizeof(Peca));
    int i = esq - 1;

    for (int j = esq; j < dir; j++) {
        if (compara(((char *)arr + j * sizeof(Peca)), pivo) < 0) {
            i++;
            troca(((char *)arr + i * sizeof(Peca)), ((char *)arr + j * sizeof(Peca)));
        }
    }
    troca(((char *)arr + (i + 1) * sizeof(Peca)), ((char *)arr + dir * sizeof(Peca)));
    return i + 1;
}


void quickSort(void *arr, int esq, int dir, int (*compara)(const void *, const void *)) {
    if (esq < dir) {
        int p = particiona(arr, esq, dir, compara);
        quickSort(arr, esq, p - 1, compara);
        quickSort(arr, p + 1, dir, compara);
    }
}


void ordernarNomes(Mecanica *mecanica, int (*compara)(const void *, const void *)) {
    printf("O Que voce quer ordenar?\n");
    printf("1 - Pecas (por nome)\n");
    printf("2 - Funcionarios(por nome)\n");
    printf("3- Pecas retiradas(por funcionario)\n");
    int opcao;
    scanf("%d", &opcao);
    switch (opcao) {
        case 1:
            quickSort(mecanica->pecas, 0, mecanica->count_pecas - 1, compara);
            break;
        case 2:
            quickSort(mecanica->funcionarios, 0, mecanica->count_funcionarios - 1, compara);
            break;
        case 3:
            quickSort(mecanica->removidas, 0, mecanica->count_removidas - 1, compara);
            break;
        default:
            printf("Opcao invalida!\n");
    }
}

//lista de pecas retiradas


void imprimeretiradas(Mecanica *mecanica){
    FILE *fp;
    fp = fopen("retiradas.txt", "rb");
    if (fp == NULL){
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    int num_retirada = fread(mecanica->removidas, sizeof(Removidas), MAX_REMOVIDAS, fp);
    if (num_retirada == 0)
    {
        printf("Nenhuma retirada encontrado no arquivo.\n");
    }
    else
    {
        mecanica->count_removidas = num_retirada;
        printf("Dados lidos do arquivo com sucesso!\n");
    }
   
    fclose(fp);

}

// funcoes funcionario

void cadastrarFuncionario(Mecanica *mecanica)
{
    if (mecanica->count_funcionarios < MAX_FUNCIONARIOS)
    {
        printf("Digite o nome do funcionário: ");
        fgets(mecanica->funcionarios[mecanica->count_funcionarios].nome_funcionario, sizeof(mecanica->funcionarios->nome_funcionario), stdin);

        printf("Digite o ID do funcionário: ");
        scanf("%d", &mecanica->funcionarios[mecanica->count_funcionarios].id_funcionario);
        getchar();

        printf("Digite o carro em reparo pelo funcionário: ");
        fgets(mecanica->funcionarios[mecanica->count_funcionarios].carro_consertando, sizeof(mecanica->funcionarios->carro_consertando), stdin);
        mecanica->count_funcionarios++;
        printf("Funcionário cadastrado com sucesso!\n");
    }
    else
    {
        printf("Limite de registro de funcionários atingido.\n");
    }
}

void atualizarFuncionario(Mecanica *mecanica)
{
    int id;
    printf("Digite o ID do funcionário a ser atualizado: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < mecanica->count_funcionarios; i++)
    {
        if (mecanica->funcionarios[i].id_funcionario == id)
        {
            printf("Digite o nome do funcionário: ");
            fgets(mecanica->funcionarios[i].nome_funcionario, sizeof(mecanica->funcionarios->nome_funcionario), stdin);
            getchar();
            printf("Digite o ID do funcionário: ");
            scanf("%d", &mecanica->funcionarios[i].id_funcionario);
            getchar();

            printf("Funcionário atualizado com sucesso!\n");
            return;
        }
    }

    printf("Funcionário não encontrado.\n");
}

void removerFuncionario(Mecanica *mecanica)
{
    int id;
    printf("Digite o ID do funcionário a ser removido: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < mecanica->count_funcionarios; i++)
    {
        if (mecanica->funcionarios[i].id_funcionario == id)
        {
            for (int j = i; j < mecanica->count_funcionarios - 1; j++)
            {
                mecanica->funcionarios[j] = mecanica->funcionarios[j + 1];
            }
            mecanica->count_funcionarios--;
            printf("Funcionário removido com sucesso!\n");
            return;
        }
    }

    printf("Funcionário não encontrado.\n");
}

void buscarFuncionario(Mecanica *mecanica)
{
    int id;
    printf("Digite o ID do funcionário a ser buscado: ");
    scanf("%d", &id);

    for (int i = 0; i < mecanica->count_funcionarios; i++)
    {
        if (mecanica->funcionarios[i].id_funcionario == id)
        {
            printf("Nome: %s\n", mecanica->funcionarios[i].nome_funcionario);
            printf("ID: %d\n", mecanica->funcionarios[i].id_funcionario);
            printf("Carro em reparo: %s\n", mecanica->funcionarios[i].carro_consertando);
            printf("Total recebido: R$%.2f\n", mecanica->funcionarios[i].total_recebido);
            return;
        }
    }
}

void listarFuncionarios(Mecanica *mecanica)
{
    printf("\nLista de todos os funcionarios da mecanica: ");
    printf("\n");
    
    for (int i = 0; i < mecanica->count_funcionarios; i++)
    {
        printf("\nNome: %s", mecanica->funcionarios[i].nome_funcionario);
        printf("ID: %d\n", mecanica->funcionarios[i].id_funcionario);
        printf("Carro em reparo: %s", mecanica->funcionarios[i].carro_consertando);
        printf("Total recebido: R$%.2f\n", mecanica->funcionarios[i].total_recebido);
    }
}

void calcularTotalRecebido(Mecanica *mecanica)
{
    int id;
    printf("Digite o ID do funcionário para calcular o total recebido: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < mecanica->count_funcionarios; i++)
    {
        if (mecanica->funcionarios[i].id_funcionario == id)
        {
            printf("Carro consertado: %s\n", mecanica->funcionarios[i].carro_consertando);
            printf("Qual o total da mao de obra? ");
            scanf("%f", &mecanica->funcionarios[i].vai_receber);
            mecanica->funcionarios[i].total_recebido += mecanica->funcionarios[i].vai_receber;
            printf(" calculado com sucesso!\n");
            printf("Digite o novo carro em reparo pelo funcionário: ");
            scanf("%s", mecanica->funcionarios[i].carro_consertando);
            printf("Carro atualizado com sucesso!\n");
            return;
        }
    }
    printf("Funcionário não encontrado.\n");
}

void escreverDadosArquivoFunc(Mecanica *mecanica)
{
    FILE *f;
    f = fopen("funcionarios.txt", "wb");
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    fwrite(mecanica->funcionarios, sizeof(FUNCIONARIO), mecanica->count_funcionarios, f);
    fclose(f);
}

void receberDadosArquivoFunc(Mecanica *mecanica)
{
    FILE *f;
    f = fopen("funcionarios.txt", "rb");
    if (f == NULL)
    {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }
    int num_funcionarios_lidos = fread(mecanica->funcionarios, sizeof(FUNCIONARIO), MAX_FUNCIONARIOS, f);
    if (num_funcionarios_lidos == 0)
    {
        printf("Nenhum funcionario encontrado no arquivo.\n");
    }
    else
    {
        mecanica->count_funcionarios = num_funcionarios_lidos;
        printf("Dados lidos do arquivo com sucesso!\n");
    }
    printf("Dados lidos do arquivo com sucesso!\n");
}
// menus

void menu_opcoes()
{
    printf("\n");
    printf("1 - Peças\n");
    printf("2 - Funcionarios\n");
    printf("3 - Sair\n");
}
void menu_opcoes_peca(Mecanica *mecanica)
{

    int opcao;
    do
    {
        printf("\nMenu Pecas:\n");
        printf("1 - Cadastrar peça\n");
        printf("2 - Atualizar peça\n");
        printf("3 - Retirar peça\n");
        printf("4 - Buscar peça\n");
        printf("5 - Listar peças\n");
        printf("6 - Escrever dados no arquivo\n");
        printf("7 - Receber dados do arquivo\n");
        printf("8 - Ordenar peças\n");
        printf("9- listar peças retiradas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            cadastrar_peca(mecanica);
            break;
        case 2:
            atualizar_peca(mecanica);
            break;
        case 3:
            retirar_peca(mecanica);
            break;
        case 4:
            buscar_peca(mecanica);
            break;
        case 5:
            listar_pecas(mecanica);
            break;
        case 6:
            escrever_dados_arquivo(mecanica);
            break;
        case 7:
            receber_dados_arquivo(mecanica);
            break;
        case 8:
            ordernarNomes(mecanica, compara_strings);
            break;
        case 9:
            //listarPecasRetiradas(mecanica);
            break;
        case 0:
            menu_opcoes();
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

void menu_opcoes_funcionario(Mecanica *mecanica)
{
    int opcao;
    do
    {
        printf("\nMenu Funcionarios:\n");
        printf("1 - Cadastrar funcionario\n");
        printf("2 - Atualizar funcionario\n");
        printf("3 - Desligar funcionario\n");
        printf("4 - Buscar funcionario\n");
        printf("5 - Listar funcionarios\n");
        printf("6 - Calcular salario\n");
        printf("7 - escrever dados no arquivo\n");
        printf("8 - receber dados do arquivo\n");
        printf("9 - Ordenar funcionarios\n");
        printf("0 - Voltar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            cadastrarFuncionario(mecanica);
            break;
        case 2:
            atualizarFuncionario(mecanica);
            break;
        case 3:
            removerFuncionario(mecanica);
            break;
        case 4:
            buscarFuncionario(mecanica);
            break;
        case 5:
            listarFuncionarios(mecanica);
            break;
        case 6:
            calcularTotalRecebido(mecanica);
            break;
        case 7:
            escreverDadosArquivoFunc(mecanica);
            break;
        case 8:
            receberDadosArquivoFunc(mecanica);
            break;
        case 9:
            ordernarNomes(mecanica, compara_strings);
            break;
        case 0:
            menu_opcoes();
            break;
        default:
            printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
}

int main()
{
    setlocale(LC_ALL, "");
    Mecanica mecanica = inicializarMecanica();
    int opcao;
    do
    {
        menu_opcoes();
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            menu_opcoes_peca(&mecanica);
            break;
        case 2:
            menu_opcoes_funcionario(&mecanica);
            break;
        case 3:
            printf("\nFinalizando programa......");
            return 0;
            break;
        }
    } while (opcao != 3);
}
