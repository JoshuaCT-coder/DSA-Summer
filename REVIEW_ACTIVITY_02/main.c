#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.c"


int main() {

List list;
initList(&list);
List list3 = newList();
insertFront(&list,10);
insertRear(&list,40);
insertRear(&list,50);
insertAt(&list, 30, 3);
// insertSorted(&list, 20);
// insertSorted(&list, 60);
displayList(list);
	return 0;
}

// 	   searchItem(list, 50);
// int getItem(list, 50);
// 	   deleteFront(&list);
// 	   deleteRear(&list);
// int deleteAt(&list,3);
// 	   deleteItem(&list, 50);
// int deleteAllItem(&list, 50);

