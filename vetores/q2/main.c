// Inversão. Suponha que um vetor v[1..n] contém uma
// permutação de [1..n]. Escreva uma função que inverta essa
// permutação: se v[i] == j no vetor original, queremos ter
// v[j] == i no fim da execução da função.

#include <stdio.h>

int vj[10], vi[]={7,5,6,3,2,9,8,1,4,0}; //vetor em branco e valores aleatórios

int main()
{
    for (int i = 0; i < 10; i++) {
        vj[vi[i]] = i; // atribui o valor i no vj[] com posição vi[i] 
    } // valor 7 está no vi[0], então o vj[7] = 0
    
    for (int i = 0; i < 10; i++) {
        printf("Original: vi[%d] = %d\n", i, vi[i]);
    }
    
    printf("\n");
    
    for (int i = 0; i < 10; i++) {
        printf("Permutação: vj[%d] = %d\n", i, vj[i]);
    }
    return 0;
}