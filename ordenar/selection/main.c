/*
Ordenações
*/
#include <stdio.h>

void selectionSort (int v[], int tam) {
    int aux, menor;
    for (int i = 0; i < tam; i++) {
        menor = i;
        for (int j = i; j < tam; j++) {
            if (v[j] < v[menor]) {
                menor = j;
            }
        }
        aux = v[menor];
        v[menor] = v[i];
        v[i] = aux;
        
        printf("\n");
        for (int i = 0; i < tam; i++) {
            printf("v[%d] = %d, ", i, v[i]);
        }
    }
}

int main()
{
    int v[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tam = sizeof(v)/sizeof(v[0]);
    printf("Vetor original:");
    for (int i = 0; i < tam; i++) {
        printf("\nv[%d] = %d", i, v[i]);
    }
    
    printf("\n\nPasso a passo:");
    selectionSort(v, tam);
    
    printf("\n\nVetor ordenado:");
    for (int i = 0; i < tam; i++) {
        printf("\nv[%d] = %d", i, v[i]);
    }

    return 0;
}