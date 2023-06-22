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
//-------------------------MANUAL SHIFTING-------------------//
bool removeItem(Queue *q,int item){							 //first occurence
	int tempf,count=MAX-1;
	
	while(q->elems[q->front]!=item && count!=0){
			tempf=front(*q);
			dequeue(q);
			enqueue(q, tempf);
			count--;
	}
		if(count==0){
			printf("\nElement not Found\n");
		}else{
			dequeue(q);
			printf("\nElement Found\n");
		}
}

//-------------------------TEMPORARY QUEUE-------------------//
/*bool removeItem(Queue *q, int item) {						 //first occurence
	int frontIndex = q->front;
	int rearIndex = q->rear;
	bool found = false;

	Queue tempQueue;
	initQueue(&tempQueue);

	while (frontIndex != EMPTY && !found) {
		if (q->elems[frontIndex] == item) {
			found = true;
			dequeue(q);  // Remove the item from the main queue
		} else {
			enqueue(&tempQueue, q->elems[frontIndex]);  // Enqueue the element into the temporary queue
			dequeue(q);  // Remove the element from the main queue
		}

		frontIndex = (frontIndex + 1) % MAX;  // Move to the next element in the main queue
	}

	// Restore the elements back to the main queue
	while (!isEmpty(tempQueue)) {
		enqueue(q, front(tempQueue));
		dequeue(&tempQueue);
	}

	return found;
}*/

Queue removeEven(Queue *q){
	Queue EvenQueue;
	initQueue(&EvenQueue);							// removes all even and return all deleted item stored in Q;
	int OrgRear;
	OrgRear= q->rear;

	while(q->front!=(OrgRear+1)%MAX){
		if(front(*q)%2==0){
			enqueue(&EvenQueue,front(*q));
			dequeue(q);
		}else{
			enqueue(q,front(*q));
			dequeue(q);
		}
	}
	return EvenQueue;
}  									
int doubletheValue(Queue *q,int item){						/*doubles the value in queue that is a multiple of the given value 
													and return how many value have been changed*/										
	int trav,ctr=0;
	trav= q->front;

	while(trav!=(q->rear+1)%MAX){
		if(q->elems[trav]%item==0){
			q->elems[trav]= q->elems[trav]*2;
			ctr++;
		}
		trav=(trav+1)%MAX;
	}			
	return ctr;								
}


