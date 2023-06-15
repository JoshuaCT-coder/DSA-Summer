#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StaticArray.h"

/*#define MAX 10

typedef int DATA;

typedef struct {
    DATA elems[MAX];
    int count;
} List;*/

void initList(List *list)
{
    list->count = 0;
    printf("List has been Initialized");
}

List newList()
{
    List list;
    list.count = 0;
    printf("New List has been Created");
    return list;
}

void displayList(List list)
{
    for (int a = 0; a < list.count; a++)
    {
        printf(" index:%d  %d\n", a, list.elems[a]);
    }
}

bool insertFront(List *list, DATA item)
{
    bool state = (list->count != MAX);
    if (state)
    {

        for (int a = list->count - 1; a > -1; a--)
        {
            list->elems[a + 1] = list->elems[a];
        }
        list->elems[0] = item;

        list->count++;
    }
    return state;
}

bool insertRear(List *list, DATA item){
    bool state = (list->count != MAX);
    if (state)
    {
        list->elems[list->count]= item;
        list->count++;
    }
    return state;
}


bool insertSorted(List *list, DATA item){
    bool state=(list->count != MAX);

    if(state){

    }
}

bool insertAt(List *list, DATA item, int loc);

bool searchItem(List list, DATA key);

int getItem(List list, DATA key);

bool deleteFront(List *list);

bool deleteRear(List *list);

int deleteAt(List *list, int loc);

bool deleteItem(List *list, DATA key);

int deleteAllItem(List *list, DATA key);
