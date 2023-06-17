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

        int i;
        for (i = 0; i < MAX && list->elems[i] != -1 && list->elems[i] <= item; i++) // Checks if the item to be added is greater than the values in the list, if -1 it stops and adds the value
        {
        }

        if (list->elems[i] == -1)
        {
            list->elems[i] = item;
        }
        else
        {
            for (int a = MAX - 1; a > i; a--)
            {
                if (a != i && list->elems[a - 1] != -1)
                {                                        /*checks if the values of a are not equal to i when it decrements
                                                          and checks if the lesser index is not -1*/
                    list->elems[a] = list->elems[a - 1]; // Shifts the values to the right
                }
            }
            list->elems[i] = item;
        }

        list->elems[i] = item;
        list->count++;
        printf("\nElement inserted at Sorted Position\n");
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
    int mid = left + (right - left) / 2;
    while (left <= right && list.elems[mid] != key)
    {
        mid = left + (right - left) / 2;
        /*while (left <= right && list.elems[left] == -1)
        {
            left++;                                              //In-case list is not full and uninitialized values arent needed
        }
        while (left <= right && list.elems[right] == -1)
        {
            right--;
        } */
        if (list.elems[mid] < key)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return (list.elems[mid] == key);
}

int getItem(List list, DATA key)
{
    {

        int left = 0;
        int right = MAX;
        int mid = left + (right - left) / 2;
        while (left <= right && list.elems[mid] != key)
        {
            mid = left + (right - left) / 2;
            /*while (left <= right && list.elems[left] == -1)
            {
                left++;                                              //In-case list is not full and uninitialized values arent needed
            }
            while (left <= right && list.elems[right] == -1)
            {
                right--;
            } */
            if (list.elems[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return (list.elems[mid] == key) ? list.elems[mid] : -1;
    }
}

bool deleteFront(List *list)
{
    bool state = (list->count != 0);
    if (state)
    {
        for (int idx = 0; idx < MAX; idx++)
        {
            if (list->elems[idx + 1] != -1)
            {
                list->elems[idx] = list->elems[idx + 1];
            }
        }
        list->elems[MAX-1]=-1;
        printf("\nElement has been deleted");
        list->count--;
    }
    else
    {
        printf("\nList is empty, no element to delete.\n");
    }
    return state;
}

bool deleteRear(List *list){
    bool state =(list->count !=0);

    if(state){
        int idx;
        for(idx=MAX-1;list->elems[idx]==-1;idx--){}
        list->elems[idx] = -1;
        printf("\n Item has been deleted");
         list->count--;
    }else
    {
        printf("\nList is empty, no element to delete.\n");
    }
    return state;
}

int deleteAt(List *list, int loc){
    int temp = list->elems[loc];
    if(list->count!=0){
        list->elems[loc]=-1;
        for(int idx=loc; idx<MAX-1;idx++){
            int temp =list->elems[idx];
                    list->elems[idx]= list->elems[idx+1];       //shifting deleted elements
                    list->elems[idx+1]=temp;
        }
        list->count--;
    }else{
        printf("\nList is empty, no element to delete.\n");
    }
    return (temp==-1)? -1: temp;
}

bool deleteItem(List *list, DATA key){
    bool state = (list->count!=0);

    if(state){
        for(int idx=0; idx<MAX;idx++){
            if(list->elems[idx]==key){
                list->elems[idx]=-1;
                for(int i=idx; i<MAX-1;i++){
                    int temp =list->elems[i];
                    list->elems[i]= list->elems[i+1];       //shifting deleted elements
                    list->elems[i+1]=temp;
                }
                printf("\n Element %d has been deleted at index[%d]",key,idx);
                 list->count--;
            }
        }
    }else{
        printf("\nList is empty, no element to delete");
    }
    return state;
}

int deleteAllItem(List *list, DATA key){
    bool state= (list->count!=0);
    int ctr=0;
    if(state){
        for(int idx=0;idx<MAX;idx++){
            if(list->elems[idx]==key){
                list->elems[idx] =-1;
                for(int i=idx;i<list->count-1 &&list->elems[i+1]!=-1; i++){              //shifting deleted elements
                    int temp=list->elems[i];
                    list->elems[i] =list->elems[i+1];
                    list->elems[i+1]=temp;
                }
            idx--;
            printf("\nItem Deleted!\n");
            ctr++;
            list->count--;
            }
        }
        }else{
            printf("\n List is empty\n");
        }
      return ctr;
}