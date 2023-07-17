#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "myheader.c"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary list;
	initDict(&list);
	addVertex(&list,"Canada");
	addVertex(&list,"Japan");
	addVertex(&list,"Coda");
	addVertex(&list,"Silent");
	addEdge(&list,"Japan","Canada");
	addEdge(&list,"Japan","Coda");
	addEdge(&list,"Japan","Silent");
	display(list);
	freeDict(&list);
	return 0;
}
