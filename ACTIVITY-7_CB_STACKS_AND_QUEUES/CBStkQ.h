#ifndef CBSTKQ_H
#define CBSTKQ_H
#define MAX 20
#include <stdbool.h>
typedef char String[20];
typedef char shortstring[5];
typedef struct{
	int date;
	int month;
	int year;
}Date;

typedef struct{
	int prodID;
	String prodName;
	int prodQty;
	double prodPrice;
	Date prodExp;
}Product;

typedef struct{
	Product items;
	int link;
}Stype;

typedef struct{
	Stype data[MAX];
	int avail;
}VirtualHeap;


typedef int Stacklist;

typedef struct{
	int front;
	int rear;
}Queue;

//------------------------VIRTUAL_HEAP-----------------//
void initVH(VirtualHeap *vh);
int allocateSpace(VirtualHeap *vh);
void insertItem(VirtualHeap *vh,Product item);
void deallocSpace(VirtualHeap* vh,int idx);
void removeItem(VirtualHeap*vh,Product item);
void populateStk(VirtualHeap *vh, Stacklist *s);
void populateQ(VirtualHeap* vh);
bool isFull(VirtualHeap vh);
bool isEmpty(VirtualHeap vh,Stacklist s, Queue q);
void visualize(VirtualHeap vh);
Product newProduct(int prodID,String prodName,int prodQty,double prodPrice,Date prodExp);
Date newDate(int date,int month,int year);

//-------------------------STACK----------------------//
void initStk(Stacklist *s);
Product top(VirtualHeap vh, Stacklist s);
void push(VirtualHeap *vh, Stacklist *s,Product item);
void pop(VirtualHeap *vh, Stacklist *s);
void displayStk(VirtualHeap vh, Stacklist s);

//-------------------------QUEUE----------------------//
void initQueue(Queue *q);
void enqueue(VirtualHeap *vh, Queue *q,Product item);
void dequeue(VirtualHeap *vh, Queue *q);
int front(VirtualHeap vh, Queue q);
void displayQueue(VirtualHeap vh, Queue q);



#endif
