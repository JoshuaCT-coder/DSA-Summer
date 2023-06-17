#include <stdio.h>
#include <stdlib.h>
#include "StaticArray.c"

/*	void displayList(List list);
bool insertFront(List *list, DATA item);
bool insertRear(List *list, DATA item);
bool insertSorted(List *list, DATA item);
bool insertAt(List *list, DATA item, int loc);
bool searchItem(List list, DATA key);
int getItem(List list, DATA key);
bool deleteFront(List *list);
bool deleteRear(List *list);
int deleteAt(List *list, int loc);
bool deleteItem(List *list, DATA key);
int deleteAllItem(List *list, DATA key);
*/

int main(int argc, char *argv[])
{

	List list1;
	initList(&list1);
	insertFront(&list1, 10);
	insertRear(&list1,90);
	insertAt(&list1,80,7);
	insertSorted(&list1,70);
	insertSorted(&list1,40);
	insertSorted(&list1,50);
	insertSorted(&list1,60);
	insertSorted(&list1,30);
	insertSorted(&list1,20);
	insertSorted(&list1,10);
	displayList(list1);
	if(searchItem(list1,30)){
		printf("\nItem found\n");
	}
	else{
		printf("\nItem not in list\n");
	}
	
	int retval = getItem(list1, 100);
	if(retval== -1){
		printf("\nElement Not Found\n");
	}else{
		printf("\n ELement found: %d",retval);
	}

	 deleteFront(&list1);
	 deleteRear(&list1);
	 
	 
int del1 = deleteAt(&list1, 7);
	 if(del1==-1){
		printf("\nNo element in that Location\n");
	 }else{
		printf("\n Element deleted is %d",del1);
	 }

	deleteItem(&list1, 50);
	int delAll =  deleteAllItem(&list1, 10);
if(delAll!=0){
	printf("\n %d element/s of 10 are deleted\n",delAll);
}else{
	printf("\nNo elements Deleted\n");
}
displayList(list1);
	return 0;
}
