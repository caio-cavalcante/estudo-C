/*
Você foi contratado para melhorar a eficiência de um sistema que armazena dados de clientes em uma pilha. No entanto, percebeu-se que alguns registros foram inseridos de forma duplicada. Seu desafio é implementar uma função que da lista encadeada, mantendo apenas a primeira ocorrência de cada valor. Deve percorrer a lista apenas uma vez para cada nó (ou seja, sem verificações desnecessárias). A função deve modificar a lista sem criar uma nova lista.

Lista encadeada: 1 → 3 → 2 → 3 → 4 → 2 → 5

Lista encadeada após remoção de duplicatas: 1 → 3 → 2 → 4 → 5
Pense em como percorrer a lista e comparar os valores sem utilizar memória extra significativa.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct reg {
    int conteudo;
    struct reg *prox;
    struct reg *ant;
} Node;

void imprimir(Node *topo) {
    printf("\nElementos na pilha: \n");
    for (Node *aux = topo; aux!= NULL; aux = aux->prox) {
        printf("%d\n", aux->conteudo);
    }
}

Node *inserir(Node *topo, int valor) {
    Node *novo = malloc(sizeof(Node));
    novo->conteudo = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (topo == NULL) {
        topo = novo;
    } else if (topo->prox == NULL) {
        novo->ant = topo;
        topo->prox = novo;
    } else {
        Node *aux = topo;
        while (aux->prox!= NULL) {
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->ant = aux;
    }
    return topo;
}

void removerDuplicados(Node *topo) {
    Node *aux = topo;
    while (aux!= NULL) {
        Node *aux2 = aux->prox;
        while (aux2!= NULL) {
            if (aux->conteudo == aux2->conteudo) {
                Node *temp = aux2;
                aux2 = aux2->prox;
                aux->prox = aux2;
                if (aux2!= NULL) {
                    aux2->ant = aux;
                }
                free(temp);
            } else {
                aux2 = aux2->prox;
            }
        }
        aux = aux->prox;
    }
}

int main (int argc, char **argv) {
    Node *topo = NULL;
    int opcao;

    do {
        printf("\nMENU\n");
        printf("[1] Inserir na pilha\n");
        printf("[2] Imprimir pilha\n");
        printf("[3] Remover duplicados\n");
        printf("[4] Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                int valor;
                printf("\nDigite um numero: ");
                scanf("%d", &valor);
                topo = inserir(topo, valor);
                break;
            case 2:
                imprimir(topo);
                break;
            case 3:
                removerDuplicados(topo);
                printf("\nDuplicados removidos!\n");
                break;
            case 4:
                printf("\nAté mais!\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
        }
    } while (opcao != 4);
    
}