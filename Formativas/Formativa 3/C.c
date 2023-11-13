#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 1000

typedef struct no{
  int dado;
  struct no *esq, *dir;
}no;

struct Stack{
  int size;
  int top;
  struct no **array;
};

struct no *newno (int dado){
  struct no *no = (struct no *) malloc (sizeof (struct no));
  no->dado = dado;
  no->esq = no->dir = NULL;
  return no;
}

struct Stack *createStack (int size){
  struct Stack *stack = (struct Stack *) malloc (sizeof (struct Stack));
  stack->size = size;
  stack->top = -1;
  stack->array =
    (struct no **) malloc (stack->size * sizeof (struct no *));
  return stack;
}

int isFull (struct Stack *stack){
  return stack->top - 1 == stack->size;
}

int isEmpty (struct Stack *stack){
  return stack->top == -1;
}

void push (struct Stack *stack, struct no *no){
  if (isFull (stack))
    return;
  stack->array[++stack->top] = no;
}

struct no *pop (struct Stack *stack){
  if (isEmpty (stack))
    return NULL;
  return stack->array[stack->top--];
}

struct no *peek (struct Stack *stack){
  if (isEmpty (stack))
    return NULL;
  return stack->array[stack->top];
}

void pos_ordem (no *raiz){
  if (raiz == NULL)
    return;

  struct Stack *stack = createStack (MAX_SIZE);
  do{
    while (raiz){

	  if (raiz->dir)
	    push (stack, raiz->dir);
	  push (stack, raiz);

	  raiz = raiz->esq;
	}

    raiz = pop (stack);

    if (raiz->dir && peek (stack) == raiz->dir){
        pop (stack);
        push (stack, raiz);
        raiz = raiz->dir;
    } else {
	  printf ("%d ", raiz->dado);
	  raiz = NULL;
	}
    }while (!isEmpty (stack));
}

int main (){

  no *raiz = NULL;
  raiz = newNode (10);
  raiz->esq = newNode (20);
  raiz->dir = newNode (30);
  raiz->esq->esq = newNode (40);
  raiz->esq->dir = newNode (50);
  raiz->dir->esq = newNode (60);
  raiz->dir->dir = newNode (70);
  printf ("Pós ordem: \n");
  printf ("[");
  postorder(raiz);
  printf ("]");

  return 0;
}