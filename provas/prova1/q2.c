/*
Faça um algoritmo que leia registros de alunos (máximo de 100), salve- 
os em uma estrutura com: nome, matrícula (inteiro), 3 notas e telefone, 
insira-os,  à  medida  em  que  forem  lidos,  em  uma  lista  duplamente 
encadeada, em ordem alfabética, e permita que o usuário exclua um 
aluno pela matrícula.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct aluno {
    char nome[100];
    int matricula;
    float notas[3];
    char telefone[15];
    struct aluno *prox;
    struct aluno *ant;
} aluno;

aluno* criar(char nome[], int matricula, float notas[], char telefone[]) {
    aluno* novo = (aluno*)malloc(sizeof(aluno));
    strcpy(novo->nome, nome);
    novo->matricula = matricula;
    for (int i = 0; i < 3; i++) {
        novo->notas[i] = notas[i];
    }
    strcpy(novo->telefone, telefone);
    novo->prox = NULL;
    novo->ant = NULL;
    return novo;
}

void inserir(aluno** topo, aluno* novo) {
    if (*topo == NULL) {
        *topo = novo;
    } else {
        aluno* aux = *topo;
        while (aux->prox != NULL && strcmp(aux->nome, novo->nome) < 0) {
            aux = aux->prox;
        }
        if (strcmp(aux->nome, novo->nome) > 0) {
            novo->prox = aux;
            aux->ant = novo;
            *topo = novo;
        } else {
            aux->prox = novo;
            novo->ant = aux;
        }
    }
}

void mostrar(aluno* topo) {
    aluno* aux = topo;
    while (aux != NULL) {
        printf("Nome: %s\n", aux->nome);
        printf("Matricula: %d\n", aux->matricula);
        printf("Notas: %.2f %.2f %.2f\n", aux->notas[0], aux->notas[1], aux->notas[2]);
        printf("Telefone: %s\n", aux->telefone);
        printf("\n");
        aux = aux->prox;
    }
}

void excluir(aluno** topo, int matricula) {
    aluno* aux = *topo;
    while (aux != NULL) {
        if (aux->matricula == matricula) {
            if (aux == *topo) {
                *topo = aux->prox;
            } else {
                aux->ant->prox = aux->prox;
            }
            free(aux);
            break;
        }
        aux = aux->prox;
    }
}

int main() {
    aluno* topo = NULL;
    char nome[100];
    int matricula, resp;
    float notas[3];
    char telefone[15];

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir aluno");
        printf("\n2 - Imprimir lista de alunos");
        printf("\n3 - Excluir aluno");
        printf("\n9 - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                printf("Qual o nome do aluno? ");
                scanf("%s", nome);
                printf("Qual a matricula do aluno? ");
                scanf("%d", &matricula);
                printf("Qual a primeira nota do aluno? ");
                scanf("%f", &notas[0]);
                printf("Qual a segunda nota do aluno? ");
                scanf("%f", &notas[1]);
                printf("Qual a terceira nota do aluno? ");
                scanf("%f", &notas[2]);
                printf("Qual o telefone do aluno? ");
                scanf("%s", telefone);
                inserir(&topo, criar(nome, matricula, notas, telefone));
                break;
            case 2:
                mostrar(topo);
                break;
            case 3:
                printf("Qual a matricula do aluno que deseja excluir? ");
                scanf("%d", &matricula);
                excluir(&topo, matricula);
                break;
            case 9:
                printf("Volte sempre!");
                break;
            default:
                printf("Opcao invalida!");
                break;
        }
    } while (resp != 9);
    return 0;
}