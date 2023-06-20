#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackLL.h"
//#include "StackARR.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*int main(int argc, char *argv[]) {
	
	Stack list;
	Stack Dump;
	initStack(&list);
	int choice;
	int TOP;
	int item;
	
	do{
	printf("\n\t-----MENU-----\n");
	printf("\nPUSH:\t[1]\nPOP\t[2]\nTOP\t[3]\nDISPLAY\t[4]\nVisualize[5]\nEXIT\t[6]\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nITEM: \n");
			scanf("%d",&item);
			push(&list,item);
			if(!isFull(list))
			{
				printf("\nElement Pushed\n");
			}
			break;
		case 2:
			pop(&list);
				if(!isEmpty(list))
			{
					printf("\nElement Deleted\n");
			}
		
			break;
		case 3:
			TOP = top(list);
			printf("\nElement AT The Top is %d\n",TOP);
			break;
		
		case 4:
			display(list);
			break;
		
		case 5:
		visualize(list);
			break;
		
	}
	}while(choice!=6);
	return 0;
}*/



int main(int argc, char *argv[]) {
	
	StackPTR list;
	initStack(list);
	int choice;
	int TOP;
	int item;
	
	do{
	printf("\n\t-----MENU-----\n");
	printf("\nPUSH:\t[1]\nPOP\t[2]\nTOP\t[3]\nDISPLAY\t[4]\nVisualize[5]\nEXIT\t[6]\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nITEM: \n");
			scanf("%d",&item);
			push(&list,item);
			if(!isFull(list))
			{
				printf("\nElement Pushed\n");
			}
			break;
		case 2:
			pop(&list);
				if(!isEmpty(list))
			{
					printf("\nElement Deleted\n");
			}
		
			break;
		case 3:
			TOP = top(list);
			printf("\nElement AT The Top is %d\n",TOP);
			break;
		
		case 4:
			display(list);
			break;
		
		case 5:
		visualize(list);
			break;
		
	}
	}while(choice!=6);
return 0;
}
