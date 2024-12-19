/*
Ordenações
*/
#include <stdio.h>

void bubbleSort (int v[], int tam) {
    int aux, flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 1; i < tam; i++) {
            if (v[i-1] > v[i]) {
                flag = 1;
                aux = v[i];
                v[i] = v[i-1];
                v[i-1] = aux;
            }
            printf("\n");
            for (int i = 0; i < tam; i++) {
                printf("v[%d] = %d, ", i, v[i]);
            }
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
    bubbleSort(v, tam);
    
    printf("\n\nVetor ordenado:");
    for (int i = 0; i < tam; i++) {
        printf("\nv[%d] = %d", i, v[i]);
    }

    return 0;
}