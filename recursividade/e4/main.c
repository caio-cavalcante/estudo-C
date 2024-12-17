/*
Prática de inserção e remoção em vetores com recursividade
*/
#include <stdio.h>
#include <stdlib.h>

#define TAM 7

int inserir (int posicao, int valor, int tamanho, int vetor[]) {
    if (posicao == tamanho) {
        vetor[tamanho] = valor;
    } else {
        vetor[tamanho] = vetor [tamanho - 1];
        inserir (posicao, valor, tamanho - 1, vetor);
    }
}

int remover (int posicao, int tamanho, int vetor[]) {
    int valor = vetor[posicao];
    if (posicao < tamanho - 1) {
        int auxiliar = remover (posicao + 1, tamanho, vetor);
        vetor[posicao] = auxiliar;
    } return valor;
}

int buscar (int valor, int tamanho, int vetor[]) {
    if (tamanho == 0) return -1;
    if (vetor[tamanho - 1] == valor) return tamanho - 1;
    return buscar(valor, tamanho - 1, vetor);
}

int main() {
    int valor, auxiliar, posicao;
    int vetor[]={3, 5, 2, 6, 0, 1, 4};
    
    for (int i = 0; i < TAM; i++) {
        printf("v[%d] = %d\n", i, vetor[i]);
    }
    
    printf("\nInforme uma posição para remover: ");
    scanf("%d", &posicao);
    remover(posicao, TAM, vetor);
    printf("v[%d] removido.\n\n", valor);
    
    for (int i = 0; i < TAM; i++) {
        printf("v[%d] = %d\n", i, vetor[i]);
    }
    
    printf("\nInforme o valor para inserir: ");
    scanf("%d", &valor);
    printf("Informe a posição para inserir: ");
    scanf("%d", &posicao);
    inserir(posicao, valor, TAM, vetor);
    
    for (int i = 0; i < TAM; i++) {
        printf("v[%d] = %d\n", i, vetor[i]);
    }

    return 0;
}