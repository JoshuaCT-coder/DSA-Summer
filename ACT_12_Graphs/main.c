#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "myheader.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Dictionary list;
	initDict(&list);
	addVertex(&list,"Canada");
	addVertex(&list,"Japan");
	addVertex(&list,"Coda");
	addVertex(&list,"Silent");
	addVertex(&list,"River");
	addVertex(&list,"Luster");
	addVertex(&list,"Rein");
	addEdge(&list,"Japan","Canada");
	addEdge(&list,"Japan","Coda");
	addEdge(&list,"Japan","Silent");
	addEdge(&list,"Japan","River");
	addEdge(&list,"Japan","Luster");
	addEdge(&list,"Japan","Rein");
	display(list);
	freeDict(&list);
	return 0;
}
