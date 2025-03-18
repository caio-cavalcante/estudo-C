/*
Dada uma lista encadeada, informada pelo usuário, que armazena
números inteiros, escreva uma função que conta a quantidade de
elementos desta lista. Escreva outra função que conta a
quantidade de vezes que o elemento temp se repete na lista.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node* prox;
} celula;

celula *inserir(celula *lista, int valor) {
    celula *nova = (celula*) malloc(sizeof(celula));
    nova->dado = valor;
    
    if(lista == NULL) {
        lista = nova;
        nova->prox = NULL;
    } else {
        nova->prox = lista;
        lista = nova;
    }

    return lista;
}

void imprimir(celula *lista) {
    celula *aux = lista;

    for (aux; aux != NULL; aux = aux -> prox) {
        printf("%d ", aux->dado);
    }
}

int contarElementos(celula *lista) {
    int cont = 0;
    celula *aux = lista;

    while (aux!= NULL) {
        cont++;
        aux = aux->prox;
    }

    return cont;
}

int contarValor(celula *lista, int valor) {
    int cont = 0;
    celula *aux = lista;

    while (aux!= NULL) {
        if (aux->dado == valor) {
            cont++;
        }
        aux = aux->prox;
    }

    return cont;
}

void ordenarCrescente(celula *lista) {
    celula *aux, *temp;
    aux = lista;
    int troca;

    while (aux!= NULL) {
        for (aux; aux->prox != NULL; aux = aux->prox) {
            temp = aux->prox;
            while (temp!= NULL) {
                if (aux->dado > temp->dado) {
                    troca = aux->dado;
                    aux->dado = temp->dado;
                    temp->dado = troca;
                }
                temp = temp->prox;
                imprimir(lista);
                printf("\n");
            }
        }
        aux = aux->prox;
    }
}

int main(int argc, char *argv[]) {
    celula *lista = NULL;
    int resp, valor, tam;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir valores");
        printf("\n2 - Imprimir lista");
        printf("\n3 - Contar elementos");
        printf("\n4 - Contar ocorrencias de um valor");
        printf("\n5 - Ordenar em ordem crescente");
        printf("\n9 - Sair\n");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
        case 1:
            printf("Quantos valores deseja adicionar? ");
            scanf("%d", &tam);
            
            for (int i = 0; i < tam; i++) {
                printf("Digite o %dº valor: ", i+1);
                scanf("%d", &valor);
                lista = inserir(lista, valor);
            }

            break;
        case 2:
            imprimir(lista);
            printf("\n");
            break; 
        case 3:
            printf("%d elementos na lista.\n", contarElementos(lista));
            break;
        case 4:
            printf("Qual o valor a contar? ");
            scanf("%d", &valor);
            printf("O valor %d se repete %d vezes na lista.\n", valor, contarValor(lista, valor));
            break;
        case 5:
            ordenarCrescente(lista);
            printf("Ordenada em ordem crescente:\n");
            imprimir(lista);
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