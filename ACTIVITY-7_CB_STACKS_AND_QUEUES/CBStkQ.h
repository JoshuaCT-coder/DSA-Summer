#ifndef CBSTKQ_H
#define CBSTKQ_H
#define MAX 10
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
int allocSpace(VirtualHeap *vh);
// void insertItem(VirtualHeap *vh,Product item);
void deallocSpace(VirtualHeap* vh,int idx);
// void removeItem(VirtualHeap*vh,Product item);

bool isFullVH(VirtualHeap vh);
bool isEmptyVH(VirtualHeap vh,Stacklist s, Queue q);
void visualize(VirtualHeap vh);
Product newProduct(int prodID,String prodName,int prodQty,double prodPrice,Date prodExp);
Date newDate(int date,int month,int year);

//-------------------------STACK----------------------//
void initStk(Stacklist *s);
bool isEmptyStk(Stacklist s);
Product top(VirtualHeap vh, Stacklist s);
void push(VirtualHeap *vh, Stacklist *s,Product item);
void pop(VirtualHeap *vh, Stacklist *s);
void displayStk(VirtualHeap vh, Stacklist s);
void populateStk2(VirtualHeap *vh, Stacklist *s);
void populateStk(VirtualHeap *vh, Stacklist *s);
//-------------------------QUEUE----------------------//
void initQueue(Queue *q);
bool isEmptyQ(Queue q);
void enqueue(VirtualHeap *vh, Queue *q,Product item);
void dequeue(VirtualHeap*vh, Queue *q);
Product front(VirtualHeap vh, Queue q);
void populateQ(VirtualHeap *vh,Queue *q);
void populateQ2(VirtualHeap *vh,Queue *q);
void displayQ(VirtualHeap vh, Queue q);



#endif
