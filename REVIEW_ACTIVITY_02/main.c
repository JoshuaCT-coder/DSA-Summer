#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.c"


int main() {

List list;
initList(&list);
List list3 = newList();
insertFront(&list,5);
insertRear(&list,10);
insertRear(&list,40);
insertRear(&list,40);
insertRear(&list,40);
insertAt(&list, 30, 3);
insertSorted(&list, 20);
insertSorted(&list, 50);
displayList(list);
searchItem(list, 60);
int retval = getItem(list, 50);
if(retval==-1){
	printf("\nItem not Found\n");
}else{
	printf("\nItem %d is taken from the list\n",retval);
}
deleteFront(&list);
deleteRear(&list);
deleteAt(&list,3);
deleteItem(&list, 20);
//int delAll =  deleteAllItem(&list, 40);
//printf("\n%d Elements of 40 have been deleted\n",delAll);

displayList(list);

	return 0;
} 


