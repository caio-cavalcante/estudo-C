/*
1. Implemente o sistema para a biblioteca usando uma lista duplamente
encadeada:
•Cada livro deve ser representado por um registro com Nome do
livro, disponibilidade e fila de espera
•Ao requisitar um livro, a pessoa entra na fila de espera, caso o livro
não esteja disponível, usando política FIFO. Ou seja, quando um
livro fica disponível, o primeiro da fila de espera do livro deve
receber o livro
•Implemente as demais funcionalidades: cadastrar livro, remover
livro, emprestar livro, devolver livro e cadastrar leitor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pessoa {
    char nome[100];
    struct pessoa *prox;
} pessoa;

typedef struct {
    char nome[100];
    int disponivel;
    pessoa *fila;
} livro;

livro biblioteca[100];
int total = 0;

pessoa *criarPessoa(char *nome) {
    pessoa *nova = malloc(sizeof(pessoa));
    strcpy(nova->nome, nome);
    nova->prox = NULL;
    return nova;
}

void enfileirar(pessoa **fila, char *nome) {
    pessoa *nova = criarPessoa(nome);

    if (*fila == NULL) {
        *fila = nova;
    } else {
        pessoa *aux = *fila;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux->prox = nova;
    }
}

char *desenfileirar(pessoa **fila) {
    if (*fila == NULL) return NULL;

    pessoa *temp = *fila;
    *fila = temp->prox;
    char *nome = strdup(temp->nome);
    free(temp);
    return nome;
}

void cadastrarLivro() {
    if (total >= 100) return;

    getchar();
    printf("Nome do livro: ");
    fgets(biblioteca[total].nome, 100, stdin);
    biblioteca[total].nome[strcspn(biblioteca[total].nome, "\n")] = '\0';
    biblioteca[total].disponivel = 1;
    biblioteca[total].fila = NULL;
    total++;
    printf("Livro cadastrado!\n");
}

int buscarLivro(char *nome) {
    for (int i = 0; i < total; i++) {
        if (strcmp(biblioteca[i].nome, nome) == 0)
            return i;
    }
    return -1;
}

void solicitarLivro() {
    char nomeLivro[100], nomePessoa[100];

    getchar();
    printf("Nome do livro: ");
    fgets(nomeLivro, 100, stdin);
    nomeLivro[strcspn(nomeLivro, "\n")] = '\0';

    int pos = buscarLivro(nomeLivro);
    if (pos == -1) {
        printf("Livro não encontrado.\n");
        return;
    }

    printf("Nome da pessoa: ");
    fgets(nomePessoa, 100, stdin);
    nomePessoa[strcspn(nomePessoa, "\n")] = '\0';

    if (biblioteca[pos].disponivel) {
        biblioteca[pos].disponivel = 0;
        printf("%s recebeu o livro \"%s\"\n", nomePessoa, nomeLivro);
    } else {
        enfileirar(&biblioteca[pos].fila, nomePessoa);
        printf("%s entrou na fila de espera.\n", nomePessoa);
    }
}

void devolverLivro() {
    char nomeLivro[100];

    getchar();
    printf("Nome do livro: ");
    fgets(nomeLivro, 100, stdin);
    nomeLivro[strcspn(nomeLivro, "\n")] = '\0';

    int pos = buscarLivro(nomeLivro);
    if (pos == -1) {
        printf("Livro não encontrado.\n");
        return;
    }

    if (biblioteca[pos].fila != NULL) {
        char *proximo = desenfileirar(&biblioteca[pos].fila);
        printf("%s recebeu o livro \"%s\" da fila\n", proximo, nomeLivro);
        free(proximo);
    } else {
        biblioteca[pos].disponivel = 1;
        printf("Livro devolvido e agora está disponível\n");
    }
}

void listarLivros() {
    for (int i = 0; i < total; i++) {
        printf("\nLivro: %s\n", biblioteca[i].nome);
        printf("Disponível: %s\n", biblioteca[i].disponivel ? "Sim" : "Não");
        printf("Fila: ");

        if (biblioteca[i].fila == NULL) {
            printf("Vazia\n");
        } else {
            pessoa *aux = biblioteca[i].fila;
            while (aux != NULL) {
                printf("%s ", aux->nome);
                aux = aux->prox;
            }
            printf("\n");
        }
    }
}

int main() {
    int resp;

    do {
        printf("\nMenu:");
        printf("\n[1] - Cadastrar livro");
        printf("\n[2] - Solicitar livro");
        printf("\n[3] - Devolver livro");
        printf("\n[4] - Listar livros");
        printf("\n[9] - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1: cadastrarLivro(); break;
            case 2: solicitarLivro(); break;
            case 3: devolverLivro(); break;
            case 4: listarLivros(); break;
            case 9: printf("Volte sempre!\n"); break;
            default: printf("respção inválida!\n");
        }
    } while (resp != 9);

    return 0;
}