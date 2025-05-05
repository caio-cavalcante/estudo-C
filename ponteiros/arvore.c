// https://rafaelherbert.github.io/arvores-binarias-em-c/ e slides de aula
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct node {
    int chave;
    int fatorBalanceamento;
    struct node *filhoDir;
    struct node *filhoEsq;
} noArvore;

noArvore *novoNo(int chave) {
    noArvore *novo = malloc(sizeof(noArvore));
    novo->chave = chave;
    novo->fatorBalanceamento = 0;
    novo->filhoDir = NULL;
    novo->filhoEsq = NULL;
    return novo;
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

int maiorAltura(int esq, int dir) {
    return (esq > dir) ? esq : dir;
}

int altura(noArvore *no) {
    if (no == NULL) return -1;
    return no->fatorBalanceamento;
}

int alturaRaiz(noArvore *raiz) {
    if (raiz == NULL) return 0;
    int esq = altura(raiz->filhoEsq);
    int dir = altura(raiz->filhoDir);
    return (esq > dir ? esq : dir) + 1;
}

// fator de balanceamento é a diferença de altura entre 2 folhas
int fatorBalanceamento(noArvore *raiz) {
    if (raiz == NULL) return 0;
    return altura(raiz->filhoEsq) - altura(raiz->filhoDir);
}

noArvore *rotacaoEsquerda(noArvore *raiz) {
    noArvore *aux, *temp;

    aux = raiz->filhoDir;
    temp = aux->filhoEsq;

    aux->filhoEsq = raiz;
    raiz->filhoDir = temp;

    raiz->fatorBalanceamento = maiorAltura(altura(raiz->filhoEsq), altura(raiz->filhoDir)) + 1;
    aux->fatorBalanceamento = maiorAltura(altura(aux->filhoEsq), altura(aux->filhoDir)) + 1;

    return aux;
}

noArvore *rotacaoDireita(noArvore *raiz) {
    noArvore *aux, *temp;

    aux = raiz->filhoEsq;
    temp = aux->filhoDir;

    aux->filhoDir = raiz;
    raiz->filhoEsq = temp;

    raiz->fatorBalanceamento = maiorAltura(altura(raiz->filhoEsq), altura(raiz->filhoDir)) + 1;
    aux->fatorBalanceamento = maiorAltura(altura(aux->filhoEsq), altura(aux->filhoDir)) + 1;

    return aux;
}

noArvore *rotacaoDuplaEsquerda(noArvore *raiz) {
    raiz->filhoEsq = rotacaoEsquerda(raiz->filhoEsq);
    return rotacaoDireita(raiz);
}

noArvore *rotacaoDuplaDireita(noArvore *raiz) {
    raiz->filhoDir = rotacaoDireita(raiz->filhoDir);
    return rotacaoEsquerda(raiz);
}

noArvore *balancear(noArvore *raiz) {
    int fator = fatorBalanceamento(raiz);

    if (fator < -1 && fatorBalanceamento(raiz->filhoDir) <= 0){
        raiz = rotacaoEsquerda(raiz);
    } else if (fator < -1 && fatorBalanceamento(raiz->filhoDir) > 0){
        raiz = rotacaoDuplaDireita(raiz);
    } else if (fator > 1 && fatorBalanceamento(raiz->filhoDir) >= 0){
        raiz = rotacaoDireita(raiz);
    } else if (fator > 1 && fatorBalanceamento(raiz->filhoDir) < 0){
        raiz = rotacaoDuplaEsquerda(raiz);
    }

    return raiz;
}

void preOrdem(noArvore *raiz) {
    if (raiz) {
        printf("%d\n", raiz->chave);
        preOrdem(raiz->filhoEsq);
        preOrdem(raiz->filhoDir);
    }
}

void emOrdem(noArvore *raiz) {
    if (raiz) {
        emOrdem(raiz->filhoEsq);
        printf("%d\n", raiz->chave);
        emOrdem(raiz->filhoDir);
    }
}

void posOrdem(noArvore *raiz) {
    if (raiz) {
        posOrdem(raiz->filhoEsq);
        posOrdem(raiz->filhoDir);
        printf("%d\n", raiz->chave);
    }
}

void desenhar(noArvore *raiz, int nivel) {
    if (raiz) {
        desenhar(raiz->filhoDir, nivel + 1);
        for (int i = 0; i < nivel; i++) printf("   ");
        printf("%d\n", raiz->chave);
        desenhar(raiz->filhoEsq, nivel + 1);
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
            desenhar(raiz, 0);
            break;
    }
}

noArvore *menor(noArvore *raiz) {
    while(raiz->filhoEsq != NULL) {
        raiz = raiz-> filhoEsq;
    }

    return raiz;
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

    raiz->fatorBalanceamento = maiorAltura(altura(raiz->filhoEsq), altura(raiz->filhoDir)) + 1;

    raiz = balancear(raiz);

    return raiz;
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
        if ((raiz->filhoEsq == NULL) || (raiz->filhoDir == NULL)) {
            noArvore *aux = raiz->filhoEsq ? raiz->filhoEsq : raiz->filhoDir;

            if (aux == NULL) {
                free(raiz);
                return NULL;
            } else {
                *raiz = *aux;
                free(aux);
            }
        } else {
            noArvore *aux = menor(raiz->filhoDir);
            raiz->chave = aux->chave;
            raiz->filhoDir = remover(raiz->filhoDir, aux->chave);
        }
    }

    raiz->fatorBalanceamento = maiorAltura(altura(raiz->filhoEsq), altura(raiz->filhoDir)) + 1;

    raiz = balancear(raiz);

    return raiz;
}

void limpar(noArvore *raiz) {
    if (raiz) {
        limpar(raiz->filhoEsq);
        limpar(raiz->filhoDir);
        free(raiz);
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
        printf("\n[4] - Limpar árvore");
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
            case 4:
                limpar(raiz);
                raiz = NULL;
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