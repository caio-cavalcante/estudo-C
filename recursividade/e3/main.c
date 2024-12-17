/*
A função de Fibonacci é definida assim: Fib(0) = 0,
Fib(1) = 1 e Fib(n) = Fib(n − 1) + Fib(n − 2) para n > 1.
Descreva a função Fib em linguagem C. Faça uma versão
recursiva e outra iterativa.
*/

#include <stdio.h>

int fibonacci_recursiva(int n) {
    if (n <= 1) return n;
    return fibonacci_recursiva(n-1) + fibonacci_recursiva(n-2);
}

int fibonacci_iterativa(int n) {
    int fib[n+2];
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    return fib[n];
}

int main() {
    int n;
    printf("Informe um número: ");
    scanf("%d", &n);
    
    printf("%d° número de Fibonacci: %d", n, fibonacci_recursiva(n));
    printf("\n");
    printf("%d° número de Fibonacci: %d", n, fibonacci_iterativa(n));
    
    return 0;
}