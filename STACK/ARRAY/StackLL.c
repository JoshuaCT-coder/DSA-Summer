#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLL.h"

void initStack(Stack *list){
	list->top->next=NULL;
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
		DATA *NewElem = malloc(sizeof(DATA)); 
		list->top= NewElem;
		list->count
	}
}
void pop(Stack *list){
	if(isEmpty(*list)){
		printf("\nList is Empty\n");
	}else{
		list->count--;
	}
}
int top(Stack list){
	return list.data[list.count-1];
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
	printf("\n\tBOTTOM\n");
	int i;
	for(i=0; i< MAX;i++){
		printf("\n%d\n",list.data[i]);
	}
}


