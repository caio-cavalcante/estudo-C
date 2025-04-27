/*
Faça o QuickSort ou o HeapSort recursivo em linguagem C, quem conseguir implementar até amanhã à noite ganha meio ponto extra! Boa sorte! Envia o arquivo .c aqui! Se eu achar a implementação igual na internet, não darei o ponto… tem que fazer você mesmo!
*/

#include <stdio.h>
#include <stdlib.h>  // para usar rand e srand
#include <time.h>    // para usar time

// realiza a troca de 2 vetores
void swap(int vet[], int i, int j) {
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

// particiona e retorna o índice do pivô
int partition(int vet[], int inicio, int fim) {
    int pivot, pivotIndex;

    // pivô é o último elemento
    pivot = vet[fim];
    pivotIndex = inicio;

    for (int i = inicio; i < fim; i++) {
        if (vet[i] < pivot) {
            swap(vet, i, pivotIndex);
            pivotIndex++;
        }
    }

    swap(vet, pivotIndex, fim);

    return pivotIndex;
}

// para evitar o pior caso possível, gera um pivô aleatório
int randomPartition(int vet[], int inicio, int fim) {
    int pivotIndex = rand() % (fim - inicio + 1) + inicio;

    swap(vet, pivotIndex, fim);

    return partition(vet, inicio, fim);
}

int quicksort(int vet[], int inicio, int fim) {
    if (inicio < fim) {
        int pivotIndex = randomPartition(vet, inicio, fim);
        quicksort(vet, inicio, pivotIndex - 1);
        quicksort(vet, pivotIndex + 1, fim);
    }
}

int heapsort(int vet[], int tam) {}

void main() {
    int tam, resp, vet[tam];
    srand(time(NULL));

    printf("\nInsira o tamanho do vetor: ");
    scanf("%d", &tam);

    for (int i = 0; i < tam; i++) {
        printf("Insira o %dº valor do vetor: ", i + 1);
        scanf("%d", &vet[i]);
    }

    printf("\nVetor desordenado: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }

    quicksort(vet, 0, tam - 1);

    printf("\nVetor ordenado: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
}