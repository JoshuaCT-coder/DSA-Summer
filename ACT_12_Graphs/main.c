#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "myheader.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary list;
	initDict(&list);

	String menuOption[8]= {"Populate Vertex","Populate Edges","Delete Vertex","Delete Edge","DFS DISPLAY","BFS Display", "VISUALIZE","EXIT"};
	int i=0;
	int choice,value;
	String temp, temp1;
	bool state1,state2;
	do{
		printf("\n--------MENU--------\n");
		for(i=0; i<8;i++){
			printf("[%d] %s \n",i+1,menuOption[i]);
		}
		printf("Enter your Choice <0 to 10>: \nPress [0] to Exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				populateVertex(&list);
				visualize(list);
				break;
			case 2:
				populateEdges(&list);
				visualize(list);
				break;
			case 3:
				visualize(list);
				printf("\nChoose an Existing Vertex to Delete: \n");
				scanf("%s",temp);
				if(checkVertex(list,temp)){
					deleteVertex(&list,temp);
				}else{
					printf("\nINPUT DOESN'T EXIST\n");
				}
				break;
			case 4:
				visualize(list);
				printf("\nChoose an Existing Edge1: \n");
				scanf("%s",temp);
				printf("\nChoose an Existing Edge2: \n");
				scanf("%s",temp1);
				state1 =checkVertex(list,temp);
				state2 = checkVertex(list,temp1);
				if(state1 && state2){
					deleteEdge(&list,temp,temp1);
				}else{
					printf("\n One or Both Edges DON'T EXIST\n");
				}
				break;
			case 5:
			visualize(list);
				printf("\nChoose a Starting Vertex: \n");
				scanf("%s",temp);
				DFSdisplay(list,temp);
				break;
			case 6:
			visualize(list);
				printf("\nChoose a Starting Vertex: \n");
				scanf("%s",temp);
				BFSdisplay(list,temp);
				break;
			case 7:
				visualize(list);
				break;
			case 0:
			break;
			
			default:
				printf("INVALID INPUT\n");
				break;
		}
	}while (choice!=0);

	freeDict(&list);
	return 0;
}
