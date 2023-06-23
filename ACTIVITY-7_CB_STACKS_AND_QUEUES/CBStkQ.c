#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "CBStkQ.h"

/*typedef struct{
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

*/



//------------------------VIRTUAL_HEAP-----------------//
void initVH(VirtualHeap *vh){
	int i;
	vh->avail=MAX-1;
	for(i=vh->avail; i!=-1;i--){
		vh->data[i].items= newProduct(0,"",0,0.00,newDate(0,0,0));
		vh->data[i].link=i-1;
	}
}
bool isFullVH(VirtualHeap vh){
	return (vh.avail==-1);
}
bool isEmptyVH(VirtualHeap vh,Stacklist s, Queue q){
	return(vh.avail==MAX-1 && s==-1 && q.rear==-1);
}
int allocSpace(VirtualHeap *vh){
	int temp=-1;
	if(!isFull){
		temp=vh->avail;
		vh->avail=vh->data[vh->avail].link;
	}
	return temp;
}
//void insertItem(VirtualHeap *vh,Product item){}
void deallocSpace(VirtualHeap* vh,int idx){
	if(idx!= -1 &&idx<MAX){
		vh->data[idx].link=vh->avail;
		vh->avail= idx;
	}
}
//void removeItem(VirtualHeap*vh,Product item){}
void populateStk(VirtualHeap *vh, Stacklist *s){
	push(vh, s,newProduct(1,"Lotion",12,12.00,newDate(1,2,2002)));
}
//void populateQ();

Product newProduct(int prodID,String prodName,int prodQty,double prodPrice,Date prodExp){
	Product p;
	p.prodID=prodID;
	strcpy(p.prodName,prodName);
	p.prodPrice=prodPrice;
	p.prodExp= prodExp;
	return p;
}
Date newDate(int date,int month,int year){
	Date d;
	d.date=date;
	d.month=month;
	d.year =year;
	return d;
}

void visualize(VirtualHeap vh){
	int trav;
	printf("%6s | %5s\n","INDEX","NEXT");
	for(trav=0;trav<MAX;trav++){
		printf("%8d | %8d\n",trav,vh.data[trav].link);
	}
}

//-------------------------STACK----------------------//
void initStk(Stacklist *s){
	*s=-1;
}
//bool isFullStk(VirtualHeap vh,Stacklist s){}
bool isEmptyStk(VirtualHeap vh,Stacklist s){
	return(s==-1);
}
Product top(VirtualHeap vh, Stacklist s){
	Product temp;
	temp = vh.data[s].items;
	return temp;
}
void push(VirtualHeap *vh, Stacklist *s,Product item){
	{
		int idx= allocSpace(vh);
		if(idx!=-1){
			vh->data[idx].items=item;
			vh->data[idx].link=*s;
			*s=idx;
		}
	}
}
void pop(VirtualHeap *vh, Stacklist *s){
	int temp;
	*s=vh->data[*s].link;
	deallocSpace(vh,*s);
}
void displayStk(VirtualHeap vh, Stacklist s){
	int trav;
	printf("%6s | %5s\n","INDEX","NEXT");
	for(trav=s; trav!=-1;trav=vh.data[trav].link){
		
		printf("%8d | %8d\n",trav,vh.data[trav].link);
	}
}

////-------------------------QUEUE----------------------//
void initQueue(Queue *q){
	
}
//bool isFull(VirtualHeap vh);
//bool isEmpty(VirtualHeap vh);
//void enqueue(VirtualHeap *vh, Queue *q,Product item);
//void dequeue(VirtualHeap *vh, Queue *q);
//int front(VirtualHeap vh, Queue q);
//void displayQueue(VirtualHeap vh, Queue q);

