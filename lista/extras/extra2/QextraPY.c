#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *prox;
    struct No *ant;
} No;

void mostrarLista(No *topo) {
    printf("===== Elementos na Lista =====\n");
    for (No *aux = topo; aux != NULL; aux = aux->prox) {
        printf("%d\n", aux->valor);
    }
}

No *inserirElemento(No *topo, int num) {
    No *novo = malloc(sizeof(No));
    novo->valor = num;
    novo->prox = NULL;
    novo->ant = NULL;

    if (topo == NULL) {
        return novo;
    } 
    
    No *aux = topo;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }

    novo->ant = aux;
    aux->prox = novo;
    
    return topo;
}

void removerDuplicatas(No *topo) {
    for (No *atual = topo; atual != NULL; atual = atual->prox) {
        No *aux = atual->prox;

        while (aux != NULL) {
            if (aux->valor == atual->valor) {
                No *temp = aux;
                aux->ant->prox = aux->prox;

                if (aux->prox != NULL) {
                    aux->prox->ant = aux->ant;
                }

                aux = aux->prox;
                free(temp);
            } else {
                aux = aux->prox;
            }
        }
    }
}

int main() {
    No *topo = NULL;
    int opcao, valor;

    do {
        printf("\n=========== MENU ===========\n");
        printf("[1] Adicionar número\n");
        printf("[2] Exibir lista\n");
        printf("[3] Remover números duplicados\n");
        printf("[4] Sair do programa\n");
        printf("============================\n");
        printf("Digite sua escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe um número para adicionar: ");
                scanf("%d", &valor);
                topo = inserirElemento(topo, valor);
                printf("Número %d adicionado!\n", valor);
                break;
            case 2:
                mostrarLista(topo);
                break;
            case 3:
                removerDuplicatas(topo);
                printf("Duplicatas removidas!\n");
                break;
            case 4:
                printf("Finalizando o programa...\n");
                break;
            default:
                printf("Opção inválida! Digite novamente.\n");
        }
    } while (opcao != 4);

    printf("Programa encerrado. Obrigado por usar!\n");
    return 0;
}
