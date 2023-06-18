#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "DynamicArray.h"

void resizeArray(List* list, int max){
    if(list->count< list->max/2){
        int newSize=list->max/2;
        DATA *NewElems =realloc(list->elems,newSize * sizeof(DATA));
        if (NewElems != NULL) {
            printf("\nSuccessfully reallocated memory for the  array.\n");
             list->max =newSize;
             list->elems = NewElems;
             list->elems[list->max]=0;
        }
    }else{
        int newSize = list->max*2;
        DATA *newElems = realloc(list->elems,newSize* sizeof(DATA));
       
        if (newElems != NULL) {
            printf("\nSuccessfully reallocated memory for the  array.\n");
             list->max =newSize;
             list->elems = newElems;

             for(int idx=list->count;idx<list->max;idx++){
                list->elems[idx]=0;
             }
    }
}
}

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
    bool state = (list->count != list->max);
    if (state)
    {
        for (int a = list->max - 2; a > -1; a--)
        {
            list->elems[a + 1] = list->elems[a];
        }
        list->elems[0] = item;

        
    }else{
        resizeArray(list, list->max);
    

    for (int i = list->count; i > 0; i--) {
        list->elems[i] = list->elems[i - 1];
    }

    list->elems[0] = item;
  
    } 
    list->count++;
    printf("\nElement inserted at the Front\n");
    return state;
}


bool insertRear(List *list, DATA item){
    bool state = (list->count== list->max);
    
    if(state){
        resizeArray(list,list->max);
        list->elems[list->count]= item;
        list->count++;
    }else{
       int idx;
       for(idx=0;idx<list->max && list->elems[idx]!=0;idx++){}
        list->elems[idx]=item;
        list->count++;
    }
    printf("\nElement inserted at Rear\n");
    return state;
}

bool insertSorted(List *list, DATA item){
     bool state = (list->count==list->max);
        if(state){
            resizeArray(list,list->max);
        }
            int idx;
            for(idx=0; idx<list->max && list->elems[idx]<=item && list->elems[idx]!=0; idx++){}
                if(list->elems[idx]==0){
                    list->elems[idx]=item;
                }else{
                    int high;
                    for(high=list->max-1; high>=idx && list->elems[high]==0; high--){}   //ommits uninitialized parts of the list
                    for(int i= high;i>=idx; i--){
                        list->elems[i+1]=list->elems[i];
                    }
                    list->elems[idx]=item;
                }
                list->count++;
                printf("\n ELement has been added in Sorted position\n");
                 return state;
        }

bool insertAt(List *list, DATA item, int loc){
    bool state =(list->elems[loc]==0);
    if(state){
        list->elems[loc]=item;
    }else{
        if(list->count== list->max){
            resizeArray(list,list->max);
        }
        int high;
        for(high=list->max-1;list->elems[high];high--){}
        while(high>=loc){
            list->elems[high+1]=list->elems[high];
            high--;
        }
        list->elems[loc];
    }
    list->count++;
    printf("\nElement inserted at Location\n");
    return state;
}

bool searchItem(List list, DATA key){
     int low =0;
     int high=list.max-1;
     int mid = low + (high-low)/2;
    
    while(low<=high && list.elems[high]==0){
        high--;
    }
    while(low<=high && list.elems[mid]!=key){
         mid = low + (high-low)/2;

        if(list.elems[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return(list.elems[mid]==key);
}

int getItem(List list, DATA key){
     int low =0;
     int high=list.max-1;
     int mid = low + (high-low)/2;
    
    while(low<=high && list.elems[high]==0){
        high--;
    }
    while(low<=high && list.elems[mid]!=key){
         mid = low + (high-low)/2;

        if(list.elems[mid]<key){
            low=mid+1;
        }else{
            high=mid-1;
        }
    }
    return(list.elems[mid]==key)? mid: 0;
}

bool deleteFront(List *list){
		bool state = (list->count!=0);

		if(state){
			int idx;
			for(idx=0; idx<list->max && list->elems[idx+1]!=0; idx++){
				list->elems[idx]=list->elems[idx+1];
			}
            list->elems[idx]=0;
            printf("\nFront Element has been deleted\n");
            list->count--;
			if(list->count<list->max/2){
                resizeArray(list,list->max);
            }
		}
	}

bool deleteRear(List *list){

}

int deleteAt(List *list, int loc);

bool deleteItem(List *list, DATA key);

int deleteAllItem(List *list, DATA key);
