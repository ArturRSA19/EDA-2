#include <stdio.h>
#include <stdlib.h>

#define M (1 << 31)

int main() {
    char caractere, *mensagem = malloc(sizeof(char) * (unsigned int) M);
    unsigned int sequencia, menorSequencia = (unsigned int) M;

    while (scanf("%u %c", &sequencia, &caractere) != EOF) {
        mensagem[sequencia] = caractere;
        if (sequencia < menorSequencia)
            menorSequencia = sequencia;
    }

    while (mensagem[menorSequencia]) {
        printf("%c", mensagem[menorSequencia++]);
    }

    printf("\n");
    free(mensagem);
    return 0;
}
