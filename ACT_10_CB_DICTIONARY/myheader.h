#ifndef	MYHEADER_H
#define MYHEADER_H
#include <stdbool.h>

#define EMPTY 0 
#define DELETED -1


typedef struct{
	int elem;
	int link;
}Data;

typedef struct{
	Data* data;
	int avail;
	int max;
	int count;
}Vspace;

Vspace newVspace(int max);
int allocSpace(Vspace*vs);
void freeSpace(Vspace *vs, int loc);
bool addelem(Vspace* vs);
bool removeElem(Vspace* vs,int item);
void visualize(Vspace vs);
int hash(int val, int size);
bool goodDensity(Vspace vs);
bool isEmpty(Vspace vs,int loc);

#endif
