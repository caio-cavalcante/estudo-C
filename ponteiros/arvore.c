// https://rafaelherbert.github.io/arvores-binarias-em-c/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int chave;
    struct node *filhoDir;
    struct node *filhoEsq;
} noArvore;

noArvore *inserir(noArvore *raiz, int chave) {
    noArvore *novo = malloc(sizeof(noArvore));
    novo->chave = chave;
    novo->filhoDir = NULL;
    novo->filhoEsq = NULL;

    if (raiz == NULL) {
        raiz = novo;
        return raiz;
    }

    if (raiz->chave > chave) {
        raiz->filhoEsq = inserir(raiz->filhoEsq, chave);
    } else {
        raiz->filhoDir = inserir(raiz->filhoDir, chave);
    }
    return raiz;
}

noArvore *busca(noArvore *raiz, int chave) {
    if (raiz == NULL) {
        return NULL;
    } else if (raiz->chave == chave) {
        return raiz;
    } else if (raiz->chave > chave) {
        return busca(raiz->filhoEsq, chave);
    } else {
        return busca(raiz->filhoDir, chave);
    }
}

void preOrdem(noArvore *raiz) {
    if (raiz == NULL) {
        return;
    } else {
        printf("%d\n", raiz->chave);
        preOrdem(raiz->filhoEsq);
        preOrdem(raiz->filhoDir);
    }
}

void emOrdem(noArvore *raiz) {
    if (raiz == NULL) {
        return;
    } else {
        emOrdem(raiz->filhoEsq);
        printf("%d\n", raiz->chave);
        emOrdem(raiz->filhoDir);
    }
}

void posOrdem(noArvore *raiz) {
    if (raiz == NULL) {
        return;
    } else {
        posOrdem(raiz->filhoEsq);
        posOrdem(raiz->filhoDir);
        printf("%d\n", raiz->chave);
    }
}

int altura(noArvore *raiz) {
    if (raiz == NULL) return 0;
    int esq = altura(raiz->filhoEsq);
    int dir = altura(raiz->filhoDir);
    return (esq > dir ? esq : dir) + 1;
}

void imprimirNivel(noArvore *raiz, int nivel, int espaco, int totalEspaco) {
    if (nivel == 1) {
        if (raiz)
            printf("%*d%*s", espaco, raiz->chave, espaco, "");
        else
            printf("%*s%*s", espaco, " ", espaco, "");
    } else if (nivel > 1) {
        if (raiz) {
            imprimirNivel(raiz->filhoEsq, nivel - 1, espaco / 2, totalEspaco);
            imprimirNivel(raiz->filhoDir, nivel - 1, espaco / 2, totalEspaco);
        } else {
            imprimirNivel(NULL, nivel - 1, espaco / 2, totalEspaco);
            imprimirNivel(NULL, nivel - 1, espaco / 2, totalEspaco);
        }
    }
}

void imprimirPiramide(noArvore *raiz) {
    int h = altura(raiz);
    int maxEspaco = (int) pow(2, h);

    for (int i = 1; i <= h; i++) {
        imprimirNivel(raiz, i, maxEspaco / 2, maxEspaco);
        printf("\n");
    }
}

void impressão(noArvore *raiz) {
    int temp;

    printf("\n[1] - Pre-ordem");
    printf("\n[2] - Em-ordem");
    printf("\n[3] - Pos-ordem");
    printf("\n[4] - Desenhada");
    printf("\nComo deseja visualizar? ");
    scanf("%d", &temp);

    switch (temp) {
        case 1:
            preOrdem(raiz);
            break;
        case 2:
            emOrdem(raiz);
            break;
        case 3:
            posOrdem(raiz);
            break;
        case 4:
            imprimirPiramide(raiz);
            break;
    }
}

noArvore *remover(noArvore *raiz, int chave) {
    if (raiz == NULL) {
        return NULL;
    } else if (raiz->chave > chave) {
        raiz->filhoEsq = remover(raiz->filhoEsq, chave);
        return raiz;
    } else if (raiz->chave < chave) {
        raiz->filhoDir = remover(raiz->filhoDir, chave);
        return raiz;
    } else {
        if (raiz->filhoEsq == NULL && raiz->filhoDir == NULL) {
            free(raiz);
            return NULL;
        } else if (raiz->filhoEsq == NULL) {
            noArvore *aux = raiz->filhoDir;
            free(raiz);
            return aux;
        } else if (raiz->filhoDir == NULL) {
            noArvore *aux = raiz->filhoEsq;
            free(raiz);
            return aux;
        } else {
            noArvore *aux = raiz->filhoDir;
            while (aux->filhoEsq != NULL) {
                aux = aux->filhoEsq;
            }
            raiz->chave = aux->chave;
            raiz->filhoDir = remover(raiz->filhoDir, aux->chave);
            return raiz;
        }
    }
}

void menu() {
    noArvore *raiz = NULL;
    int resp, temp, chave;

    do {
        printf("\nMenu:");
        printf("\n[1] - Inserir valor");
        printf("\n[2] - Imprimir árvore");
        printf("\n[3] - Remover valor");
        printf("\n[9] - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                printf("Insira um valor: ");
                scanf("%d", &chave);
                raiz = inserir(raiz, chave);
                break;
            case 2:
                impressão(raiz);
                break;
            case 3:
                printf("Insira um valor: ");
                scanf("%d", &chave);
                raiz = remover(raiz, chave);
                break;
            case 9:
                printf("Volte sempre!\n");
                break;
            default:
                printf("Selecione uma opcao valida.\n");
                break;
        }
    } while (resp != 9 && resp > 0);
}

int main() {
    menu();
    return 0;
}