/*
Faça um algoritmo que implemente uma lista duplamente encadeada 
circular de números inteiros. Nesta lista, a inserção sempre deverá ser 
feita de forma ordenada crescente, inserindo sempre o elemento na sua 
posição correta (a inserção deve ser feita de acordo com o valor do 
elemento a ser inserido, e não no início ou no fim da lista). Faça a 
função de inserção e de exibição da lista, para que possamos exibir a 
lista antes e depois da inserção, podendo conferir se a inserção foi feita 
corretamente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *prox;
    struct node *ant;
}celula;

celula *inserir(celula *lista, int valor) {
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->dado = valor;
    nova->prox = NULL;
    nova->ant = NULL;
    celula *aux = lista;
    celula *temp = NULL;

    if (lista = NULL) {
        lista = nova;
        nova->ant = nova;
        nova->prox = nova;
        return lista;
    } else if (aux->dado > nova->dado) {
        temp->dado = aux->dado;
        aux->dado = nova->dado;
        nova->dado = temp->dado;
        nova->prox = aux->ant;
    } else {
        while (aux->prox != aux && aux->dado > nova->dado) {
            temp->dado = aux->dado;
            aux->dado = nova->dado;
            nova->dado = temp->dado;
            nova->prox = aux->ant;
        }
    }

    lista = aux;
    return lista;
}

void imprimir(celula *lista) {
    celula *aux = lista;
    while (aux->prox != aux) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }
    printf("%d\n", aux->dado);
}

int main() {
    celula *lista = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir valor");
        printf("\n2 - Imprimir lista");
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
            case 9:
                printf("Volte sempre!");
                break;
            default:
                printf("Opção inválida!");
                break;
        }
    } while (resp != 9);

    return 0;
}