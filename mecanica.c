#include <stdio.h>
#include <stdlib.h>

// Structure for 'peca'
typedef struct Pecas {
    char nome_peca[50];
    int id_peca;
    char data_comprada[10];
    char tipo_carro[50];
    int estoque;
    char data_retirada[10];
    Funcionario nome_funcionario[50];
}Pecas;

// Structure for 'funcionario'
typedef struct Funcionario {
    char nome_funcionario[50];
    int id_funcionario;
    Pecas nome_peca;
    char carro_consertando[50];
    Pecas data_retirada;
    double total_recebido;
    double vai_receber;
}Funcionario;

