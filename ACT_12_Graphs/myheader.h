#ifndef MY_HEADER_H
#define MY_HEADER_H
#define MAX 26
#define EMPTY_KEY ""

#include <stdbool.h>
// based on the first letter of the word
// an array of an array dynamic list

typedef char String[15];

typedef struct{
	String *data;
	int count;
	int max;
}ArrayList;

typedef struct{
	String key;
	ArrayList value;
}ArrNode;

typedef struct{
	ArrNode List[26];
}Dictionary;

void initDict(Dictionary *dic);
int hash(char * item);
void addVertex(Dictionary *dic,String item);
void addEdge(Dictionary *dic, String vertex1, String vertex2);
bool checkVertex(Dictionary dic, String item);
void deleteVertex(Dictionary *dic, String key);
void deleteEdge(Dictionary *dic, String vertex1, String vertex2);
void visualize(Dictionary dic);
void BFSdisplay(Dictionary dic);
void DFSdisplay(Dictionary dic);

//Helper Functions
void DFShelper(Dictionary *dic);
int getHashIndex(Dictionary dic, String vertex);
void freeDict(Dictionary *dic);
#endif
