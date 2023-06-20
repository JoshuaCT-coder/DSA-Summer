#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

int main(){
	List emplist;
	
	initList(&emplist);
	addEmployee(&emplist, newEmployee(1011,"Maria Posada","Female",40.0));
	addEmployee(&emplist, newEmployee(1012,"Derrick Posada","Male",50.0));
	addEmployee(&emplist, newEmployee(1013,"Juan Posada","Male",60.0));
	addEmployee(&emplist, newEmployee(1014,"Carmen Posada","Female",40.0));
	addEmployee(&emplist, newEmployee(1015,"Barry Posada","Male",60.0));
	addEmployee(&emplist, newEmployee(1016,"Juanita Posada","Female",40.0));
	addEmployee(&emplist, newEmployee(1017,"Jann Posada","Female",60.0));
	addEmployee(&emplist, newEmployee(1018,"Nina Posada","Female",40.0));
	displayEmployeeList(emplist);
	List femEmp = getFemaleEmployee(&emplist);
	printf("\n\t-----------FEMALE-----------\n");
	displayEmployeeList(femEmp);
	return 0;
}
