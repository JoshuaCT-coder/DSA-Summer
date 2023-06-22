#include <stdio.h>
#include <stdlib.h>
#include "Circular.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Queue myQueue;
	initQueue(&myQueue);
	String menuOption[8]= {"Enqueue", "Dequeue", "isEMPTY", "isFULL","FRONT","DISPLAY", "VISUALIZE","EXIT"};
	int i;
	int choice,value;
	do{
		printf("\nMENU\n");
		for(i=0; i<8;i++){
			printf("[%d] %s \n",i+1,menuOption[i]);
		}
		printf("Enter yout Choice <0 to EXIT>: \n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enqueue\n");
				if(!isFull(myQueue)){
				printf("Enter a number: ");
				scanf("%d",&value);
				enqueue(&myQueue,value);
				}else{
					printf("LIST IS FULL, CAN'T ENQUEUE!\n");
				}
				visualize(myQueue);
				break;
			case 2:
			
				printf("Dequeue\n");
				if(!isEmpty(myQueue)){
				dequeue(&myQueue);
				printf("Queue has moved\n");
				}else{
					printf("LIST IS EMPTY, CAN'T DEQUEUE!\n");
				}	
				visualize(myQueue);
				break;
			case 3:
				printf("%s\n",(isEmpty(myQueue))?"List is Empty":"List is not Empty");
				break;
			case 4:
				printf("%s\n",(isFull(myQueue))?"List is Full":"List is not Full");
				break;
			case 5:
				if(!isEmpty(myQueue)){
				printf("Front Element\n");
				printf("%d\n",front(myQueue));
				}else{
					printf("No Elements in Queue");
				}
				break;
			case 6:
				printf("Display\n");
				display(myQueue);
				break;
			case 7:
				visualize(myQueue);
				break;
			default:
				printf("INVALID INPUT\n");
				break;
		}
	}while (choice!=0);
	
	visualize(myQueue);
	
	return 0;
}
