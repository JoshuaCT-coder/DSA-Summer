#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dictionary.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int size=20;
	Dictionary dict;
	initDict(&dict,38);
	
	visualize(dict);
	freeDictionary(&dict);
	
		return 0;
}
