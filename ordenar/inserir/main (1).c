/*
Ordenações
*/
#include <stdio.h>

void  insertionSort (int v[], int tam) {
    int aux;
    for (int i = 1; i < tam; i++) {
        int j = i;
        while ((j > 0) && (v[j] < v[j-1])) {
            aux = v[j];
            v[j] = v[j-1];
            v[j-1] = aux;
            j--;
        }
        printf("\n");
        for (int k = 0; k < tam; k++) {
            printf("v[%d] = %d, ", k, v[k]);
        }  
    }
}

int main()
{
    int v[] = {5, 4, 3, 2, 1};
    int tam = sizeof(v)/sizeof(v[0]);
    printf("Vetor: ");
    for (int i = 0; i < tam; i++) {
        printf("\nv[%d] = %d", i, v[i]);
    }
    
    printf("\n\nPasso a passo:");
    insertionSort(v, tam);
    
    printf("\n\nVetor ordenado: ");
    for (int i = 0; i < tam; i++) {
        printf("\nv[%d] = %d", i, v[i]);
    }

    return 0;
}