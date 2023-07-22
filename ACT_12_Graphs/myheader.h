#ifndef MY_HEADER_H
#define MY_HEADER_H
#define MAX 26
#define EMPTY_KEY ""

#include <stdbool.h>
// based on the first letter of the word
// an array of an array dynamic list

typedef char String[20];

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

typedef struct{
	String list[MAX];
	int top;
}Stack;

typedef struct{
	String data[MAX];
	int front;
	int rear;
	int count;
}Queue;

typedef struct{
	String data[MAX];
	int count;
}Visited;

void initDict(Dictionary *dic);
int hash(char * item);
void addVertex(Dictionary *dic,String item);
void addEdge(Dictionary *dic, String vertex1, String vertex2);
bool checkVertex(Dictionary dic, String item);
void deleteVertex(Dictionary *dic, String key);
void deleteEdge(Dictionary *dic, String vertex1, String vertex2);
void visualize(Dictionary dic);
void BFSdisplay(Dictionary dic, String vertex);
void DFSdisplay(Dictionary dic, String vertex);

//Helper Functions

int getHashIndex(Dictionary dic, String vertex);
void freeDict(Dictionary *dic);
void populateEdges(Dictionary * list);
void populateVertex(Dictionary *list);
bool searchVisited(Visited list, String item);
bool searchVisitedQ(Queue q, String item);
void visitedDisplay(Visited v);
void initVisited(Visited *v);

//Stack functions
void pop(Stack *s);
void push(Stack *s, String vertex);
char * top(Stack * s);
void displaySTK(Stack s);
int addUnvisitedSTK(Dictionary dic,Stack *s, Visited *v);


//Queue Functions
void initQueue(Queue *q);
void enqueue(Queue *q, String vertex);
void dequeue(Queue *q);
char *front(Queue * q);
void displayQ(Queue q);
int addUnvisitedQ(Dictionary dic,Queue *q,Visited v);
#endif
