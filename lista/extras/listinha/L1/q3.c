/*
3. Escreva uma função para remover elementos duplicados de uma Lista
Duplamente Encadeada de Inteiros informados pelo usuário.
•Obs1: sua função deve assumir que os elementos da sua lista estão
desordenados.
•Obs2: sua função deve remover quantos elementos duplicados fo-
rem necessários, de forma que ao término da chamada da função
a lista não possua nenhum elemento duplicado
•Ex: lista de entrada = 3→4 →1 →3 →1 →5 →9 →4 →3
lista na saída = 3→4 →1 →5 →9 (quarto, quinto, oitavo e nono
elementos foram removidos)
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No *prox;
    struct No *ant;
} celula;

celula *inserir(celula *lista, int valor) {
    celula *nova = malloc(sizeof(celula));
    nova->dado = valor;
    nova->prox = NULL;
    nova->ant = NULL;

    if (lista == NULL) {
        lista = nova;
        return lista;
    }

    if (lista->prox == NULL) {
        lista->prox = nova;
        nova->ant = lista;
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
        printf("Lista vazia!\n");
        return;
    }

    celula *aux = lista;

    while (aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("\n");
}

celula *removerDup(celula *lista) {
    if (lista == NULL) {
        printf("Lista vazia!\n");
        return NULL;
    }

    if (lista->prox == NULL) {
        printf("Lista sem duplicados!\n");
        return lista;
    }

    celula *aux = lista;

    while (aux != NULL) {
        celula *temp = aux->prox;
        while (temp != NULL) {
            celula *dup = temp->prox;
            if (aux->dado == temp->dado) {
                temp->ant->prox = dup;
                if (dup != NULL) {
                    dup->ant = temp->ant;
                }
                free(temp);
            }
            temp = dup;
        }
        aux = aux->prox;
    }
    
    printf("Lista sem duplicados!\n");
    return lista;
}

void main() {
    celula *lista = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir valor");
        printf("\n2 - Imprimir lista");
        printf("\n3 - Remover duplicados");
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
                lista = removerDup(lista);
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