/*
Faça o QuickSort ou o HeapSort recursivo em linguagem C, quem conseguir implementar até amanhã à noite ganha meio ponto extra! Boa sorte! Envia o arquivo .c aqui! Se eu achar a implementação igual na internet, não darei o ponto… tem que fazer você mesmo!
*/

#include <stdio.h>

// troca 2 vetores
void swap(int vet[], int i, int j) {
    int aux = vet[i];
    vet[i] = vet[j];
    vet[j] = aux;
}

//organiza os elementos para o maior elemento ficar na ultima posição
void heapify(int vet[], int n, int i) {
    int maior = i;
    int esq = 2 * i + 1;
    int dir = 2 * i + 2;

    if (esq < n && vet[esq] > vet[maior]) {
        maior = esq;
    }

    if (dir < n && vet[dir] > vet[maior]) {
        maior = dir;
    }

    if (maior != i) {
        swap(vet, i, maior);
        heapify(vet, n, maior);
    }
}

// ordena usando heapify para construir e organizar o vetor, removendo elementos e colocando-os em ordem
void heapsort(int vet[], int tam) {
    for (int i = tam / 2 - 1; i >= 0; i--) {
        heapify(vet, tam, i);
    }

    for (int i = tam - 1; i >= 0; i--) {
        swap(vet, 0, i);
        heapify(vet, i, 0);
    }
}

void main() {
    int tam, resp, vet[tam];

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

    heapsort(vet, tam);

    printf("\nVetor ordenado: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vet[i]);
    }
}