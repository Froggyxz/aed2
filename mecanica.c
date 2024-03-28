#include <stdio.h>
#include <stdlib.h>

typedef struct Funcionario {
    char nome_funcionario[50];
    int id_funcionario;
    Pecas nome_peca[50];
    char carro_consertando[50];
    Pecas data_retirada[10];
    double total_recebido;
    double vai_receber;
}Funcionario;

typedef struct Pecas {
    char nome_peca[50];
    int id_peca;
    char data_comprada[10];
    char tipo_carro[50];
    int estoque;
    char data_retirada[10];
    Funcionario nome_funcionario[50];
}Pecas;


//funcoes pecas

Pecas cadastro_peca(){
}
Pecas atualizacao_peca(){
    
}
Pecas retirar_peca(){
}
Pecas buscar_peca(){
    
}
Pecas listagem_peca(){
}

//funcoes funcionario

Funcionario cadastro_funcionario(){
}
Funcionario atualizar_funcionario(){
    
}
Funcionario desligar_funcionario(){
    
}
Funcionario buscar_funcionario(){
    
}
Funcionario listagem_funcionario(){

    
}
Funcionario salario_funcionario(){
}

//manipulacao de arquivos

void gravar_dados_peca(Pecas peca) {
    FILE *arquivo = fopen("pecas.txt", "a");
    if (arquivo == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
        return;
    }
    fprintf(arquivo, "%s %d %s %s %d\n", peca.nome_peca, peca.id_peca, peca.data_comprada, peca.tipo_carro, peca.estoque);
    fclose(arquivo);
}
void gravar_dados_funcionario(Funcionario funcionario) {
    FILE *arquivo = fopen("funcionarios.txt", "a");
    if (arquivo == NULL) {
        printf("nao foi possivel abrir o arquivo\n");
        return;
    }
    fprintf(arquivo, "%s %d %s %lf %lf\n", funcionario.nome_funcionario, funcionario.id_funcionario, funcionario.carro_consertando, funcionario.total_recebido, funcionario.vai_receber);
    fclose(arquivo);
}
Pecas recuperar_dados_peca() {
    Pecas peca;
    FILE *arquivo = fopen("pecas.txt", "r");
    if (arquivo == NULL) {
        printf("nao foi possivel abrir o arquivo\n");
        return peca;
    }
    fscanf(arquivo, "%s %d %s %s %d\n", peca.nome_peca, &peca.id_peca, peca.data_comprada, peca.tipo_carro, &peca.estoque);
    fclose(arquivo);
    return peca;
}
Funcionario recuperar_dados_funcionario() {
    Funcionario funcionario;
    FILE *arquivo = fopen("funcionarios.txt", "r");
    if (arquivo == NULL) {
        printf("nao foi possivel abrir o arquivo.\n");
        return funcionario;
    }
    fscanf(arquivo, "%s %d %s %lf %lf\n", funcionario.nome_funcionario, &funcionario.id_funcionario, funcionario.carro_consertando, &funcionario.total_recebido, &funcionario.vai_receber);
    fclose(arquivo);
    return funcionario;
}

// menus

void menu_opcoes(){
    printf("1 - Pecas\n");
    printf("2 - Funcionarios\n");
    printf("3 - Sair\n");
}
void menu_opcoes_peca(){
    printf("1 - Cadastrar peca\n");
    printf("2 - Atualizar peca\n");
    printf("3 - Retirar peca\n");
    printf("4 - Buscar peca\n");
    printf("5 - Listar pecas\n");
    printf("6 - escrever dados no arquivo\n");
    printf("7 - receber dados do arquivo\n");
    printf("8 - Voltar\n");
}
void menu_opcoes_funcionario(){
    printf("1 - Cadastrar funcionario\n");
    printf("2 - Atualizar funcionario\n");
    printf("3 - Desligar funcionario\n");
    printf("4 - Buscar funcionario\n");
    printf("5 - Listar funcionarios\n");
    printf("6 - Calcular salario\n");
    printf("7 - escrever dados no arquivo\n");
    printf("8 - receber dados do arquivo\n");
    printf("9 - Voltar\n");
}

int main(){
    Pecas peca;
    Funcionario funcionario;
    int opcao;
    menu_opcoes();
    scanf("%d", &opcao);
    switch(opcao){
        case 1:
          opcoes_peca();
        break;
        case 2:
            menu_opcoes_funcionario();
            break;
        case 3:
            break;
}
}
