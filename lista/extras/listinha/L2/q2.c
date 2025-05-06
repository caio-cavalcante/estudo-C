/*
2. Duas árvores binárias são similares se elas são vazias ou se elas não são
vazias e suas subárvores da esquerda são similares e suas subárvores da
direita são também similares. Escreva um algoritmo para determinar
se duas árvores binárias são similares.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int chave;
    struct node *filhoDir;
    struct node *filhoEsq;
} noArvore;

noArvore *novoNo(int chave) {
    noArvore *novo = malloc(sizeof(noArvore));
    novo->chave = chave;
    novo->filhoDir = NULL;
    novo->filhoEsq = NULL;
    return novo;
}

noArvore *inserir(noArvore *raiz, int chave) {
    noArvore *novo = novoNo(chave);

    if (raiz == NULL) {
        raiz = novo;
        return raiz;
    } else if (raiz->chave > chave) {
        raiz->filhoEsq = inserir(raiz->filhoEsq, chave);
    } else if (raiz->chave < chave) {
        raiz->filhoDir = inserir(raiz->filhoDir, chave);
    } else {
        printf("Chave já cadastrada.\n");
    }

    return raiz;
}

void desenhar(noArvore *raiz, int nivel) {
    if (raiz) {
        desenhar(raiz->filhoDir, nivel + 1);
        for (int i = 0; i < nivel; i++) printf("   ");
        printf("%d\n", raiz->chave);
        desenhar(raiz->filhoEsq, nivel + 1);
    }
}

noArvore *busca(noArvore *raiz, int chave) {
    if (raiz == NULL) {
        printf("Nó não encontrado\n");
        return NULL;
    } else if (raiz->chave > chave) {
        return busca(raiz->filhoEsq, chave);
    } else if (raiz->chave < chave) {
        return busca(raiz->filhoDir, chave);
    } else {
        return raiz;
    }
}

int comparar(noArvore *raiz, noArvore *root) {
    if (raiz == NULL && root == NULL) {
        return 1; // árvores iguais
    } else if (raiz == NULL || root == NULL) {
        return 0; // árvores diferentes
    } else if (raiz->chave == root->chave) {
        return comparar(raiz->filhoDir, root->filhoDir) && comparar(raiz->filhoEsq, root->filhoEsq);
    } else {
        return 0; // árvores diferentes
    }
}

int main() {
    noArvore *raiz = NULL, *root = NULL;
    int resp, chave;

    do {
        printf("\nMenu:");
        printf("\n[1] - Inserir valor");
        printf("\n[2] - Imprimir árvore");
        printf("\n[3] - Comparar árvores");
        printf("\n[9] - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                int temp;
                printf("Escolha a árvore (1 ou 2): ");
                scanf("%d", &temp);
                if (temp == 1) {
                    printf("Insira um valor: ");
                    scanf("%d", &chave);
                    raiz = inserir(raiz, chave);
                } else if (temp == 2) {
                    printf("Insira um valor: ");
                    scanf("%d", &chave);
                    root = inserir(root, chave);
                } else {
                    printf("Opção inválida!\n");
                }
                break;
            case 2:
                printf("Primeira árvore:\n");
                desenhar(raiz, 0);
                printf("\n");
                printf("Segunda árvore:\n");
                desenhar(root, 0);
                break;
            case 3:
                int aux = comparar(raiz, root);
                if (aux) {
                    printf("Árvores iguais\n");
                } else {
                    printf("Árvores diferentes\n");
                }
                break;
            case 9:
                printf("Volte sempre!\n");
                break;
            default:
                printf("respção inválida!\n");
        }
    } while (resp != 9);

    return 0;
}