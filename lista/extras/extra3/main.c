/*
Um vetor ARRUMADO é um vetor v[p .. r] onde existe ao menos um j
∈ [p, r] tal que v[p..j − 1] ≤ v[j] < v[j + 1..r] (ou seja, existe ao menos
um j pertencente ao vetor v, cujos elementos da esquerda são menores
que j e os elementos da direita são maiores que j). Escreva um
algoritmo, em linguagem C, que decida se v[p..r] está ARRUMADO.
Em caso afirmativo, o seu algoritmo deve devolver o valor de j. OBS.:
Os vetores arrumados NÃO se resumem aos vetores ORDENADOS,
pois eles podem não estar exatamente ordenados!!
*/

#include <stdio.h>

/*
vou percorrer todos os valores do vetor
inicialmente vou salvar o valor j e ver se
todos a esquerda dele são menores que ele
e se todos a direita dele são maiores que ele
*/
void arrumado(int v[], int p, int r) {
  int cont = -1;

  for (int j = p; j <= r; j++) {
    int esq_men = 1;
    int dir_mai = 1;

    for (int i = p; i < j; i++) {
      if (v[i] > v[j]) {
        esq_men = 0;
        break;
      }
    }

    for (int i = j+1; i <= r; i++) {
      if (v[i] <= v[j]) {
        dir_mai = 0;
        break;
      }
    }

    if (esq_men && dir_mai) {
      printf("O vetor está arrumado, e o j é %d.\n", v[j]);
      cont++;
    }
  }

  if (cont == -1) {
    printf("O vetor não está arrumado.\n", p, r);
  }
}

void main() {
  int v1[7] = {2, 1, 4, 5, 3, 7, 6};
  int v2[7] = {2, 1, 4, 3, 5, 7, 6};
  int v3[7] = {1, 2, 4, 3, 5, 7, 6};
  int p = 0, r = 6;

  printf("Vetor 1:\n");
  arrumado(v1, p, r);
  printf("\nVetor 2:\n");
  arrumado(v2, p, r);
  printf("\nVetor 3:\n");
  arrumado(v3, p, r);
}