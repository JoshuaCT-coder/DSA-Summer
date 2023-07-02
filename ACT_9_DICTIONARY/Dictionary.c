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


void addElem(Dictionary *d,Student item){
	ElemPtr *trav;
	ElemPtr *trav1;
	int idx =Hash(item,d->max);
	ElemPtr temp= malloc(sizeof(Stype));

	for(trav = &d->elems[idx]; *trav != NULL && strcmp((*trav)->data.studName.Lname, item.studName.Lname) <= 0; trav = &(*trav)->next){

		if(strcmp((*trav)->data.studName.Lname,item.studName.Lname)==0){
			printf("\nLast name the same\n");

				printf("\nFirst name checking\n");
				printf("\n%s %s",(*trav)->data.studName.Fname,(*trav)->data.studName.Lname);
				for(trav1=trav;*trav1!=NULL && strcmp((*trav1)->data.studName.Fname, item.studName.Fname)<0 && strcmp((*trav1)->data.studName.Lname,item.studName.Lname)==0;trav1=&(*trav1)->next){}
				 printf("\nloop finished\n");
					if(*trav1!=NULL){
							if(strcmp((*trav1)->data.studName.Fname,item.studName.Fname)==0){
								printf("\nMiddle name checking\n");
								for(;*trav1!=NULL && strcmp((*trav1)->data.studName.Mname, item.studName.Mname)<0 && strcmp((*trav1)->data.studName.Lname,item.studName.Lname)==0;trav1=&(*trav1)->next){}
									if(*trav1!=NULL){
										if(strcmp((*trav1)->data.studName.Mname,item.studName.Mname)==0){

											printf("\nID number checking\n");
											for(;*trav1!=NULL && strcmp((*trav1)->data.studId,item.studId)<0 && strcmp((*trav1)->data.studName.Lname,item.studName.Lname)==0;trav1=&(*trav1)->next){}
												if(*trav1!=NULL){			
													if(strcmp((*trav1)->data.studId,item.studId)==0){
													printf("\nThis Person already exists\n");
													return;
											
													}else{
														printf("\n %s is larger then %s\n",(*trav1)->data.studId,item.studId);
														trav=trav1;
															break;
													}
												}else{
													 printf("\nEnd of the list\n");
													trav=trav1;
													break;
												}
										}else{
											 printf("\n %s is larger then %s\n",(*trav1)->data.studName.Mname,item.studName.Mname);
											trav=trav1;
											break;
											}
										}else{
											 printf("\nEnd of the list\n");
											trav=trav1;
											break;
										}
								}else{
								 printf("\n %s is larger then %s\n",(*trav1)->data.studName.Fname,item.studName.Fname);
								trav=trav1;
								break;
								}
							}else{
								 printf("\nEnd of the list\n");
									trav=trav1;
									break;
								}
					}
	}

	temp->data=item;
	temp->next=*trav;
	*trav=temp;
	printf("\nElement Added\n\n----------------\n");
}
void removeElem(Dictionary *d, Student item){
	ElemPtr *trav;
	ElemPtr *trav1;
	int result;
	int idx =Hash(item,d->max);
	ElemPtr temp;

	for(trav = &d->elems[idx]; *trav != NULL && strcmp((*trav)->data.studName.Lname, item.studName.Lname) != 0; trav = &(*trav)->next){}

			printf("\nLast name the same\n");

				printf("\nFirst name checking\n");
				
				for(trav1=trav;*trav1!=NULL && strcmp((*trav1)->data.studName.Fname, item.studName.Fname)!=0 && strcmp((*trav1)->data.studName.Lname,item.studName.Lname)==0;trav1=&(*trav1)->next){}
				 printf("\nloop finished\n");
					if(*trav1!=NULL){
							
								printf("\nMiddle name checking\n");
								for(;*trav1!=NULL && strcmp((*trav1)->data.studName.Mname, item.studName.Mname)!=0 && strcmp((*trav1)->data.studName.Lname,item.studName.Lname)==0 && strcmp((*trav1)->data.studName.Fname,item.studName.Fname)==0;trav1=&(*trav1)->next){}
									if(*trav1!=NULL){

											printf("\nID number checking\n");
											for(;*trav1!=NULL && strcmp((*trav1)->data.studId,item.studId)!=0 && strcmp((*trav1)->data.studName.Lname,item.studName.Lname)==0 && strcmp((*trav1)->data.studName.Mname,item.studName.Mname)==0 && strcmp((*trav1)->data.studName.Fname,item.studName.Fname)==0;trav1=&(*trav1)->next){}
												if(*trav1!=NULL){			
													temp=*trav1;
													*trav=(*trav)->next;
													free(temp);
													printf("\nElement found and has been deleted\n");
												}else{
													 printf("\nElement not found\n");
												}
										
										}else{
											 printf("\nElement not found\n");
											trav=trav1;
										}
								}else{
								 printf("\nElement not found\n");
									trav=trav1;
								}
}

int Hash (Student s,int size){
	return (toupper(s.studName.Lname[0])-65)%26;
}

void freeDictionary(Dictionary* dict) {

    free(dict->elems);
    dict->count = 0;
    dict->max = 0;
}


void populate(Dictionary *d){
	addElem(d,newstudent("21100012",newName("Janus","Casera","Ridriguez"),newBday(18,04,2002),'M',"BSCS",2));
	addElem(d,newstudent("21100012",newName("Joshua","Casera","Radriguez"),newBday(18,04,2002),'M',"BSCS",2));
	addElem(d,newstudent("21100012",newName("Jeremy","Casera","Redriguez"),newBday(18,04,2002),'M',"BSCS",2));
	addElem(d,newstudent("21100012",newName("Jarco","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
	addElem(d,newstudent("21100012",newName("Jimmy","Casera","Rudriguez"),newBday(18,04,2002),'M',"BSCS",2));
	addElem(d,newstudent("21100012",newName("Jorus","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
	addElem(d,newstudent("31100556",newName("Joshua","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
	addElem(d,newstudent("22200124",newName("Joshua","Mirio","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
	addElem(d,newstudent("21100012",newName("Joshua","Casera","Saramo"),newBday(18,04,2002),'M',"BSCS",2));
	visualize(*d);
	addElem(d,newstudent("31100556",newName("Joshua","Casera","Rodriguez"),newBday(18,04,2002),'M',"BSCS",2));
}

void visualize(Dictionary d){
	Fullname fullName;
	int trav;
	Student currentElem; 


	printf("\n%6s | %9s | %-30s | %2s | %7s | %-12s | %-5s\n","INDEX","ID","STUDENT NAME","SEX","PROGRAM","DATE","YEAR"); 
	for(trav=0;trav<d.max;trav++){
		printf("\n%6d | ",trav);
		if(d.elems[trav]!=NULL){

			ElemPtr travrow= d.elems[trav];

			while(travrow!=NULL){

			currentElem=travrow->data;
			strcpy(fullName, currentElem.studName.Fname);
			strcat(fullName, " ");
			strcat(fullName, currentElem.studName.Mname);
			strcat(fullName, " ");
			strcat(fullName, currentElem.studName.Lname);

				printf("%-9s | %-30s | %2c | %-7s | %4s %2d %4d | %5d\n%-9s",currentElem.studId,
													fullName,
													currentElem.sex,
													currentElem.program,
													Dates[currentElem.bday.month],
													currentElem.bday.date,
													currentElem.bday.year,
													currentElem.year,"");
			travrow=travrow->next;
		}
		}else{
			printf("%-60s\n","EMPTY");
		}
		
	}
	printf("-----------------------------------------------------------------------\n");

}
