/*
Inspirado por uma questão que vi num vídeo de YouTube
Tem a premissa de atualizar a mediana de um vetor a medida que ele cresce
https://www.hackerrank.com/challenges/find-the-running-median/problem
*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void selectionSort(int vet[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < tam; j++) {
            if (vet[j] < vet[menor]) {
                menor = j;
            }
        }
        int aux = vet[i];
        vet[i] = vet[menor];
        vet[menor] = aux;
    }
}

float mediana(int vet[], int tam) {
    if (tam % 2 == 0) {
        return (vet[tam / 2] + vet[tam / 2 - 1]) / 2;
    } else {
        return vet[tam / 2];
    }
}

float media(int vet[], int tam) {
    int soma = 0;
    for (int i = 0; i < tam; i++) {
        soma += vet[i];
    }
    return soma / tam;
}

int moda(int vet[], int tam) {
    int moda = vet[0], qtde = 1;
    for (int i = 1; i < tam; i++) {
        if (vet[i] == moda) {
            qtde++;
        } else {
            qtde = 1;
            moda = vet[i];
        }
    }
    return moda;
}

void imprimir(int vet[], int tam) {
    printf("[");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("]");
    printf("\nMediana: %.2f", mediana(vet, tam));
    printf("\nMedia: %.2f", media(vet, tam));
    printf("\nModa: %d", moda(vet, tam));
}

int main() {
    int vet[MAX], resp, valor, quant;

    do {
        printf("\n\nInsira um valor: ");
        scanf("%d", &valor);

        vet[quant] = valor;
        quant++;
        selectionSort(vet, quant);
        imprimir(vet, quant);
    } while (valor != -1);

    return 0;
}