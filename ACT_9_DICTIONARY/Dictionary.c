#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionary.h"
#include <ctype.h>

shortstring Dates[13]={"","Jan","Feb","Mar","Apr","May","June","July","Aug","Oct","Nov","Dec"};


Student newstudent(String studId,Name studName, Birthday bday, char sex, String program, int year){
	Student temp;
	strcpy(temp.studId,studId);
	temp.studName=studName;
	temp.bday=bday;
	temp.sex=sex;
	temp.year=year;
	strcpy(temp.program,program);
	return temp;
}
Name newName(String fname, String mname, String lname){
	Name temp;
	strcpy(temp.Fname,fname);
	strcpy(temp.Mname,mname);
	strcpy(temp.Lname,lname);
	return temp;
}
Birthday newBday(int date, int month, int year){
	Birthday bday;
	bday.date=date;
	bday.month=month;
	bday.year=year;
	return bday;
}

// Dictionary createDict();
void initDict(Dictionary *d,int max){
	int i;
	ElemPtr *ptr = malloc(sizeof(ElemPtr)*max);
		for(i=0; i<max;i++){
			ptr[i]=NULL;
		}
			d->max=max;
			d->count=0;
	d->elems=ptr;
}


void addElem(Dictionary *d,Student item){}
void removeElem(Dictionary *d, Student item);


int Hash (Student s,int size){
	return toupper(s.studName.Lname[0])-65;
}

void freeDictionary(Dictionary* dict) {
    for (int i = dict->max-1; i >-1; i--) {
        free(dict->elems[i]);
    }
    free(dict->elems);
    dict->count = 0;
    dict->max = 0;
}


void populate(){
	newstudent("21100012",newName("Joshua","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2);
}

void visualize(Dictionary d){
	Fullname fullName;
	int trav;
	Student currentElem; 


	printf("\n%6s | %9s | %-30s | %2s | %7s | %-12s | %-5s\n","INDEX","ID","STUDENT NAME","SEX","PROGRAM","DATE","YEAR"); 
	for(trav=0;trav<d.max;trav++){
		printf("%6d | ",trav);
		if(d.elems[trav]!=NULL){

			ElemPtr travrow= d.elems[trav];
			currentElem=travrow->data;

			strcpy(fullName, currentElem.studName.Fname);
			strcat(fullName, " ");
			strcat(fullName, currentElem.studName.Mname);
			strcat(fullName, " ");
			strcat(fullName, currentElem.studName.Lname);

			while(travrow!=NULL){
			printf("%-9d | %-30s | %2s | %-7s | %4s %2d %4d | %5d\n",currentElem.studId,
													fullName,
													currentElem.sex,
													currentElem.program,
													Dates[currentElem.bday.month],
													currentElem.bday.date,
													currentElem.bday.year);
			travrow=travrow->next;
		}
		}else{
			printf("%-60s\n","EMPTY");
		}
		
	}
	printf("-----------------------------------------------------------------------\n");

}
