#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

void initQueue(Queue *q){
	q->front=7;
	q->rear=q->front-1;
	int i;
	for(i=0;i<MAX;i++){
		q->elems[i]=EMPTY;
	}
}
void enqueue(Queue *q, int item){
	if(!isFull(*q)){
		q->rear = (q->rear +1)%MAX;
		q->elems[q->rear]=item;
	}
}
void dequeue(Queue *q){
	if(!isEmpty(*q)){
		q->elems[q->front]=EMPTY;
		q->front = (q->front+1)%MAX;
	}
}
int front (Queue q){
	return q.elems[q.front];
}
bool isEmpty(Queue q){
	return(q.rear+1)%MAX==q.front;
}
bool isFull(Queue q)
{
	return((q.rear+2)%MAX==q.front);
}

void visualize(Queue q)
{
	int i;
	printf("%5s | %5s | %s\n","INDEX","VALUE", "POSITION");
	printf("------------------------\n");
	for(i=0;i<MAX;i++){
		printf("%5d | ",i);
		if(q.elems[i]!=EMPTY){
			printf("%5d | ",q.elems[i]);
	}else{
		printf("%5s | "," ");
	}
			if(i==q.front){
				printf("FRONT");
			} 
			if(i==q.rear){
				printf("REAR");
			}
				printf("\n");		
		}
	printf("------------------------\n");
	}

void display(Queue q){
	printf("MyQUEUE\n");
	while(!isEmpty(q)){
		printf("%d |",front(q));
		dequeue(&q);
	}
}

bool removeItem(Queue *q,int item){							 //first occurence
	int trav,tempf;
	for(trav=q->front;trav!=(q->rear+1)% MAX && q->elems[trav]!= item;trav=(trav+1)%MAX){}
		if(trav!=(q->rear+1)%MAX){
	}else{
		printf("\nNo element Found!\n");
	}	
	
}
Queue removeEven(Queue *q);   	// removes all even and return all deleted item stored in Q;
int doubletheValue(Queue *q);		//deletes the value in queue that is a multiple of the given value and return how many value have been changed


