#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int dado;
    struct reg *ant;
    struct reg *prox;
} celula;

celula *enfileirar(celula *fila, int valor) {
    celula *nova = malloc(sizeof(celula));
    nova->dado = valor;
    nova->ant = NULL;
    nova->prox = NULL;

    if (fila == NULL) {
        fila = nova;
    } else {
        celula *aux = fila;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nova;
        nova->ant = aux;
    }

    return fila;
}

celula *desenfileirar (celula *fila) {
    celula *aux = fila;

    if (fila == NULL) {
        printf("Fila vazia.\n");
        return NULL;
    } else {
        aux = aux->prox;
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
        for (aux; aux != NULL; aux = aux->prox) {
            printf("%d ", aux->dado);
        }
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