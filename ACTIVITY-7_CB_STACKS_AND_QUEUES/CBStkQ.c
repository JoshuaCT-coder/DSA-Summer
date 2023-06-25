#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "CBStkQ.h"

shortstring Dates[13]={"","Jan","Feb","Mar","Apr","May","June","July","Aug","Oct","Nov","Dec"};
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
	return(vh.avail==-1);
}
bool isEmptyVH(VirtualHeap vh,Stacklist s, Queue q){
	return(vh.avail==MAX-1 && s==-1 && q.rear==-1);
}
int allocSpace(VirtualHeap *vh){
	int temp=-1;
	if(!isFullVH(*vh)){
		temp=vh->avail;
		vh->avail=vh->data[vh->avail].link;
		printf("\nSpace Successful Allocated\n");
	}
	if(temp==-1){
		printf("\nStorage is FULL Space Allocation Failed\n");
	}
	return temp;
}
//void insertItem(VirtualHeap *vh,Product item){}
void deallocSpace(VirtualHeap* vh,int idx){
	if(idx!= -1 &&idx<MAX){
		vh->data[idx].items=newProduct(0,"",0,0.00,newDate(0,0,0));
		vh->data[idx].link=vh->avail;
		vh->avail= idx;
	}
}
//void removeItem(VirtualHeap*vh,Product item){}

Product newProduct(int prodID,String prodName,int prodQty,double prodPrice,Date prodExp){
	Product p;
	p.prodID=prodID;
	strcpy(p.prodName,prodName);
	p.prodQty=prodQty;
	p.prodPrice=prodPrice;
	p.prodExp= prodExp;
	return p;
}
Date newDate(int date,int month,int year){
	Date d;
	d.date=date;
	d.month=month;
	d.year=year;
	return d;
}

void visualize(VirtualHeap vh){
	int trav;
	Product currentProd; 
	printf("\n%6s | %5s | %-12s | %10s | %6s | %-12s | %-5s\n","INDEX","ID","PRODUCT NAME","QUANTITY","PRICE", "DATE","NEXT"); 
	for(trav=0;trav<MAX;trav++){
		currentProd= vh.data[trav].items;
		printf("%6d | ",trav);
		if(vh.data[trav].items.prodID!=0){
			printf("%5d | %-12s | %-10d | %6.2f | %4s %2d %4d | ",currentProd.prodID,
													currentProd.prodName,
													currentProd.prodQty,
													currentProd.prodPrice,
													Dates[currentProd.prodExp.month],
													currentProd.prodExp.date,
													currentProd.prodExp.year);
		}else{
			printf("%-60s","EMPTY");
		}
		printf("%-5d\n",vh.data[trav].link);
	}
	printf("-----------------------------------------------------------------------\n");
	printf("%10s: %d\n","AVAILABLE",vh.avail);
}








//-------------------------STACK----------------------//
void initStk(Stacklist *s){
	*s=-1;
}
//bool isFullStk(VirtualHeap vh,Stacklist s){}
bool isEmptyStk(Stacklist s){
	return(s==-1);
}
Product top(VirtualHeap vh, Stacklist s){
	Product temp;
	temp = vh.data[s].items;
	return temp;
}
void push(VirtualHeap *vh, Stacklist *s,Product item){
		int idx= allocSpace(vh);
		if(idx!=-1){
			vh->data[idx].items=item;
			vh->data[idx].link=*s;
			*s=idx;
		}
}
void pop(VirtualHeap *vh, Stacklist *s){
	int temp;
	temp=*s;
	*s=vh->data[*s].link;
	deallocSpace(vh,temp);
	
}
// void deallocSpace(VirtualHeap* vh,int idx){
// 	if(idx!= -1 &&idx<MAX){
// 		vh->data[idx].items=newProduct(0,"",0,0.00,newDate(0,0,0));
// 		vh->data[idx].link=vh->avail;
// 		vh->avail= idx;
// 	}
// }
void populateStk(VirtualHeap *vh, Stacklist *s){
	push(vh,s,newProduct(1001,"Lotion",12,12.00,newDate(12,2,2002)));
	push(vh,s,newProduct(1002,"Matches",5,8.00,newDate(30,6,2004)));
	push(vh,s,newProduct(1003,"Chips",100,27.00,newDate(23,2,2006)));
}
void populateStk2(VirtualHeap *vh, Stacklist *s){
	push(vh,s,newProduct(1004,"Milo",13,13.00,newDate(11,4,2005)));
	push(vh,s,newProduct(1005,"Candle",15,9.00,newDate(20,7,2004)));
	push(vh,s,newProduct(1006,"Shampoo",120,35.00,newDate(13,12,2006)));
}
void displayStk(VirtualHeap vh, Stacklist s){
	VirtualHeap tempvh;
	Stacklist tempS;
	initVH(&tempvh);
	initStk(&tempS);

	Product currentProd;
	printf("\n-------------------------DISPLAY STACK FROM TOP-------------------------\n");
	printf("\n%6s | %5s | %-12s | %10s | %6s | %-12s | %-5s\n","INDEX","ID","PRODUCT NAME","QUANTITY","PRICE", "DATE","NEXT"); 
	while(s!=-1){
		currentProd= top(vh,s);
		printf("%6d | ",s);
			printf("%5d | %-12s | %-10d | %6.2f | %4s %2d %4d | ",currentProd.prodID,
													currentProd.prodName,
													currentProd.prodQty,
													currentProd.prodPrice,
													Dates[currentProd.prodExp.month],
													currentProd.prodExp.date,
													currentProd.prodExp.year);
		
		printf("%-5d\n",vh.data[s].link);
		push(&tempvh,&tempS,currentProd);
		pop(&vh,&s);
	}	
	printf("\n-----------------------DISPLAY STACK FROM BOTTOM------------------------\n");
	
	printf("\n%6s | %5s | %-12s | %10s | %6s | %-12s | %-5s\n","INDEX","ID","PRODUCT NAME","QUANTITY","PRICE", "DATE","NEXT"); 
	while(tempS!=-1){
		currentProd=top(tempvh,tempS);
		
		printf("%6d | ",tempS);
			printf("%5d | %-12s | %-10d | %6.2f | %4s %2d %4d | ",currentProd.prodID,
													currentProd.prodName,
													currentProd.prodQty,
													currentProd.prodPrice,
													Dates[currentProd.prodExp.month],
													currentProd.prodExp.date,
													currentProd.prodExp.year);
		
		printf("%-5d\n",tempvh.data[tempS].link);
		pop(&tempvh,&tempS);
	}
	}








//-------------------------QUEUE----------------------//
void initQueue(Queue *q){
	q->front=-1;
	q->rear=-1;
}

bool isEmptyQ(Queue q){
	return (q.front==-1);
}
Product front(VirtualHeap vh, Queue q){
	Product temp;
	temp=vh.data[q.front].items;
	return temp;
}
void enqueue(VirtualHeap *vh, Queue *q,Product item){
	int idx= allocSpace(vh);
	if(isEmptyQ(*q)){
		vh->data[idx].link=q->rear;
		q->front=idx;
		q->rear=idx;
		vh->data[idx].items=item;
	}else{
		vh->data[idx].items=item;
		vh->data[idx].link=vh->data[q->rear].link;
		vh->data[q->rear].link=idx;
		q->rear=idx;
	}
}
void dequeue(VirtualHeap *vh,Queue *q){
	if(!isEmptyQ(*q)){
	int temp=q->front;
	q->front= vh->data[temp].link;
	deallocSpace(vh,temp);
	}
}

void populateQ(VirtualHeap *vh,Queue *q){
	enqueue(vh,q,newProduct(1007,"Laptop",15,200.00,newDate(12,2,2012)));
	enqueue(vh,q,newProduct(1008,"Ipad",300,100.00,newDate(30,6,2014)));
	enqueue(vh,q,newProduct(1009,"Jordans",200,99.00,newDate(23,2,2016)));
}


void populateQ2(VirtualHeap *vh,Queue *q){
	enqueue(vh,q,newProduct(1010,"Cars",15,1000.00,newDate(11,4,2015)));
	enqueue(vh,q,newProduct(1011,"Champagne",20,300.00,newDate(20,7,2014)));
	enqueue(vh,q,newProduct(1012,"Diamonds",150,2500.00,newDate(13,12,2016)));
}
void displayQ(VirtualHeap vh, Queue q){
	Product currentProd;
	printf("\n-------------------------DISPLAY STACK FROM FRONT-------------------------\n");
	printf("\n%6s | %5s | %-12s | %10s | %6s | %-12s | %-5s\n","INDEX","ID","PRODUCT NAME","QUANTITY","PRICE", "DATE","NEXT"); 
	while(q.front!=-1){
		currentProd= front(vh,q);
		printf("%6d | ",q.front);
			printf("%5d | %-12s | %-10d | %6.2f | %4s %2d %4d | ",currentProd.prodID,
													currentProd.prodName,
													currentProd.prodQty,
													currentProd.prodPrice,
													Dates[currentProd.prodExp.month],
													currentProd.prodExp.date,
													currentProd.prodExp.year);
		
		printf("%-5d\n",vh.data[q.front].link);
		dequeue(&vh,&q);
	}	
}

