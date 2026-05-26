/**
 * struct -- ***
2. if/else
3. while
4. for
5. switch -- ***
6. Funções
7. Menu de opções
8. Cadastro de dados
9. Listagem dos dados cadastrados
10. Algum cálculo ou validação
 */

#include <stdio.h>
#include <string.h>

struct Dinherio
{
    char nome[50];
    float dinherioMensal;
    float gastosVariaveis;
    float gastosFixos;
};
void menu()
{
    printf("\n=== AJUDAR SALARIO MENSAL ===\n");
    printf("1. Informe seu Nome\n");
    printf("2. Dinheiro Mensal\n");
    printf("3. Gastos Variaveis\n");
    printf("4. Gastos Fixos\n");
    printf("5. Resumo\n");
    printf("0. Sair\n");
    printf("Opcao: ");
}

int main()
{
    int opcao;
    struct Dinherio d[100];
    int cadastrados = 0;
    do
    {
        menu();
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            printf("Informe seu Nome\n");
            scanf(" %[^\n]", d[cadastrados].nome);
            break;
        case 2:
            printf("Informe sua Renda Mensal\n"); // faltou isso
            scanf("%f", &d[cadastrados].dinherioMensal);
            break;
        case 3:
            printf("Informe seu Gastos Variaveis\n");
            scanf(" %f", &d[cadastrados].gastosVariaveis);

            float saldoParcial = d[cadastrados].dinherioMensal - d[cadastrados].gastosVariaveis;

            printf("Saldo parcial: R$ %.2f\n", saldoParcial);
            break;
        case 4:
            printf("Informe seu Gastos Fixos\n");
            scanf(" %f", &d[cadastrados].gastosFixos);
            cadastrados++;
            break;
        case 5:
            for (int i = 0; i < cadastrados; i++)
            {
                float saldo = d[i].dinherioMensal - d[i].gastosVariaveis - d[i].gastosFixos;
                printf("Nome: %s\n", d[i].nome);
                printf("Renda: R$ %.2f\n", d[i].dinherioMensal);
                printf("Gastos Variaveis: R$ %.2f\n", d[i].gastosVariaveis);
                printf("Gastos Fixos: R$ %.2f\n", d[i].gastosFixos);
                if (saldo >= 0)
                    printf("Saldo: R$ %.2f (positivo)\n\n", saldo);
                else
                    printf("Saldo: R$ %.2f (negativo)\n\n", saldo);
            }
            break;

        default:
            break;
        }
    } while (opcao != 0);
    return 0;
}