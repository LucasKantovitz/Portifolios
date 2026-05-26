#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[50];
    char autor[50];
    int ano;
    int qtd;
};

struct Livro livros[100];
int total = 0;

int menu() {
    printf("\n=== BIBLIOTECA ===\n");
    printf("1. Cadastrar livro\n");
    printf("2. Listar livros\n");
    printf("3. Verificar disponibilidade\n");
    printf("4. Buscar por ano\n");
    printf("0. Sair\n");
    printf("Opcao: ");
    return 0;
}

int cadastrar() {
    printf("\n-- Cadastro de Livro --\n");
    printf("Titulo: ");
    scanf(" %[^\n]", livros[total].titulo);
    printf("Autor: ");
    scanf(" %[^\n]", livros[total].autor);
    printf("Ano: ");
    scanf("%d", &livros[total].ano);
    printf("Quantidade: ");
    scanf("%d", &livros[total].qtd);
    total++;
    printf("Livro cadastrado!\n");
    return 0;
}

int listar() {
    if (total == 0) { printf("Nenhum livro cadastrado.\n"); return 0; }
    for (int i = 0; i < total; i++) {
        char *status = livros[i].qtd > 0 ? "Disponivel" : "Indisponivel";
        printf("\n[%d] %s - %s (%d) | Qtd: %d | %s\n",
            i+1, livros[i].titulo, livros[i].autor,
            livros[i].ano, livros[i].qtd, status);
    }
    return 0;
}

int verificar() {
    char busca[50];
    printf("Titulo: ");
    scanf(" %[^\n]", busca);
    for (int i = 0; i < total; i++) {
        if (strcmp(livros[i].titulo, busca) == 0) {
            if (livros[i].qtd > 0)
                printf("Disponivel! Quantidade: %d\n", livros[i].qtd);
            else
                printf("Indisponivel.\n");
            return 0;
        }
    }
    printf("Livro nao encontrado.\n");
    return 0;
}

int buscarAno() {
    int ano;
    printf("Mostrar livros apos o ano: ");
    scanf("%d", &ano);
    for (int i = 0; i < total; i++) {
        if (livros[i].ano > ano)
            printf("%s (%d)\n", livros[i].titulo, livros[i].ano);
    }
    return 0;
}

int main() {
    int op;
    do {
        menu();
        scanf("%d", &op);
        switch (op) {
            case 1: cadastrar(); break;
            case 2: listar();    break;
            case 3: verificar(); break;
            case 4: buscarAno(); break;
            case 0: printf("Ate logo!\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (op != 0);
    return 0;
}