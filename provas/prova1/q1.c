/*
Faça um algoritmo que leia um vetor com 50 nomes e ordene-os em 
ordem alfabética pelo algoritmo de SelectionSort.
*/
#include <stdio.h>
#include <string.h>
#define TAM 50

void selectionSort(char nomes[TAM][30]) {
    int i, j, min;
    char aux[30];
    for (i = 0; i < TAM - 1; i++) {
        min = i;
        for (j = i + 1; j < TAM; j++) {
            if (strcmp(nomes[j], nomes[min]) < 0) {
                min = j;
            }
        }
        strcpy(aux, nomes[i]);
        strcpy(nomes[i], nomes[min]);
        strcpy(nomes[min], aux);
    }
}

int main() {
    char nomes[TAM][30];
    for (int i = 0; i < TAM; i++) {
        printf("Informe o %d° nome: ", i + 1);
        scanf("%s", nomes[i]);
    }
    selectionSort(nomes);
    for (int i = 0; i < TAM; i++) {
        printf("%s\n", nomes[i]);
    }
    return 0;
}