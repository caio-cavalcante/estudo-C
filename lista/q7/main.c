/*
7. O Zodíaco chinês é composto por animais com ciclo de 12 anos. Uma
maneira simplificada de identificá-lo é verificando-se apenas o ano de
seu nascimento do seguinte modo:

Crie um algoritmo que receba o ano de nascimento do usuário e retorne o
signo correspondente. Use listas simplesmente encadeadas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    int ano;
    char animal[20];
    struct celula* prox;
} celula;

celula* criarCelula(int ano, char animal[]) {
    celula* nova;
    nova = (celula*)malloc(sizeof(celula));
    nova->ano = ano;
    strcpy(nova->animal, animal);
    nova->prox = NULL;
    return nova;
}

void inserir(celula** topo, celula* nova) {
    if (*topo == NULL) {
        *topo = nova;
    } else {
        celula* temp = *topo;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = nova;
    }
}

char* buscar(celula* topo, int anoNasc) {
    int ano = anoNasc % 12;
    celula* temp = topo;
    while (temp != NULL) {
        if (temp->ano == ano) {
            return temp->animal;
        }
        temp = temp->prox;
    }
    return "Não encontrado.";
}

int main() {
    celula* lista = NULL;

    inserir(&lista, criarCelula(0, "Macaco"));
    inserir(&lista, criarCelula(1, "Galo"));
    inserir(&lista, criarCelula(2, "Cachorro"));
    inserir(&lista, criarCelula(3, "Porco"));
    inserir(&lista, criarCelula(4, "Rato"));
    inserir(&lista, criarCelula(5, "Boi"));
    inserir(&lista, criarCelula(6, "Tigre"));
    inserir(&lista, criarCelula(7, "Coelho"));
    inserir(&lista, criarCelula(8, "Dragão"));
    inserir(&lista, criarCelula(9, "Serpente"));
    inserir(&lista, criarCelula(10, "Cavalo"));
    inserir(&lista, criarCelula(11, "Cabra"));

    int ano;
    printf("Digite o ano de nascimento: ");
    scanf("%d", &ano);

    char* signo = buscar(lista, ano);
    printf("Seu signo do zodíaco chinês é: %s\n", signo);

    celula* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}
