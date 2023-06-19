#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

HourlyEmployee newEmployee(int id, String name,String gender, float hours){
	HourlyEmployee he;
	
	he.idNumber = id;
	strcpy(he.name,name);
	strcpy(he.gender,gender);
	he.totalHrsWrkd =hours;
	
	return he;
}

void displayEmployee(HourlyEmployee he){
	printf("\nID: %d\n",he.idNumber);
	printf("\nNAME: %s\n",he.name);
	printf("\nGENDER: %c\n",he.gender);
	printf("\nHOURS WORKED: %.2f\n",he.totalHrsWrkd);
}

void initList(List *list){
	list->max=2;
	list->employee = (HourlyEmployee*)malloc(sizeof(HourlyEmployee) * list->max);
	list->count = 0;
}
void addEmployee(List *list, HourlyEmployee emp){
	if(list->count == list->max){
	int newSize = list->max *2;
	EmployeeList newList = realloc(list->employee,sizeof(HourlyEmployee) * newSize);
	if(newList!=NULL){
		printf("\nList Successfully Reallocated\n");
             list->max =newSize;
             list->employee = newList;
	}
}
	list->employee[(list->count)++]= emp;
}
void displayEmployeeList(List list){
	int i;
	printf("\n\t-------EMPLOYEE LIST----------\n");
	printf("\n%10s | %15s | %10s\n","ID","NAME","GENDER");
	for(i=0; i< list.count;i++){
		printf("\n%10d | %15s | %10s\n",list.employee[i].idNumber,list.employee[i].name,list.employee[i].gender);
	}
}
List getFemaleEmployee(List *list){
	List femEmp;
	
}



