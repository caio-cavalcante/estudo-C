/*
2. Faça um algoritmo que implemente uma função que leia uma sequência
de NOMES informados pelo usuário, salve-os numa lista simples-
mente encadeada circular, ordene-os usando um dos algoritmos de
ordenação visto em sala e mostre-os em ordem decrescente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char nome[30];
    struct node *prox;
}celula;

celula *criarNo() {
    celula *nova = (celula *)malloc(sizeof(celula));
    return nova;
}

celula *inserir(celula *lista, char nome[]) {
    celula *nova = criarNo();
    strcpy(nova->nome, nome);
    nova->prox = NULL;

    if (lista == NULL) {
        lista = nova;
        return lista;
    }
    
    if (lista->prox == NULL) {
        lista->prox = nova;
        return lista;
    }

    celula *aux = lista;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    aux->prox = nova;
    return lista;
}

void imprimir(celula *lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista de nomes:\n");
    
    celula *aux = lista;
    while (aux != NULL) {
        printf("%s\n", aux->nome);
        aux = aux->prox;
    }
}

celula *ordenar(celula *lista) {
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return lista;
    }
    
    if (lista->prox == NULL) {
        printf("Lista ordenada!\n");
        return lista;
    }
    
    celula *aux = lista, *subs;
    
    while (aux->prox != NULL) {
        subs = aux->prox;
        while (subs != NULL) {
            if (strcmp(aux->nome, subs->nome) > 0) {
                char temp[30];
                strcpy(temp, aux->nome);
                strcpy(aux->nome, subs->nome);
                strcpy(subs->nome, temp);
            }
            subs = subs->prox;
        }
        aux = aux->prox;
    }
    printf("Lista ordenada!\n");
    return lista;
}

void main() {
    celula *lista = NULL;
    char nome[30];
    int resp;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir nome");
        printf("\n2 - Imprimir lista");
        printf("\n3 - Ordenar lista");
        printf("\n9 - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                printf("Qual o nome a inserir? ");
                scanf("%s", &nome);

                lista = inserir(lista, nome);
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
}