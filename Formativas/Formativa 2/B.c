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

void inicializaTabela(TH *h, int tamanho) {
    h->tb = (int *)malloc(tamanho * sizeof(int));
    h->M = tamanho;
    h->N = 0;
    for (int i = 0; i < h->M; ++i) {
        h->tb[i] = -1; // Inicializa todas as posições com -1, indicando vazio.
    }
}

void THinsere(TH *h, int ch) {
    int posicao = hash(ch, h->M);
    int inicial = posicao;
    while (h->tb[posicao] != -1) {
        posicao = hash((posicao + 1), h->M); // Sondagem linear para encontrar a próxima posição vazia.
        if (posicao == inicial) {
            // A tabela está completamente cheia, você pode decidir como lidar com esse caso.
            // Por exemplo, pode redimensionar a tabela aqui, mas essa lógica não está incluída neste código.
            return;
        }
    }

    h->tb[posicao] = ch;
    h->N++;
}

int THremove(TH *h, int ch) {
    int posicao = hash(ch, h->M);
    int inicial = posicao;
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
        if (posicao == inicial) {
            break;
        }
    }

    return -1; // Chave não encontrada na tabela.
}

int THbusca(TH *h, int ch) {
    int posicao = hash(ch, h->M);
    int inicial = posicao;
    while (h->tb[posicao] != -1) {
        if (h->tb[posicao] == ch) {
            return 1; // Chave encontrada na tabela.
        }
        posicao = hash((posicao + 1), h->M); // Sondagem linear para procurar a chave.
        if (posicao == inicial) {
            break;
        }
    }
    return 0; // Chave não encontrada na tabela.
}

void liberarTabela(TH *h) {
    free(h->tb);
    h->tb = NULL;
    h->M = 0;
    h->N = 0;
}

int main() {
    TH tabela;
    inicializaTabela(&tabela, 10); // Tamanho inicial da tabela é 10

    // Exemplo de uso
    THinsere(&tabela, 42);
    THinsere(&tabela, 18);
    THinsere(&tabela, 56);
    
    int chaveBusca = 18;
    if (THbusca(&tabela, chaveBusca)) {
        printf("Chave %d encontrada na tabela.\n", chaveBusca);
    } else {
        printf("Chave %d não encontrada na tabela.\n", chaveBusca);
    }

    THremove(&tabela, 18);
    
    chaveBusca = 18;
    if (THbusca(&tabela, chaveBusca)) {
        printf("Chave %d encontrada na tabela.\n", chaveBusca);
    } else {
        printf("Chave %d não encontrada na tabela.\n", chaveBusca);
    }

    liberarTabela(&tabela);

    return 0;
}
