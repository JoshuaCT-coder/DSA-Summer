#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "CBStkQ.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
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
}Product;*/

int main(int argc, char *argv[]){
	
	shortstring Dates[13]={"","Jan","Feb","Mar","Apr","May","June","July","Aug","Oct","Nov","Dec"};
	String Menu[4]={"Stack","Queue","Visualize","Exit"};
	String MenuStk[6]={"Top","Push","Pop","Display","Visualize","Exit"};
	String MenuQ[5]={"Enqueue","Deueue","Display","Visualize","Exit"};
	int choice,choice1,choice2;
	int value;
	int i;
	
	VirtualHeap vh;
	initVH(&vh);
	
	Stacklist s;
	initStk(&s);
	
	populateStk	(&vh,&s);
	do{
		printf("%4s\n","----------MENU---------");
		for(i=0;i<4;i++){
			printf("%14s | %d\n",Menu[i],i);
		}
		printf("Enter a choice: ");
		scanf("%d",&choice);
	}while (choice!=0);
	
	return 0;
}
