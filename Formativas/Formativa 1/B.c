#include <stdio.h>
#include <stdlib.h>

// Definição da struct celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Função para inserir no início da lista
void insere_inicio(celula *le, int x) {
    celula *nova = malloc(sizeof(celula)); // Aloca memória para a nova célula
    nova->dado = x; // Atribui o valor de x ao dado da nova célula
    nova->prox = le->prox; // A nova célula aponta para o próximo elemento da lista
    le->prox = nova; // O cabeçalho aponta para a nova célula
}

// Função para inserir antes de um elemento y
void insere_antes(celula *le, int x, int y){
    celula *nova = malloc(sizeof(celula));
    nova->dado = x;
    celula *aux = le->prox;
    celula *ant = le;
    while(aux != NULL){
        if(aux->dado == y){
            ant->prox = nova;
            nova->prox = aux;
            return;
        }
        ant = aux;
        aux = aux->prox;
    }
    ant->prox = nova;
    nova->prox = NULL;
}
