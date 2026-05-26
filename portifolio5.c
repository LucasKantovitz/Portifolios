#include <stdio.h>

struct Dinheiro {
    char nome[50];
    float renda;
    float gastosVariaveis;
    float gastosFixos;
};

struct Dinheiro d[100];
int total = 0;

void menu() {
    printf("\n=== SALARIO MENSAL ===\n");
    printf("1. Novo cadastro\n");
    printf("2. Adicionar renda\n");
    printf("3. Adicionar gasto variavel\n");
    printf("4. Adicionar gasto fixo\n");
    printf("5. Ver resumo\n");
    printf("0. Sair\n");
    printf("Opcao: ");
}

int main() {
    int opcao;

    do {
        menu();
        if (scanf("%d", &opcao) != 1) opcao = -1;
        scanf("%*[^\n]");

        switch (opcao) {
            case 1:
                if (total >= 100) {
                    printf("Limite atingido!\n");
                } else {
                    printf("Nome: ");
                    scanf(" %49[^\n]", d[total].nome);
                    d[total].renda = 0;
                    d[total].gastosVariaveis = 0;
                    d[total].gastosFixos = 0;
                    total++;
                }
                break;

            case 2:
                if (total == 0) {
                    printf("Cadastre alguem primeiro!\n");
                } else {
                    printf("Renda: ");
                    scanf("%f", &d[total-1].renda);
                    scanf("%*[^\n]");
                }
                break;

            case 3:
                if (total == 0) {
                    printf("Cadastre alguem primeiro!\n");
                } else {
                    float v;
                    printf("Gasto variavel: ");
                    scanf("%f", &v);
                    scanf("%*[^\n]");
                    d[total-1].gastosVariaveis += v;
                    printf("Total variaveis: R$ %.2f\n", d[total-1].gastosVariaveis);
                }
                break;

            case 4:
                if (total == 0) {
                    printf("Cadastre alguem primeiro!\n");
                } else {
                    float f;
                    printf("Gasto fixo: ");
                    scanf("%f", &f);
                    scanf("%*[^\n]");
                    d[total-1].gastosFixos += f;
                    printf("Total fixos: R$ %.2f\n", d[total-1].gastosFixos);
                }
                break;

            case 5:
                if (total == 0) {
                    printf("Nenhum cadastro.\n");
                } else {
                    for (int i = 0; i < total; i++) {
                        float saldo = d[i].renda - d[i].gastosVariaveis - d[i].gastosFixos;
                        printf("\nNome: %s\n", d[i].nome);
                        printf("Renda: R$ %.2f\n", d[i].renda);
                        printf("Gastos Variaveis: R$ %.2f\n", d[i].gastosVariaveis);
                        printf("Gastos Fixos: R$ %.2f\n", d[i].gastosFixos);
                        if (saldo >= 0)
                            printf("Saldo: R$ %.2f (positivo)\n", saldo);
                        else
                            printf("Saldo: R$ %.2f (negativo)\n", saldo);
                    }
                }
                break;

            case 0:
                printf("Ate logo!\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}