/*
Dada uma lista encadeada informada pelo usuário, que armazena
números inteiros, escreva uma função que transforma a lista em
outras duas listas encadeadas: a primeira contendo os elementos
cujo conteúdo é par e a segunda contendo os elementos com
conteúdos ímpares. Sua função deve manipular somente os
ponteiros e não o conteúdo das células.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *prox;
}celula;

celula * inserir(celula * lista, int valor) {
    celula * nova = malloc(sizeof(celula));
    nova->dado = valor;
    
    if(lista == NULL) {
        lista = nova;
        nova->prox = NULL;
    } else {
        nova->prox = lista;
        lista = nova;
    }

    return lista;
}

void imprimir(celula * lista) {
    if (lista != NULL) {
        printf("%d ", lista->dado);
        imprimir(lista->prox);
    }
}

void separar_listas(celula *lista) {
    celula *aux = lista;
    celula *auxPar = NULL;
    celula *auxImpar = NULL;
    while (aux!= NULL) {
        if (aux->dado % 2 == 0) {
            if (auxPar == NULL) {
                auxPar = aux;
            } else {
                auxPar->prox = aux;
            }
        } else {
            if (auxImpar == NULL) {
                auxImpar = aux;
            } else {
                auxImpar->prox = aux;
            }
        }
        aux = aux->prox;
    }

    printf("Lista par: ");
    imprimir(auxPar);

    printf("\nLista ímpar: ");
    imprimir(auxImpar);
    printf("\n");
    
    free(auxPar);
    free(auxImpar);
}

int main (int argc, char *argv[]) {
    celula *lista = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir valor");
        printf("\n2 - Imprimir lista");
        printf("\n3 - Imprimir listas separadas");
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
            printf("\n");
            break;
        case 3:
            separar_listas(lista);;
            printf("\n");
            break;
        case 9:
            printf("Volte sempre!");
            break;     
        default:
            printf("Selecione uma opção válida.");
            printf("\n");
            break;
        }
    } while(resp != 9);

    return 0;
}