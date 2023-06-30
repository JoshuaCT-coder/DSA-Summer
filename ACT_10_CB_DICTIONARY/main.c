#include <stdio.h>
#include <stdlib.h>
#include "myheader.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Vspace vs;
	
	vs=newVspace(10);
	printf("\n%d---%d\n",vs.avail,vs.data[vs.avail].link);
	
	addElem(&vs,10);
	addElem(&vs,10);
	addElem(&vs,10);
	addElem(&vs,10);
	
		visualize(vs);
	return 0;
}
