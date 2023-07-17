#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "myheader.h"

int hash(char * item){
	char firstletter = toupper(item[0]);

    int hashvalue = (int)firstletter % 26;

    return hashvalue;
}


void initDict(Dictionary *dic){
	int i;
	for(i=0;i<MAX;i++){
	strcpy(dic->List[i].key,EMPTY_KEY);
	dic->List[i].value.count=0;
	dic->List[i].value.max=5;
	dic->List[i].value.data=NULL;
	}
}


void addVertex(Dictionary *dic,String item){
	int hashval=hash(item);
	if(dic->List[hashval].key!=EMPTY_KEY){
		strcpy(dic->List[hashval].key,item);
	}else if(strcmp(dic->List[hashval].key,EMPTY_KEY)==0){
		printf("\nVertex Already exists\n");
	}else{
		while (dic->List[hashval].key!=EMPTY_KEY){
        hashval = (hashval + 1) % MAX;
    }
    strcpy(dic->List[hashval].key,item);
	}
}

bool checkVertex(Dictionary dic, String item){
	int hashval=hash(item);
	bool state= false;
	if(strcmp (dic.List[hashval].key,item)==0){
	 state = true;	
	
	}else{
		while (strcmp(dic.List[hashval].key,EMPTY_KEY)!=0){
        hashval = (hashval + 1) % MAX;
    }
	    if(strcmp(dic.List[hashval].key,EMPTY_KEY)==0){
	    	state = false;
		}
}
return state;
}



void addEdge(Dictionary *dic, String item1, String item2){
	bool state1= checkVertex(*dic,item1);
	bool state2= checkVertex(*dic,item2);
	int hash1=hash(item1);
	int hash2=hash(item2);
	String temp;
	if (state1 && state2){
			if(strcmp(dic->List[hash1].key,item1)==0){
				if(dic->List[hash1].value.data==NULL){
					dic->List[hash1].value.data = malloc(sizeof(String)*dic->List[hash1].value.max);
				}else{
					if
				}
	
  
			}else{
				
				while (strcmp(dic.List[hash2].key,EMPTY_KEY)!=0){
		        hashval = (hashval + 1) % MAX;
		   			 }
			    if(strcmp(dic.List[hashval].key,EMPTY_KEY)==0){
			    	state = false;
					}
				}		
	}else{
		printf("\nOne vertex does not Exist\n");
	}
}
void display(Dictionary dic);




