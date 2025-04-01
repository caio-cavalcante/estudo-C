#include <stdio.h>
#include <stdlib.h>

/*
typedef facilita o struct ao dar um nome no final
struct node é um espaço reservado que guarda informações
também possui um ponteiro para estruturar e apontar para o próximo elemento
o tipo dele é node para apontar para o próximo node
*/ 
typedef struct node {
    int dado;
    struct node * prox;
} celula;

/*
para inserir um elemento, podemos decidir entre o primeiro ou o ultimo
como a lista está vazia, primeiro criamos um nó, já é alocado
e retorna um ponteiro para esse nó
é necessário o tamanho exato, mas malloc retorna void, por isso o cast (celula *)
*/
celula * criarNo() {
    celula * nova = (celula *) malloc(sizeof(celula));
    return nova;
}

/*
para inserir no inicio, precisa da lista a ser inserida e o dado também
após inserir, retorna a lista, por isso o tipo é celula *
primeiro cria o no vazia, só a forma
o * nova vai apontar a área e indicar o valor
por isso o campo dado que está na forma apontada por nova vai receber um valor
conferimos se a lista está vazia, para fazer a mesma coisa com o prox
ele vai apontar para o próximo elemento, ou NULL
caso não esteja vazia, precisamos fazer uma troca:
o campo prox vai apontar para onde a lista apontava
e a lista, que não aponta mais, vai receber a nova celula
*/
celula * inserirInicio(celula * lista, int valor) {
    celula * nova = criarNo();
    nova->dado = valor;
    
    if(lista == NULL) {
        lista = nova;
        nova->prox = NULL;
    } else {
        nova->prox = lista;
        lista = nova;
    }

    return lista;
}

/*
vai receber uma lista de celulas e incluir o valor desejado no fim da lista
normalmente criamos um novo nó, atribuímos o valor
caso a lista esteja vazia, ela recebe o novo elemento
mas caso não esteja, é necessário percorrer toda ela e encontrar quem aponta para NULL
para isso, usamos um auxiliar, assim como no método imprimir
enquanto o campo próximo de auxiliar não encontrar NULL, vai para o seguinte
quando encontrar NULL, segue para associar o campo próximo de nova para NULL
e realiza a troca do campo próximo de auxiliar para nova
*/
celula * inserirFinal(celula * lista, int valor) {
    celula * nova = criarNo();
    nova->dado = valor;

    if (lista == NULL) {
        nova->prox = NULL;
        lista = nova;
    } else {
        celula * aux = lista;
        
        while (aux->prox != NULL) {
            aux = aux->prox;
        }

        nova->prox = NULL;
        aux->prox = nova;
    }
    return lista;
}

/*
vamos percorrer a lista enquanto houver itens
não podemos mudar a posição do ponteiro lista
vamos usar um auxiliar para apontar onde a lista aponta
para incrementar uma celula, vamos fazer o ponteiro receber o mesmo valor que o prox
*/
void imprimirIterativo(celula * lista) {
    celula * aux = lista;

    while(aux != NULL) {
        printf("%d ", aux->dado);
        aux = aux->prox;
    }

/* o loop for funciona semelhante ao while, apenas locais diferentes para elementos
    for (aux; aux != NULL; aux = aux -> prox) {
        printf("%d ", aux->dado);
    }
*/
}

/*
impressão recursiva irá imprimir e repetir enquanto o campo prox não apontar para NULL
*/
void imprimirRecursivo(celula * lista) {
    if (lista != NULL) {
        printf("%d ", lista->dado);
        imprimirRecursivo(lista->prox);
    }
}

/*
a busca consiste em usar um ponteiro auxiliar para iteração
ele vai percorrer a lista, sem que essa perca sua referência
pode ser feita de forma recursiva, onde a função retorna ela mesma
até que o campo de conteúdo aponte para o mesmo valor desejado
*/
celula * buscar(celula * lista, int valor) {
    celula * aux = lista;

    while (aux != NULL && aux->dado != valor) {
        aux = aux->prox;
    }

    return aux;
}

/*
vamos percorrer a lista procurando o valor a ser removido
caso o valor já não esteja na lista, retorna NULL
se o primeiro valor já for o desejado, lixo assume lista temporariamente
então, lista passa a apontar para o próximo elemento, que está com lixo
senão, vamos usar aux para percorrer a lista
enquanto o campo próximo não for vazio e o campo dado não seja igual a valor
depois de usarmos &&, vamos tratar cada condição
caso a lista ainda não esteja apontando para vazio, fazemos a troca
lixo vai receber o nó desejado e auxiliar vai passar a apontar para o próximo desse nó
*/
celula * remover(celula * lista, int valor) {
    celula * aux = lista, * lixo = NULL;

    if (lista != NULL && lista->dado == valor) {
        lixo = lista;
        lista = lista->prox;
        free(lixo);
        return lista;
    }

    while (aux != NULL && aux->prox != NULL && aux->prox->dado != valor) {
        aux = aux->prox;
    }

    if (aux != NULL && aux->prox != NULL) {
        lixo = aux->prox;
        aux->prox = lixo->prox;
        free(lixo);
    }

    return lista;
}

/*
iniciamos a lista de tipo estruturado como vazia
*/
int main(int argc, char *argv[]) {
    celula *lista = NULL;
    int resp, valor;

    do {
        printf("\nMenu:");
        printf("\n1 - Inserir valor no início");
        printf("\n2 - Inserir valor no final");
        printf("\n3 - Imprimir lista iterativamente");
        printf("\n4 - Imprimir lista recursivamente");
        printf("\n5 - Buscar valor na lista");
        printf("\n6 - Remover valor na lista");
        printf("\n9 - Sair");
        printf("\nO que deseja fazer? ");
        scanf("%d", &resp);

        switch (resp) {
        case 1:
            printf("Qual o valor a inserir? ");
            scanf("%d", &valor);

            lista = inserirInicio(lista, valor);
            break;
        case 2:
            printf("Qual o valor a inserir? ");
            scanf("%d", &valor);

            lista = inserirFinal(lista, valor);
            break;
        case 3:
            imprimirIterativo(lista);
            printf("\n");
            break; 
        case 4:
            imprimirRecursivo(lista);
            printf("\n");
            break;
        case 5:
            printf("Qual valor deseja buscar? ");
            scanf("%d", &valor);

            if (buscar(lista, valor) == NULL) {
                printf("%d não está na lista.", valor);
            } else {
                printf("%d está na lista!", valor);
            } 
            printf("\n");
            break;
        case 6:
            printf("Qual valor deseja remover? ");
            scanf("%d", &valor);

            remover(lista, valor);
            break;
        case 9:
            printf("Volte sempre!");
            break;     
        default:
            printf("Selecione uma opção válida.");
            printf("\n");
            break;
        }
    } while(resp != 9);
    
    return 0;
}