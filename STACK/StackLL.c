#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLL.h"

void initStack(Stack *list){
	list->top=NULL;
	list->count=0;
}

bool isEmpty(Stack list){
	 return(list.count==0);
}
bool isFull(Stack list){
	return(list.count==MAX);
}
void push(Stack *list,int item){
	if(isFull(*list)){
		printf("\nLIST IS FULL UNABLE TO PUSH\n");
	}else{
		DataPTR temp = malloc(sizeof(DATA)); 
		temp->next=list->top;
		temp->num=item;
		list->top=temp;
		list->count++;
	}
}
void pop(Stack *list){
	if(isEmpty(*list)){
		printf("\nList is Empty\n");
	}else{
		DataPTR temp = list->top;
		list->top=temp->next;
		free(temp);
		list->count--;
	}
}
int top(Stack list){
	return list.top->num;
}
void display(Stack list){
	Stack temp;
	initStack(&temp);
	while(list.count!=0 && (!isFull(temp))){
		push(&temp,top(list));
		pop(&list);
	}
	printf("\n-----Stack-----\n");
	while(temp.count!=0){
		printf("\n %d \n",top(temp));
		pop(&temp);
	}
}
void visualize(Stack list){
	printf("\n\t FROM TOP\n");
	DataPTR trav;
	for(trav=list.top; trav!=NULL; trav=trav->next){
		printf("\n%d\n",trav->num);
	}
}


