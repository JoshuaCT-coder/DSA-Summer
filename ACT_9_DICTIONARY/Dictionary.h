#ifndef DICTIONARY_H
#define DICTIONARY_H
#include <stdbool.h>

typedef char String[20];

typedef char shortstring[5];
typedef char Fullname[35];

typedef struct{
	String Fname;
	String Mname;
	String Lname;
}Name;

typedef struct{
	int date;
	int month;
	int year;
}Birthday;

typedef struct{
	String studId;
	Name studName;
	char sex;
	Birthday bday;
	String program; 
	int year;
}Student;

 
typedef struct node{
 	Student data;
 	struct node* next;
 }Stype,*ElemPtr;
 
typedef struct{
	ElemPtr *elems;
	int count;
	int max;
}Dictionary;


Student newstudent(String studId,Name studName, Birthday bday, char sex, String program, int year);
Name newName(String fname, String mname, String lname);
Birthday newBday(int date, int month, int year);


// Dictionary createDict();
void initDict(Dictionary *d,int max);
int Hash (Student s,int size);
void addElem(Dictionary *d,Student item);
void populate(Dictionary *d);
//void removeElem(Dictionary *d, Student item);
void visualize(Dictionary d);
void freeDictionary(Dictionary* dict);

#endif
