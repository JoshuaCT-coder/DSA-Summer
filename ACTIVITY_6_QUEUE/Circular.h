#ifndef  CIRCULAR_H
#define  CIRCULAR_H
#include <stdbool.h>

#define MAX 10
#define EMPTY 9999


typedef char String[30];

typedef struct{
int elems[MAX];
int front;
int rear;
}Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int item);
void dequeue(Queue *q);
int front(Queue q);
bool isEmpty(Queue q);
bool isFull(Queue q);
void visualize(Queue q);
void display(Queue q);

bool removeItem(Queue *q,int item); //first occurence
Queue removeEven(Queue *q);   	// removes all even and return all deleted item stored in Q;
int doubletheValue(Queue *q); 		//deletes the value in queue that is a multiple of the given value and return how many value have been changed
#endif
