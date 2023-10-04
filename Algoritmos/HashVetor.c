#include <stdio.h>
#include <stdlib.h>

#define M 31 //Tamanho da tabela

void inicioTabela(int tabela[M]){
    for(int i = 0; i < M; i++){
        tabela[i] = 0;
    }
}

int hash(int chave){
    return chave%M; //resultado = chave mod(M)
}

void inserir(int t[], int valor){
    int id = hash(valor); //Retorna a posição da chave
    while(t[id] != 0){ //Já existe alguém na posição
        id = hash(id+1); //Tratamento de colisão
    }
    t[id] = valor;
}

int busca(int t[], int chave){
    int id = hash(chave);
    while(t[id] != 0){
        if(t[id] == chave){
            return t[id]; //Existe no vetor
        } else {
            id = hash(id+1);
        }
    }
    return 0; //Não existe no vetor
}

void imprimir(int t[]){
    for(int i = 0; i < M; i++){
        printf("Índice: %d || Valor: %d\n", i, t[i]);
    }
    printf("\n");
}

int main(){

    int tabela[M];
    int valor, chave, aux;
    inicioTabela(tabela);

    int op;

    do{
        printf("\n");
        printf("Escolha uma opcao:\n");
        printf("-----------------------------\n");
        printf("1 - Inserir chave\n");
        printf("2 - Buscar chave\n");
        printf("3 - Imprimir tabela\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        switch(op){
            case 1:
                printf("Digite o valor a ser inserido: ");
                scanf("%d", &valor);
                inserir(tabela, valor);
                break;
            case 2:
                printf("Digite a chave a ser buscada: ");
                scanf("%d", &chave);
                aux = busca(tabela, chave);
                if(aux != 0){
                    printf("Chave encontrada!\n");
                    printf("Valor: %d\n", aux);
                    printf("Índice: %d\n", hash(aux));
                } else {
                    printf("Chave não encontrada!\n");
                }
                break;
            case 3:
                imprimir(tabela);
                break;
            case 0:
                break;
            default:    
                printf("Opção inválida!\n");
                break;
        }

    }while(op != 0);

    return 0;
}