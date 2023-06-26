#include <stdio.h>
#include <stdlib.h>
#include "SETS.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]){
	String Menu[10]={"Set A","Set B","Union","Intersect","Difference A-B","Difference B-A","Sym Diff","Disp. Set A","Disp. Set B","Exit"};
	String Menu1[4]={"Insert","Remove","Display","Exit"};
	int choice,choice1,choice2;
	int value;
	int i;
	Set A= newSet();
	Set B = newSet();
	Set tempS;
	do{
		printf("\n%4s\n","----------MENU---------");
		for(i=0;i<10;i++){
			printf("%14s | %d\n",Menu[i],i+1);
		}
		printf("Enter a choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 0:
				break;
			case 1:
				do{
					printf("\n%4s\n","-------SET A MENU---------");
				for(i=0;i<4;i++){
					printf("%14s | %d\n",Menu1[i],i+1);
				}
				printf("Enter a choice: ");
				scanf("%d",&choice1);
				switch(choice1){
					case 0:
					break;
					case 1:
						printf("Enter your number to insert: ");
						scanf("%d",&value);
						addElem(&A,value);
					break;
						case 2: 
						printf("Enter your number to insert: ");
						scanf("%d",&value);
						removeElem(&A,value);
					break;	
					case 3: 
					displaySet(A);
						break;	
				}
				}while(choice1!=0);
				break;
			case 2:
				do{
					printf("\n%4s\n","-------SET B MENU---------");
				for(i=0;i<4;i++){
					printf("%14s | %d\n",Menu1[i],i+1);
				}
				printf("Enter a choice: ");
				scanf("%d",&choice2);
				switch(choice2){
					case 0:
					break;
					case 1:
						printf("Enter your number to insert: ");
						scanf("%d",&value);
						addElem(&B,value);
					break;
						case 2: 
						printf("Enter your number to insert: ");
						scanf("%d",&value);
						removeElem(&B,value);
					break;	
					case 3: 
					displaySet(B);
						break;	
				}
				}while(choice2!=0);				
				break;
			case 3:
			tempS=unionSet(A,B);
			printf("\n----------UNION SET----------\n");
			displaySet(tempS);
				break;
			case 4:
			tempS=interSet(A,B);
			printf("\n----------INTERSECTION SET----------\n");
			displaySet(tempS);
				break;
			case 5:
			tempS=differenceSet(A,B);
			printf("\n----------DIFFERNCE SET A-B ----------\n");
			displaySet(tempS);
				break;
			case 6:
			tempS=differenceSet(B,A);
			printf("\n----------DIFFERNCE SET B-A ----------\n");
			displaySet(tempS);
				break;
			case 7:
			tempS= symmetricDiffSet(A,B);
			displaySet(tempS);
				break;
				case 8:
			displaySet(A);
				break;
			case 9:
			displaySet(B);
				break;
			default:
			printf("\n INVALID INPUT: Out of Bounds\n");
				break;
			}
	}while(choice!=0);	
	
	return 0;
}
