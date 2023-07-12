
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 10
typedef char String[30];
String Month[13]={"","Jan","Feb","Mar","Apr","May","Jun","July","Aug","Sep","Oct","Nov","Dec"};

typedef struct {
	int date;
	int month;
	int year;
} MyDate;

typedef struct {
	int prodID;
	String prodName;
	char category;   // each bit is one category
	int qty;
	MyDate expiryDate;
} Product;

typedef struct {
	Product *prods;
	int top;	
	int max;
} ProductStack;

typedef struct node{
	Product prod;
	struct node *next;
} ProdNode, *ProductList, *ProdPtr;

typedef struct {
	ProdPtr front;
	ProdPtr rear;
} ProductQueue;

MyDate newDate(int month, int date, int year) {
	MyDate d = {date, month, year};
	
	return d;
}

Product newProduct(int id, String name, char category, int qty, MyDate expiry) {
	Product p;
	
	p.prodID = id;
	strcpy(p.prodName, name);
	p.category = category;
	p.qty = qty;
	p.expiryDate = expiry;
	
	return p;
}

ProductStack newProductStackList(int size) {
	ProductStack list;
	
	list.prods = malloc(sizeof(Product) * size);
	list.top = 0;
	list.max = size;
	
	return list;
}

bool isEmpty(ProductStack list){
	 return(list.top==0);
}
bool isFull(ProductStack list){
	return(list.top==MAX);
}
Product top(ProductStack list){
	return list.prods[list.top-1];
}

void push(ProductStack *list,Product elem){
	if(isFull(*list)){
		printf("\nLIST IS FULL UNABLE TO PUSH\n");
	}else{
		list->prods[list->top]=elem;
		list->top++;
	}
}
void pop(ProductStack *list){
	if(isEmpty(*list)){
		printf("\nList is Empty\n");
	}else{
		list->top--;
	}
}

//create add product that adds all the product in linked list in the rear
void addProduct(ProductList *list, Product p)
{
	
	ProdPtr *trav;
	for(trav=list;*trav!=NULL;trav=&(*trav)->next){}
	
		ProdPtr temp=malloc(sizeof(ProdNode));
		temp->prod=p;
		temp->next=NULL;
		*trav=temp;
		printf("\nElement added\n");
	
}

int yearDiff(int year1, int year2){
	return year1-year2;
}
int monthDiff(int month1, int month2){
	return month1-month2;
}
int dateDiff(int date1, int date2){
	return date1-date2;
}


//create a function that returns a stack of product that the earliest to expire is places at the top of the list for all the product from a product list
ProductStack arrangeByExpiry(ProductList list) {
    printf("\n\n\nREARRANGING USING STACKS\n");
    ProductStack temp = newProductStackList(MAX);
    ProductStack dump = newProductStackList(MAX);
    ProdPtr* trav;
    int i = 0;
    int a = 0;
    trav = &list;
    push(&temp, (*trav)->prod);
    trav = &(*trav)->next;
    displayStk(temp);

    for (; (*trav) != NULL; trav = &(*trav)->next) {
		printf("%d --- %d",(*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year);
        if (yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) > 0) { 
			printf("\nGreater Year\n");   // list is greater than top of stack - YEAR
            push(&temp, (*trav)->prod);
            printf("\nElement Pushed\n");
        }
        else if (yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) < 0) {    // list is lesser than top of stack - YEAR
		printf("\nLesser Year\n");
            while (temp.top != 0 && yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) < 0) {
                push(&dump, temp.prods[temp.top - 1]);
                pop(&temp);
            }

           if(temp.top!=0 && yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0) {		
							printf("\nSame Year\n");		// list is equal to top of stack - YEAR
						if (monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) > 0) {
							push(&temp, (*trav)->prod);
							printf("\nElement Pushed\n");
						}
						else if (monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) < 0) {
							while (temp.top != 0 && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) < 0  && yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0) {
								push(&dump, temp.prods[temp.top - 1]);
								pop(&temp);
							}
											if(temp.top!=0  && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) == 0 &&  yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0){			// list has the same year and month as the top of stack
																		printf("\nSame Month\n");
																	if (dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) > 0) {
																		push(&temp, (*trav)->prod);
																		printf("\nElement Pushed\n");
																	}
																	else if (dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) < 0) {
																		while (temp.top != 0 && dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) < 0   && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) == 0   && yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0) {
																			push(&dump, temp.prods[temp.top - 1]);
																			pop(&temp);
																		}
																	if(temp.top!=0 &&dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) == 0 && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) == 0 &&  yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0){	
																			printf("\nSame Dates\n");
																		push(&temp, (*trav)->prod);
																		printf("\nElement Pushed\n");
																	}else{
																		push(&temp, (*trav)->prod);
																		printf("\nElement Pushed AT THE BOTTOM\n");
																	}
																	}

												}else{
													push(&temp, (*trav)->prod);
													printf("\nElement Pushed at the BOTTOM\n");
												}
							}else{
								printf("\nEqual Month\n");
								if (dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) > 0) {
										push(&temp, (*trav)->prod);
										printf("\nElement Pushed\n");
									}
									else if (dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) < 0) {
										while (temp.top != 0 && dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) < 0   && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) == 0   && yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0) {
											push(&dump, temp.prods[temp.top - 1]);
											pop(&temp);
										}
									if(temp.top!=0 &&dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) == 0 && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) == 0 &&  yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0){	
											printf("\nSame Dates\n");
										push(&temp, (*trav)->prod);
										printf("\nElement Pushed\n");
									}else{
										push(&temp, (*trav)->prod);
										printf("\nElement Pushed AT THE BOTTOM\n");
									}
									}
							}
        	}else{
				push(&temp, (*trav)->prod);
				printf("\nElement Pushed at the BOTTOM\n");
			}
    	}else{
			printf("\nEqual YEAR\n");
			if (monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) > 0) {
							push(&temp, (*trav)->prod);
							printf("\nElement Pushed\n");
						}
						else if (monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) < 0) {
							while (temp.top != 0 && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) < 0  && yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0) {
								push(&dump, temp.prods[temp.top - 1]);
								pop(&temp);
							}
											if(temp.top!=0  && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) == 0 &&  yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0){			// list has the same year and month as the top of stack
																		printf("\nSame Month\n");
																	if (dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) > 0) {
																		push(&temp, (*trav)->prod);
																		printf("\nElement Pushed\n");
																	}
																	else if (dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) < 0) {
																		while (temp.top != 0 && dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) < 0   && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) == 0   && yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0) {
																			push(&dump, temp.prods[temp.top - 1]);
																			pop(&temp);
																		}
																	if(temp.top!=0 &&dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) == 0 && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) == 0 &&  yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0){	
																			printf("\nSame Dates\n");
																		push(&temp, (*trav)->prod);
																		printf("\nElement Pushed\n");
																	}else{
																		push(&temp, (*trav)->prod);
																		printf("\nElement Pushed AT THE BOTTOM\n");
																	}
																	}

												}else{
													push(&temp, (*trav)->prod);
													printf("\nElement Pushed at the BOTTOM\n");
												}
								}else{
									printf("\nEqual Month\n");
									if (dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) > 0) {
											push(&temp, (*trav)->prod);
											printf("\nElement Pushed\n");
										}
										else if (dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) < 0) {
											while (temp.top != 0 && dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) < 0   && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) == 0   && yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0) {
												push(&dump, temp.prods[temp.top - 1]);
												pop(&temp);
											}
										if(temp.top!=0 &&dateDiff((*trav)->prod.expiryDate.date, temp.prods[temp.top - 1].expiryDate.date) == 0 && monthDiff((*trav)->prod.expiryDate.month, temp.prods[temp.top - 1].expiryDate.month) == 0 &&  yearDiff((*trav)->prod.expiryDate.year, temp.prods[temp.top - 1].expiryDate.year) == 0){	
												printf("\nSame Dates\n");
											push(&temp, (*trav)->prod);
											printf("\nElement Pushed\n");
										}else{
											push(&temp, (*trav)->prod);
											printf("\nElement Pushed AT THE BOTTOM\n");
										}
										}
								}
							
						}
  
				while (dump.top != 0) {
				push(&temp, dump.prods[dump.top - 1]);
				pop(&dump);
				}
				
	}


    return temp;
}





Product front (ProductQueue q){
	return q.front->prod;
}
bool isEmptyQ(ProductQueue q){
	return(q.rear==NULL);
}

ProductQueue newProductQueue() {
	ProductQueue pq;
	
	pq.front = pq.rear = NULL;
	
	return pq;
}
void enqueue(ProductQueue *q,Product item){
		ProdPtr temp=malloc(sizeof(ProdNode));
		temp->prod=item;
		temp->next=q->rear->next;
		q->rear->next=temp;
		q->rear=temp;
		printf("\nAdded to Queue\n");
}

void dequeue(ProductQueue *q){
	if(!isEmptyQ(*q)){
		ProdPtr temp;
		temp=q->front;
		q->front=q->front->next;
		free(temp);
	}
}

populateQ(ProductQueue *q){
	enqueue(q,newProduct(11023,"Shampoo",'A',10,newDate(3,15,2012)));
	enqueue(q,newProduct(21203,"Chips",'B',10,newDate(2,13,2002)));
	enqueue(q,newProduct(21100,"Detergent",'C',10,newDate(6,12,2003)));
	enqueue(q,newProduct(31138,"Hairspray",'D',10,newDate(4,12,2003)));
	enqueue(q,newProduct(43241,"Canton",'E',10,newDate(1,12,2008)));
	enqueue(q,newProduct(54455,"Spam",'F',10,newDate(2,12,2002)));
	enqueue(q,newProduct(60000,"Shaving Cream",'G',10,newDate(3,12,2012)));

}

//create a function that removes all product in the queue and returns the removed product into a product linked list where quantity is lesser than the specified value 
ProductList getLessQuantity(ProductQueue *prodQueue, int thesholdQty){
	
	
};

void display(ProductList L){
		ProdPtr trav;
	printf("\n--------LIST--------\n");
	printf("\n%6s | %-15s | %8s | %3s | %-8s \n","ID","PRODNAME","CATEGORY","QTY","DATE");
	for(trav=L; trav!=NULL;trav=trav->next){
		printf("\n%6d | %-15s | %-8c | %3d | %4s, %d %d  \n",trav->prod.prodID,trav->prod.prodName,trav->prod.category,trav->prod.qty,Month[trav->prod.expiryDate.month],trav->prod.expiryDate.date,trav->prod.expiryDate.year);
	}
}

void displayStk(ProductStack list){
	ProductStack temp=newProductStackList(MAX);
	while(list.top!=0 && (!isFull(temp))){
		push(&temp,top(list));
		pop(&list);
	}
	printf("\n\n--------Stack TOP--------\n");
	printf("\n%6s | %-15s | %8s | %3s | %-8s \n","ID","PRODNAME","CATEGORY","QTY","DATE");
	while(temp.top!=0){
		Product trav=top(temp);
		printf("\n%6d | %-15s | %-8c | %3d | %4s, %d %d \n",trav.prodID,trav.prodName,trav.category,trav.qty,Month[trav.expiryDate.month],trav.expiryDate.date,trav.expiryDate.year);
		pop(&temp);
	}
}

void displayQ(ProductQueue list){

	printf("\n\n--------Queue--------\n");
	printf("\n%6s | %-15s | %8s | %3s | %-8s \n","ID","PRODNAME","CATEGORY","QTY","DATE");
	while(list.front!=NULL){
		Product trav=front(list);
		printf("\n%6d | %-15s | %-8c | %3d | %4s, %d %d \n",trav.prodID,trav.prodName,trav.category,trav.qty,Month[trav.expiryDate.month],trav.expiryDate.date,trav.expiryDate.year);
		dequeue(&list);
	}
}
int main() {
	

	ProductList list=NULL;
	addProduct(&list,newProduct(11023,"Shampoo",'A',10,newDate(3,15,2012)));
	addProduct(&list,newProduct(21203,"Chips",'B',10,newDate(2,13,2002)));
		addProduct(&list,newProduct(21203,"Chips",'B',10,newDate(2,11,2002)));
	addProduct(&list,newProduct(21100,"Detergent",'C',10,newDate(6,12,2003)));
	addProduct(&list,newProduct(31138,"Hairspray",'D',10,newDate(4,12,2003)));
	addProduct(&list,newProduct(43241,"Canton",'E',10,newDate(1,12,2008)));
	addProduct(&list,newProduct(54455,"Spam",'E',10,newDate(2,12,2002)));
	addProduct(&list,newProduct(60000,"Shaving Cream",'E',10,newDate(3,12,2012)));
	display(list);
	
	ProductStack Stack= arrangeByExpiry(list);
	displayStk(Stack);
	
	ProductQueue Q = newProductQueue();
	populateQ(&Q);
	displayQ(Q);


	return 0;
}
