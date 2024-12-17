/*
Implemente uma função que elimine os elementos menores ou igual a
zero de vetores lidos. Essa função deve apagar todos os elementos
menores ou iguais a zero de um vetor passado como parâmetro da
função.
*/

#include <stdio.h>

void removeZero(int vet[], int tam) {
    int i, j;

    for (i = 0, j = 0; i < tam; i++) {
        if (vet[i] > 0) {
            vet[j] = vet[i];
            j++;
        }
    }

    for (i = j; i < tam; i++) {
        vet[i] = 0;
    }
}

int main() {
    int vetor[] = {1, -5, 3, 0, -8, 2, -7, 4, 9, 6};
    int tam = sizeof(vetor) / sizeof(vetor[0]);
    
    printf("Vetor original:\n");
    for (int i = 0; i < tam; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    removeZero(vetor, tam);
    
    printf("Vetor modificado:\n");
    for (int i = 0; i < tam; i++) {
        if (vetor[i] != 0) {
            printf("%d ", vetor[i]);
        } else {
            break;
        }
    }
}