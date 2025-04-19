/*
1. Faça uma algoritmo que implemente uma função que leia uma sequência
de NÚMEROS informados pelo usuário, salve-os numa lista dupla-
mente encadeada, ordene-os usando um dos algoritmos de ordenação
visto em sala e mostre-os em ordem crescente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *prox;
    struct node *ant;
} celula;

celula *inserir(celula *lista, int valor) {
    celula *aux, *nova = (celula *)malloc(sizeof(celula));
    nova->dado = valor;
    nova->prox = NULL;
    nova->ant = NULL;

    if (lista == NULL) {
        lista = nova;
    } else {
        aux = lista;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nova;
        nova->ant = aux;
    }

    return lista;
}

celula *ordenar(celula *lista) {
    if (lista == NULL) {
        printf("Lista vazia.");
        return lista;
    }

    if (lista->prox == NULL) {
        printf("Lista ordenada!");
        return lista;
    }

    celula *temp1, *temp2;
    int aux;

    for (temp1 = lista; temp1->prox != NULL; temp1 = temp1->prox) {
        for (temp2 = temp1->prox; temp2 != NULL; temp2 = temp2->prox) {
            if (temp1->dado > temp2->dado) {
                aux = temp1->dado;
                temp1->dado = temp2->dado;
                temp2->dado = aux;
            }
        }
    }

    printf("Lista ordenada!\n");
    return lista;
}

void imprimir(celula *lista) {
    celula *aux;
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    } else {
        aux = lista;
        while (aux != NULL) {
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    celula *lista = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir valor");
        printf("\n2 - Imprimir lista");
        printf("\n3 - Ordenar lista");
        printf("\n9 - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                printf("Qual o valor a inserir? ");
                scanf("%d", &valor);

                lista = inserir(lista, valor);
                break;
            case 2:
                imprimir(lista);
                break;
            case 3:
                lista = ordenar(lista);
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

    return 0;
}