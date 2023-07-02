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
			/*void populate(Dictionary *d){
			addElem(d,newstudent("21100012",newName("Janus","Casera","Ridriguez"),newBday(18,04,2002),'M',"BSCS",2));
			addElem(d,newstudent("21100012",newName("Joshua","Casera","Radriguez"),newBday(18,04,2002),'M',"BSCS",2));
			addElem(d,newstudent("21100012",newName("Jeremy","Casera","Redriguez"),newBday(18,04,2002),'M',"BSCS",2));
			addElem(d,newstudent("21100012",newName("Jarco","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
			addElem(d,newstudent("21100012",newName("Jimmy","Casera","Rudriguez"),newBday(18,04,2002),'M',"BSCS",2));
			addElem(d,newstudent("21100012",newName("Jorus","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
			addElem(d,newstudent("31100556",newName("Joshua","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
			addElem(d,newstudent("22200124",newName("Joshua","Mirio","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
			addElem(d,newstudent("21100012",newName("Joshua","Casera","Saramo"),newBday(18,04,2002),'M',"BSCS",2));
			addElem(d,newstudent("31100556",newName("Joshua","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));

			//VISUALIZE BEFORE TESTING DUPLICATE//
			visualize(*d);

			//DUPLICATE//
			addElem(d,newstudent("31100556",newName("Joshua","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
			}*/

				break;
			case 2:
			removeElem(&d,newstudent("31100556",newName("Joshua","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
			removeElem(&d,newstudent("31100556",newName("Joshua","Casera","Samoa"),newBday(18,04,2002),'M',"BSCS",2));
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
