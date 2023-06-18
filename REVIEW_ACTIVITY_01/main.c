#include <stdio.h>
#include <stdlib.h>
// #include "StaticArray.c	// for Static array we assume -1 is uninitialized values so that it wont be garbage
#include "DynamicArray.c"   //for Dynaimc array we assume 0 is uninitialized values so that it wont be garbage


//my functions are inefficient and O(2) because I am assuming there are gaps in the list



/* -- -- -- -- -- -- -- -- -- -- -- -- -STATIC ARRAY TESTING-- -- -- -- -- -- -- -- -- -- -- -- -
int main(int argc, char *argv[])
{
	List list1;
	initList(&list1);
	insertFront(&list1, 10);
	insertRear(&list1, 90);
	insertAt(&list1, 80, 7);
	insertSorted(&list1, 70);
	insertSorted(&list1, 40);
	insertSorted(&list1, 50);
	insertSorted(&list1, 60);
	insertSorted(&list1, 30);
	insertSorted(&list1, 20);
	insertSorted(&list1, 10);
	displayList(list1);

	if (searchItem(list1, 30)){
		printf("\nItem found\n");
	}else{
		printf("\nItem not in list\n");
	}


	int retval = getItem(list1, 100);
	if (retval == -1){
		printf("\nElement Not Found\n");
	}else{
		printf("\n ELement found: %d", retval);
	}

	//deleteFront(&list1);
	deleteRear(&list1);

	int del1 = deleteAt(&list1, 7);
	if (del1 == -1){
		printf("\nNo element in that Location\n");
	}else{
		printf("\n Element deleted is %d", del1);
	}

	deleteItem(&list1, 50);
	int delAll = deleteAllItem(&list1, 10);
	if (delAll != 0){
		printf("\n %d element/s of 10 are deleted\n", delAll);
	}else{
		printf("\nNo elements Deleted\n");
	}

	displayList(list1);

	return 0;
}*/

//--------------------------------Dynamic Array TESTING--------------------------------
int main()
{
	List list2;
    initList(&list2);
    list2.elems[0]=1;
    list2.elems[1]=20;
    list2.elems[2]=30;
    list2.elems[3]=40;
    list2.elems[4]=50;
    list2.elems[5]=60;
    list2.elems[6]=70;
    list2.elems[7]=80;
    list2.elems[8]=90;
    list2.elems[9]=100;

    list2.count=10;
    insertFront(&list2, 10);
   	insertRear(&list2, 10);
	insertSorted(&list2, 80);
	insertAt(&list2,30, 4);
	displayList(list2);
	bool srch = searchItem(list2, 20);
	if(srch){
		printf("\n Element is Found\n");
	}else{
		printf("\nElement is not Found\n");
	}

	
	int retval = getItem(list2, 20);
	if(retval==0){
		printf("\n Element is not in the List\n");
	}else{
		printf("\nElement 20 is found in index %d\n", retval);
	}
	deleteFront(&list2);
	deleteRear(&list2);
	displayList(list2);
	// deleteAt(list2, 3);
	// deleteItem(list2, 20);
	// deleteAllItem(list2, 10);
	free(list2.elems);
	return 0;
}
// int deleteAt(List *list, int loc);
// bool deleteItem(List *list, DATA key);
// int deleteAllItem(List *list, DATA key);
