/*
4. Faça um algoritmo que leia duas listas informadas pelo usuário, depois
mostre-as na tela e deixe o usuário escolher um elemento de cada listas
e troque-os. Não pode trocar apenas o conteúdo da célula, deve-se re-
alizar a troca através da manipulação de ponteiros, trocando as células
de posição.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *prox;
    struct node *ant;
} celula;

celula *inserir(celula *lista, int valor) {
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->dado = valor;
    nova->prox = NULL;
    nova->ant = NULL;

    if (lista == NULL) {
        lista = nova;
        return lista;
    }

    celula *aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = nova;
    nova->ant = aux;

    return lista;
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

void trocar(celula *lista1, celula *lista2, int num1, int num2) {
    celula *aux1 = lista1, *aux2 = lista2;

    while (aux1->dado != num1) {
        aux1 = aux1->prox;
    }

    while (aux2->dado != num2) {
        aux2 = aux2->prox;
    }

    celula *prev_aux1 = aux1->ant;
    celula *next_aux1 = aux1->prox;
    celula *prev_aux2 = aux2->ant;
    celula *next_aux2 = aux2->prox;

    if (prev_aux1 != NULL) {
        prev_aux1->prox = aux2;
    } else {
        lista1 = aux2;
    }

    if (next_aux1 != NULL) {
        next_aux1->ant = aux2;
    }

    if (prev_aux2 != NULL) {
        prev_aux2->prox = aux1;
    } else {
        lista2 = aux1;
    }

    if (next_aux2 != NULL) {
        next_aux2->ant = aux1;
    }

    aux1->ant = prev_aux2;
    aux1->prox = next_aux2;
    aux2->ant = prev_aux1;
    aux2->prox = next_aux1;

    printf("Valores trocados!\n");
}

void main() {
    celula *lista1 = NULL, *lista2 = NULL;
    int tam, resp, valor1, valor2;

    printf("Insira o tamanho das listas: ");
    scanf("%d", &tam);

    printf("\n");
    for (int i = 0; i < tam; i++) {
        printf("Insira o %dº valor da primeira lista: ", i + 1);
        scanf("%d", &valor1);

        lista1 = inserir(lista1, valor1);
    }

    for (int i = 0; i < tam; i++) {
        printf("Insira o %dº valor da segunda lista: ", i + 1);
        scanf("%d", &valor2);

        lista2 = inserir(lista2, valor2);
    }

    imprimir(lista1);
    imprimir(lista2);

    do {
        printf("\nMenu:");
        printf("\n[1] - Trocar valores");
        printf("\n[2] - Imprimir lista");
        printf("\n[9] - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                printf("Insira um valor da primeira lista: ");
                scanf("%d", &valor1);

                printf("Insira um valor da segunda lista: ");
                scanf("%d", &valor2);

                trocar(lista1, lista2, valor1, valor2);
                break;
            case 2:
                imprimir(lista1);
                imprimir(lista2);
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