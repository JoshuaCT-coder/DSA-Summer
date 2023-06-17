#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H

#include <stdbool.h>

#define MAX 10

typedef int DATA;

typedef struct {
	DATA *elems;	//changed this datatype so that I can realloc, if it isnt a pointer I cant realloc, I would have to realloc the entire List and manually tranfser from two different lists plus calloc can initialize empty nodes into 0 so its convenient;
	int count;
	int max;
} List;

void initList(List *list);
List newList(int max);
void displayList(List list);
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

#endif
