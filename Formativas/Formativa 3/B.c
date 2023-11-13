#include<stdio.h>
#include<stdlib.h>
typedef struct no{ // no defining for tree
	int dado;
    struct no *esq, *dir;
}no;

struct stack {
	struct no* dado;
	struct stack* next;
};

void push(struct stack** top,struct no* n); //function declation
struct no* pop(struct stack** top);
int isEmpty(struct stack* top);

void em_ordem(no* raiz) //Inorder Traversing function
{ 
	struct no* temp = raiz;
	struct stack* s_temp = NULL;
	int flag = 1;
	while(flag) //Loop run untill temp is null and stack is empty
	{
		if(temp){
			push(&s_temp,temp);
			temp = temp->esq;
		}
		else{
			if(!isEmpty(s_temp)){
				temp = pop(&s_temp);
				printf("%d ",temp->dado);
				temp = temp->dir;
			}
			else
				flag = 0;
		}
	 } 
}
void push(struct stack** top,struct no* n) //push no in stack
{
	struct stack* new_n = (struct stack*)malloc(sizeof(struct stack));
	new_n->dado = n;
	new_n->next = (*top);
	(*top) = new_n;
}
int isEmpty(struct stack* top) // check if stack is empty
{
	if(top==NULL)
		return 1;
	else
		return 0;
}
struct no* pop(struct stack** top_n) // pop the no from stack
{
	struct no* item;
	struct stack* top;
	top = *top_n;
	item = top->dado;
	*top_n = top->next;
	free(top);
	return item;
}
struct no* create_no(int dado) // create a no for tree
{
	struct no* new_n = (struct no*)malloc(sizeof(struct no));
	new_n->dado = dado;
	new_n->esq = NULL;
	new_n->dir = NULL;
	return (new_n);
}