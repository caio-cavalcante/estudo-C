// filas: First In, First Out
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int dado;
    struct reg *esq;
    struct reg *dir;
} celula;

celula *enfileirar(celula *fila, int valor) {
    celula *nova = malloc(sizeof(celula));
    nova->dado = valor;
    nova->esq = NULL;
    nova->dir = NULL;

    if (fila == NULL) {
        fila = nova;
    } else {
        celula *aux = fila;
        while (aux->dir != NULL) {
            aux = aux->dir;
        }
        aux->dir = nova;
        nova->esq = aux;
    }

    return fila;
}

celula *desenfileirar (celula *fila) {
    celula *aux = fila;

    if (fila == NULL) {
        printf("Fila vazia.\n");
        return NULL;
    } else {
        aux = aux->dir;
        free(fila);
        return aux;
    }
}

void imprimir(celula *fila) {
    celula *aux = fila;

    if (fila == NULL) {
        printf("Fila vazia.\n");
        return;
    } else {
        for (aux; aux != NULL; aux = aux->dir) {
            printf("%d ", aux->dado);
        }
        printf("\n");
    }
}

void main() {
    celula *fila = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Enfileirar valor");
        printf("\n2 - Desenfileirar valor");
        printf("\n3 - Imprimir fila");
        printf("\n9 - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                printf("Qual o valor a inserir? ");
                scanf("%d", &valor);

                fila = enfileirar(fila, valor);
                break;
            case 2:
                fila = desenfileirar(fila);
                break;
            case 3:
                imprimir(fila);
                break;
            case 9:
                printf("Volte sempre!");
                break;
            default:
                printf("Selecione uma opção válida.");
                printf("\n");
                break;
        }
    } while (resp != 9);
}