#include <stdio.h>

#define MAXVAL 100000

int main() {
    int n, m, i, j, a, b;
    int melhor_trilha;
    long int esforco1, esforco2;
    long int min_esforco;

    min_esforco = MAXVAL;
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        esforco1 = 0;
        esforco2 = 0;
        scanf("%d %d", &m, &a);

        for (j = 1; j < m; j++) {
            scanf("%d", &b);

            if (a > b) {
                esforco1 += a - b; // final para o início
            } else {
                esforco2 += b - a; // início para o final
            }

            a = b;
        }

        if (esforco1 > esforco2) {
            esforco1 = esforco2;
        }

        if (esforco1 < min_esforco) {
            min_esforco = esforco1;
            melhor_trilha = i;
        }
    }

    printf("%d\n", melhor_trilha);

    return 0;
}