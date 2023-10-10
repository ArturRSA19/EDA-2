#include <stdio.h>
#include <stdio.h>

typedef struct celula {
    int x;
    struct celula *prox;
} celula;

// Uma função que procura pela primeira ocorrência do elemento x na lista encadeada e devolve um ponteiro para a célula que o contém.

celula *busca(celula *le, int x) {
    celula *p = le->prox;      

    while (p != NULL && p->x != x) {
        p = p->prox;
    }

    return p;
}

// Função recursiva

celula *busca_rec(celula *le, int x) {
    if (le->prox == NULL) {
        return NULL;
    }

    if (le->prox->x == x) {
        return le->prox;
    }

    return busca_rec(le->prox, x);
}