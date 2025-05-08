/*
1.) Fazer o algoritmo de MDC de forma recursiva;
*/

#include <stdio.h>

int MDC(int num1, int num2, int divisor) {
    if(num1 % divisor == 0 && num2 % divisor == 0) {
        printf("MDC(%d, %d) = %d", num1, num2, divisor);
        return divisor;
    } else {
        return MDC(num1, num2, divisor-1);
    }
}

void main() {
    int num1, num2;
    char resp;

    do {
        printf("Informe dois números inteiros: ");
        scanf("%d %d%*c", &num1, &num2);

        MDC(num1, num2, num1);

        printf("\nDeseja repetir operação? S-Sim e N-Não\n");
        scanf("%c", &resp);
    } while((resp == 'S') || (resp == 's'));
}