#include <stdio.h>

typedef int Item;

#define key(A) (A)
#define less(A, B) (key(A) < key(B))
#define exch(A, B) {Item t = A; A = B; B = t;}
#define cmpexch(A, B) {if(less(B, A)) exch(A, B);}

int separa(Item *v, int l, int r){
    Item c = v[r];
    int j = l;
    for(int k = l; k<r; k++){
        if(less(v[k], c)){
            exch(v[k], v[j]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

void quick_select(Item *v, int l, int r, int k){
    if(r<=l) return;
    int j = separa(v, l, r);
    if(j>k) quick_select(v, l, j-1, k);
    if(j<k) quick_select(v, j+1, r, k);
}

int main(void){
    Item vetor[6] = {30, 45, 60, 10, 5, 92};

    quick_select(vetor, 0, 5, 3);
    for(int i = 0; i<=5; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}