#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionary.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int size=20;
	Dictionary d;
	initDict(&d,38);
	populate(&d);
	visualize(d);
	freeDictionary(&d);
	
		return 0;
}
