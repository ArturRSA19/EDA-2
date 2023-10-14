#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb; // tabela hash
    int M; // tamanho da tabela hash
    int N; // total de chaves presentes na tabela
} TH;

int hash(int chave, int M) {
    return chave % M;
}

void THinsere(TH *h, int ch) {
    int indice = hash(ch, h->M);

    // Verifica se a chave já existe na lista
    celula *atual = h->tb[indice].prox;
    while (atual != NULL) {
        if (atual->dado == ch) {
            return; // Chave já existe, não faz nada
        }
        atual = atual->prox;
    }

    // Insere a chave no início da lista encadeada
    celula *nova = malloc(sizeof(celula));
    nova->dado = ch;
    nova->prox = h->tb[indice].prox;
    h->tb[indice].prox = nova;
    h->N++;
}

int THremove(TH *h, int ch) {
    int indice = hash(ch, h->M);
    celula *anterior = &h->tb[indice];
    celula *atual = h->tb[indice].prox;

    while (atual != NULL) {
        if (atual->dado == ch) {
            anterior->prox = atual->prox;
            free(atual);
            h->N--;
            return 0; // Chave encontrada e removida com sucesso
        }
        anterior = atual;
        atual = atual->prox;
    }

    return -1; // Chave não encontrada
}

int THbusca(TH *h, int ch) {
    int indice = hash(ch, h->M);
    celula *atual = h->tb[indice].prox;

    while (atual != NULL) {
        if (atual->dado == ch) {
            return 1; // Chave encontrada
        }
        atual = atual->prox;
    }

    return 0; // Chave não encontrada
}
