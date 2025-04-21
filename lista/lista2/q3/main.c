/*
3. Faça um algoritmo que implemente a função
celula *buscarOuInserir(int x, celula *point),
onde x é um inteiro e *point é um ponteiro para uma lista de inteiros.
Esta função deverá buscar o inteiro x na lista de inteiros cujo topo é
apontado por *point. Se encontrar x, deverá retornar um ponteiro
para o elemento que contém x, se não encontrar x, deverá inserir x na
última posição da lista e deverá retornar um ponteiro para o elemento
inserido.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *prox;
} celula;


celula *buscarOuInserir(int x, celula *point) {
    celula *nova = malloc(sizeof(celula));
    nova->dado = x;
    nova->prox = NULL;

    if (point == NULL) {
        return nova;
    }

    celula *aux = point;

    while (aux->prox != NULL) {
        if (aux->dado == x) {
            printf("O valor %d ja existe na lista em %p\n", x, aux);
            return point;
        }
        aux = aux->prox;
    }

    nova->prox = point;
    printf("O valor %d não existia na lista e foi inserido em %p\n", x, nova);
    return nova;
}

void imprimir(celula *lista) {
    if (lista == NULL) {
        printf("Lista vazia\n");
        return;
    }

    celula *aux = lista;

    while (aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }

    printf("\n");
}

void main() {
    celula *lista = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n[1] - Inserir valor");
        printf("\n[2] - Imprimir lista");
        printf("\n[9] - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                printf("Insira um valor: ");
                scanf("%d", &valor);

                lista = buscarOuInserir(valor, lista);
                break;
            case 2:
                imprimir(lista);
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