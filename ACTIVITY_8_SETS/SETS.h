#ifndef SETS_H
#define SETS_H
#define MAX 20
#include <stdbool.h>

typedef char String[30];
//typedef bool Set[20]
typedef struct{
	bool elems[MAX];
	int count;
}Set;

//void initSet();
Set newSet();
bool addElem(Set *s, int item);
bool removeElem(Set *s, int elem);
void displaySet(Set s);

Set unionSet(Set a, Set b);
Set interSet(Set a, Set b);
Set differenceSet(Set a, Set b);
Set symmetricDiffSet(Set a, Set b);
int cardinality(Set s);
#endif
