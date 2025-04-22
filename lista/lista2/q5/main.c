/*
5. Faça um algoritmo que inverta uma fila F1, criando uma nova fila F2.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *dir;
    struct node *esq;
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

celula *inverter(celula *fila1, celula *fila2) {
    if (fila1 == NULL) {
        printf("Fila vazia.\n");
        return NULL;
    }

    fila2 = NULL;
    celula *aux = fila1;
    celula *ultimo = NULL;

    while (aux != NULL) {
        ultimo = aux;
        aux = aux->dir;
    }
    
    while (ultimo != NULL) {
        fila2 = enfileirar(fila2, ultimo->dado);
        ultimo = ultimo->esq;
    }

    printf("Fila invertida!\n");
    return fila2;
}

void main() {
    celula *F1 = NULL, *F2 = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n[1] - Enfileirar valor");
        printf("\n[2] - Imprimir fila");
        printf("\n[3] - Inverter fila");
        printf("\n[9] - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                printf("Insira um valor: ");
                scanf("%d", &valor);

                F1 = enfileirar(F1, valor);
                break;
            case 2:
                printf("Fila 1: ");
                imprimir(F1);
                printf("Fila 2: ");
                imprimir(F2);
                break;
            case 3:
                F2 = inverter(F1, F2);
                break;
            case 9:
                printf("Volte sempre!");
                break;
            default:
                printf("Selecione uma opção válida.\n");
                break;
        }
    } while (resp != 9);
}