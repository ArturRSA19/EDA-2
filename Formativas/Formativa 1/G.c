#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Stack{
    char hist[101][101]; // histórico de strings
    int x;
} Stack;

void push(Stack *pilha, char *str) {
    strcpy(pilha->hist[++pilha->x], str);
}

char *pop(Stack *pilha) {
    if (pilha->x < 0) {
        return "NULL";
    }
    return pilha->hist[pilha->x--];
}

int main() {
    Stack pilha;
    pilha.x = -1;

    char aux[101]; // auxiliar para ler a string
    char str[101]; // string a ser inserida
    while (scanf("%s", aux) != EOF) {
        if (strcmp(aux, "inserir") == 0) {
            getchar();  
            fgets(str, 101, stdin); 
            str[strlen(str) - 1] = '\0';  
            push(&pilha, str);
        } else if (strcmp(aux, "desfazer") == 0) {
            printf("%s\n", pop(&pilha));
        }
    }
    return 0;
}