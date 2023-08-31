#include <stdio.h>
#include <stdlib.h>

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

void counting_sort(int *v, int n, int c){
    int *aux = calloc(c+1, sizeof(int));
    for(int i = 0; i<n; i++){
        aux[v[i]]++;
    }
    int j = 0;
    for(int i = 0; i<=c; i++){
        while(aux[i]--){
            v[j++] = i;
        }
    }
}

int main(){

    int vetor[6] = {30, 45, 60, 10, 5, 92};
    counting_sort(vetor, 6, 92);
    for(int i = 0; i<6; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}