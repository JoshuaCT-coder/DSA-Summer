#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Cursorbased.h"

 Student newStudent(int studID, String studName, char sex, String program){
 	Student s;
 	s.studID =studID;
 	strcpy(s.studName,studName);
 	s.sex=sex;
 	strcpy(s.program, program);
 	return s;
 }
 
 VirtualHeap newVH(){
 	VirtualHeap vh;
 	int i;
 	
 	for(i=0;i<MAX;i++){
 		vh.elems[i].elem= newStudent(0,"",' ',"");
 		vh.elems[i].next=i-1;	 
		 }
		 vh.avail= MAX-1;
	return vh;
 }
 int allocSpace(VirtualHeap *vh){
 	int retval = vh->avail;
 	if(retval!=-1){
 		vh->avail= vh->elems[vh->avail].next;	
	 }else{
	 	printf("\nNo available spcae\n");
	 }
	 return retval;
 }
 void insertfront(VirtualHeap *vh,List *list, Student item){
 	int temp =allocSpace(vh);
 	
 	if(temp!=-1){
 	 	vh->elems[temp].next=*list;
 		vh->elems[temp].elem=item;
 		*list=temp;
	 }
 }
 
void display(VirtualHeap vh, List list){
	int i;
	printf("\nStart of list is index [%d]\n",list);
 	printf("\n%5s | %30s | %s\n","Index", "Elements", "Next");
 	printf("\n---------------------------------------------\n");
 	
 	for(i=list;i!=-1;i=vh.elems[i].next){
 		printf("%5d | ",i);
 		if(vh.elems[i].elem.studID==0){
 			printf("%30s |","EMPTY");
		 }else{
		 	printf("%4d - %-23s |",vh.elems[i].elem.studID,vh.elems[i].elem.studName);
		 }
		 printf("%d\n",vh.elems[i].next);
	 }
	 	printf("\n---------------------------------------------\n");
	 	printf("AVAILABLE:%d\n\n",vh.avail);
 	
 }
 void visualizeSpace(VirtualHeap vh){
 	int i;
 	printf("\n%5s | %30s | %s\n","Index", "Elements", "Next");
 	printf("\n---------------------------------------------\n");
 	for(i=0;i<MAX;i++){
 		printf("%5d | ",i);
 		if(vh.elems[i].elem.studID==0){
 			printf("%30s |","EMPTY");
		 }else{
		 	printf("%4d - %-23s |",vh.elems[i].elem.studID,vh.elems[i].elem.studName);
		 }
		 printf("%d\n",vh.elems[i].next);
	 }
	 	printf("\n---------------------------------------------\n");
	 	printf("AVAILABLE:%d\n\n",vh.avail);
 }
 
 void deallocSpace(VirtualHeap *vh,int index){
 	if(index!=-1){
 	vh->elems[index].next=vh->avail;
 	vh->elems[index].elem=newStudent(0,"",' ',"");
 	vh->avail=index;
 	}
 }
 Student removeStudent(VirtualHeap *vh,List *list,String key){
 	Student retval;
 	List *trav,temp;
 	for(trav=list;strcmp(vh->elems[*trav].elem.studName,key)!=0 && *trav!=-1;trav=&vh->elems[*trav].next){}
 	retval = vh->elems[*trav].elem;
 	temp=*trav;
 	*trav=vh->elems[*trav].next;
 	deallocSpace(vh,temp);								  
	printf("\n----------------DELETED ELEMENT--------------\n");
	if(retval.studName==0){
 			printf("%30s |","EMPTY");
		 }else{
		 	printf("%4d - %-23s |",retval.studID,retval.studName);
		 }
		 printf("%d\n\n\n",vh->elems[temp].next);
 	return retval;


 }
   
 
