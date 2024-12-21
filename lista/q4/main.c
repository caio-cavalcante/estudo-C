/*
4. Escreva um algoritmo que leia o valor base de indenização de um plano
de saúde, a idade do paciente indenizado e o nome completo do
paciente. Calcule o reajuste de indenização sobre o valor base de acordo
com a idade do paciente. Seu algoritmo deve aumentar o valor da
indenização em:
a) 30% se o paciente tiver até 12 anos;
b) 10% se o paciente tiver idade entre 13 e 49 anos (inclusive);
c) 15% se o paciente tiver idade entre 50 e 65 anos (inclusive) e;
d) 35% se o paciente tiver idade acima de 65 anos.

AO FINAL, SOMENTE AO FINAL, Seu programe deve mostrar
(um paciente por linha): o nome do paciente, a idade do paciente e
qual foi o valor da indenização reajustado. Obs: o usuário deve fazer
esse procedimento para quantos clientes ELE QUISER. Dica: você
PODE usar três vetores: um para os nomes, outro para as
idades e outro para as indenizações reajustadas.
*/

#include <stdio.h>

int reajuste (int valorBase, int idade) {
    if (idade <= 12) {
        return valorBase * 1.30;
    } else if (idade >= 13 && idade <= 49) {
        return valorBase * 1.10;
    } else if (idade >= 50 && idade <= 65) {
        return valorBase * 1.15;
    } else {
        return valorBase * 1.35;
    }
}

int main() {
    int tam, valorBase, idade;

    printf("Informe o valor base de indenização: ");
    scanf("%d", &valorBase);

    printf("Informe a quantidade de clientes: ");
    scanf("%d", &tam);
    
    char nomes[tam][100];
    int idades[tam];
    int reajustes[tam];
    
    for (int i = 0; i < tam; i++) {
        printf("\nCliente %d:\n", i+1);
        printf("Nome: ");
        scanf("%s", nomes[i]);
        
        printf("Idade: ");
        scanf("%d", &idade);
        idades[i] = idade;

        reajustes[i] = reajuste(valorBase, idade);
    }

    for (int i = 0; i < tam; i++) {
        printf("\nNome: %s; Idade: %d; Valor da indenização reajustado: %d.", nomes[i], idades[i], reajustes[i]);
    }

    return 0;
}