#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int dado;
    struct node *prox;
    struct node *ant;
} celula;

celula *inserirOrdenado(celula *lista, int valor) {
    celula *aux, *nova = (celula*) malloc(sizeof(celula));
    nova->dado = valor;
    nova->prox = NULL;
    nova->ant = NULL;

    if (lista == NULL) {
        lista = nova;
        return lista;
    } else if (lista->dado > valor) {
        nova->prox = lista;
        lista->ant = nova;
        lista = nova;
        return lista;
    } else {
        aux = lista;

        while (aux->prox != NULL && aux->prox->dado < valor) {
            aux = aux->prox;
        }

        nova->prox = aux->prox;
        nova->ant = aux;

        if (aux->prox != NULL) {
            aux->prox->ant = nova;
        }

        aux->prox = nova;
        return lista;
    }
}

void imprimir(celula *lista) {
    celula *aux;
    if (lista == NULL) {
        printf("Lista vazia.\n");
        return;
    } else {
        aux = lista;
        while (aux != NULL) {
            printf("%d ", aux->dado);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void buscar(celula *lista, int valor) {
    celula *aux = lista;
    int cont = 0;

    if (lista == NULL) {
        printf("Lista vazia.\n");
    } else {        
        while (aux!= NULL) {
            if(aux->dado == valor) {
                cont++;
            }
            aux = aux->prox;
        }

        if (cont != 0) {
            if (cont == 1) {
                printf("\nO valor %d aparece %d vez na lista.\n", valor, cont); 
            } else {
                printf("\nO valor %d aparece %d vezes na lista.\n", valor, cont);
            }
        } else {
            printf("\nO valor %d não foi encontrado na lista.\n", valor);
        }
    }
}

/*
verificar se a lista é vazia
se o primeiro valor é igual o lixo
se só tem um valor na lista e era o lixo
se não, precisa percorrer procurando o valor
remover o nó trocando as referências
se o valor não estiver na lista
*/
celula *remover(celula *lista) {
    celula *lixo, *aux;
    int valor;

    if (lista == NULL) {
        printf("A lista está vazia.\n");
        return NULL;
    }

    printf("Qual valor deseja remover? ");
    scanf("%d", &valor);

    if (lista->dado == valor) {
        if (lista->prox == NULL) {
            lixo = lista;
            lista = NULL;
            free(lixo);
            printf("A lista foi limpa com sucesso.\n");
            return lista;
        } else {
            lixo = lista;
            lista = lista->prox;
            lixo->ant = NULL;
            free(lixo);
            printf("Primeiro valor removido com sucesso.\n");
            return lista;
        }
    }

    aux = lista;
    while (aux->prox != NULL && aux->prox->dado != valor) {
        aux = aux->prox;
    }

    if (aux->prox != NULL) {
        lixo = aux->prox;
        aux->prox = lixo->prox;
        if (lixo->prox != NULL) {
            lixo->prox->ant = aux;
        }
        free(lixo);
        printf("Valor removido com sucesso.\n");
    } else {
        printf("Valor não encontrado na lista.\n");
    }

    return lista;
}


int main(int argc, char *argv[]) {
    celula *lista = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir valor ordenando");
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

            lista = inserirOrdenado(lista, valor);
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

    return 0;
}
