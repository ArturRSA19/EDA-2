#include <stdio.h>
#include <stdlib.h>

#define Item int

typedef struct no{
    Item dado;
    struct no *esq, *dir;
}no;

void pre_ordem(no *raiz) { //Imprime todos os elementos da árvore em pré-ordem sem recursão
    if(raiz == NULL){
        return;
    }
    no **pilha = malloc(sizeof(no *)); // Aloca memória para a pilha
    int topo = 0;
    pilha[topo++] = raiz; 
    while (topo > 0) {
        no *aux = pilha[--topo];
        printf("%d ", aux->dado);
        if (aux->dir != NULL) pilha[topo++] = aux->dir;
        if (aux->esq != NULL) pilha[topo++] = aux->esq;
    }
    free(pilha); // Libera a memória alocada para a pilha
}
