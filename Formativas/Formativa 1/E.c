#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int x;
    struct celula *prox;
} celula;

void mescla_listas (celula *l1, celula *l2, celula *l3){
    l1 = l1->prox; // Pula o cabeçalho
    l2 = l2->prox; // Pula o cabeçalho

    while(l1 != NULL && l2 != NULL){ // Enquanto l1 e l2 não forem nulos
        if(l1->x < l2->x){ // Se o elemento de l1 for menor que o de l2
            l3->prox = l1; // l3 recebe o elemento de l1
            l1 = l1->prox; // l1 anda
        } else { // Se o elemento de l2 for menor que o de l1
            l3->prox = l2; // l3 recebe o elemento de l2
            l2 = l2->prox; // l2 anda
        }
        l3 = l3->prox; // l3 anda
    }

    if(l1 != NULL){ // Se l1 não for nulo
        l3->prox = l1; // l3 recebe l1
    }

    if(l2 != NULL){ // Se l2 não for nulo
        l3->prox = l2; // l3 recebe l2
    }
}