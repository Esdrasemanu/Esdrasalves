#include <stdio.h>
#include <string.h>

#define NOME_TAM 30
#define TEL_TAM 15

int main() {
    FILE *fp;
    char nome[NOME_TAM + 1];
    char telefone[TEL_TAM + 1];

    fp = fopen("contatos.txt", "w");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while (1) {
        printf("Digite o nome: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strcspn(nome, "\n")] = '\0'; // Remove newline

        printf("Digite o telefone (0 para sair): ");
        fgets(telefone, sizeof(telefone), stdin);
        telefone[strcspn(telefone, "\n")] = '\0';

        if (strcmp(telefone, "0") == 0)
            break;

        // Escreve nome e telefone com tamanho fixo, separados por espaço
        fprintf(fp, "%-*s %-*s\n", NOME_TAM, nome, TEL_TAM, telefone);
    }

    fclose(fp);
    printf("Contatos salvos em 'contatos.txt'.\n");
    return 0;
}
