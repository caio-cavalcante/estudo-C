// pilhas: Last In, First Out
#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int dado;
    struct reg *cima;
    struct reg *baixo;
} celula;

celula *empilhar(celula *pilha, int valor) {
    celula *topo = malloc(sizeof(celula));
    topo->dado = valor;
    topo->baixo = NULL;
    topo->cima = NULL;

    if (pilha == NULL) {
        pilha = topo;
        return pilha;
    } else {
        topo->baixo = pilha;
        pilha->cima = topo;
        pilha = topo;
    }
    return pilha;
}

celula *desempilhar(celula *pilha) {
    if (pilha == NULL) {
        printf("Pilha vazia.\n");
        return pilha;
    } else {
        pilha = pilha->baixo;
        pilha->cima = NULL;
        return pilha;
    }
}

void imprimir(celula *pilha) {
    celula *aux = pilha;

    if (pilha == NULL) {
        printf("Pilha vazia.\n");
        return;
    } else {
        printf("Pilha:\n");
        while (aux != NULL) {
            printf("%d\n", aux->dado);
            aux = aux->baixo;
        }
    }
}

void main() {
    celula *pilha = NULL;

    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Empilhar valor");
        printf("\n2 - Desempilhar valor");
        printf("\n3 - Imprimir pilha");
        printf("\n9 - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                printf("Qual o valor a inserir? ");
                scanf("%d", &valor);

                pilha = empilhar(pilha, valor);
                break;
            case 2:
                pilha = desempilhar(pilha);
                break;
            case 3:
                imprimir(pilha);
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