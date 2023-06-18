#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef int DATA;

typedef struct node {
	DATA data;
	struct node *next;
} NodeType, *NodePtr, *List;

// typedef struct node{
// 	NodePtr cells;							//Could be used if you want to count for the elements in the list
// 	int count;
// }*List;

void initList(List *list);
List newList();
NodePtr createNode(DATA data);
void displayList(List list);
bool insertFront(List *list, DATA item);
bool insertRear(List *list, DATA item);
bool insertAt(List *list, DATA item, int loc);
bool insertSorted(List *list, DATA data);
bool searchItem(List list, DATA key);
int getItem(List list, DATA key);
bool deleteFront(List *list);
bool deleteRear(List *list);
int deleteAt(List *list, int loc);
bool deleteItem(List *list, DATA key);
int deleteAllItem(List *list, DATA key);

#endif
