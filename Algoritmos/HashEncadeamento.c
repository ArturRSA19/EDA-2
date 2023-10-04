#include <stdio.h>
#include <stdlib.h>

#define M 31 //Tamanho da tabela

typedef struct no{
    int chave;
    struct no *prox;
}No;

typedef struct{
    No *inicio;
    int tamanho;
}Lista;

void inicializaLista(Lista *l){
    l->inicio = NULL;
    l->tamanho = 0;
}

void inserirNaLista(Lista *l, int valor){
    No *novo = (No*)malloc(sizeof(No));
    
    if(novo){
        novo->chave = valor;
        novo->prox = l->inicio;
        l->inicio = novo;
        l->tamanho++;
    } else {
        printf("Erro de alocação!\n");
    }
}

int buscarNaLista(Lista *l, int valor){
    No *aux = l->inicio;
    while(aux && aux->chave != valor){
        aux = aux->prox;
    }

    if(aux){
        return aux->chave;
    } else {
        return 0;
    }
}

void imprimeLista(Lista *l){
    No *aux = l->inicio;
    printf("Tamanho da lista: %d || Valores: ", l->tamanho);
    while(aux){ //Enquanto não for NULL
        printf("%d", aux->chave);
        if(aux->prox){
            printf(" -> ");
        }
        aux = aux->prox;
    }
    printf("\n");
}

void inicioTabela(Lista tabela[]){
    for(int i = 0; i < M; i++){
        inicializaLista(&tabela[i]);
    }
}

int hash(int chave){
    return chave%M; //resultado = chave mod(M)
}

void inserir(Lista t[], int valor){
    int id = hash(valor); //Retorna a posição da chave
    inserirNaLista(&t[id], valor);
}

int busca(Lista t[], int chave){
    int id = hash(chave);
    return buscarNaLista(&t[id], chave);
}

void imprimir(Lista t[]){
    for(int i = 0; i < M; i++){
        printf("Índice: %2d || ", i);
        imprimeLista(&t[i]);
        printf ("\n");
    }
    printf("\n");
}

int main(){

    Lista tabela[M];
    int valor, chave, aux;
    inicioTabela(tabela);

    int op;

    do{
        printf("\n");
        printf("Escolha uma opcao:\n");
        printf("-----------------------------\n");
        printf("1 - Inserir chave\n");
        printf("2 - Buscar chave\n");
        printf("3 - Imprimir tabela\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        printf("\n");
        switch(op){
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(tabela, valor);
                break;
            case 2:
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &chave);
                aux = busca(tabela, chave);
                if(aux != 0){
                    printf("Chave encontrada!\n");
                    printf("Valor: %d\n", aux);
                    printf("Índice: %d\n", hash(aux));
                } else {
                    printf("Chave não encontrada!\n");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            case 0:
                break;
            default:    
                printf("Opção inválida!\n");
                break;
        }

    }while(op != 0);

    return 0;
}