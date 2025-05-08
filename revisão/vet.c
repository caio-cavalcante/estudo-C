/*
2.) Faça um algoritmo que leia um vetor com 20 elementos inteiros aleatórios e ordene-os. Por Bubble Sort, Insertion Sort e Selection Sort
*/
#include <stdio.h>

#define TAM 20

void bubble(int vet[], int tam) {
    int aux, flag = 0;

    while(!flag) {
        flag = 1;
        for (int i = 1; i < (tam-1); i++) {
            if (vet[i] > vet[i+1]) {
                flag = 0;
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }
}

void insertion(int vet[], int tam) {
    int aux;

    for (int i = 0; i < tam; i++) {
        for (int j = i; j >= 0; j--) {
            if (vet[j-1] > vet[j]) {
                aux = vet[j];
                vet[j]=vet[j-1];
                vet[j-1]=aux;
            }
        }
    }
}

void selection(int vet[], int tam) {
    int aux, index, menor;

    for (int i = 0; i < tam; i++) {
        menor = vet[i];
        index = i;
        for (int j = 1; j < tam; j++) {
            if (menor < vet[j]) {
                menor = vet[j];
                index = j;
            }
        }
        aux = vet[i];
        vet[i] = vet[index];
        vet[index] = aux;
    }
}

void imprimir(int vet[], int tam) {
    printf("\n");
    for (int i = 0; i < tam; i++) {
        printf("%d", vet[i]);
    }
}

void main() {
    int vet[TAM];
    char resp;

    do {
        printf("Informe os valores do vetor: ");
        for (int i = 1; i == 20; i++) {
            printf("%dº valor do vetor: ", i);
            scanf("%d%*c", &vet[i]);
        }
        
        printf("Vetor desordenado:");
        imprimir(vet, TAM);

        bubble(vet, TAM);

        printf("\nVetor ordenado:");
        imprimir(vet, TAM);
        
        printf("\nDeseja repetir operação? S-Sim e N-Não\n");
        scanf("%c", &resp);
    } while((resp == 'S') || (resp == 's'));
}