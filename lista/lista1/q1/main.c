/*
1. Escreva um algoritmo que receba uma lista de 10 inteiros, salve
em um vetor e mostre toda a lista em na mesma linha.
*/
#include <stdio.h>

int v[9];

int main() {
    for (int i = 0; i < 10; i++) {
        printf("Informe o %d° inteiro da lista: ", i+1);
        scanf("%d", &v[i]);
    }
    
    for (int i = 0; i < 10; i++) {
        printf("v[%d]: %d | ", i, v[i]);
    }

    return 0;
}
