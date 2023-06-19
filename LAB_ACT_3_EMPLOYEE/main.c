#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.c"

int main(){
	List emplist;
	
	initList(&emplist);
	addEmployee(&emplist, newEmployee(1011,"Maria Posada","Female",40.0));
	addEmployee(&emplist, newEmployee(1012,"Derrick Posada","Male",50.0));
	addEmployee(&emplist, newEmployee(1013,"Juan Posada","Male",60.0));
	addEmployee(&emplist, newEmployee(1014,"Maria Posada","Female",40.0));
	displayEmployeeList(emplist);
	return 0;
}
