#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "LinkedList.h"


void initList(List *list){
    *list = NULL;
}

List newList(){
    List list = NULL;
    return list;
}

NodePtr createNode(DATA data){
    NodePtr list = malloc(sizeof(NodeType));                        //Edited the datatype so that I can use it in other functions
    if(list !=NULL){
    list->data = data;
    list->next = NULL;
    }else{
        printf("\nFailed to allocate memory\n");
    }
    return list;
}

void displayList(List list){
    List trav;
    int ctr=0;
    for(trav = list; trav != NULL; trav = trav->next){
        printf("\nElement %d\n",trav->data);
        ctr++;
    }
    printf("\nThere are %d number of elements\n",ctr);
}

bool insertFront(List *list, DATA item){
    List temp = createNode(item);
    temp->next= *list;
    *list = temp;
    printf("\nElement Successfully inserted at Front\n");
    return(temp!=NULL);
}

bool insertRear(List *list, DATA item){
    List temp = createNode(item);
    List *trav;

    for(trav=list;(*trav)!= NULL; trav=&(*trav)->next){}
    (*trav)= temp;
     printf("\nElement Successfully inserted at the Rear\n");
    return(temp!=NULL);
}

bool insertAt(List *list, DATA item, int loc){
    List temp = createNode(item);
    List *trav =list;
    int ctr=1;

    /*if (loc > count){                // this condition is assuming you have a count variable and can identfy if your location is within bounds of the exisiting linked list

    }*/

    while(ctr<loc && (*trav)!=NULL){
        
        trav=&(*trav)->next;
        ctr++;
    } 
    if((*trav)== NULL && ctr<loc){
        printf("\n Location out of Bounds \n");
    }else{
         temp->next = *trav;
        *trav= temp;
         printf("\nElement Successfully inserted at the %d location\n",loc);
    } 
     return(temp!=NULL);
}

bool insertSorted(List *list, DATA data);

bool searchItem(List list, DATA key);

int getItem(List list, DATA key);

bool deleteFront(List *list);

bool deleteRear(List *list);

int deleteAt(List *list, int loc);

bool deleteItem(List *list, DATA key);

int deleteAllItem(List *list, DATA key);
