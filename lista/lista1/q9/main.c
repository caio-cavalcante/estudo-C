/*
9. Dada a série de Fibonacci:
Fib = 1, 1, 2, 3, 5, 8, 13, 21, 34 ..., na qual podemos descobrir o valor
do elemento seguinte, pois o elemento sempre é a soma dos dois
elementos anteriores da série, logo: Fib(n) = Fib(n-1) + Fib(n-2). Leia
um número n, que representa a quantidade de parcelas da série de
Fibonacci desejada e informe todas as parcelas da série, implemente
este algoritmo de forma recursiva.
*/

#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    printf("Informe um número: ");
    scanf("%d", &n);
    
    printf("Parcelas da série de Fibonacci:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i+1));
    }
    
    return 0;
}