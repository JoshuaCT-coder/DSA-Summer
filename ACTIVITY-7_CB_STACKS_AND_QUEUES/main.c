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
	String Menu[4]={"Stack","Queue","Visualize","Exit"};
	String MenuStk[6]={"Top","Push","Pop","Display","Visualize","Exit"};
	String MenuQ[6]={"Front","Enqueue","Dequeue","Display","Visualize","Exit"};
	shortstring Dates[13]={"","Jan","Feb","Mar","Apr","May","June","July","Aug","Oct","Nov","Dec"};
	int choice,choice1,choice2;
	int value;
	int i;
	
	VirtualHeap vh;
	initVH(&vh);
	Stacklist s;
	initStk(&s);
	Queue q;
	initQueue(&q);
	populateStk(&vh,&s);
	populateQ(&vh,&q);



	do{
		printf("\n%4s\n","----------MENU---------");
		for(i=0;i<4;i++){
			printf("%14s | %d\n",Menu[i],i+1);
		}
		printf("Enter a choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 0:
			break;

			case 1:
			do{
						printf("%4s\n","\n----------STACK MENU---------\n");
						for(i=0;i<6;i++){
							printf("%14s | %d\n",MenuStk[i],i+1);
						}
						printf("Enter a choice: ");
						scanf("%d",&choice1);
							switch (choice1){
								case 0:
									break;
								case 1:
								Product TOP = top(vh,s);
								printf("\n%6s | %5s | %-12s | %10s | %6s | %-12s | %-5s\n","INDEX","ID","PRODUCT NAME","QUANTITY","PRICE", "DATE","NEXT"); 
										printf("%6d | ",s);
										if(vh.data[s].items.prodID!=0){
											printf("%5d | %-12s | %-10d | %6.2f | %4s %2d %4d | ",TOP.prodID,
																					TOP.prodName,
																					TOP.prodQty,
																					TOP.prodPrice,
																					Dates[TOP.prodExp.month],
																					TOP.prodExp.date,
																					TOP.prodExp.year);
										}else{
										printf("%-60s","EMPTY");
									}
									printf("%-5d\n",vh.data[s].link);
								break;
							case 2:
							populateStk2(&vh,&s);						
								break;
							case 3:
							pop(&vh,&s);
								break;
							case 4:
							displayStk(vh,s);
								break;
							case 5:
							visualize(vh);
								break;
							default:
							printf("\n INVALID INPUT: Out of Bounds\n");
								break;
			
						}
					}while(choice1!=0);
				break;
			case 2:
					do{
					printf("%4s\n","\n----------QUEUE MENU---------\n");
					for(i=0;i<6;i++){
						printf("%14s | %d\n",MenuQ[i],i+1);
					}
					printf("Enter a choice: ");
					scanf("%d",&choice2);
						switch (choice2){
							case 0:
								break;
							case 1:
							Product FRONT = front(vh,q);
							printf("\n%6s | %5s | %-12s | %10s | %6s | %-12s | %-5s\n","INDEX","ID","PRODUCT NAME","QUANTITY","PRICE", "DATE","NEXT"); 
									printf("%6d | ",s);
									if(vh.data[q.front].items.prodID!=0){
										printf("%5d | %-12s | %-10d | %6.2f | %4s %2d %4d | ",FRONT.prodID,
																				FRONT.prodName,
																				FRONT.prodQty,
																				FRONT.prodPrice,
																				Dates[FRONT.prodExp.month],
																				FRONT.prodExp.date,
																				FRONT.prodExp.year);
									}else{
										printf("%-60s","EMPTY");
									}
									printf("%-5d\n",vh.data[q.front].link);
								break;
							case 2:
							populateQ2(&vh,&q);						
								break;
							case 3:
							dequeue(&vh,&q);
								break;
							case 4:
							displayQ(vh,q);
								break;
							case 5:
							visualize(vh);
								break;
							default:
							printf("\n INVALID INPUT: Out of Bounds\n");
								break;
							}
				}while(choice2!=0);
				break;	
			case 3:
			visualize(vh);
				break;
			default:
			printf("\nINVALID INPUT: Out of Bounds!\n");
			break;
		}
	}while(choice!=0);	
	
	return 0;
}
