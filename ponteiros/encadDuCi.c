#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *prox;
    struct node *ant;
} celula;

celula *inserir(celula *lista, int valor) {
    
}

void main(int argc, char *argv[]) {
    celula *lista = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir valor");
        printf("\n2 - Imprimir lista");
        printf("\n3 - Buscar valor na lista");
        printf("\n4 - Remover valor da lista");
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
        case 3:
            printf("Qual valor deseja buscar? ");
            scanf("%d", &valor);

            buscar(lista, valor);
            break;
        case 4:
            lista = remover(lista);
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
}
