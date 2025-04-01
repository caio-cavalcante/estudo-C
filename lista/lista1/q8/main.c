/*
8. Faça um algoritmo iterativo e depois um recursivo que implemente a
função Fatorial. O algoritmo deve ler um número inteiro e informar o
seu fatorial, no seguinte formato:
8! = 8*7*6*5*4*3*2*1 = 40320
N! = N*(N-1)*(N-2)*...*3*2*1 = resultado
*/

#include <stdio.h>

int fatorial_iterativo(int n) {
    int resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int fatorial_recursivo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * fatorial_recursivo(n - 1);
    }
}

char mostra_multiplicação(int n) {
    printf("%d", n);
    for (n; n > 1; n--) {
        printf(" * %d", n-1);
    }   
}

int main() {
    int n;
    printf("Informe um número inteiro: ");
    scanf("%d", &n);
    
    printf("%d! = ", n);
    printf("%c", mostra_multiplicação(n));
    printf(" = %d", fatorial_iterativo(n));
    printf("\n");
    printf("%d! = ", n);
    printf("%c", mostra_multiplicação(n));
    printf(" = %d", fatorial_recursivo(n));
    
    return 0;
}