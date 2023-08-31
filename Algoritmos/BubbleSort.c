#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

void bubble_sort(Item *v, int l, int r){
    for(int i = l; i<r; i++){
        for(int j = l; j<r; j++){
            cmpexch(v[j], v[j+1]);
        }
    }
}

int main(void){
    Item vetor[6] = {30, 45, 60, 10, 5, 92};

    bubble_sort(vetor, 0, 5);
    for(int i = 0; i<=5; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}