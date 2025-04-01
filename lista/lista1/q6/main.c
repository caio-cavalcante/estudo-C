/*
6. Escreva um algoritmo que cadastre os seguintes dados de clientes:
nome completo, RG, CPF e telefone. Armazene todos os dados em
uma ÚNICA LISTA. AO FINAL, SOMENTE AO FINAL, Seu
algoritmo deverá mostrar (um cliente por linha):
a) o nome completo do paciente,
b) o RG;
c) o CPF e;
d) o telefone do cliente.
Obs: o usuário deve fazer esse procedimento para quantos clientes quiser
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct reg {
    char nome[100];
    char rg[15];
    char cpf[15];
    char telefone[15];
    struct Cliente* prox;
} Cliente;

Cliente* criar(char nome[], char rg[], char cpf[], char telefone[]) {
    Cliente* novo = (Cliente*)malloc(sizeof(Cliente));
    strcpy(novo->nome, nome);
    strcpy(novo->rg, rg);
    strcpy(novo->cpf, cpf);
    strcpy(novo->telefone, telefone);
    novo->prox = NULL;
    return novo;
}

void inserir(Cliente** topo, Cliente* novo) {
    if (*topo == NULL) {
        *topo = novo;
    } else {
        Cliente* temp = *topo;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void mostrar(Cliente* topo) {
    Cliente* temp = topo;
    while (temp != NULL) {
        printf("Nome: %s, RG: %s, CPF: %s, Telefone: %s.", temp->nome, temp->rg, temp->cpf, temp->telefone);
        printf("\n");
        temp = temp->prox;
    }
}

int main() {
Cliente* lista = NULL;
    char nome[100], rg[15], cpf[15], telefone[20];
    char resp;

    do {
        printf("Digite o nome completo do cliente: ");
        fgets(nome, sizeof(nome), stdin);
        
        printf("Digite o RG do cliente: ");
        fgets(rg, sizeof(rg), stdin);
        

        printf("Digite o CPF do cliente: ");
        fgets(cpf, sizeof(cpf), stdin);

        printf("Digite o telefone do cliente: ");
        fgets(telefone, sizeof(telefone), stdin);

        Cliente* novo = criar(nome, rg, cpf, telefone);
        inserir(&lista, novo);

        printf("\nDeseja cadastrar outro cliente? (s/n): ");
        scanf(" %c", &resp);
        getchar();
    } while (resp == 's' || resp == 'S');

    printf("\nLista de Clientes Cadastrados:\n");
    printf("============================\n");
    mostrar(lista);

    Cliente* temp;
    while (lista != NULL) {
        temp = lista;
        lista = lista->prox;
        free(temp);
    }

    return 0;
}