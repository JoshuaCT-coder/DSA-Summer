#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DynamicArray.h"



void initList(List *list){
    list->elems = calloc(MAX, sizeof(DATA));
    list->count = 0;
    list->max = MAX;
}


List newList(int max){
    List list;
    list.max = max;    
}

void displayList(List list){
    for(int idx=0; idx < list.max;idx++){
        if(list.elems[idx]!=0){
        printf("\n Index [%d]: %d\n",idx, list.elems[idx]);
        }else{
            printf("\nIndex [%d]: EMPTY\n",idx);
        }
    }
    printf("\n Number of Elements: %d\n",list.count);
}



bool insertFront(List *list, DATA item)
{
    bool state = (list->count == list->max);
    if (state)
    {
        for (int a = MAX - 2; a > -1; a--)
        {
            list->elems[a + 1] = list->elems[a];
        }
        list->elems[0] = item;

        list->count++;
        printf("\nElement inserted at the Front\n");
    }else{
        int newSize = list->max*2;
        DATA *newElems = realloc(list->elems,newSize* sizeof(DATA));
       
        if (newElems != NULL) {
            printf("\nSuccessfully reallocated memory for the  array.\n");
             list->max =newSize;
             list->elems[0] = newElems;
    

    for (int i = list->count; i > 0; i--) {
        list->elems[i] = list->elems[i - 1];
    }

    list->elems[0] = item;
    list->count++;
    }
}
    return state;
}


bool insertRear(List *list, DATA item){

}

bool insertSorted(List *list, DATA item){

}

bool insertAt(List *list, DATA item, int loc){

}

bool searchItem(List list, DATA key){

}

int getItem(List list, DATA key){

}

bool deleteFront(List *list){

}

bool deleteRear(List *list){

}

int deleteAt(List *list, int loc);

bool deleteItem(List *list, DATA key);

int deleteAllItem(List *list, DATA key);
