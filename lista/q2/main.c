/*
2. Escreva um algoritmo que receba uma lista de 10 inteiros, solicite um
número qualquer e informar se o número informado está na lista ou
não. Implemente duas versões, uma com vetores, e outra com listas
simplesmente encadeadas.
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 10

int buscarVetor(int valor, int vet[], int tam) {
    for (int i = 0; i < tam; i++) {
        if (vet[i] == valor) {
            return 1;
        }
    }
    return 0;
}

typedef struct reg {
    int conteudo;
    struct reg *prox;
} celula;

celula *inserir (int valor, celula *topo) {
    celula *nova;
    nova = malloc(sizeof(celula));
    nova->conteudo = valor;
    nova->prox = NULL;
    if (topo != NULL) {
        nova->prox = topo;
    }
    topo = nova;
    return topo;
}

celula *buscarLista (int valor, celula *lista) {
    celula *aux = lista;
    while (aux != NULL && aux->conteudo == valor) {
        aux = aux->prox;
    }
    return aux;
}

int main() {
    int vet[TAM], valorV, valorL;
    int tam = sizeof(vet)/sizeof(vet[0]);
    celula *lista;

    for (int i = 0; i < tam; i++) {
        printf("Informe o %d° valor do vetor: ", i+1);
        scanf("%d", &vet[i]);
    }
    
    printf("Informe o valor para procurar no vetor: ");
    scanf("%d", &valorV);

    if (buscarVetor(valorV, vet, tam)) {
        printf("%d está no vetor.\n", valorV);
    } else {
        printf("%d não está no vetor.\n", valorV);
    }

    printf("\n");

    for (int i = 0; i < TAM; i++) {
        int aux;
        printf("Informe o %d° valor da lista: ", i+1);
        scanf("%d", &aux);
        lista = inserir(aux, lista);
    }
    
    printf("Informe o valor para procurar na lista: ");
    scanf("%d", &valorL);

    if (buscarLista(valorL, lista) != NULL) {
        printf("%d está na lista.\n", valorL);
    } else {
        printf("%d não está na lista.\n", valorL);
    }



    return 0;
}
