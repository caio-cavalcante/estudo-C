/*
3. Escreva um algoritmo que leia 10 números de reais e informe (faça uma
função – modularizada – para cada funcionalidade pedida):
a) a média dos elementos;
b) o maior e menor elemento;
c) a quantidade de elementos positivos e a quantidade de elementos
negativos.
*/

#include <stdio.h>

#define TAM 10

float media (int vet[], int tam) {
    float soma = 0;
    for (int i = 0; i < tam; i++) {
        soma += vet[i];
    }
    return soma / tam;
}

int maior (int vet[], int tam) {
    int maior = vet[0];
    for (int i = 1; i < tam; i++) {
        if (vet[i] > maior) {
            maior = vet[i];
        }
    }
    return maior;
}

int menor (int vet[], int tam) {
    int menor = vet[0];
    for (int i = 1; i < tam; i++) {
        if (vet[i] < menor) {
            menor = vet[i];
        }
    }
    return menor;
}

int qtdePositivos (int vet[], int tam) {
    int qtde = 0;
    for (int i = 0; i < tam; i++) {
        if (vet[i] > 0) {
            qtde++;
        }
    }
    return qtde;
}

int qtdeNegativos (int vet[], int tam) {
    int qtde = 0;
    for (int i = 0; i < tam; i++) {
        if (vet[i] < 0) {
            qtde++;
        }
    }
    return qtde;
}

int main() {
    int vet[TAM];
    int tam = sizeof(vet)/sizeof(vet[0]);

    for (int i = 0; i < tam; i++) {
        printf("Informe o %d° valor do vetor: ", i+1);
        scanf("%d", &vet[i]);
    }

    printf("\na) Média: %.2f", media(vet, tam));
    printf("\nb) Maior elemento: %d", maior(vet, tam));
    printf("\nb) Menor elemento: %d", menor(vet, tam));
    printf("\nc) Quantidade de elementos positivos: %d", qtdePositivos(vet, tam));
    printf("\nc) Quantidade de elementos negativos: %d", qtdeNegativos(vet, tam));

    return 0;
}