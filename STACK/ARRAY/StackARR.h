#ifndef STACKARR_H
#define STACKARR_H

#define MAX 10

typedef int DATA;

typedef struct{
	DATA data[MAX];
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
