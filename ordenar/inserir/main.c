/*
Prática de ordenação por inserção: insertion sort
*/

#include <stdio.h>

void insertionSort(int vet[], int tam) {
    for (int i = 1; i < tam; i++) {
        int aux = vet[i];
        int j = i - 1;

        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j = j - 1;
        }
        vet[j + 1] = aux;
    }
}

int main() {
    int vet[] = {5, 2, 4, 6, 1, 3};
    int tam = sizeof(vet) / sizeof(vet[0]);

    printf("Vetor antes da ordenação: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");

    insertionSort(vet, tam);
    
    printf("Vetor depois da ordenação: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }

    return 0;
}