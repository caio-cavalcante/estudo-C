// Diga qual o conte udo do vetor v
// depois das seguintes instru ̧c ̃oes:
// int v[99];
// for (i = 0; i < 99; ++i) v[i] = 98 − i;
// for (i = 0; i < 99; ++i) v[i] = v[v[i]];

#include <stdio.h>

int v[10];

int main()
{
    for (int i = 0; i < 10; i++) { // atribui valores decrescentes ao vetor
        v[i] = 9-i;
        printf("v[%d] = %d\n", i, v[i]);
    }
        
        printf("\n");
        
    for (int i = 0; i < 10; i++) { // atribui novo valor
        v[i] = v[v[i]]; // na metade, já atualizou, então repete valores
        printf("v[%d] = %d\n", i, v[i]);
    }
    return 0;
}
