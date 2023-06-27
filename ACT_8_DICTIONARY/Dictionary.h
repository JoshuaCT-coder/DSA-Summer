#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdbool.h>

typedef char String[20];

typedef struct{
	String Fname;
	String Mname;
	String Lname;
}Name;

typedef stuct{
	int date;
	int month;
	int year;
}Birthday;

typedef struct{
	String studId;
	char sex;
	Name studName;
	Birthday bday;
	String program; 
	int year;
}Student;

 typedef struct node{
 	Student elem;
 	struct node* next;
 }Stype;
 
typedef struct{
	Stype *elems[MAX];
	int count;
	int max;
}Dictionary;


Dictionary createDict();
void initDict(Dictionary *d,int max);
void addElem(Dictionary *d,Student item);
void removeElem(Dicitonary *d, Student item);
void visualize(Dictionary d);
int Hash (Student s,int size);


#endif
