#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int dado;
    struct reg *prox;
} celula;

celula *inserir(celula *lista, int valor) {
    celula *nova, *aux;
    nova = malloc(sizeof(celula));
    nova->dado = valor;
    nova->prox = NULL;

    if (lista != NULL) {
        aux = lista;

        while (aux->prox != lista) {
            aux = aux->prox;
        }
        nova->prox = aux->prox;
        aux->prox = nova;
    } else {
        nova->prox = nova;
    }
    lista = nova;
    return lista;
}

void imprimir(celula *lista) {
    celula *aux;

    if (lista == NULL) {
        printf("Lista Vazia");
    }

    for (aux = lista; aux != NULL; aux = aux->prox) {
        printf("%d ", aux->dado);
        if (aux->prox == lista) break;
    }
}

celula *buscar(celula *lista, int valor) {
    celula *aux, *topo;
    topo = lista;
    aux = lista->prox;

    while (aux->dado != valor) {
        aux = aux->prox;
        if (aux == topo) {
            break;
        }
    }

    if (aux->dado == valor) {
        printf("%d está na lista!", valor);
    } else {
        printf("%d não está na lista.", valor);
    }
    return aux;
}

void remover(celula *lista, int valor) {
}

int main(int argc, char *argv[]) {
    celula *lista = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir valor");
        printf("\n2 - Imprimir lista");
        printf("\n3 - Buscar valor");
        printf("\n4 - Remover valor na lista");
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
                printf("Qual valor deseja buscar? ");
                scanf("%d", &valor);

                buscar(lista, valor);
                printf("\n");
                break;
            case 4:
                printf("Qual valor deseja remover? ");
                scanf("%d", &valor);

                remover(lista, valor);
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