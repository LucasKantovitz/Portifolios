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

void cadastrar() {
    printf("Titulo: "); scanf(" %49[^\n]", livros[total].titulo);
    printf("Autor: ");  scanf(" %49[^\n]", livros[total].autor);
    printf("Ano: ");    scanf("%d", &livros[total].ano);
    printf("Qtd: ");    scanf("%d", &livros[total].qtd);
    total++;
    printf("Cadastrado!\n");
}

void listar() {
    if (total == 0) {
        printf("Nenhum livro.\n");
        return;
    }
    for (int i = 0; i < total; i++) {
        printf("\n[%d] %s - %s (%d)\n", i+1, livros[i].titulo, livros[i].autor, livros[i].ano);
        if (livros[i].qtd > 0)
            printf("Disponivel | Qtd: %d\n", livros[i].qtd);
        else
            printf("Indisponivel\n");
    }
}

void verificar() {
    char busca[50];
    printf("Titulo: ");
    scanf(" %49[^\n]", busca);
    for (int i = 0; i < total; i++) {
        if (strcmp(livros[i].titulo, busca) == 0) {
            if (livros[i].qtd > 0)
                printf("Disponivel! Qtd: %d\n", livros[i].qtd);
            else
                printf("Indisponivel.\n");
            return;
        }
    }
    printf("Nao encontrado.\n");
}

void buscarAno() {
    int ano;
    printf("Apos o ano: ");
    scanf("%d", &ano);
    for (int i = 0; i < total; i++) {
        if (livros[i].ano > ano)
            printf("%s (%d)\n", livros[i].titulo, livros[i].ano);
    }
}

int main() {
    int op;
    do {
        printf("\n1-Cadastrar\n2-Listar\n3-Verificar\n4-Buscar Ano\n0-Sair\nOpcao: ");
        if (scanf("%d", &op) != 1) op = -1;
        scanf("%*[^\n]");
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