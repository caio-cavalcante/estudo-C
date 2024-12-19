/*
Demonstrativo com passo a passo de cada ordenação
*/

#include <stdio.h>
#include <stdlib.h>

void insertionSort(int tam, int v[]){
    int j,aux;
    for(int i=1; i<tam; i++){
        j = i;
        while((j>0) && (v[j]<v[j-1])){
            aux=v[j];
            v[j]=v[j-1];
            v[j-1]=aux;
            j--;
            
            printf("\n");
            
            for (int k = 0; k < tam; ++k) {
                printf("v[%d] = %d, ", k, v[k]);
            }
        }
    } 
}

void bubbleSort(int tam, int v[]){
    int aux;
    for(int j=1; j<tam; j++){
        for(int i=1; i<tam; i++){
            if (v[i-1] > v[i]){
               aux=v[i];
               v[i]=v[i-1];
               v[i-1]=aux;
            }
            
            printf("\n");
            
            for (int k = 0; k < tam; ++k) {
                printf("v[%d] = %d, ", k, v[k]);
            }
        }
    } 
}

void selectionSort(int tam, int vet[]) {
    int aux, menor;
    for (int i = 0; i < tam; i++){
        menor = i;
        for (int j = i; j < tam; j++) {
            if (vet[j] < vet[menor]) {
                menor = j;
            }
        }
        aux = vet[menor];
        vet[menor] = vet[i];
        vet[i] = aux;
    }
}

int main (void){
    int i,j,aux,tam;
    int v1[]={2, 4, 6, 5, 3};
    int v2[]={2, 4, 6, 5, 3};
    int v3[]={2, 4, 6, 5, 3};
    tam = sizeof(v1)/ sizeof(v1[0]);

    printf("Vetor Original:\n");
    for (int k = 0; k < tam; ++k) {
        printf("v[%d] = %d, ", k, v1[k]);
    }
    
    printf("\n\nInsertion Sort:");
    insertionSort(tam, v1);
    
    printf("\n\nBubble Sort:");
    bubbleSort(tam, v2);
    
    printf("\n\nSelection Sort:");
    selectionSort(tam, v3);

    return 0;
}