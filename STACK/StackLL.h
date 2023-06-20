#ifndef STACKARR_H
#define STACKARR_H

#define MAX 10    //We'll use MAX for the sake of having a limit for the ARRAY and the LINKED LIST

typedef struct node{
	int num;
	struct node * next;
}DATA,*DataPTR;

typedef struct{
	DATA *top;
	int count;
}Stack;

void initStack(Stack *list);
bool isEmpty(Stack list);
bool isFull(Stack list);
void push(Stack *list,int item);
void pop(Stack *list);
int top(Stack list);
void display(Stack list);
void visualize(Stack list);

#endif
