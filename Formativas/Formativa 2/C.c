#include <stdio.h>

int achaMaj(int *cores, int tamanho) {
    int candidato = -1, aux = 0; //aux é a quantidade de vezes que o candidato aparece

    for (int i = 0; i < tamanho; i++) {
        if (aux == 0) {
            candidato = cores[i];
            aux = 1;
        } else if (candidato == cores[i]) {
            aux++;
        } else {
            aux--;
        }
    }

    return candidato;
}

int main() {
    int N; // qtd de cores

    while (1) { 
        scanf("%d", &N);

        if (N == 0) {
            break;
        }

        int cores[N];
        
        for (int i = 0; i < N; ++i) {
            scanf("%d", &cores[i]);
        }

        int majoritario = achaMaj(cores, N);
        printf("%d\n", majoritario);
    }

    return 0;
}
