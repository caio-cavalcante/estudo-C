#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *prox;
    struct node *ant;
} celula;



int main(int argc, char *argv[]) {
    celula *lista = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir valor no início");
        printf("\n2 - Imprimir lista");
        printf("\n9 - Sair\n");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
        case 1:
            printf("Qual o valor a inserir? ");
            scanf("%d", &valor);

            lista = inserirInicio(lista, valor);
            break;
        case 2:
            imprimir(lista);
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