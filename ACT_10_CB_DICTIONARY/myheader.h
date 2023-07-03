#ifndef	MYHEADER_H
#define MYHEADER_H
#include <stdbool.h>

#define EMPTY 0 
#define DELETED -1

typedef char String[20];
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
int allocSpace(Vspace *vs);
int hash(int val,int size);
bool goodDensity(Vspace vs);
bool isEmpty(Vspace vs,int loc);
void freeSpace(Vspace *vs, int loc);
void visualize(Vspace vs);
void rehash(Vspace *vs);
bool addElem(Vspace* vs, int item);
bool removeElem(Vspace* vs, int item);


#endif
