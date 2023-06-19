#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef char String[20];

typedef struct{
	int idNumber;
	String name;
	String gender;
	float totalHrsWrkd;
}HourlyEmployee, *EmployeeList;

typedef struct{
	EmployeeList employee;
	int count;
	int max;
}List;


HourlyEmployee newEmployee(int id, String name,String gender, float hours);
void displayEmployee(HourlyEmployee item);

void initList(List *list);
void addEmployee(List *list, HourlyEmployee emp);
void displayEmployeeList(List list);
List getFemaleEmployee(List *list);



#endif
