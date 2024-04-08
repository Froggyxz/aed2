#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PECAS 10
#define MAX_FUNCIONARIOS 10

typedef struct FUNCIONARIO {
    char nome_funcionario[50];
    int id_funcionario;
    char carro_consertando[50];
    double total_recebido;
    double vai_receber;
    char data_retirada[10];
}FUNCIONARIO;

typedef struct {
    char nome[50];
    int id;
    char data_comprada[10];
    char tipo_carro[50];
    int estoque;
} Peca;

FUNCIONARIO funcionarios[MAX_FUNCIONARIOS];
Peca pecas[MAX_PECAS];
int count = 0;

void cadastrar_peca() {
    if(count < MAX_PECAS) {
        printf("Digite o nome da peca: ");
        fgets(pecas[count].nome, sizeof(pecas->nome), stdin);
        printf("Digite o id da peca: ");
        scanf("%d", &pecas[count].id);
        getchar();
        printf("Digite a data que a peca foi comprada (dd/mm/aaaa): ");
        fgets(pecas[count].data_comprada, sizeof(pecas->data_comprada), stdin);
        printf("Digite o tipo de carro para a peca: ");
        fgets(pecas[count].tipo_carro, sizeof(pecas->tipo_carro), stdin);
        printf("Digite a quantidade em estoque: ");
        scanf("%d", &pecas[count].estoque);
        getchar();
        count++;
    } else {
        printf("Nao e possivel cadastrar mais pecas. O limite e de %d pecas.\n", MAX_PECAS);
    }
}

void atualizar_peca() {
    int id, i;
    printf("Digite o id da peca que deseja atualizar: ");
    scanf("%d", &id);
    getchar();

    for(i = 0; i < count; i++) {
        if(pecas[i].id == id) {
            printf("Digite o novo nome da peca: ");
            fgets(pecas[i].nome, sizeof(pecas->nome), stdin);
            printf("Digite a nova data que a peca foi comprada (dd/mm/aaaa): ");
            fgets(pecas[i].data_comprada, sizeof(pecas->data_comprada), stdin);
            printf("Digite o novo tipo de carro para a peca: ");
            fgets(pecas[i].tipo_carro, sizeof(pecas->tipo_carro), stdin);
            printf("Digite a nova quantidade em estoque: ");
            scanf("%d", &pecas[i].estoque);
            getchar();
            printf("Peca atualizada com sucesso!\n");
            return;
        }
    }
    printf("Peca com id %d nao encontrada.\n", id);
}

void retirar_peca() {
    int id, i;
    printf("Digite o id da peca que deseja retirar: ");
    scanf("%d", &id);
    getchar();

    for(i = 0; i < count; i++) {
        if(pecas[i].id == id) {
            printf("Peca com id %d retirada com sucesso!\n", id);
            for(int j = i; j < count - 1; j++) {
                pecas[j] = pecas[j + 1];
            }
            count--;
            return;
        }
    }
    printf("Peca com id %d nao encontrada.\n", id);
}

void buscar_peca() {
    int id, i;
    printf("Digite o id da peca que deseja buscar: ");
    scanf("%d", &id);
    getchar();

    for(i = 0; i < count; i++) {
        if(pecas[i].id == id) {
            printf("Peca encontrada:\n");
            printf("Nome: %s\n", pecas[i].nome);
            printf("ID: %d\n", pecas[i].id);
            printf("Data Comprada: %s\n", pecas[i].data_comprada);
            printf("Tipo de Carro: %s\n", pecas[i].tipo_carro);
            printf("Estoque: %d\n", pecas[i].estoque);
            return;
        }
    }
    printf("Peca com id %d nao encontrada.\n", id);
}

void listar_pecas() {
    if(count == 0) {
        printf("Nao ha pecas cadastradas.\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        printf("\nPeca %d:", i + 1);
        printf("\nNome: %s", pecas[i].nome);
        printf("\nID: %d", pecas[i].id);
        printf("\nData Comprada: %s", pecas[i].data_comprada);
        printf("\nTipo de Carro: %s", pecas[i].tipo_carro);
        printf("\nEstoque: %d", pecas[i].estoque);
    }
}

void escrever_dados_arquivo() {
    FILE *fp;
    fp = fopen("pecas.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        fprintf(fp, "Nome: %s\n", pecas[i].nome);
        fprintf(fp, "ID: %d\n", pecas[i].id);
        fprintf(fp, "Data Comprada: %s\n", pecas[i].data_comprada);
        fprintf(fp, "Tipo de Carro: %s\n", pecas[i].tipo_carro);
        fprintf(fp, "Estoque: %d\n", pecas[i].estoque);
    }

    fclose(fp);
    printf("Dados escritos no arquivo com sucesso!\n");
    
}

void receber_dados_arquivo() {
    FILE *fp;
    fp = fopen("pecas.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    count = 0;
    while(fscanf(fp, "Nome: %s\n", pecas[count].nome) != EOF) {
        fscanf(fp, "ID: %d\n", &pecas[count].id);
        fscanf(fp, "Data Comprada: %s\n", pecas[count].data_comprada);
        fscanf(fp, "Tipo de Carro: %s\n", pecas[count].tipo_carro);
        fscanf(fp, "Estoque: %d\n", &pecas[count].estoque);
        count++;
    }

    fclose(fp);
    printf("Dados lidos do arquivo com sucesso!\n");
    
}


//funcoes funcionario

void cadastrarFuncionario() {
    if (count < MAX_FUNCIONARIOS) {
        printf("Digite o nome do funcionário: ");
        fgets(funcionarios[count].nome_funcionario, sizeof(funcionarios->nome_funcionario), stdin);

        printf("Digite o ID do funcionário: ");
        scanf("%d", &funcionarios[count].id_funcionario);
        getchar();

        printf("Digite o carro em reparo pelo funcionário: ");
        fgets(funcionarios[count].carro_consertando, sizeof(funcionarios->carro_consertando), stdin);
        count++;
        printf("Funcionário cadastrado com sucesso!\n");
    } else {
        printf("Limite de registro de funcionários atingido.\n");
    }
}

void atualizarFuncionario() {
    int id;
    printf("Digite o ID do funcionário a ser atualizado: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (funcionarios[i].id_funcionario == id) {
            printf("Digite o nome do funcionário: ");
            fgets(funcionarios[i].nome_funcionario, sizeof(funcionarios->nome_funcionario), stdin);

            printf("Digite o ID do funcionário: ");
            scanf("%d", &funcionarios[i].id_funcionario);

            printf("Funcionário atualizado com sucesso!\n");
            return;
        }
    }

    printf("Funcionário não encontrado.\n");
}

void removerFuncionario() {
    int id;
    printf("Digite o ID do funcionário a ser removido: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < count; i++) {
        if (funcionarios[i].id_funcionario == id) {
            for (int j = i; j < count - 1; j++) {
                funcionarios[j] = funcionarios[j + 1];
            }
            count--;
            printf("Funcionário removido com sucesso!\n");
            return;
        }
    }

    printf("Funcionário não encontrado.\n");
}

void buscarFuncionario() {
    int id;
    printf("Digite o ID do funcionário a ser buscado: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (funcionarios[i].id_funcionario == id) {
            printf("Nome: %s\n", funcionarios[i].nome_funcionario);
            printf("ID: %d\n", funcionarios[i].id_funcionario);
            printf("Carro em reparo: %s\n", funcionarios[i].carro_consertando);
            printf("Total recebido: R$%.2f\n", funcionarios[i].total_recebido);
            return;
      
        }
    }
}

void listarFuncionarios()
{
    printf("\nLista de todos os funcionarios da mecanica: ");
    printf("\n");

    for (int i = 0; i < count; i++)
    {
        printf("\nNome: %s", funcionarios[i].nome_funcionario);
        printf("\nID: %d", funcionarios[i].id_funcionario);
        printf("\nCarro em reparo: %s", funcionarios[i].carro_consertando);
        printf("\nTotal recebido: R$%.2f", funcionarios[i].total_recebido);

    }

}

void atualizarCarro() {
    int id;
    printf("Digite o ID do funcionário para atualizar o carro: ");
    scanf("%d", &id);
    for (int i = 0; i < count; i++) {
        if (funcionarios[i].id_funcionario == id) {
            printf("Digite o novo carro em reparo pelo funcionário: ");
            fgets(funcionarios[i].carro_consertando, sizeof(funcionarios->carro_consertando), stdin);
            printf("Carro atualizado com sucesso!\n");
            return;
        }
    }
    printf("Funcionário não encontrado.\n");
}

void calcularTotalRecebido() {
    int id;
    printf("Digite o ID do funcionário para calcular o total recebido: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < count; i++) {
        if (funcionarios[i].id_funcionario == id) {
            printf("Carro consertado: %s\n", funcionarios[i].carro_consertando);
            printf("Qual o total da mão de obra? ");
            scanf("%f", &funcionarios[i].vai_receber);
            funcionarios[i].vai_receber += funcionarios[i].total_recebido;
            strcpy(funcionarios[i].carro_consertando, "Nenhum");
            printf(" calculado com sucesso!\n");
            return;
        }
    }
    printf("Funcionário não encontrado.\n");
}

void escreverDadosArquivoFunc()
{
    FILE *f = fopen("escritaFuncionario.txt", "w");

    if (f == NULL)
    {
        printf("\nErro ao abrir arquivo!\n");
    }

    for (int i = 0; i < count; i++)
    {
        fprintf(f, "\nNome: %s", funcionarios[i].nome_funcionario);
        fprintf(f, "ID: %d", funcionarios[i].id_funcionario);
        fprintf(f, "Total recebido: R$%.2lf\n", funcionarios[i].total_recebido);
        
    }

    fclose(f);
    
}

//void receberDadosArquivoFunc()
//{








//}
// menus

void menu_opcoes(){
    printf("\n");
    printf("1 - Pecas\n");
    printf("2 - Funcionarios\n");
    printf("3 - Sair\n");
}
void menu_opcoes_peca(){
    int opcao;
    do {
        printf("\nMenu Pecas:\n");
        printf("1 - Cadastrar peca\n");
        printf("2 - Atualizar peca\n");
        printf("3 - Retirar peca\n");
        printf("4 - Buscar peca\n");
        printf("5 - Listar pecas\n");
        printf("6 - Escrever dados no arquivo\n");
        printf("7 - Receber dados do arquivo\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                cadastrar_peca();
                break;
            case 2:
                atualizar_peca();
                break;
            case 3:
                retirar_peca();
                break;
            case 4:
                buscar_peca();
                break;
            case 5:
                listar_pecas();
                break;
            case 6:
                escrever_dados_arquivo();
                break;
            case 7:
                receber_dados_arquivo();
                break;
            case 0:
                exit;
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);
    
    }

void menu_opcoes_funcionario(){

int opcao;
do{
    printf("\nMenu Funcionarios:\n");
    printf("1 - Cadastrar funcionario\n");
    printf("2 - Atualizar funcionario\n");
    printf("3 - Desligar funcionario\n");
    printf("4 - Buscar funcionario\n");
    printf("5 - Listar funcionarios\n");
    printf("6 - Calcular salario\n");
    printf("7 - escrever dados no arquivo\n");
    printf("8 - receber dados do arquivo\n");
    printf("9 - Atualizar carro\n");
    printf("0 - Voltar\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);
    getchar();
    
    switch(opcao){
        case 1:
            cadastrarFuncionario();
            break;
        case 2:
            atualizarFuncionario();
            break;
        case 3:
            removerFuncionario();
            break;
        case 4:
            buscarFuncionario();
            break;
        case 5:
            listarFuncionarios(); 
            break;
        case 6:
            calcularTotalRecebido();
            break;
        case 7:
            //escreverDadosArquivoFunc(); //não existe ainda
            break;
        case 8:
            //receberDadosArquivoFunc(); //não existe ainda
            break;
        case 9:
            atualizarCarro();
            break;
        case 0:
            exit;
            break;
        default:
            printf("Opcao invalida!\n");
    }
}while(opcao != 0);
}

int main(){
    int opcao;
do{
    menu_opcoes();
    scanf("%d", &opcao);
    
    switch(opcao){
        case 1:
            menu_opcoes_peca();
        break;
        case 2:
            menu_opcoes_funcionario();
            break;
        case 3:
            printf("\nFinalizando programa......");
            return 0;
            break;
    }
}while (opcao != 3);
}
