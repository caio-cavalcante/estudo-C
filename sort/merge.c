/*
Ordenações
*/
#include <stdio.h>

void merge (int v[], int esq, int meio, int dir) {
    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;
    
    int E[n1], D[n2];
    
    for (i = 0; i < n1; i++) {
        E[i] = v[esq+i];
    }
    for (j = 0; j < n2; j++) {
        D[j] = v[meio+1+j];
    }
    
    k = esq;
    i = 0;
    j = 0;
    
    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) {
            v[k] = E[i];
            i++;
        } else {
            v[k] = D[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        v[k] = E[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        v[k] = D[j];
        j++;
        k++;
    }
}

void mergeSort (int v[], int esq, int dir) {
    if (esq < dir) {
        int meio = (esq+dir)/2;
        
        mergeSort(v, esq, meio);
        mergeSort(v, meio+1, dir);
        
        merge(v, esq, meio, dir);
    }
}

void imprimir (int v[], int tam) {
    for (int i = 0; i < tam; i++) {
        printf("\nv[%d] = %d", i, v[i]);
    }
}

int main()
{
    int v[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int tam = sizeof(v)/sizeof(v[0]);
    printf("Vetor original:");
    imprimir(v, tam);
    
    mergeSort(v, 0, tam-1);
    
    printf("\n\nVetor ordenado:");
    imprimir(v, tam);

    return 0;
}