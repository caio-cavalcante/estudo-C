/*
1 Escreva uma função que receba x, v e n e devolva 1 se x está
em v[0..n-1] e 0 em caso contrário.
2 Suponha que o vetor v[0..n-1] tem dois ou mais elementos
iguais a x. Qual deles será apontado pela função busca?
3 Quantas comparações entre x e elementos do vetor v a função
busca faz?
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int busca(int x, int v[], int n) {
    for (int i = 0; i < n; i++) {
        if (v[i] == x) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    
    int n;
    int x;

    printf("Informe o tamanho do vetor v: ");
    scanf("%d", &n);
    
    int v[n];

    for (int i = 0; i < n; i++) {
        v[i] = rand() % n + 1;
        printf("v[%d] = %d\n", i, v[i]);
    }
    
    printf("Informe o valor de x: ");
    scanf("%d", &x);
    
    if (busca(x, v, n)) {
        printf("Valor x está no vetor.");
    } else {
        printf("Valor x não está no vetor.");
    }

    return 0;
}