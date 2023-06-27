#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionary.h"

Dictionary createDict();
void initDict(Dictionary *d,int max){
	int i;
	for(i=0; i<max;i++){
		d->elems[i]=NULL;
	}
		d->max=max;
		d->count=0;
}
void addElem(Dictionary *d,Student item){
	
}
void removeElem(Dicitonary *d);
void visualize(Dictionary d);

int Hash (Student s,int size){
	return toupper(s.studName.Lname[0])-65;
}

