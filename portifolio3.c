#include <stdio.h>
#include <string.h>

struct produto
{
    int codigo;
    char nome[50];
    float valorUnitario;
    int estoque;
};

struct venda
{
    int codigoProduto;
    char nomeProduto[50];
    int quantidade;
    float valorTotal;
};

int main()
{
    int menu;
    struct produto produtos[10];
    struct venda vendas[50];
    int totalProdutos = 0;
    int totalVendas = 0;

    do
    {
        printf("\n===== MENU =====\n");
        printf("1 - Cadastrar produto\n");
        printf("2 - Listar produtos\n");
        printf("3 - Vender produto\n");
        printf("4 - Listar Vendas\n");
        printf("5 - Sair\n");
        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Informe o codigo: ");
            scanf("%d", &produtos[totalProdutos].codigo);

            printf("Informe o nome: ");
            scanf("%s", produtos[totalProdutos].nome);

            do {
                printf("Informe o valor unitario: ");
                scanf("%f", &produtos[totalProdutos].valorUnitario);
                if (produtos[totalProdutos].valorUnitario <= 0)
                    printf("Valor deve ser maior que zero!\n");
            } while (produtos[totalProdutos].valorUnitario <= 0);

            do {
                printf("Informe o estoque: ");
                scanf("%d", &produtos[totalProdutos].estoque);
                if (produtos[totalProdutos].estoque < 0)
                    printf("Estoque nao pode ser negativo!\n");
            } while (produtos[totalProdutos].estoque < 0);

            totalProdutos++;
            printf("Produto cadastrado!\n");
            break;

        case 2:
            if (totalProdutos == 0) { printf("produto não foi cadastrado.\n"); break; }

            for (int i = 0; i < totalProdutos; i++)
            {
                printf("\nCodigo: %d\n", produtos[i].codigo);
                printf("Nome: %s\n", produtos[i].nome);
                printf("Valor: R$ %.2f\n", produtos[i].valorUnitario);
                printf("Estoque: %d\n", produtos[i].estoque);
            }
            break;

        case 3:
            if (totalProdutos == 0) { printf(" nao tem produto cadastrado.\n"); break; }

            int codigo, quantidade, indice = -1;

            printf("Informe o codigo: ");
            scanf("%d", &codigo);

            for (int i = 0; i < totalProdutos; i++)
                if (produtos[i].codigo == codigo) { indice = i; break; }

            if (indice == -1) { printf("Produto nao encontrado!\n"); break; }

            printf("Produto: %s\n", produtos[indice].nome);
            printf("Informe a quantidade: ");
            scanf("%d", &quantidade);

            if (quantidade <= 0) { printf("Quantidade deve ser maior que zero\n"); break; }
            if (quantidade > produtos[indice].estoque) { printf("Estoque insuficiente! Disponivel: %d\n", produtos[indice].estoque); break; }

            float total = quantidade * produtos[indice].valorUnitario;
            produtos[indice].estoque -= quantidade;

            vendas[totalVendas].codigoProduto = produtos[indice].codigo;
            strcpy(vendas[totalVendas].nomeProduto, produtos[indice].nome);
            vendas[totalVendas].quantidade = quantidade;
            vendas[totalVendas].valorTotal = total;
            totalVendas++;

            printf("Venda realizada! Total: R$ %.2f | Estoque restante: %d\n", total, produtos[indice].estoque);
            break;

        case 4:
            if (totalVendas == 0) { printf("Nenhuma venda realizada.\n"); break; }

            float totalGeral = 0;
            for (int i = 0; i < totalVendas; i++)
            {
                printf("\nVenda %d - %s | Qtd: %d | Total: R$ %.2f\n",
                    i + 1, vendas[i].nomeProduto, vendas[i].quantidade, vendas[i].valorTotal);
                totalGeral += vendas[i].valorTotal;
            }
            printf("\nTotal geral: R$ %.2f\n", totalGeral);
            break;

        case 5:
            printf("Saindo\n");
            break;

        default:
            printf("Opcao invalida!\n");
            break;
        }
    } while (menu != 5);

    return 0;
}