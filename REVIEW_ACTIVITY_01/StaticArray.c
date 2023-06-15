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
    for (int i = 0; i < MAX; i++)
    {
        list->elems[i] = -1;
    }
    list->count = 0;
    printf("\nList has been Initialized\n");
}

List newList()
{
    List list;
    list.count = 0;
    printf("\nNew List has been Created\n");
    return list;
}

void displayList(List list)
{
    printf("\nCurrent List:\n\n");
    for (int a = 0; a < MAX; a++)
    {
        printf("    index:%d  %d\n", a, list.elems[a]);
    }
    printf("Element count: %d\n", list.count);
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
        printf("\nElement inserted at the Front\n");
    }
    return state;
}

bool insertRear(List *list, DATA item)
{
    bool state = (list->count != MAX);
    if (state)
    {
        list->elems[list->count] = item;
        list->count++;
        printf("\nElement inserted at the Rear\n");
    }
    return state;
}

bool insertSorted(List *list, DATA item)
{
    bool state = (list->count != MAX);

    if (state)
    {

        int i = 0;

        while (i < list->count && list->elems[i] != -1 && list->elems[i] <= item)
        {
            i++;
        }

        for (int j = list->count - 1; j >= i; j--)
        {
            list->elems[j + 1] = list->elems[j];
        }

        list->elems[i] = item;
        list->count++;
    }
    return state;
}

bool insertAt(List *list, DATA item, int loc)
{
    bool state = (list->count != MAX && loc >= 0 && loc <= (MAX - 1));
    if (state)
    {
        if (list->elems[loc] == -1)
        {
            list->elems[loc] = item;
            list->count++;
            printf("\nElement inserted at the At Location\n");
        }
    }
    return state;
}

bool searchItem(List list, DATA key)
{
    int left = 0;
    int right = MAX;
    int mid;
    while (left <= right)
    {
        mid = left + (right - left) / 2;
        while (left <= right && list.elems[left] == -1)
        {
            left++;
        }
        while (left <= right && list.elems[right] == -1)
        {
            right--;
        }
        while (list.elems[mid] != key)
        {
            if (list.elems[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }

    return (list.elems[mid] == key);
}

int getItem(List list, DATA key);

bool deleteFront(List *list);

bool deleteRear(List *list);

int deleteAt(List *list, int loc);

bool deleteItem(List *list, DATA key);

int deleteAllItem(List *list, DATA key);
