#include <stdio.h>
#include <stdlib.h>
#include "SETS.h"



bool t = true;
bool f = false;


Set newSet(){
	Set temp; 
	int i;
	for(i=0; i<MAX; i++){
		temp.elems[i]=f;
	}
		temp.count=0;
	return temp;
}
bool addElem(Set *s, int item){
	int i;
	for(i=0;item!=i;i++){}
	if(s->elems[i]==f && i<MAX){
		s->elems[i]=t;
		s->count++;
		printf("\nElement Added \n");
	}
}
bool removeElem(Set *s, int item){
	int i;
	for(i=0;item!=i;i++){}
	if(s->elems[i]==t && i<MAX){
		s->elems[i]=f;
		s->count--;
			printf("\nElement Removed\n");
	}else{
		printf("\nElement not found \n");
	}
}

void displaySet(Set s){
	int i;
		printf("\n {");
	for(i=0;i<MAX;i++){
		if(s.elems[i]==t){
			printf("%d | ",i);
		}
	}	
	printf("}\n");
	printf("\nCardinality: %d\n",cardinality(s));
}

Set unionSet(Set a, Set b){
	int i;
	Set unionS=newSet();
	for(i=0;i<MAX;i++){
		if(a.elems[i]==t || b.elems[i]==t){
			unionS.elems[i]=t;
			unionS.count++;
		}
	}
return unionS;	
}
Set interSet(Set a, Set b){
	int i;
	Set newS=newSet();
	for(i=0;i<MAX;i++){
		if(a.elems[i]==t && b.elems[i]==t){
			newS.elems[i]=t;
			newS.count++;
		}
	}
return newS;	
}
Set differenceSet(Set a, Set b){
		int i;
	Set newS=newSet();
	for(i=0;i<MAX;i++){
		if(a.elems[i]==t && b.elems[i]==f){
			newS.elems[i]=t;
			newS.count++;
		}
	}
	
return newS;	
}
Set symmetricDiffSet(Set a, Set b){
	Set Awb=newSet();
	Set BwA=newSet();
	Set temp=newSet();
	Awb=differenceSet(a,b);
	BwA=differenceSet(b,a);
	temp=unionSet(Awb, BwA);
	return temp;
}
int cardinality(Set s){
	return s.count;
}
