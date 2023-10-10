#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int x;
    struct celula *prox;
} celula;

int remove_depois(celula *p) {
    if (p->prox == NULL) {
        return -1;
    }

    else {
        p->prox = p->prox->prox;

        return 1;
    }
}

void remove_elemento(celula *le, int x) { 
    celula *no = (celula *)malloc(sizeof(celula));
    celula *ponteiro = (celula *)malloc(sizeof(celula));
    if (no == NULL) return;
    if (ponteiro == NULL) return;

    if (le->prox == NULL) {
        return;
    }
    if (le->prox->prox == NULL) {
        return;
    }

    no->prox = le->prox;
    ponteiro->prox = le->prox;

    if (no->prox->x == x) {
        le->prox = no->prox->prox;
        return;
    }

    no->prox = le->prox;
    ponteiro->prox = le->prox;

    while (no->prox->prox != NULL) {
        if (no->prox->prox->x == x) {
            no->prox = no->prox->prox;
            ponteiro->prox->prox = no->prox->prox;
            break;
        }
        no->prox = no->prox->prox;
        ponteiro->prox = ponteiro->prox->prox;
    }

    return;
}

void remove_todos_elementos(celula *le, int x) {
    celula *no = (celula *)malloc(sizeof(celula));
    celula *ponteiro = (celula *)malloc(sizeof(celula));
    if (no == NULL) return;
    if (ponteiro == NULL) return;

    if (le->prox == NULL) {
        return;
    }
    if (le->prox->prox == NULL) {
        return;
    }

    no->prox = le->prox;
    ponteiro->prox = le->prox;

    if (no->prox->x == x) {
        le->prox = no->prox->prox;
    }

    no->prox = le->prox;
    ponteiro->prox = le->prox;

    while (no->prox->prox != NULL) {
        if (no->prox->prox->x == x) {
            ponteiro->prox = ponteiro->prox->prox;
            no->prox->prox = ponteiro->prox->prox;
            //
            ponteiro->prox = no->prox;
            continue;
        }
        no->prox = ponteiro->prox->prox;
        ponteiro->prox = ponteiro->prox->prox;
    }

    return;
}