/*
Faça um algoritmo que leia dois vetores com 20 inteiros cada, junte-os 
num terceiro vetor de 40 posições, ordenando-o através do método de 
ordenação InsertionSort.
*/
#include <stdio.h>
#include <stdlib.h>
#define TAM 20

void juntar (int vetor1[], int vetor2[], int vetor3[]) {
    for (int i = 0; i < 2*TAM; i++) {
        if (i < TAM) {
            vetor3[i] = vetor1[i];
        } else {
            vetor3[i] = vetor2[i-TAM];
        }
    }
}

void insertionSort (int vetor3[]) {
    int i, j, aux, flag = 0;
    while (!flag) {
        flag = 1;
        for (i = 1; i < (TAM-1); i++) {
            if (vetor3[i] > vetor3[i+1]) {
                flag = 0;
                aux = vetor3[i];
                vetor3[i] = vetor3[i+1];
                vetor3[i+1] = aux;
            }
        }
    }
}

int main() {
    int vetor1[TAM], vetor2[TAM], vetor3[2*TAM];

    for (int i = 0; i < TAM; i++) {
        printf("Informe o %d° valor do vetor 1: ", i+1);
        scanf("%d", &vetor1[i]);
    }

    for (int i = 0; i < TAM; i++) {
        printf("Informe o %d° valor do vetor 2: ", i+1);
        scanf("%d", &vetor2[i]);
    }

    juntar(vetor1, vetor2, vetor3);
    insertionSort(vetor3);

    printf("\nVetor 1: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor1[i]);
    }
    
    printf("\nVetor 2: ");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", vetor2[i]);
    }

    printf("\nVetor 3: ");
    for (int i = 0; i < 2*TAM; i++) {
        printf("%d ", vetor3[i]);
    }

    return 0;
}