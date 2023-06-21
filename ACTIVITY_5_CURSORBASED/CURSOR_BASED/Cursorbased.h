#ifndef CURSOR_BASED_H
#define CURSOR_BASED_H

#define MAX 10

typedef char String[20];
typedef int List;

typedef struct{
int studID;
String studName;
char sex;
String program;
}Student;

typedef struct{
	Student elem;
	int next;	
}Node,Stype;

 typedef struct{
 	Stype elems[MAX];
 	int avail;
 }VirtualHeap;
 
 Student newStudent(int studID, String studName, char sex, String program);
 
 VirtualHeap newVH();
 int allocSpace(VirtualHeap *vh);

 void insertfront(VirtualHeap *vh,List *list, Student item);
 
 void display(VirtualHeap vh, List list);
 void visualizeSpace(VirtualHeap);
 
 void deallocSpace(VirtualHeap *vh,int index);
 Student removeStudent(VirtualHeap *vh,List *list,String key);
 
// 
// int deallocspace();
// initVH();
 
 
#endif
