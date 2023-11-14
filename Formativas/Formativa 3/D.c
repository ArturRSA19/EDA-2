#include <stdio.h>
#include <stdlib.h>

#define Item int
#define MAX 10010

Item maxDepth;
char str[MAX];

Item maxValue(Item a, Item b) {
    Item max;
    if (a > b) 
        max = a;
    else 
        max = b;

    return max;
}

Item recFun(Item posL, Item depth) {
    Item posR, retVal;

    maxDepth = maxValue(maxDepth, depth);
    if (str[posL] == 'l') 
        return posL + 1;

    posR = recFun(posL + 1, depth + 1);
    retVal = recFun(posR, depth + 1);

    return retVal;
}

int main() {
    Item aux; // aux = casos de teste

    scanf("%d", &aux);
    fgetc(stdin);

    while (aux--) {
        fgets(str, MAX, stdin);

        maxDepth = 0;
        recFun(0, 0);

        printf("%d\n", maxDepth);
    }

    return 0;
}
