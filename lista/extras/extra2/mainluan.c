#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
    struct reg *ant;
} celula;

void mostrar(celula *topo) {
    printf("======================\n");
    for (celula *aux = topo; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->conteudo);
    }
}

celula *inserir(celula *topo, int valor) {
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = valor;
    nova->prox = NULL;
    nova->ant = NULL;

    if (topo == NULL) {
        topo = nova;
    } else if (topo->prox == NULL) {
        nova->ant = topo;
        topo->prox = nova;
    } else {
        celula *aux;
        for (aux = topo; aux->prox != NULL; aux = aux->prox);

        nova->ant = aux;
        aux->prox = nova;
    }

    return topo;
}

void deletar(celula* topo) {
    celula *indice = topo;

    while (indice != NULL) {
        celula *aux = indice->prox;
        celula *ant = indice;

        while (aux != NULL) {
            if (aux->conteudo == indice->conteudo) {
                ant->prox = aux->prox;
                if (aux->prox != NULL) {
                    aux->prox->ant = ant;
                }
                celula *temp = aux;
                aux = aux->prox;
                free(temp);
            } else {
                ant = aux;
                aux = aux->prox;
            }
        }

        indice = indice->prox;
    }
}

int main() {
    celula *topo = NULL;
    int resp = NULL;

    do {
        printf("======================\n");
        printf("[1] - Mostrar lista\n");
        printf("[2] - Inserir valor\n");
        printf("[3] - Remover valor\n");
        printf("[4] - Sair\n");
        printf("======================\n");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                mostrar(topo);
                break;
            case 2:
                int valor;
                printf("Digite o valor: ");
                scanf("%d", &valor);

                topo = inserir(topo, valor);
                break;
            case 3:
                deletar(topo);
                break;
        }
    } while (resp != 4);

    return 0;
}