#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct no{
    Item valor;
    struct no *prox;
}No;

typedef struct{
    No *inicio;
    Item tamanho;
}Lista;

void inserirNoInicio(Lista *lista, Item valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista->inicio;
    lista->inicio = novo;
    lista->tamanho++;

}

void inserirNoFinal(Lista *lista, Item valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;

    if(lista->inicio == NULL){ //Caso de lista iniciando vazia
        lista->inicio = novo;
    } else {                  //Caso de lista com pelo menos um elemento
        No *atual = lista->inicio;
        while(atual->prox != NULL){
            atual = atual->prox;
        }
        atual->prox = novo;
    }
    lista->tamanho++;
}

void imprimirLista(Lista *lista){
    No *atual = lista->inicio;
    printf("Tamanho da lista: %d\n", lista->tamanho);
    while(atual != NULL){
        printf("%d", atual->valor);
        if(atual->prox != NULL){
            printf(" -> ");
        }
        atual = atual->prox;
    }
    printf(" -> NULL\n");
}

int main(){
    Lista lista;
    lista.inicio = NULL;
    lista.tamanho = 0;

    int opcao, valor;

    do{
        printf("\n");
        printf("Escolha uma opcao:\n");
        printf("-----------------------------\n");
        printf("1 - Inserir no inicio\n");
        printf("2 - Inserir no final\n");
        printf("3 - Imprimir lista\n");
        printf("0 - Sair\n");
        scanf("%d", &opcao);
        switch(opcao){
            case 1:
                printf("Digite o valor a ser inserido no início da lista: ");
                scanf("%d", &valor);
                inserirNoInicio(&lista, valor);
                break;
            case 2:
                printf("Digite um valor para ser inserido no final da lista:");
                scanf("%d", &valor);
                inserirNoFinal(&lista, valor);
            case 3:
                imprimirLista(&lista);
                break;
            case 0:
                break;
            default:
                printf("Opcao invalida\n");
        }
    }while(opcao != 0);
    return 0;
}