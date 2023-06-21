#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cursorbased.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
VirtualHeap VH = newVH();
List mylist =-1;

insertfront(&VH,&mylist,newStudent(101,"Jonathan C. Herman",'M',"BS IT"));
insertfront(&VH,&mylist,newStudent(101,"Raya The Dragon", 'F',"BS in a boat"));
insertfront(&VH,&mylist,newStudent(101,"Gwen Stacy", 'F',"BS in Swinging"));
visualizeSpace(VH);
display(VH,mylist);
removeStudent(&VH,&mylist,"Raya The Dragon");
visualizeSpace(VH);
display(VH,mylist);

	return 0;
}
