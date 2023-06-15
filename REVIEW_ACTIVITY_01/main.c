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
	insertRear(&list1,80);
	insertAt(&list1,40,4);
	insertedSorted(&list1,80);
	displayList(list1);

	if(searchItem(list1,30)){
		printf("Item found");
	}
	else{
		printf("Item not in list");
	}


	return 0;
}
