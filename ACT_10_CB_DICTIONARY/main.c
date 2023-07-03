#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {

	String Menu[4]={"AddElem","DeleteELem","Visualize","Exit"};
	Vspace vs;
	int choice;
	vs=newVspace(10);

	do{
		printf("\n--------MENU--------\n");
		int i;
		int data;
		for(i=0;i<4;i++){
			printf("\n%12s :[%d]\n",Menu[i],i+1);
		}
		printf("\nEnter Choice: ");
		scanf("%d",&choice);
		
		switch(choice){
			case 0:
				break;
			case 1:
			printf("\nADD ELEM\n");
			printf("\nEnter Element: ");
			scanf("%d",&data);
			addElem(&vs,data);
				break;
			case 2:
			printf("\nDELETE ELEM\n");
			printf("\nEnter Element: ");
			scanf("%d",&data);
			removeElem(&vs,data);
				break;
			case 3:
			printf("\n VISUALIZE: \n");
			visualize(vs);
				break;
			default:
			printf("\nOut of Bounds\n");
				break;				
		}

	}while(choice!=0);

		free(vs.data);
		printf("\nFreed Array\n");
	return 0;
}
