#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myheader.h"

/*typedef struct{
	int elem;
	int link;
}Data;
typedef struct{
	Data* data;z
	int avail;
	int max;
}Vspace;
*/

Vspace newVspace(int max){
	Vspace newVS;
	newVS.data=malloc(sizeof(Data)*max);
	int i,a;
	newVS.avail=max/2;
	newVS.max=max;
	for(i=0;i<newVS.avail;i++){
		newVS.data[i].elem=EMPTY;
		newVS.data[i].link=-1;
	}
	for(;i<max-1;i++){
		newVS.data[i].elem=EMPTY;
		newVS.data[i].link=i+1;
	}
	newVS.data[i].elem=EMPTY;
	newVS.data[i].link=-1;

	return newVS;
}
int allocSpace(Vspace *vs){
	int temp; 
	
	if(vs->avail!=-1){	
		temp= vs->avail;
		vs->avail=vs->data[vs->avail].link;
		
	}else{
		printf("\nNo more Available Space\n");
		}	
	return temp;
}

bool addElem(Vspace* vs, int item){
	int hashval=hash(item,vs->max/2);
	if(goodDensity(*vs)){
		if(isEmpty(*vs,hashval)){
			vs->data[hashval].elem=item;
		}else{
			int idx= allocSpace(vs);
			vs->data[idx].elem=item;
			vs->data[idx].link=vs->data[hashval].link;
			vs->data[hashval].link=idx;
	}
		vs->count++;	
	}else{
		rehash(vs);
		int idx= allocSpace(vs);
		vs->data[idx].elem=item;
		vs->data[idx].link=vs->data[hashval].link;
		vs->data[hashval].link=idx;
		vs->count++;
	}
}
bool removeElem(Vspace* vs, int item){
	int hashval=hash(item,vs->max/2);
	if(vs->data[hashval].elem==item){
		if(	vs->data[hashval].link=-1){
			vs->data[hashval].elem=DELETED;
		}else{
			vs->data[hashval].elem=EMPTY;
		}
		vs->count--;
	}else{
		int *trav;
		for(trav=&(vs->data[hashval].link);*trav!=-1&&vs->data[*trav].elem!=item;trav=&(vs->data[*trav].link)){}
		if(*trav!=-1){
			int temp=*trav;
			*trav=vs->data[*trav].link;
			freeSpace(vs,temp);
			vs->count--;
		}else{
			printf("\nItem not Found\n");
		}	
	}
	if(vs->data[hashval].link==-1){
		vs->data[hashval].elem=EMPTY;
	}
}

void freeSpace(Vspace *vs, int loc){
	vs->data[loc].link=vs->avail;
	vs->data[loc].elem=EMPTY;
	vs->avail=loc;
}

void visualize(Vspace vs){
	int i;
	int half =vs.max/2;
	printf("%5s | %5s | %5s %10s %5s | %5s | %5s\n","INDEX","DATA","LINK","","INDEX","DATA","LINK");
	printf("----------------------          ---------------------\n");
	for(i=0;i<half;i++){
		printf("%5d | %5d | %5d %10s %5d | %5d | %5d\n",
				i,vs.data[i].elem,vs.data[i].link
				,"",i+half,vs.data[i+half].elem,vs.data[i+half].link);
	}
}
int hash(int val,int size){
	return val%size;
}

bool goodDensity(Vspace vs){
	return ((vs.count/vs.max)<=0.7);
}

bool isEmpty(Vspace vs,int loc){
	return(vs.data[loc].elem==EMPTY);
}
void rehash(Vspace *vs){
	int newSize =vs->max*2;
	Vspace newvs;
	newvs.data=malloc(sizeof(Data)*newSize);
	newvs.count=0;
	newvs.avail=newSize/2;
	
	int i;
	for(i=0;i<newvs.avail;i++){
		newvs.data[i].elem=EMPTY;
		newvs.data[i].link=-1;
	}
	for(;i<newSize-1;i++){
		newvs.data[i].elem=EMPTY;
		newvs.data[i].link=i+1;
	}
	newvs.data[i].elem=EMPTY;
	newvs.data[i].link=-1;
	
	int trav;
	for(trav=0;trav<vs->max;trav++){
		if(vs->data[trav].elem!=EMPTY && vs->data[trav].elem!=DELETED){
			addElem(&newvs,vs->data[trav].elem);
		}
	vs->data=newvs.data;
	vs->count=newvs.count;
	vs->avail=newvs.avail;
	vs->max= newSize;
	free(newvs.data);
	}
}

