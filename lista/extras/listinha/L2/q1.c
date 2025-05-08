/*
1. ) Escreva um algoritmo que receba uma expressaoessão matemática (com-
posta por operandos compostos por um único algarismo, operações de
+, -, * e / e parênteses) representada por um string e retorne uma
árvore binária representando esta expressaoessão
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

typedef struct noArvore {
    char valor;
    struct noArvore *filhoEsq;
    struct noArvore *filhoDir;
} noArvore;

noArvore* criarNo(char valor) {
    noArvore* no = (noArvore*) malloc(sizeof(noArvore));
    no->valor = valor;
    no->filhoEsq = no->filhoDir = NULL;
    return no;
}

int ehSimbolo(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int ordemOperacao(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Converte a expressão de string para pos-fixa
void expressaoPosfixa(char* expressao, char* posfixa) {
    char pilha[MAX];
    int topo = -1, temp = 0;
    
    for (int i = 0; expressao[i]; i++) {
        char c = expressao[i];
        
        if (isdigit(c)) {
            posfixa[temp++] = c;
        } else if (c == '(') {
            pilha[++topo] = c;
        } else if (c == ')') {
            while (topo >= 0 && pilha[topo] != '(')
                posfixa[temp++] = pilha[topo--];
            if (topo >= 0) topo--; // Remove '('
        } else if (ehSimbolo(c)) {
            while (topo >= 0 && ordemOperacao(pilha[topo]) >= ordemOperacao(c))
                posfixa[temp++] = pilha[topo--];
            pilha[++topo] = c;
        }
    }

    while (topo >= 0)
        posfixa[temp++] = pilha[topo--];

    posfixa[temp] = '\0';
}

// Constrói árvore da pós-fixa
noArvore* posfixaArvore(char* posfixa) {
    noArvore* pilha[MAX];
    int topo = -1;

    for (int i = 0; posfixa[i]; i++) {
        char c = posfixa[i];
        noArvore* no = criarNo(c);
        if (ehSimbolo(c)) {
            no->filhoDir = pilha[topo--];
            no->filhoEsq = pilha[topo--];
        }
        pilha[++topo] = no;
    }

    return pilha[topo];
}

// Monta árvore da expressão
noArvore* expressaoArvore(char* expressao) {
    char posfixa[MAX];
    expressaoPosfixa(expressao, posfixa);
    return posfixaArvore(posfixa);
}

void desenhar(noArvore *raiz, int nivel) {
    if (raiz) {
        desenhar(raiz->filhoDir, nivel + 1);
        for (int i = 0; i < nivel; i++) printf("   ");
        printf("%c\n", raiz->valor);
        desenhar(raiz->filhoEsq, nivel + 1);
    }
}

int main() {
    char expressao[MAX];

    printf("\n\nDigite uma expressão matemática: ");
    scanf("%s", expressao);

    noArvore* raiz = expressaoArvore(expressao);
    printf("Árvore desenhada:\n\n");
    desenhar(raiz, 0);
    return 0;
}