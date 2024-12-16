/*
Faça um algoritmo recursivo que encontre qual o maior valor
de um vetor.
*/
#include <stdio.h>

int maior (int n, int v[]) {
    int nMaior;
    if (n == 0) return -1;
    
    if (n == 1) return v[0];
    
    nMaior = maior (n-1, v);
    
    if (v[n-1] > nMaior) {
        return v[n-1];
    } else {
        return nMaior;
    }
}

int main() {
    int n;
    
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);
    int v[n];

    for (int i = 0; i < n; i++) {
        printf("Informe o %d° número do vetor: ", i+1);
        scanf("%d", &v[i]);
    }
    
    int m = maior(n, v);
    printf("O maior número do vetor é: %d", m);

    return 0;
}
