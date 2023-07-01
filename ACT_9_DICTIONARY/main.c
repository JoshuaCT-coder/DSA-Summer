#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionary.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int size=20;
	Dictionary d;
	initDict(&d,26);
	String Menu[4]={"Insert","Delete","Visualize","Exit"};
	int i,choice;

	printf("------MENU------\n");
	do{
	for(i=0;i<4; i++){
		printf("%-10s [%d]\n",Menu[i],i+1);
	}
	printf("----------------\n");
	printf("Enter a choice: ");
	scanf("%d",&choice);
		switch(choice){
			case 0:
				break;
			case 1:
			populate(&d);
				break;
			case 2:
			//removeElem();
				break;
			case 3: 
			visualize(d);
				break;
			default:
			printf("Out of Bounds\n");
			break;
		}
	}while(choice!=4);
	freeDictionary(&d);
	
		return 0;
}
