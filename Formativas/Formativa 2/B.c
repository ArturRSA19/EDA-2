#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *tb; // tabela hash
    int M;  // tamanho da tabela hash
    int N;  // total de chaves presentes na tabela
} TH;

int hash(int ch, int M) {
    return ch % M;
} 

int aumentaTamanho(int M) {
    int novoTamanho = 2 * M + 1;
    while (1) {
        int primo = 1;
        for (int i = 2; i * i <= novoTamanho; ++i) {
            if (novoTamanho % i == 0) {
                primo = 0;
                break;
            }
        }
        if (primo) {
            return novoTamanho;
        }
        novoTamanho += 2;
    }
}

void inicializaTabela(TH *h, int tamanho) {
    h->tb = (int *)malloc(tamanho * sizeof(int));
    h->M = tamanho;
    h->N = 0;
    for (int i = 0; i < h->M; ++i) {
        h->tb[i] = -1; // Inicializa todas as posições com -1, indicando vazio.
    }
}

void redimensionaTabela(TH *h) {
    int novoTamanho = aumentaTamanho(h->M);
    int *novaTabela = (int *)malloc(novoTamanho * sizeof(int));
    for (int i = 0; i < novoTamanho; ++i) {
        novaTabela[i] = -1; // Inicializa todas as posições com -1, indicando vazio.
    }

    for (int i = 0; i < h->M; ++i) {
        if (h->tb[i] != -1) {
            int posicao = hash(h->tb[i], novoTamanho);
            while (novaTabela[posicao] != -1) {
                posicao = hash((posicao + 1), novoTamanho);
            }
            novaTabela[posicao] = h->tb[i];
        }
    }

    free(h->tb);
    h->tb = novaTabela;
    h->M = novoTamanho;
}

void THinsere(TH *h, int ch) {
    if (h->N > h->M / 2) {
        redimensionaTabela(h);
    }

    int posicao = hash(ch, h->M);
    while (h->tb[posicao] != -1) {
        posicao = hash((posicao + 1), h->M); // Sondagem linear para encontrar a próxima posição vazia.
    }

    h->tb[posicao] = ch;
    h->N++;
}

int THremove(TH *h, int ch) {
    int posicao = hash(ch, h->M);
    while (h->tb[posicao] != -1) {
        if (h->tb[posicao] == ch) {
            h->tb[posicao] = -1; // Marca a posição como vazia.
            h->N--;

            // Reinsere as chaves seguintes se necessário.
            posicao = hash((posicao + 1), h->M);
            while (h->tb[posicao] != -1) {
                int chaveAtual = h->tb[posicao];
                h->tb[posicao] = -1;
                h->N--;
                THinsere(h, chaveAtual);
                posicao = hash((posicao + 1), h->M);
            }

            return 0; // Chave encontrada e removida.
        }
        posicao = hash((posicao + 1), h->M); // Sondagem linear para procurar a chave.
    }

    return -1; // Chave não encontrada na tabela.
}

int THbusca(TH *h, int ch) {
    int posicao = hash(ch, h->M);
    while (h->tb[posicao] != -1) {
        if (h->tb[posicao] == ch) {
            return 1; // Chave encontrada na tabela.
        }
        posicao = hash((posicao + 1), h->M); // Sondagem linear para procurar a chave.
    }
    return 0; // Chave não encontrada na tabela.
}

int main() {
    // Exemplo de uso das funções:

    TH tabela;
    inicializaTabela(&tabela, 10); // Inicializa a tabela com tamanho 10.

    THinsere(&tabela, 5);
    THinsere(&tabela, 15);
    THinsere(&tabela, 25);
    THinsere(&tabela, 35);

    printf("Busca 15: %d\n", THbusca(&tabela, 15)); // Deve imprimir 1 (verdadeiro).
    printf("Busca 20: %d\n", THbusca(&tabela, 20)); // Deve imprimir 0 (falso).

    THremove(&tabela, 15);

    printf("Busca 15 após remoção: %d\n", THbusca(&tabela, 15)); // Deve imprimir 0 (falso).

    free(tabela.tb); // Libera a memória alocada para a tabela.

    return 0;
}
