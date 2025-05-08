/*
Em um banco, há apenas um caixa e todos devem ser atendidos por
ordem de chegada. No entanto, pessoas idosas têm prioridade e passam para
o início da fila. Considerando que, em vários dias, o número de idosos é muito
grande, foram estipuladas as seguintes regras:
1. uma pessoa é atendida na ordem de chegada.
2. no máximo 2 idosos podem passar na frente de uma pessoa que não é
idosa.
Escreva um programa que leia uma sequência de informação da ordem de
chegada e Prioridade do pessoa e imprima a ordem de atendimento (considere
que todos chegaram antes de começar o atendimento, na ordem em que são
apresentados).
Ex. de entrada:
geral, geral, idoso, idoso, idoso, geral, idoso
ou pode ser lido tb: 1,1,2,2,2,1,2 (considerando que 1 é geral e 2 é idoso) Ex.
saída: 3 4 1 2 5 7 6
OBS.: Crie e use as funções enfileirar, desenfileirar, imprimir fila, etc, faça o
algoritmo para funcionar com qualquer entrada fornecida. Pode usar números
no lugar das palavras geral e idoso.
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int prioridade;  // 1 geral, 2 idoso
    int ordemChegada;
    int ordemAtendimento;
    struct node *prox;
} pessoa;

pessoa *novaPessoa(int prioridade, int ordem) {
    pessoa *nova = malloc(sizeof(pessoa));
    nova->prioridade = prioridade;
    nova->ordemChegada = ordem;
    nova->ordemAtendimento = ordem;
    nova->prox = NULL;
    return nova;
}

void passaVez(pessoa *fila) {
    int ordem = 1;

    while (fila != NULL) {
        fila->ordemAtendimento = ordem++;
        fila = fila->prox;
    }
}

pessoa *enfileirar(pessoa *fila, int prioridade, int ordemChegada) {
    pessoa *nova = novaPessoa(prioridade, ordemChegada);

    if (fila == NULL)
        return nova;

    if (prioridade == 1) {
        // Inserir no fim
        pessoa *aux = fila;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = nova;
        return fila;
    }

    pessoa *ant = NULL, *curr = fila;
    int ateDois = 0;

    while (curr != NULL) {
        if (curr->prioridade == 2) {
            ateDois++;
        } else {
            // Encontramos um geral
            if (ateDois < 2) {
                // Podemos inserir o idoso antes do geral
                if (ant == NULL) {
                    nova->prox = fila;
                    return nova;
                } else {
                    ant->prox = nova;
                    nova->prox = curr;
                    return fila;
                }
            } else {
                // Já teve 2 idosos, inserir depois do geral
                while (curr != NULL && curr->prioridade == 1) {
                    ant = curr;
                    curr = curr->prox;
                }
                ant->prox = nova;
                nova->prox = curr;
                return fila;
            }
        }
        ant = curr;
        curr = curr->prox;
    }

    // Se chegou aqui, todos eram idosos ou já no fim
    ant->prox = nova;
    return fila;
}

pessoa *desenfileirar(pessoa *fila) {
    if (fila == NULL) {
        printf("Fila vazia!!\n");
        return NULL;
    }

    pessoa *lixo = fila;
    fila = fila->prox;
    free(lixo);
    return fila;
}

void imprimirOrdem(pessoa* fila) {
    pessoa* aux = fila;
    printf("Atendimento: ");
    while (aux != NULL) {
        printf("%d ", aux->ordemChegada);
        aux = aux->prox;
    }
    printf("\n");
}

void imprimirPrioridade(pessoa* fila) {
    pessoa* aux = fila;
    printf("Prioridade: ");
    while (aux != NULL) {
        printf("%d ", aux->prioridade);
        aux = aux->prox;
    }
    printf("\n");
}

int main() {
    pessoa *fila = NULL;
    int resp, prioridade, ordem = 1;

    do {
        printf("\nMenu:");
        printf("\n[1] - Enfileirar");
        printf("\n[2] - Desenfileirar");
        printf("\n[3] - Imprimir fila");
        printf("\n[9] - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);
        switch (resp) {
            case 1:
                printf("Prioridade (1 - geral, 2 - idoso): ");
                scanf("%d", &prioridade);

                while (prioridade != 1 && prioridade != 2) {
                    printf("Prioridade inválida!");
                    printf("\nPrioridade (1 - geral, 2 - idoso): ");
                    scanf("%d", &prioridade);
                }

                fila = enfileirar(fila, prioridade, ordem);
                ordem++;
                break;
            case 2:
                fila = desenfileirar(fila);
                break;
            case 3:
                imprimirOrdem(fila);
                imprimirPrioridade(fila);
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