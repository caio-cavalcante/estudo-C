/*
5. Escreva um algoritmo que leia três vetores do mesmo nanho (N) e:
a) calcule a norma de cada um dos vetores, informe qual vetor tem a
maior norma (a norma de um vetor é a raiz quadrada da soma de seus
elementos );
b) calcule o vetor soma dos três vetores (o vetor soma é a soma de cada
elemento).
*/

#include <stdio.h>
#include <math.h>

double calculaNorma (double vet[], int n) {
    double soma = 0;
    for (int i = 0; i < n; i++) {
        soma += vet[i] * vet[i];
    }
    return sqrt(soma);
}

int main() {
    int n = 5;
    double vetorA[n], vetorB[n], vetorC[n], vetSoma[n];
    double maiorNorma;

    for (int i = 0; i < n; i++) {
        printf("Informe o %d° valor do %d° vetor: ", i+1, 1);
        scanf("%d", &vetorA[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Informe o %d° valor do %d° vetor: ", i+1, 2);
        scanf("%d", &vetorB[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("Informe o %d° valor do %d° vetor: ", i+1, 3);
        scanf("%d", &vetorC[i]);
    }

    double normaA = calculaNorma(vetorA, n);
    double normaB = calculaNorma(vetorB, n);
    double normaC = calculaNorma(vetorC, n);

    if (normaA > normaB && normaA > normaC) {
        maiorNorma = 1;
    } else if (normaB > normaC) {
        maiorNorma = 2;
    } else {
        maiorNorma = 3;
    }
    
    printf("\nNorma do vetor 1: %.2f\n", normaA);
    printf("Norma do vetor 2: %.2f\n", normaB);
    printf("Norma do vetor 3: %.2f\n", normaC);
    printf("Vetor com maior norma: %.0f\n", maiorNorma);

    printf("\nVetor soma: ");
    for (int i = 0; i < n; i++) {
        vetSoma[i] = vetorA[i] + vetorB[i] + vetorC[i];
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", vetSoma[i]);
    }
    printf("\n");

    return 0;
}