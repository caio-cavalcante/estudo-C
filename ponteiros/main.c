#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
    struct reg *ant;
} celula;

void mostrarTudo(celula *topo) {
    celula *aux = topo;

    do {
        printf("%d ", aux->conteudo);
        aux = aux->prox;
    } while (aux != NULL);
    printf("\n");
}

celula *inserir(celula *topo, int conteudo) {
    celula *nova = malloc(sizeof(celula));
    nova->conteudo = conteudo;
    nova->prox = NULL;
    nova->ant = NULL;

    if (topo == NULL) {
        topo = nova;
    } else if (topo->prox == NULL) {
        nova->ant = topo;
        topo->prox = nova;
    } else {
        celula *aux = topo;
        while (aux->prox != NULL) aux = aux->prox;

        nova->ant = aux;
        aux->prox = nova;
    }

    return topo;
}

int main() {
    int resp;
    int valor;
    celula *topo = NULL;

    while (resp != 2) {
        printf("[1] - Inserir valor\n");
        printf("[2] - Sair\n");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                printf("Insira um valor: ");
                scanf("%d", &valor);
                topo = inserir(topo, valor);
                break;

            default:
                break;
        }
    }

    mostrarTudo(topo);
    return 0;
}
