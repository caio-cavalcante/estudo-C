/*
Ordenações
*/
#include <stdio.h>

void shellSort (int v[], int tam) {
    int j, valor, salto = 1;
    while (salto < tam) {
        salto = 3*tam+1;
    }
    while (salto > 1) {
        salto /= 3;
        for (int i = salto; i < tam; i++) {
            valor = v[i];
            j = i - salto;
            while ((j >= 0) && (valor < v[j])) {
                v[j+salto] = v[j];
                j -= salto;
            }
            v[j+salto] = valor;
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
    shellSort(v, tam);
    
    printf("\n\nVetor ordenado:");
    for (int i = 0; i < tam; i++) {
        printf("\nv[%d] = %d", i, v[i]);
    }

    return 0;
}