/*
1. Faça uma algoritmo que implemente uma função que leia uma sequência
de NÚMEROS informados pelo usuário, salve-os numa lista dupla-
mente encadeada, ordene-os usando um dos algoritmos de ordenação
visto em sala e mostre-os em ordem crescente.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int dado;
  struct node *prox;
  struct node *ant;
} celula;

celula *inserir(celula *lista, int valor) {
  celula *aux, *nova = (celula *)malloc(sizeof(celula));
  nova->dado = valor;
  nova->prox = NULL;
  nova->ant = NULL;

  if (lista == NULL) {
    lista = nova;
  } else {
    aux = lista;
    while (aux->prox!= NULL) {
      aux = aux->prox;
    }
    aux->prox = nova;
    nova->ant = aux;
  }

  return lista;
}

/*
tratar se: a lista só tem 1 elemento
se tiver apenas 1, 
*/
celula *ordenar(celula *lista) {
  if (lista == NULL) {
    printf("Lista vazia.");
    return lista;
  } else if (lista->prox == NULL) {
    printf("Lista ordenada!");
    return lista;
  } else {

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

int main(int argc, char *argv[]) {
  celula *lista = NULL;
  int resp, valor;

  do {
    printf("\nMenu:");
    printf("\n1 - Inserir valor");
    printf("\n2 - Imprimir lista");
    printf("\n3 - Ordenar lista");
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
        ordenar(lista);
        break;
      case 9:
        printf("Volte sempre!");
        break;
      default:
        printf("Selecione uma opção válida.");
        printf("\n");
        break;
    }
  } while (resp != 9);

  return 0;
}